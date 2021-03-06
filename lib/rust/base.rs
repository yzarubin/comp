#![allow(unused_imports)]
#![allow(non_snake_case)]
#![allow(dead_code)] 
#![allow(non_camel_case_types)]
use std::io::{self, Read};
use std::collections::*;
use std::cmp::*;
use std::iter::*;
use std::str::FromStr;
use std::fmt::Debug;

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

static BS: i64 = 1000000007;
fn ri() -> i64 { let r: i64 = read!(); r }
fn rs() -> String { let r: String = read!(); r }
fn ru() -> usize { let r: usize = read!(); r }
fn rvec<T: FromStr>() -> Vec<T> where T::Err:Debug {
  return ({let r: String = read!("{}\n"); r}).split_whitespace().map(|x|x.parse().unwrap()).collect::<Vec<_>>(); 
}
type u = usize;

/******************SOLUTION***********************/



fn main() {
/*
  let mut buffer = String::new();
  io::stdin().read_to_string(&mut buffer).unwrap();
  let input = buffer.split('\n').collect::<Vec<_>>();
*/


}





