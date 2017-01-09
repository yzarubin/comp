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
    use::std::io::Read;
    use::std::str::FromStr;
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


/*************************************************/

//https://www.hackerrank.com/challenges/vertical-sticks


fn main() {

  let t: i32 = read!();

  for _ in 0..t {
    let n: usize = read!();
    let nf = n as f64;
    let s: String = read!("{}\n");

    let nums: Vec<f64> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut ans: f64 = 0.0;
    for i in nums.iter() {
      let gt = nums.iter().fold(0, |a, v| a + if v >= i {1} else {0}) - 1;
      let lt = n - gt - 1;

      for j in 0..n {
        let mut contribution: f64 = 0.0;

        if j == 0 {
          contribution += 1.0;
        } else {
          if gt == 0 {
            contribution += (j + 1) as f64;
          } else {
            let mut p = 1.0;
            let empty_slots = min(lt, j);
            contribution += gt as f64 / (n - 1) as f64;

            for slot in 1..empty_slots+1 {
              let avail = lt - slot + 1;
              let greater_probability = if j - slot == 0 {1.0} else {gt as f64 / (n - 1 - slot) as f64};

              p *= avail as f64 / (n - 1 - slot + 1) as f64;
              contribution += (slot + 1) as f64 * p * greater_probability;
            }
          }
        }

        ans += contribution / nf;
      }
    }

    println!("{0:.2}",  ans);
  }
}

