#include<stdio.h>
int main() {
	int arr[5]= {1,6,3,0,5};
	int n=5;
	int i,j;
	int minIndex;
    for(int i=0;i<n-1;i++){
      minIndex= i ;
      for(int j=i+1;j<n;j++){
        if(arr[j]<minIndex){
          minIndex=j;
        }
      }
      
        if(arr[minIndex]!=i){
          swap(arr[minIndex],arr[i]);
        
      }
    }	
	printf("\n sorted array : ");
	for(i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
}
