#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> banner;
int max_ = -1;
int seen[100000] = {false};
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        banner.push_back(make_pair(h, i));
    }
    sort(banner.begin(), banner.end());
    for(pair<int, int> x: banner)
        cout << x.first << " " << x.second << endl;
    for(int i = 1; i < banner.size() ; i++){
        if(banner[i].first  == banner[i+1].first) {
            cout << banner[i].second+1 << " > " << banner[i].first <<  " .+.  " <<banner[i+1].second + 1 << " > " << banner[i+1].first << endl;
            int num = abs(banner[i].second  - banner[i+1].second);
            seen[banner[i].first] = true;
            if(max_ < num ){
                max_ = num;
            }
        }
    }
    cout << max_ << endl;
}
