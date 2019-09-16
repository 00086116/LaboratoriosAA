#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void quickSort(int*, int, int);
int partition(int*, int, int);

int main(void){
    int T, N;
    cin >> T;
    int *A = new int[N];
    for(int tests = 0; tests < T; tests++){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> A[i];
        quickSort(A, 0, N - 1);
        if(A[N - 1] % 2 != 0)
            cout << A[N - 1] + 1 << endl;
        else
            cout << A[N - 1] + 2 << endl;
    }
}

void quickSort(int *A, int start, int end){
    if(start < end){
        int part = partition(A, start, end);
        quickSort(A, start, part - 1);
        quickSort(A, part + 1, end);
    }
}

int partition(int *A, int start, int end){
    int x = *(A + end);
    int i = start - 1, temp = 0;
    for(int j = start; j < end; j++){
        if(*(A + j) < x){
            i++;
            temp = *(A + i);
            *(A + i) = *(A + j);
            *(A + j) = temp;
        }
    }

    temp = *(A + i + 1);
    *(A + i + 1) = *(A + end);
    *(A + end) = temp;
    return i + 1;
}