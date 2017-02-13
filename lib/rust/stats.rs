fn fact(n: i32) -> i32 {
    if (n == 0 || n == 1) {return 1}
    else {return n * fact(n-1)}
}

fn poisson_dist(lambda: f64, k: i32) -> f64 {
    return lambda.powi(k) * std::f64::consts::E.powf(-lambda) / fact(k) as f64;
}

fn cov(X: &Vec<f64>, Y: &Vec<f64>) -> f64 {
  let mut ans = 0.0;
  let uX = mean(&X);
  let uY = mean(&Y);

  for i in 0..X.len() {
    ans += (X[i] - uX) * (Y[i] - uY);
  }

  return ans / X.len() as f64;
}

fn mean(nums: &Vec<f64>) -> f64 {
  return nums.iter().fold(0.0,|a, v| a + v) / nums.len() as f64;
}

fn std(nums: &Vec<f64>) -> f64 {
  let u = mean(nums);
  let s = nums.iter().fold(0.0, |a, v| a + (v - u).powi(2)) / nums.len() as f64;
  return s.sqrt();
}

fn pearson(X: &Vec<f64>, Y: &Vec<f64>) -> f64 {
  return cov(X, Y) / std(X) / std(Y);
}