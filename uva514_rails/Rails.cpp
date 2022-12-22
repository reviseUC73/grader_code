#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    vector<int> station;
    int b[1001];
    int n;
    while(scanf("%d", &n), n){
        bool is_break = false;
        while(!is_break){
            station.clear();
            for(int i = 0; i < n; i++){
                scanf("%d", &b[i]);
                if(b[i] == 0){
                    is_break = true;
                    break;
                }
            }
            if(is_break) continue;
            int j = 0;
            bool is_ok = true;
            for(int i = 1; i <= n; i++){
                station.push_back(i);
                while(!station.empty() && station.back() == b[j]){
                    station.pop_back();
                    j++;
                }
            }
            cout<<(station.empty() ? "Yes" : "No")<<endl;
        }
        cout<<endl;
    }
    return 0;
}
