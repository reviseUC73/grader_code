// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <set>
// #include <vector>

// using namespace std;

// int main() {
//   int n;
//   cin >> n;
//   for (int count = 0; count < n; count++) {
//     int b, sg, sb;
//     cin >> b >> sg >> sb;
//     multiset<int> gTeam;
//     multiset<int> bTeam;
//     for (int i = 0; i < sg; i++) {
//       int ginput;
//       cin >> ginput;
//       gTeam.insert(ginput);
//     }
//     for (int i = 0; i < sb; i++) {
//       int binput;
//       cin >> binput;
//       bTeam.insert(binput);
//     }

//     vector<int> gTeamVec;
//     vector<int> bTeamVec;
//     while (gTeam.size() != 0 && bTeam.size() != 0) {
//       for (int i = 0; i < b; i++) {
//         if (gTeam.size() == 0 || bTeam.size() == 0) {
//           break;
//         }
//         auto gTeamLem = gTeam.end();
//         auto bTeamLem = bTeam.end();
//         gTeamLem--;
//         bTeamLem--;
//         gTeam.erase(gTeamLem);
//         bTeam.erase(bTeamLem);
//         if (*gTeamLem > *bTeamLem) {
//           gTeamVec.push_back(*gTeamLem - *bTeamLem);
//         } else if (*bTeamLem > *gTeamLem) {
//           bTeamVec.push_back(*bTeamLem - *gTeamLem);
//         }
//       }
//       for (int i = 0; i < gTeamVec.size(); i++) {
//         gTeam.insert(gTeamVec[i]);
//       }
//       for (int i = 0; i < bTeamVec.size(); i++) {
//         bTeam.insert(bTeamVec[i]);
//       }
//       gTeamVec.clear();
//       bTeamVec.clear();
//     }
//     if (gTeam.size() == 0 && bTeam.size() == 0) {
//       cout << "green and blue died" << endl;
//     } else if (gTeam.size() == 0) {
//       cout << "blue wins" << endl;
//       for (auto i = bTeam.rbegin(); i != bTeam.rend(); i++) {
//         cout << *i << endl;
//       }
//     } else if (bTeam.size() == 0) {
//       cout << "green wins" << endl;
//       for (auto i = gTeam.rbegin(); i != gTeam.rend(); i++) {
//         cout << *i << endl;
//       }
//     }
//     if (count != n - 1) {
//       cout << endl;
//     }
//   }
//   return 0;
// }
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int count = 0; count < n; count++)
    {
        int b, sg, sb;
        cin >> b >> sg >> sb;
        vector<int> gTeam;
        vector<int> bTeam;
        for (int i = 0; i < sg; i++)
        {
            int ginput;
            cin >> ginput;
            gTeam.push_back(ginput);
        }
        for (int i = 0; i < sb; i++)
        {
            int binput;
            cin >> binput;
            bTeam.push_back(binput);
        }

        vector<int> gTeamVec;
        vector<int> bTeamVec;
        while (gTeam.size() != 0 && bTeam.size() != 0)
        {
            for (int i = 0; i < b; i++)
            {
                if (gTeam.size() == 0 || bTeam.size() == 0)
                {
                    break;
                }
                int gTeamLem = gTeam.back();
                int bTeamLem = bTeam.back();
                gTeam.pop_back();
                bTeam.pop_back();
                if (gTeamLem > bTeamLem)
                {
                    gTeamVec.push_back(gTeamLem - bTeamLem);
                }
                else if (bTeamLem > gTeamLem)
                {
                    bTeamVec.push_back(bTeamLem - gTeamLem);
                }
            }
            for (int i = 0; i < gTeamVec.size(); i++)
            {
                gTeam.push_back(gTeamVec[i]);
            }
            for (int i = 0; i < bTeamVec.size(); i++)
            {
                bTeam.push_back(bTeamVec[i]);
            }
            gTeamVec.clear();
            bTeamVec.clear();
        }
        sort(gTeam.begin(), gTeam.end(), greater<int>());
        sort(bTeam.begin(), bTeam.end(), greater<int>());
        if (gTeam.size() == 0 && bTeam.size() == 0)
        {
            cout << "green and blue died" << endl;
        }
        else if (gTeam.size() == 0)
        {
            cout << "blue wins" << endl;
            for (auto i = bTeam.begin(); i != bTeam.end(); i++)
            {
                cout << *i << endl;
            }
        }
        else if (bTeam.size() == 0)
        {
            cout << "green wins" << endl;
            for (auto i = gTeam.begin(); i != gTeam.end(); i++)
            {
                cout << *i << endl;
            }
        }
        if (count != n - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
