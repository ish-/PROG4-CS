#include <math.h>
#include <string>
#include <vector>
using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"

struct Input {
  int x;
  int y;
  int d;
};

struct TestValue { Input input; int expected; };
vector<TestValue> testValues = {
  { { 10, 85, 30 }, 3 },
  { { 0, 100, 21 }, 5 },
};

int FrogJump (int X, int Y, int D) {
  int dist = Y - X;
  return ceil((double)dist / D);
}

int main() {
  for (auto& t : testValues) {
    string title = "FrogJump( " + to_string(t.input.x) + ", " + to_string(t.input.y) + ", " + to_string(t.input.d) + " )";
    TEST(title, FrogJump(t.input.x, t.input.y, t.input.d), t.expected);
  }
}
