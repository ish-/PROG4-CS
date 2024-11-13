#include <math.h>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "common.hpp"

using Input = vector<int>;

struct TestValue { Input input; int expected; };
vector<TestValue> testValues = {
  { { 9, 3, 9, 3, 7 }, 7 },
  { { -1, 2, 2, -1, 0 }, 0 },
  { { 1, 9, 9, 1, 9 }, 9 },
};

int OddOccurrencesInArray (vector<int>& A) {
  unordered_set<int> pairs;
  for (int i = 0; i < A.size(); i++) {
    int v = A[i];
    if (pairs.find(v) == pairs.end())
      pairs.insert(v);
    else
      pairs.erase(v);
  }
  for (auto& p : pairs)
    return p;

  throw runtime_error("No odd occurrences in array");
}

int main() {
  for (auto& t : testValues) {
    string title = "OddOccurrencesInArray( " + to_string(t.input) + " )";
    TEST(title, OddOccurrencesInArray(t.input), t.expected);
  }
}
