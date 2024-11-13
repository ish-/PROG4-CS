#include <vector>
using namespace std;

class City;
class Road;

class Road {
public:
  float cost;
  City* city1;
  City* city2;

  Road (const float& cost, City* city1, City* city2);
};

class City {
public:
  char name;
  vector<Road*> roads;

  City (const char name) : name(name) {}
  // City (const std::char& name, const vector<float>& costs) : name(name), costs(costs) {}

  Road* addRoad (City* city, float cost) {
    Road* road = new Road(cost, this, city);
    roads.push_back(road);
    return road;
  }
};
ostream& operator<< (ostream& os, City* city) { os << city->name; return os; }

Road::Road (const float& cost, City* city1, City* city2): cost(cost), city1(city1), city2(city2) {
  city1->roads.push_back(this);
  city2->roads.push_back(this);
};
