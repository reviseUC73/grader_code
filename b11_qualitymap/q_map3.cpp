#include <iostream>
#include<vector>
#include <queue>

using namespace std;
int max = 1000;
// string are = "owfkfowk";
string area[35];
int main()
{   
    int row , column;
    cin >> row >> column;
    for(int i= 0; i <row; i++)
    {
        cin >> area[i];
    }
    int a1=0,a2=0;
    queue<int> q;

    for(int i= 0; i < row; i++)
    {
        int val = 0;
        for(int j= 0; j < column; j++)
        {   val++;
            if(area[i][j] == '#')
            {
                q.push(j+1);
                break;
            }
            if (area[i][j] == '*')
            {   
                a1 += val;
            }
            

    // cout << area[1];

}