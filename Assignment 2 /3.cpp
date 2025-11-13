// // //a. Linear Search
// #include <bits/stdc++.h>
// using namespace std;
// int findMissingLinear(int arr[], int n) {
//     for(int i = 0; i < n-1; i++) {
//         if(arr[i] != i+1)
//             return i+1; // missing number
//     }
//     return n; // if last number is missing
// }
// int main(){
//     int arr[] = {1,2,4,5};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     cout<<"The missing element is : " << findMissingLinear(arr,n)<<endl;
//     return 0;
// }

// b. Binary Search
#include <iostream>
using namespace std;
int findMissingBinary(int arr[], int n) {
    int left = 0, right = n-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == mid+1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + 1;
}
int main(){
    int arr[] = {1,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

   cout<<"The missing element is : " << findMissingBinary(arr,n)<<endl;
    return 0;
}