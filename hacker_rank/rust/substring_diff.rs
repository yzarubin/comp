#![allow(unused_imports)]
#![allow(non_snake_case)]
use std::io::{self, Read};
use std::collections::*;
use std::cmp::*;
use std::iter::*;

/* text_io macros */
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
    // typesafe macros :)
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

#[allow(dead_code)]
static BS: i64 = 1000000007;

/*********SOLUTION**********/

fn main() { 
  let t: i32 = read!();

  for _ in 0..t {
    let n: usize = read!();
    let s1: String = read!();
    let s2: String = read!();
    let s1 = s1.into_bytes();
    let s2 = s2.into_bytes();
    let sz = s1.len();
    let mut dp: Vec<Vec<i64>> = vec![vec![0; sz+1]; sz+1];

    for i in 0..sz {
      for j in 0..sz {
        dp[i+1][j+1] = dp[i][j];
        if s1[i] == s2[j] {
          dp[i+1][j+1] += 1;
        }
      }
    }
    
    let mut ans = 0;

    for x in 0..sz {
      let mut t = 1;
      let mut h = 1;
      let mut sum = 0;
      let mut miss = 0;

      loop {
        if miss <= n {
          if h+x == sz+1 {
            break;
          }
          
          if dp[h][h+x] == dp[h-1][h+x-1]  {
            miss += 1;
          }
          sum += 1;
          h += 1;

        } else {
          if dp[t][t+x] == dp[t-1][t+x-1] && miss > 0 {
            miss -= 1;
          }
          t += 1;
          sum -= 1;
        }

        if miss <= n {
          ans = max(ans, sum);
        }
      }

      let mut t = 1;
      let mut h = 1;
      let mut sum = 0;
      let mut miss = 0;

      loop {
        if miss <= n {
          if h+x == sz+1 {
            break;
          }
          
          if dp[h+x][h] == dp[h+x-1][h-1] {
            miss += 1;
          }
          sum += 1;
          h += 1;

        } else {
          if dp[t+x][t] == dp[t+x-1][t-1] && miss > 0 {
            miss -= 1;
          }
          t += 1;
          sum -= 1;
        }

        if miss <= n {
          ans = max(ans, sum);
        }
      }
    }
    
    println!("{}", ans);
  }
}




