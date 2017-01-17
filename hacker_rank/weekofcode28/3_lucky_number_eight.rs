#![allow(unused_imports)]
#![allow(non_snake_case)]
use std::io::{self, Read};
use std::collections::*;
use std::cmp::*;
use std::iter::*;

macro_rules! read(
  () => { read!("{}") };
  ($text:expr) => {{
    let value;
    scan!($text, value);
    value
  }};
  ($text:expr, $input:expr) => {{
    let value;
    scan!($input => $text, value);
    value
  }};
);

macro_rules! scan(
  ($text:expr, $($arg:expr),*) => { scan!(::std::io::stdin().bytes().map(|c| c.unwrap()) => $text, $($arg),*) };
  ($input:expr => $text:expr, $($arg:expr),*) => {{
    use ::std::io::Read;
    use ::std::str::FromStr;
    let text: &'static str = $text;
    let stdin: &mut Iterator<Item = u8> = &mut ($input);

    let mut text = text.bytes();
    $(
    loop { match text.next() {
      Some(b'{') => match text.next() {
        Some(b'{') => assert_eq!(Some(b'{'), stdin.next()),
        Some(b'}') => {
          let s: Vec<u8> = match text.next() {
            Some(c) => stdin.take_while(|&ch| ch != c).collect(),
            None => stdin.take_while(|ch| !b"\t\r\n ".contains(ch)).collect(),
          };
          let s =  std::str::from_utf8(&s).unwrap();
          $arg = FromStr::from_str(s).expect(&format!("could not parse {} as target type of {}", s, stringify!($arg)));
          break;
        }
        Some(_) => panic!("found bad curly brace"),
        None => panic!("found single open curly brace at the end of the format string"),
      },
      Some(c) => assert_eq!(Some(c), stdin.next()),
      None => panic!("Bad read! format string: did not contain {{}}"),
    } }
    )*
    for c in text {
      assert_eq!(Some(c), stdin.next());
    }
  }};
);

#[allow(dead_code)] static BS: i64 = 1000000007;
#[allow(dead_code)] fn addmod (a: i64, b: i64) -> i64 { let mut g = a + b; if a >= BS { g -= BS; } g }
#[allow(dead_code)] fn mulmod (a: i64, b: i64) -> i64 { a * b % BS } 


/*************************************************/
/******************SOLUTION***********************/
/*************************************************/


fn main() {

  let n: usize = read!();
  let s: String = read!();
  let s = s.into_bytes();

  let mut pow2: Vec<i64> = vec![0; 100000*2+5];
  pow2[0] = 1;
  for i in 1..pow2.len() {
    pow2[i] = mulmod(pow2[i-1], 2);
  }
 
  let mut mult2: Vec<String> = vec![];
  let mut mult3: Vec<String> = vec![];
  let mut ans: i64 = 0;

  mult2.push("00".to_string());
  mult2.push("08".to_string());
  mult3.push("000".to_string());
  mult3.push("008".to_string());

  for x in 9..1000 {
    if x % 8 == 0 {
      let c = x.to_string();

      if x < 100 { 
        mult3.push(format!("0{}", &c));
        mult2.push(c);
      } else { 
        mult3.push(c); 
      }
    }
  }

  let mut singles = vec![vec![0; n+1]; 10];

  for i in 0..10 {
    for j in (0..n).rev() {
      let c = (i + 48) as u8;
      singles[i][j] = singles[i][j + 1];
      if s[j] == c { singles[i][j] += 1; }
    }
  }

  ans += s.iter().fold(0i64, |a, &v| a + if v == '0' as u8 || v == '8' as u8 {1} else {0} );

  for d in mult2.iter() {
    let db = d.as_bytes();

    for i in 0..n {
      if s[i] == db[0] {
        ans = addmod(ans, singles[(db[1] - 48) as usize][i+1]);
      }
    }
  }

  for d in mult3.iter() {
    let db = d.as_bytes();
    let mut memo: Vec<i64> = vec![0; n+1];

    for i in (0..n).rev() {
      memo[i] = memo[i+1];
      if s[i] == db[1] {
        memo[i] = addmod(memo[i], singles[db[2] as usize - 48][i+1]);
      }
    }

    for i in 0..n {
      if s[i] == db[0] {
        ans = addmod(ans, mulmod(pow2[i], memo[i+1]));
      }
    }
  }

  println!("{:?}", ans % BS);

}


