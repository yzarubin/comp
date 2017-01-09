#![allow(unused_imports)]
use std::io::{self, Read};
use std::collections::*;
use std::cmp::*;
use std::iter::*;

fn main() {
  let mut buffer = String::new();
  io::stdin().read_to_string(&mut buffer).unwrap();
  let input = buffer.split('\n').collect::<Vec<_>>();

  let mut nums  = input[0]
    .split_whitespace()
    .map(|x| x.parse().unwrap())
    .collect::<Vec<i32>>();

  nums.sort_by(|a, b| a.cmp(b));

  let a = nums[0] + 1;
  let b = nums[1] + 1;
  let c = nums[2] + 1;
  let d = nums[3] + 1;

  let mut ans = 0;
  let mut dp: Vec<Vec<i64>> = vec![vec![0; 6010]; 3010];
  let mut co: Vec<i64> = vec![0; 3010];

  for i in 1..c {
    for j in i..d {
      co[i as usize] += 1;
      dp[i as usize][(i^j) as usize] += 1;
    }
  }

  for i in (1..3005).rev() {
    co[i] = co[i] + co[i+1];
    for j in 0..6005 {
      dp[i][j] = dp[i][j] + dp[i+1][j];
    }
  }

  for i in 1..a {
    for j in i..b {
      ans += co[ j as usize] - dp[j as usize][(i^j) as usize];
    }
  }


  println!("{:?}", ans);
}
