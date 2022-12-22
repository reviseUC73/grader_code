#include <iostream>
using namespace std;

int main() {
  int n, z, d, e;
  cin >> n >> z >> d >> e;

  int stops = 0;
  int pos = 0;
  while (pos < z) {
    int next_station = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > pos && x - pos <= e) {
        // If the next station is within walkable distance, go there
        next_station = x;
        break;
      }
    }
    if (next_station == INT_MAX) {
      // If no station is within walkable distance, try driving to the next station
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > pos) {
          next_station = x;
          break;
        }
      }
      if (next_station == INT_MAX || next_station - pos > d) {
        // If no station is within driving distance, it is impossible to reach the destination
        cout << -1 << endl;
        return 0;
      } else {
        // Otherwise, drive to the next station and refill
        pos = next_station;
        stops++;
      }
    } else {
      // If a station is within walkable distance, go there and refill
      pos = next_station;
      stops++;
    }
  }

  cout << stops << endl;
  return 0;
}
