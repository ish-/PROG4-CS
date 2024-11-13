#include <math.h>
#include <string>
#include <limits>

using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"

using Input = vector<int>;

struct TestValue { Input input; int expected; };
vector<TestValue> testValues = {
  { { 3, 1, 2, 4, 3 }, 1 },
  { { 1, 2, 3, 4, 5 }, 3 },
  { { 1, 2, 3, 4, 5 }, 3 },
  { { 1, 4 }, 3 },
  { { -2, 4, -5, 2 }, 3 },
};

int TapeEquilibrium (vector<int>& A) {
  int minDiff = numeric_limits<int>::max();
  int sum = 0;
  for (int i = 0; i < A.size(); i++)
    sum += A[i];

  int lSum = 0;
  for (int i = 1; i < A.size(); i++) {
    lSum += A[i - 1];
    minDiff = min(minDiff, abs(sum - lSum - lSum));
  }
  return minDiff;
}


int main() {
  for (auto& t : testValues) {
    string title = "TapeEquilibrium( " + to_string(t.input) + " )";
    TEST(title, TapeEquilibrium(t.input), t.expected);
  }
}
