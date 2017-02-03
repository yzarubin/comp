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
#[allow(dead_code)] fn addmod (a: i64, b: i64) -> i64 { let mut g = a + b; if a >= BS { g -= BS; }  g }
#[allow(dead_code)] fn mulmod (a: i64, b: i64) -> i64 { a * b % BS } 


/******************SOLUTION***********************/



fn fast_mod(mut a: i64, mut b: i64, p: i64) -> i64 {
  let mut res = 1;
  while b > 0 {
    if (b & 1) > 0 {
      res = (res * a) % p;
    }

    a = (a * a) % p;
    b >>= 1;
  }

  return res;
}

fn main() {
  let a: String = read!("{}");
  let b: String = read!("{}");
  let k = 314160;
  let a = a.into_bytes();
  let b = b.into_bytes();

  let mut ans = 0;
  let mut asum = 0;
  let mut bsum = 0;

  for i in 0..a.len() {
    if a[i] == b'1' {
      let pos = a.len() - i - 1;
      asum = (asum +  fast_mod(2, pos as i64, BS)) % BS;
    }
  }

  for i in 0..b.len() {
    if b[i] == b'1' {
      let pos = b.len() - i - 1;
      bsum += fast_mod(2, pos as i64, BS);
    }
  }

  for _ in 0..k {
    ans = (ans + asum) % BS;
    ans = (ans + bsum) % BS;
    bsum = (bsum << 1) % BS;
  }

  let mut dpb: Vec<i64> = vec![0; b.len()];

  for i in (0..b.len()).rev() {
    if i < b.len() - 1 { dpb[i] = dpb[i+1] }
    if b[i] == b'1' { dpb[i] += 1 }
  }

  for i in 0..a.len() {
    if a[i] == b'1' {
      let g = a.len() - i;
      let pos = a.len() - i - 1;
      let d = if g >= b.len() {dpb[0]} else {dpb[b.len() - g]};
      let r = fast_mod(2, pos as i64, BS) * d % BS * 2 % BS;

      ans = (ans + BS - r) % BS;
    }
  }

  println!("{}", ans);
}


