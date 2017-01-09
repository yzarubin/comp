use std::io;
//use std::io::prelude::*;
use std::str::FromStr;
use std::fmt::Debug;
use std::char;
use std::cmp::Ordering;

fn read_vec<T: FromStr >() -> Vec<T> where T::Err:Debug {
  let stdin = io::stdin();
  let mut tmp = String::new();
  stdin.read_line(&mut tmp).unwrap();
  let data: Vec<T> = tmp
    .split_whitespace()
    .map(|s| s.parse().unwrap())
    .collect();
  return data;
}

fn pr(n: i32) {
  print!("{}", char::from_u32(n as u32 + ('a' as u32)).unwrap());
}


fn main() {
  let nums = read_vec::<i32>();

  let mut c = -1;
  let mut p = nums.into_iter()
    .map(|n| { c += 1; (n, c) })
    .filter(|pair| pair.0 > 0)
    .collect::<Vec<_>>();

  p.sort_by(|a, b| a.cmp(b));

  let x = p[0];
  let mut p = p.into_iter()
    .filter(|pair| pair.1 != x.1)
    .collect::<Vec<_>>();

  p.sort_by(|a, b| {
    if (*a).1 < (*b).1 {
      return Ordering::Less;
    } else {
      return Ordering::Greater;
    }
  });

  let mut rem = vec![];

  for i in p.iter() {
    for _ in 0..i.0 {
      rem.push(i.1);
    }
  }

  // interlace
  if rem.len() > 0 && x.1 < rem[0] {
    let mut i = 0;
    pr(x.1);
    for _ in 1..x.0 {
      pr(x.1);
      pr(rem[i]);
      i += 1;
    }

    for k in rem.iter().skip(i) {
      pr(*k);
    }
  } else {
    pr(x.1);
    for _ in 1..x.0 {
      rem.push(x.1);
    }
    rem.sort();
    for j in rem.iter() {
      pr(*j);
    }
  }
}


