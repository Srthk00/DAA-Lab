#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int binary_search(vector<int> arr,int low,int high,int target){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
            return 1;
        else if(arr[mid]<target)
            low=mid+1;
        else  
            high=mid-1;
    }
    return 0;
}

int expo_search(vector<int> arr,int target){
    if(arr[0]==target)
        return 1;
    int i=1;
    while(i<arr.size() && arr[i]<=target){
        i*=2;
    }
    int n=arr.size();
    return binary_search(arr,i/2,min(i,n-1),target);
}

int main(){
    int n,val,target;
    vector<int> arr;
    cout << "Enter size of array: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        arr.push_back(val);
    }
    cout << "Enter element to search: ";
    cin >> target;
    if(expo_search(arr,target))
        cout << "Element is present...";
    else
        cout << "Element is Not present...";
    return 0;
}