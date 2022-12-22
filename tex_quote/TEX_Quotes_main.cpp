#include <iostream>
using namespace std;
int main()
{
    int check = 1;
    char box[10000];
    while (cin.getline(box, 10000))
    {
        for (int i = 0; box[i]; i++)
        {
            if (box[i] == '\"')
            {
                if (check == 1)
                {
                    cout << "``";
                  check = 2;
                }
                else if (check == 2)
                {
                    cout << "''";
                  check = 1;
                }
            }
            else
            {
                cout << box[i];
            }
          
        }cout<<endl;
        
    }
}
// #include <iostream>

// using namespace std;

// int main() {
//     string text;
//     bool open = true;

//     while (getline(cin, text)){
//         for (int i=0; text[i]; ++i){
//             if (text[i] == '"'){
//                 if (open)
//                     cout << "``";
//                 else
//                     cout << "''";
//                 open = not open;
//             } else
//                 cout << text[i];
//         }
//         cout << "\n";
//     }
// }