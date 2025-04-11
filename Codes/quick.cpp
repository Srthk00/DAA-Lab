#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void print(vector<int> arr,int n){
    for (int i=0;i<n;i++){
        cout << arr[i] << ",";
    }
}

int pivot(vector<int>& arr,int low,int high){
    int pi=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick(vector<int>& arr,int low,int high){
    if(low<high){
        int p=pivot(arr,low,high);
        quick(arr,low,p-1);
        quick(arr,p+1,arr.size()-1);
    }
}

int main(){
    int n, val;
    vector<int> arr;
    cout << "enter the size of an array:";
    cin >> n;
    cout << "enter the element of array:";
    for(int i=0;i<n;i++){
        cin >> val;
        arr.push_back(val);
    }
    print(arr,n);
    quick(arr,0,n);
    cout << endl;
    print(arr,n);
    return 0;
}