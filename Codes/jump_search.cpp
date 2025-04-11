#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int linear(vector<int> arr,int a,int b,int target){
    for(int i=a;i<=b;i++){
        if(arr[i]==target){
            return 1;
        }
        else if(arr[i]>target){
            return 0;
        }
    }
    return 0;
}

int jump(vector<int> arr,int target){
    int n=arr.size();
    int window=sqrt(n);
    int i=window;
    while(i<n && arr[i]<target){
        i+=window;
    }
    return linear(arr,i-window,min(i,n-1),target);
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
    int found=jump(arr,target);
    if(found==-1)
        cout << "The Element " << target << " is Not present...";
    else
        cout << "The Element " << target << " is present at index: " << found;
    return 0;   
}