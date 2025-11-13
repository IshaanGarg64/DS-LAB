#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        // Check if arr[i] has appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            count++;
        }
    }
    cout<<"Total number of distinct elements : "<<count<<endl;
    return 0;
}