#include <iostream>
#include<vector>
#include <queue>

using namespace std;
int max = 1000;
int zero[30]    = { 0 };
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
        {   



            if(area[i][j] == '#')
            {
                
            }




            if (area[i][j] == '*')
            {   
                
            }
            

    // cout << area[1];

}}