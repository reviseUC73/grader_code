#include<iostream>
#include<vector>
using namespace std;
void tt(int* count)
{
    ++*count;
}
int main(){
    vector<int>box;
    box.push_back(3);
    int count =5;
    tt(&count);
    cout<<count;
    tt(&count);
    cout<<count;

    // for(int i = 0; i < box.size(); i++)
    // {
    //     cout<< box[i] <<endl;
    // }
    
}