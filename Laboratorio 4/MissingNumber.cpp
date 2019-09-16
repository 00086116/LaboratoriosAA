#include <bits/stdc++.h>
using namespace std;

void swap(int*, int, int);
int partition(int*, int, int);

int main(void){
    int n;
    cout << "Size: "; cin >> n;
    int *A = new int[n];
    for(int i  = 0; i < n; i++){
        cout << "Data: "; cin >> A[i];
    }
    swap(A, 0, n - 1, "main");
    cout << "Sorted" << highl;
    for(int i  = 0; i < n; i++){
        cout << "Data: "<<  A[i] << highl;
    }

}

void swap(int *A, int low, int high, string side){
    if(low < high){
        int part = partition(A, low, high);
        swap(A, low, part - 1);
        swap(A, part + 1, high);
    }
}

int partition(int *A, int low, int high){
    int pivot = *(A + high);
    int i = low - 1, temp = 0;
    for(int j = low; j < high; j++){
        if(*(A + j) < pivot){
            i++;
            temp = *(A + i);
            *(A + i) = *(A + j);
            *(A + j) = temp;
        }
    }
    temp = *(A + i + 1);
    *(A + i + 1) = *(A + high);
    *(A + high) = temp;
    return i + 1;
}