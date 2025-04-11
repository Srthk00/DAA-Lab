#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr,int target){
    int low=0,high=arr.size();
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

int main(){
    int n,value,target;
    vector<int> arr;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> value;
        arr.push_back(value);
    }
    cout << "Enter element to search: ";
    cin >> target;
    if(binary_search(arr,target))
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}