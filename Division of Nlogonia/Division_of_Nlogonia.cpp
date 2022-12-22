#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        if (n==0){break;}
        int main_x,main_y,x,y;
        cin>> main_x>>main_y;
        string box[n];
        for(int i =0; i<n;i++){
            cin>>x>>y;
            if(main_x == x or main_y == y){box[i]="divisa";}
            else if(x > main_x and y  >main_y){box[i]="NE";}
            else if(x < main_x and y  >main_y){box[i]="NO";}
            else if(x < main_x and y  <main_y){box[i]="SO";}
            else if(x > main_x and y  <main_y){box[i]="SE";}
        }
        // for(int i=0;i<n ;i++){printf("%s \n",box[i]);}
        for(int i=0;i<n ;i++){cout<<box[i]<<endl;}
    }
}