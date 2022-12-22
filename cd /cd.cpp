#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 


int main()
{
    int cd1, cd2;
    cin >> cd1 >> cd2;
    while (cd1!=0 and cd2 != 0)
    {
        int k = 0;
        vector<int> mylist;
        // vector<int> mylist2;

        vector<int>::iterator it;
        
        it = mylist.begin();
        // vector<int>::iterator it2 = mylist2.begin();

        for(int i = 0; i < cd1; i++)
        {
            int num;
            cin >> num;
            // mylist.insert(it, num); 
            mylist.push_back(num);
        }   

        for (int i = 0; i < cd2; i++)
        {
            int num;
            cin >> num;
            bool found = (find(mylist.begin(), mylist.end(), num) != mylist.end());
            if (found)
            {
                k += 1;
            }
        }
        
        cout << k << endl;
        cin >> cd1 >> cd2;
    }
}
