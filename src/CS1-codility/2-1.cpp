#include <math.h>
#include <string>
#include <vector>
using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"

struct Input {
  vector<int> arr;
  int shift;
};

struct TestValue { Input input; vector<int> expected; };
vector<TestValue> testValues = {
  { {{ 3, 8, 9, 7, 6 }, 3}, { 9, 7, 6, 3, 8 } },
  { {{ 1, 2, 3, 4, 5 }, 0}, { 1, 2, 3, 4, 5 } },
  { {{ 1, 2, 3, 4, 5 }, -1}, { 2, 3, 4, 5, 1 } },
  { {{ 1, 2, 3, 4, 5 }, -6}, { 2, 3, 4, 5, 1 } },
  { {{ 10 }, -6}, { 10 } },
  { {{ }, -6}, { } },
};

vector<int> CyclicRotation (vector<int>& A, int K) {
  int l = A.size();
  vector<int> res(l);
  for (int i = 0; i < l; i++) {
    // why it gives 0 for K<0 ???
    // int idx = (i + K) % A.size();
    int idx = (i + K) % l;
    if (idx < 0)
      idx += A.size();
    res[idx] = A[i];
  }
  return res;
}

int main() {
  for (auto& t : testValues) {
    string title = "CyclicRotation( " + to_string(t.input.arr) + ", " + to_string(t.input.shift) + " )";
    TEST(title, CyclicRotation(t.input.arr, t.input.shift), t.expected);
  }
}
