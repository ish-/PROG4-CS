#include <string>
using namespace  std;

inline string b (int a) {
  string bin = "";
  int mask = 1 << 30;
  for (int i = 0; i < 31; i++) {
    if ((mask&a) >= 1)
      bin += "1";
    else if (bin.size() > 0)
      bin += "0";
    mask >>= 1;
  }
  return bin;
}

bool operator== (vector<int>& a, vector<int>& b) {
  if (a.size() != b.size())
    return false;
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i])
      return false;
  return true;
}

string to_string (const vector<int>& v) {
  string result = "vector{ ";
  for (size_t i = 0; i < v.size(); ++i) {
    result += std::to_string(v[i]);
    if (i < v.size() - 1) {
      result += " ";
    }
  }
  result += " }";
  return result;
}