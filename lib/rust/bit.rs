

fn highest_bit(mut i: i32) -> u32 {
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