#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    multiset<int> lst;
    int n,k;
    cin >> n,k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        lst.insert(val);
    }
    for (multiset<int>::iterator first = lst.begin(); first != lst.end();)
    {   
        for(int i = 0;i<k;i++)
        {
            first++;
        }
        cout<< *first <<endl;
        
    }
}


// int main(){
//     int n;
//     int k;
//     cin >> n;
//     cin >> k;
//     int box[1000000];
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         box[i] =  val;
        
//     }
//     // int len = sizeof(box) / sizeof(box[0]);
//     // sort(box,box+len);
//     sort(box,box+n);
//     for(int i = k-1,cnt=0 ; i<n; i+=k,cnt++)
//     {
//         // i +=k-1;
//         // cout<<"yo"<<endl;
//         // cout << "round: "<<cnt<<" ";
//         cout << box[i] << endl;
//     }
// }


