#include <ostream>
#include <vector>
#include <string>
using namespace std;

#define LOG_VECTOR
#include "log.hpp"
#include "City.hpp"

const float MAX = 9999.;
vector<City*> cities;

struct ShortestRouteResult {
  float distance;
  vector<City*> route;
};
ostream& operator<< (ostream& os, ShortestRouteResult& r) { os << "{ " << r.distance << ", " << r.route << " }"; return os; }

ShortestRouteResult getShortestRoute (City* city, vector<City*> route = {}, float distance = 0) {
  route.push_back(city);
  float minDistance = MAX;
  vector<City*> bestRoute = route;

  for (Road* road : city->roads) {
    City* nextCity = road->city1 == city ? road->city2 : road->city1;

    // if nextCity is not in route
    if (find(route.begin(), route.end(), nextCity) == route.end()) {
      auto [_dist, _route] = getShortestRoute(nextCity, route, distance + road->cost);
      if (_dist < minDistance) {
        minDistance = _dist;
        bestRoute = _route;
      }
    }
  }

  if (minDistance == MAX && bestRoute.size() == cities.size()) {
    // LOG("City:", city, "Route:", route, "Distance:", distance, "MinDistance:", minDistance, "BestRoute:", bestRoute);
    return {distance, route};
  } else {
    return {minDistance, bestRoute};
  }
}

int main () {
  City* A = new City('A');
  City* B = new City('B');
  City* C = new City('C');
  City* D = new City('D');
  City* E = new City('E');
  cities = {A, B, C, D, E};

  B->addRoad(E, 1);
  C->addRoad(D, 1);
  A->addRoad(B, 2);
  A->addRoad(C, 2);
  B->addRoad(C, 3);
  B->addRoad(D, 3);
  C->addRoad(E, 3);
  D->addRoad(E, 3);

  for (City* city : cities) {
    string title = "getShortestRoute(" + string(1, city->name) + ")";
    LOG(title, getShortestRoute(city));
  }
}