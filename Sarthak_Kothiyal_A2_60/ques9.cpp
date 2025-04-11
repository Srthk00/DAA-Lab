#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int i=0;
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

void SORT(vector<int> &arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        SORT(arr,low,mid);
        SORT(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int check(vector<int> arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1])
            return arr[i];
    }
    return -1;
}

int main(){
    int n,val,testcases,target;
    cout << "Enter number of testcases: ";
    cin >> testcases;
    while(testcases>0){
        vector<int> arr;    
        cout << "Enter size of array: ";
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        SORT(arr,0,arr.size()-1);
        int result=check(arr);
        if(result==-1)
            cout << "Array Does Not contain any Duplicate Elements..." << endl;
        else
            cout << "Array contain Duplicates of: " << result << endl;
        testcases--;
    }
    return 0;
}