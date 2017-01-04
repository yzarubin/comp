
fn gcd(a: i64, b: i64) -> i64 {
  return if b != 0 { gcd(b, a % b) } else { a };
}

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