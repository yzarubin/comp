
ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}

ll fast_mod_exp(ll a, ll b, ll p) {
  ll res = 1;

  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
 
  return res;
}

ll mod_inverse(ll a, ll p) {
  return fast_mod_exp(a, p-2, p);
}



ll n_choose_k(ll n, ll k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  int result = n;
  for (int i = 2; i <= k; ++i) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}


//Binomial coefficient C(n,k) mod prime
ll n_choose_k_prime(ll n, ll k, ll p) {
  if (k == 0) return 1;
  if (n == 0) return 0;

  auto mod_inverse = [](ll a, ll p) -> ll {
    return fast_mod_exp(a, p - 2, p);
  };

  ll numerator = 1;
  for (int i = 0; i < k; i++) numerator = (numerator * (n - i)) % p;
   
  ll denominator = 1;
  for (int i = 1; i <= k; i++) denominator = (denominator * i) % p;
   
  ll res = mod_inverse(denominator, p);
  res = (res * numerator) % p;
  return res;
}

// Miller-Rabin
bool mrpt(ll p) {
  // a ^ b % c for numbers > than int
  auto mod_exp_big = [](ll a, ll b, ll c) -> ll {
    ll x = 0, y = a % c;
    while (b > 0) {
      if (b % 2 == 1) {
          x = (x + y) % c;
      }
      y = (y * 2) % c;
      b /= 2;
    }
    return x % c;
  };

  if (p < 2) return false;
  if (p != 2 && p % 2 == 0) return false;

  int iterations = 20;
  ll s = p - 1;

  while (s % 2 == 0) s /= 2;
  for (int i = 0; i < iterations; i++) {
    ll a = rand() % (p - 1) + 1, temp = s;
    ll mod = fast_mod_exp(a, temp, p);

    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mod_exp_big(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}

// triangle with n rows
vector<vector<ll> > pt;
void pascal(int n) {
  for (int line = 0; line < n; line++) {
    pt.push_back(vector<ll>(line + 1));
    for (int i = 0; i <= line; i++) {
      if (line == i || i == 0) pt[line][i] = 1;
      else pt[line][i] = pt[line-1][i-1] + pt[line-1][i];
    }
  }
}

vector<bool> primesMemo;
void sieve (ll M) {
  primesMemo.resize(M + 1, true);
  for (ll i = 2; i * i <= M; i++) {
    if (primesMemo[i]) {
      for (ll j = i; i * j <= M; j++) {
        primesMemo[i * j] = false;
      }
    }
  }
}

ll sumSeries(ll n) {
  return n * (n + 1) / 2;
}


