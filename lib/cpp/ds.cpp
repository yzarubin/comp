// BIT (1-based)
vector<int> BITTree(N+1);
void update(int i, int val, vector<int> &tree){
  while (i <= tree.size()){
    BITTree[i] += val;
    i += (i & -i);
  }
}

int read(int i, vector<int> &tree){
  int sum = 0;
  while (i > 0){
    sum += tree[i];
    i -= (i & -i);
  }
  return sum;
}


