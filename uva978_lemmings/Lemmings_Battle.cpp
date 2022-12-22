#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int B, SG, SB;
        cin >> B >> SG >> SB;

        vector<int> green, blue;
        for (int i = 0; i < SG; i++) {
            int p;
            cin >> p;
            green.push_back(p);
        }
        for (int i = 0; i < SB; i++) {
            int p;
            cin >> p;
            blue.push_back(p);
        }

        sort(green.rbegin(), green.rend());
        sort(blue.rbegin(), blue.rend());

        while (!green.empty() && !blue.empty()) {
            vector<int> survivors;
            for (int i = 0; i < B; i++) {
                if (green.empty() || blue.empty()) break;
                int g = green.back();
                int b = blue.back();
                green.pop_back();
                blue.pop_back();
                if (g > b) {
                    survivors.push_back(g - b);
                } else if (b > g) {
                    survivors.push_back(b - g);
                }
            }
            for (int s : survivors) {
                if (s > 0) {
                    green.push_back(s);
                } else {
                    blue.push_back(-s);
                }
            }
            sort(green.rbegin(), green.rend());
            sort(blue.rbegin(), blue.rend());
        }

        if (green.empty() && blue.empty()) {
            cout << "green and blue died" << endl;
        } else if (blue.empty()) {
            cout << "green wins" << endl;
            for (int g : green) {
                cout << g << endl;
            }
        } else {
            cout << "blue wins" << endl;
            for (int b : blue) {
                cout << b << endl;
            }
        }
        if (T) cout << endl;
    }

    return 0;
}