#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int count = 0; count < n; count++) {
    int b, sg, sb;
    cin >> b >> sg >> sb;
    multiset<int> gTeam;
    multiset<int> bTeam;
    for (int i = 0; i < sg; i++) {
      int ginput;
      cin >> ginput;
      gTeam.insert(ginput);
    }
    for (int i = 0; i < sb; i++) {
      int binput;
      cin >> binput;
      bTeam.insert(binput);
    }

    while (gTeam.size() != 0 && bTeam.size() != 0) {
      multiset<int> gTeamVec;
      multiset<int> bTeamVec;
      for (int i = 0; i < b; i++) {
        if (gTeam.size() == 0 || bTeam.size() == 0) {
          break;
        }
        auto gTeamLem = gTeam.end();
        auto bTeamLem = bTeam.end();
        gTeamLem--;
        bTeamLem--;
        gTeam.erase(gTeamLem);
        bTeam.erase(bTeamLem);
        if (*gTeamLem > *bTeamLem) {
          gTeamVec.insert(*gTeamLem - *bTeamLem);
        } else if (*bTeamLem > *gTeamLem) {
          bTeamVec.insert(*bTeamLem - *gTeamLem);
        }
      }
      for (auto i = gTeamVec.begin(); i != gTeamVec.end(); i++) {
        gTeam.insert(*i);
      }
      for (auto i = bTeamVec.begin(); i != bTeamVec.end(); i++) {
        bTeam.insert(*i);
      }
    }
    if (gTeam.size() == 0 && bTeam.size() == 0) {
      cout << "green and blue died" << endl;
    } else if (gTeam.size() == 0) {
      cout << "blue wins" << endl;
      for (auto i = bTeam.rbegin(); i != bTeam.rend(); i++) {
        cout << *i << endl;
      }
    } else if (bTeam.size() == 0) {
      cout << "green wins" << endl;
      for (auto i = gTeam.rbegin(); i != gTeam.rend(); i++) {
        cout << *i << endl;
      }
    }
    if (count != n - 1) {
      cout << endl;
    }
  }
  return 0;
}