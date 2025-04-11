#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void heapify(int arr[],int i,int n){
    int parent=i,left=2*i,right=2*i+1;
    if(left<=n && arr[left]>arr[parent]){
        parent=left;
    }
    if(right<=n && arr[right]>arr[parent]){
        parent=right;
    }
    if(parent!=i){
        swap(arr[i],arr[parent]);
        heapify(arr,parent,n);
    }
}

void heapsort(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,i,n);
    }
    for(int i=n;i>1;i--){
        swap(arr[1],arr[i]);
        heapify(arr,1,i-1);
    }
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    cout << "Original Array: ";
    for(int i=1;i<=n;i++){
        cout << arr[i] << ",";
    }
    heapsort(arr,n);
    cout << endl << "Sorted Array: ";
    for(int i=1;i<=n;i++){
        cout << arr[i] << ",";
    }
    return 0;
} 