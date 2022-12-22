#include <iostream>
using namespace std;
int main(){
    int bucket[6] = {0,0,0,0,0,0};
    int n,enter;
    cin>>n;
    int min_index = 0;
    for(int i = 0 ;i<n;i++){
        cin>> enter;
        for(int j = 0 ;j<5;j++){
            if(bucket[min_index] > bucket[j]){
                min_index = j;
                
            }
        } 
        bucket[min_index] += enter;
        if (bucket[min_index]>=1000){
            bucket[min_index] = 0;
            bucket[5] +=1000;
            }
    for (int f = 0; f<6;f++){
        printf("%d ",bucket[f]);
    }
    printf("\n");
    }
    cout<<bucket[5];
}