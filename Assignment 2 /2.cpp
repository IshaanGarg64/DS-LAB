#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]  = arr[j];
                arr[j] = temp;
                isSwap = true;
            }
        }
        if(!isSwap) return;  // array is already sorted
    }
}
int main(){
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

