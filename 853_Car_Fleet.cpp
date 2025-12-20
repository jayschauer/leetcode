#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int carFleet(int target, const vector<int>& position,
               const vector<int>& speed) {
    vector<pair<int, int>> cars;
    cars.reserve(position.size());
    for (size_t i = 0; i < position.size(); i++) {
      cars.push_back({position[i], speed[i]});
    }

    sort(cars.begin(), cars.end());
    int fleets = 0;
    for (int i = cars.size() - 1; i >= 0;) {
      // Check when the farthest ahead car would reach target:
      fleets++;
      double arrival_t = (target - cars[i].first) / (double)cars[i].second;
      i--;
      while (i >= 0 &&
             (target - cars[i].first) / (double)cars[i].second <= arrival_t) {
        // this car would've arrived at/before car ahead, but gets stuck
        i--;
      }
    }

    return fleets;
  }
};

int main() {
  Solution sol;

  cout << sol.carFleet(10, {4, 1, 0, 7}, {2, 2, 1, 1}) << endl;

  return 0;
}
