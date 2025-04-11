#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr,int low,int high,int target){
    if(low>high)
        return 0;
    int mid=low+(high-low)/2;
    if(arr[mid]==target)
        return 1;
    else if(arr[mid]<target)
        return binary_search(arr,mid+1,high,target);
    else
        return binary_search(arr,low,mid-1,target);
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
    if(binary_search(arr,0,arr.size(),target))
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}