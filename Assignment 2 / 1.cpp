#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow
        if (arr[mid] == key)
            return mid;        // key found → return index
        else if (arr[mid] < key)
            low = mid + 1;     // search in right half
        else
            high = mid - 1;    // search in left half
    }
    return -1; // not found
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the element you want to find : ";
    cin>>x;
    int result = binarySearch(arr, n, x);
    if (result != -1)    cout << "Element " << x << " found at index " << result << "\n";
    else    cout << "Element " << x << " not found\n";
    return 0;
}


