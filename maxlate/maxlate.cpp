#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  // Store the work deadline and required work days in a vector of pairs
  vector<pair<int, int>> works;
  for (int i = 0; i < n; i++) {
    int d, c;
    cin >> d >> c;
    works.emplace_back(d, c);
  }

  // Sort the works by deadline
  sort(works.begin(), works.end());

  // Keep track of the maximum number of late days and the current number of work days
  int max_late_day = 0;
  int current_day = 0;
  for (const auto& [deadline, required_work_day] : works) {
    current_day += required_work_day;
    if (current_day > deadline + 10) {
      int late_day = current_day - deadline - 10;
      max_late_day = max(max_late_day, late_day);
    }
  }

  cout << max_late_day * 1000 << endl;
  return 0;
}
