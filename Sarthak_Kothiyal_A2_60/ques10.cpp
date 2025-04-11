#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr,int low,int mid,int high,int &comp,int &inver){
    vector<int> temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);        
        }
        else{   
            temp.push_back(arr[right++]);
            inver+=(mid-left+1);
        }
        comp++;
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

void divide(vector<int>& arr,int low,int high,int &comp,int &inver){
    if(low<high){
        int mid=(low+high)/2;
        divide(arr,low,mid,comp,inver);
        divide(arr,mid+1,high,comp,inver);
        merge(arr,low,mid,high,comp,inver);
    }
}

int main(){
    int n,val,testcases;
    cout << "Enter number of test cases: ";
    cin >> testcases;
    while(testcases>0){
        int comp=0,inver=0;
        vector<int> arr;
        cout << "Enter size of array: ";
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Elements before sorting: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        divide(arr,0,arr.size()-1,comp,inver);
        cout << "Elements after sorting: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        cout << "Number of Comparisons: " << comp << endl;
        cout << "Number of inversions: " << inver << endl;
        testcases--;
    }
}