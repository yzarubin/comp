template<typename T>
string sv(vector<T> &v) {
  if (v.size() == 0) return "[]";
  stringstream ss;
  ss << "[";
  for (std::size_t i = 0; i < v.size() - 1; ++i) ss << v[i] << ", ";
  ss << v[v.size() - 1] << "]";
  return ss.str();
}

template<typename T>
void sv2d(vector<vector<T>> &v) {
  for (int i = 0; i < v.size(); i++) cout << sv(v[i]) << endl;
}