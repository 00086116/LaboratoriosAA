#include <iostream>

using namespace std;

void fastest_way(){
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    for (int j = 1; j < n; j++){
        if (f1[j-1]+a1[j] <= f2[j-1]+t2[j-1]+ a1[j]){
            f1[j] = f1[j-1] + a1[j];
        }else{
            f1[j] = f2[j-1] + t2[j-1] + a1[j];
        }
        
        if (f2[j-1] + a2[j] <= f1[j-1]+ t1[j-1] + a2[j]){
            f2[j] = f2[j-1] + a2[j];
        }else{
            f2[j] = f1[j-1] + t1[j-1] + a2[j];
        }

        if( f1[j] <= f2[j]){
            cout<< f1[j]<<" "<<endl;
        }else{
            cout<< f2[j]<<" "<<endl;
        }
    }

    if( f1[n-1] + x1 <= f2[n-1]+ x2){
        cout<< f1[n-1]+ x1<<endl;
    }else{
        cout<< f2[n-1]+ x2<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    fastest_way();

    return 0;
}