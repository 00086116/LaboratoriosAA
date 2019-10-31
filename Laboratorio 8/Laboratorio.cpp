#include <stdio.h>
#include <iostream>

using namespace std;

int ASP(int inicio [], int final []){
    int L [11]= {0};

    for (int i=0; i<11; i++ ){
        for (int j=0; j<i; j++){
            if (final[j]<inicio[i] && L[i]< L[j]){
                L[i]=L[j];
            }    
        }
        L[i]++;
    }
    return L[10]++;
}

int main(){
    int inicio []={0,1,2,3,3,5,5,6,8,8,12};
    int final []={6,4,13,5,8,7,9,10,11,12,14};
    cout<<ASP(inicio,final);
    return 0;
}