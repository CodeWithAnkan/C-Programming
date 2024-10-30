#include<stdio.h>

// Merging in one array from two arrays

void merge(int A[], int B[], int C[], int m, int n){
    int i, j, k;
    i=j=k=0;
    while(i<m && j<n){
        if (A[i] <= B[j])
        {
            C[k] = A[i];
            i++; k++;
        } else{
            C[k] = B[j];
            j++; k++;
        }        
    }
    while(i<m){
        C[k] = A[i];
        i++; k++;
    }
    while(j<n){
        C[k] = B[j];
        j++; k++;
    }

}

// merging in a single array

void singleMerge(){
    
}

int main(){

    return 0;
}