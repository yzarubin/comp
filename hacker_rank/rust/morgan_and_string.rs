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

/*************************************************/
/******************SOLUTION***********************/
/*************************************************/
//MZBMWEYYDIADTLCOUEGMDBYFWUR

//ZZYYZZZA
//ZZYYZZZB

//ZZYYZZZBZZYYZZZA
//ZZYYZZYYZZZAZZZB
//ABACABA
//ABACABA

fn main() {

    let t: i32 = read!();

    for _ in 0..t {
      let s1 = {let s1: String = read!(); s1}.into_bytes();
      let s2 = {let s2: String = read!(); s2}.into_bytes();
      let mut i = 0;
      let mut j = 0;

      while i  < s1.len() && j < s2.len() {
        if s1[i] == s2[j] {
          let mut k = 0; 

          let mut pref2 = false;

          loop {
            if i+k >= s1.len() {
              pref2 = true;
              break;
            } else if j+k >= s2.len() {
              break;
            } else if s1[i+k] < s2[j+k] {
              break;
            } else if s1[i+k] > s2[j+k] {
              pref2 = true;
              break;
            }
            k+= 1;
          }

          if !pref2 {
            print!("{}", s1[i] as char);
            i += 1;
            while i < s1.len() && s1[i-1] == s1[i] {
              print!("{}", s1[i] as char);
              i += 1;
            }
          } else if pref2 {
            print!("{}", s2[j] as char);
            j += 1;
            while j < s2.len() && s2[j-1] == s2[j] {
              print!("{}", s2[j] as char);
              j += 1;
            }
          }

          
        } else {

          if s1[i] < s2[j] {
            print!("{}", s1[i] as char);
            i += 1;
          } else {
            print!("{}", s2[j] as char);
            j += 1;
          }
        }

      }

      for x in i..s1.len() {
        print!("{}", s1[x] as char);
      }

      for x in j..s2.len() {
        print!("{}", s2[x] as char);
      }

      print!("\n");
      

    }
}


