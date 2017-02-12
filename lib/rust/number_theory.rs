
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

fn nck(n: i64, mut k: i64) -> i64 {
  if k > n { return 0 }
  if k * 2 > n { k = n - k }
  if k == 0 { return 1 };

  let mut result: i64 = n;
  for i in 2..k+1 {
    result *= n - i + 1;
    result /= i;
  }

  return result;
}


fn sieve(sz: usize) -> Vec<i64> {
  let mut primes = vec![1; sz];

  for i in (2usize..).take_while(|x| x * x < sz) {
    if primes[i] == 1 {
      for j in (i..).take_while(|x| i * x < sz) {
        primes[i * j] = 0;
      } 
    }
  }
  return primes;
}






