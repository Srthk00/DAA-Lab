// Comparision based sorting algorithm that follow the recursive approch of divide and conqure

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);    
        }
        else{   
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);    
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void divide(vector<int>& arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        divide(arr,low,mid);
        divide(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int n,val;
    vector<int> arr;
    cout << "Enter size of array: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        arr.push_back(val);
    }
    divide(arr,0,arr.size()-1);
    cout << "Sorted Array: " << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << ",";
    }
    return 0;
}