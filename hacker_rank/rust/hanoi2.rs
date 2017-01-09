#![allow(unused_imports)]
use std::io::{self, Read};
use std::collections::*;
use std::iter::*;
use std::cmp::*;
use std::hash::{Hash, SipHasher, Hasher};

fn highest_one_bit(mut i: i32) -> u32 {
  i |= i >>  1;
  i |= i >>  2;
  i |= i >>  4;
  i |= i >>  8;
  i |= i >> 16;
  return i as u32 - (i as u32 >> 1);
}

fn lowest_bit(i: i32) -> i32 {
  return i & -i;
}

fn main() {
  let mut buffer = String::new();
  io::stdin().read_to_string(&mut buffer).unwrap();
  let input = buffer.split('\n').collect::<Vec<_>>();

  let n: usize = input[0].parse().unwrap();
  let nums = input[1].split_whitespace().map(|x| x.parse().unwrap()).collect::<Vec<u8>>();
  
  let mut initial_state: Vec<i32> = vec![0; 5];
  let mut memo = HashSet::new();


  for i in (0..n).rev() {
    let x = nums[i] as usize;
    let mask = 1 << i;
    initial_state[x - 1] |= mask;
  }

  let mut q = VecDeque::new();
  q.push_back(initial_state);

  let goal = (1 << n) - 1;

  while !q.is_empty() {
    let current = q.pop_front().unwrap();

    if current[0] == goal {
      println!("{:?}", current[4]);
      break;
    }


    for i in 0..4 {
      if current[i] == 0 {continue};

      for j in 0..4 {
        if i == j {continue};


        let from = current[i];
        let lowest_bit_from = lowest_bit(from) as i32;
        let to = current[j];
        let lowest_bit_to = lowest_bit(to) as i32;

        if to != 0 && lowest_bit_from > lowest_bit_to {continue};
        
        let mut next = current.to_vec();
        next[4] += 1;
        next[i] ^= lowest_bit_from;
        next[j] |= lowest_bit_from;

        let t = (next[0],next[1],next[2],next[3]);
        if memo.contains(&t) {continue};
        memo.insert(t);

        //println!("{:?} --> {:?}", current, next);
        q.push_back(next);
      }
    }
  }
}