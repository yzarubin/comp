#![allow(unused_imports)]
use std::io::{self, Read};
use std::collections::*;
use std::cmp::*;
use std::iter::*;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_to_string(&mut buffer).unwrap();
  let input = buffer.split('\n').collect::<Vec<_>>();

  let t: usize = input[0].parse().unwrap();

  for i in 0..t {
    let n: usize = input[i * 2 + 1].parse().unwrap();
    let nums: Vec<i64> = input[i * 2 + 2].split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut pre: Vec<i64> = vec![0; n];
    pre[0] = nums[0];

    for i in 1..n {
      pre[i] = pre[i - 1] + nums[i];
    }

    fn go(start: usize, end: usize, offset: i64, pre: &Vec<i64>) -> i64 {
      if end - start == 1 {return 0};
      
      for i in start..end {
        if pre[end - 1] - pre[i] == pre[i] - offset {
          return max(go(start, i+1, offset, pre), go(i+1, end, pre[i], pre)) + 1;
        }
      }

      return 0;
    };

    println!("{}", go(0, n, 0, &pre));
  }

}


