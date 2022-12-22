#include <iostream>
using namespace std;
int main()
{

    char box[10000];
    char box_[10000];
    while (cin.getline(box, 10000))
    {
        int loop = 0;
        int loop_copy = 0;
        int check = 1;

        while (true)
        {
            if (box[loop] == '\"')
            {
                if (check == 1)
                {
                    ;
                    box_[loop_copy] = '`';
                    box_[loop_copy + 1] = '`';
                    check = 2;
                    loop_copy++;
                    // cout << box;
                }
                else if (check == 2)

                {
                    box_[loop_copy] = '\'';
                    box_[loop_copy + 1] = '\'';
                    check = 1;
                    loop_copy++;
                    // cout << box_;
                }
            }
            else
            {
                box_[loop_copy] = box[loop];
            }
            loop++;
            loop_copy++;
            if (box[loop] == '\0')
            {
                box_[loop_copy] = '\0';
                break;
            }
        }
        cout << box_ << endl;
    }
}
