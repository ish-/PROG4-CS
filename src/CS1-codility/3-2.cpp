#include <math.h>
#include <string>

using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"

using Input = vector<int>;

struct TestValue { Input input; int expected; };
vector<TestValue> testValues = {
  { { 1, 3, 4, 5 }, 2 },
  { { 1, 2, 3, 4, 5 }, 6 },
};

int PermMissingElem (vector<int>& A) {
  int smoothSum = 0;
  int sum = 0;
  int i = 0;
  for (; i < A.size(); i++) {
    smoothSum += i + 1;
    sum += A[i];
  }
  smoothSum += i + 1;
  return smoothSum - sum;
}

int main() {
  for (auto& t : testValues) {
    string title = "PermMissingElem( " + to_string(t.input) + " )";
    TEST(title, PermMissingElem(t.input), t.expected);
  }
}
