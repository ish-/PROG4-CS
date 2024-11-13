#include <math.h>
#include <string>
#include <vector>
using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"


struct TestValue { int input; int expected; };
vector<TestValue> testValues = {
  { 8, 0 },
  { 9, 2 },
  { 15, 0 },
  { 20, 1 },
  { 32, 0 },
  { 238, 1 },
  { 529, 4 },
  { 1041, 5 },
};

int BinaryGap (int a) {
  int maxGap = 0;
  int gap = -1;

  while (a > 0) {
    if (a & 1) {
      if (gap > maxGap)
        maxGap = gap;
      gap = 0;
    }
    else if (gap != -1)
      gap++;
    a >>= 1;
  }
  return maxGap;
}

int main() {

  for (auto& t : testValues) {
    string title = "BinaryGap( " + to_string(t.input) + " 0b" + b(t.input) + " )";
    TEST(title, BinaryGap(t.input), t.expected);
  }

}
