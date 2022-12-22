#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#define PI pair<int,int>
#define PII pair<PI,int>
using namespace std;
int a[100][100];
queue<PII> q;
bool mark[100][100];
int update[5][3] = {{-1,0},{1,0},{0,-1},{0,1}};
int n;

void bfs(int start_i,int start_j){
    q.push(PII(PI(start_i,start_j),0));
    int mx_step = 0;
    bool chstar = false, chdor = false;
    while(!q.empty()){
        int nowi = q.front().first.first;
        int nowj = q.front().first.second;
        int step = q.front().second;
        mx_step = max(mx_step,step);
        if(a[nowi][nowj] == '*') chstar = true;
        if(a[nowi][nowj] == '$') chdor = true;
        q.pop();
        for(int i=0;i<4;i++){
            int newi = nowi + update[i][0];
            int newj = nowj + update[i][1];
            if(newi<0 || newi >=n ||newj <0 || newj >=n) continue;
            if(mark[newi][newj]) continue;
            if(a[newi][newj] == '#') continue;
            q.push(PII(PI(newi,newj),step+1));
        }
    }
    // if()
}

int main(){
    int n;
    char c = 'a';
    printf("%d",c);
    char str[3];
    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    cout << str;
    // for(int i = 0;i<4;i++){
    //     printf("%d %d\n",update[i][0],update[i][1]);
    // }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         bfs(i,j);
    //     }
    // }
    return 0;
}