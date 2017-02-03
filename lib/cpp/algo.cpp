int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
  int i, j, k;
  int inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i]; 
  return inv_count;
}

int msort(vector<int> &arr, vector<int> &temp, int left, int right) {
  int mid, inv_count = 0;
  if (right > left) {
    mid = (right + left)/2;
    inv_count  = msort(arr, temp, left, mid);
    inv_count += msort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

int count_inversions(vector<int> arr) {
  vector<int> temp(arr.size());
  return msort(arr, temp, 0, arr.size() - 1);
}



//kmp
vector<int> kmp;
for (int i = 1; i < s.size(); i++) {
  int j = kmp[i-1];

  while (true) {
    if (s[i] == s[j]) {
      kmp[i] = j+1;
      break;
    } else {
      if (j == 0) break;
      j = kmp[j-1];
    }
  }
}

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }

  return a + b;
}
