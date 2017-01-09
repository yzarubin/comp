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

/// This macro allows to pass several variables so multiple values can be read
#[macro_export]
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
          let s = match ::std::str::from_utf8(&s) {
            Ok(s) => s,
            Err(e) => {
              let n = e.valid_up_to();
              if n == 0 {
                panic!("input was not valid utf8: {:?}", s);
              } else {
                panic!("input was only partially valid utf8: \"{}\" followed by {:?}",
                     ::std::str::from_utf8(&s[..n]).unwrap(), &s[n..]);
              }
            }
          };
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
/***********END****************/


static BS: i64 = 1000000007;

fn main() { 
  let N: usize = read!("{}");
  let w: String = read!("{}\n");
  let w: Vec<i64> = w.split_whitespace().map(|x| x.parse().unwrap()).collect();

  let mut n = 1;
  let mut diag = 0;
  let mut corner = 0;
  let mut ans = 0;

  for i in 0..N {

    ans = (ans * 4) % BS + n * corner % BS * 12 + 8 * corner % BS + (12 * n %BS * w[i]) % BS + w[i]; 

    let tmp = (n * 2 * w[i]) % BS * n * 2 % BS;
    let tmp2 = (n * 3 * w[i]) % BS * n * 4 % BS;
    ans = ans + tmp + tmp2;

    corner = corner * 4 % BS + (diag + 2 * w[i]) * n % BS + (diag + 3 * w[i]) * 2 * n  % BS + (diag + w[i]) * 2  % BS + w[i];
    diag = diag * 2 + 3 * w[i] % BS;
    n =  n * 4 + 2;

    ans = ans % BS;
    corner = corner % BS;
    diag = diag % BS;
    n = n % BS;
  }

  println!("{}", ans );
}



