#include <iostream>
#include <vector>

using namespace std;

int binary(vector<int> arr,int target,int &comp){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            comp++;
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
            comp++;
        }
        else{
            low=mid+1;
            comp++;
        }
    }
    return -1;
}

int main(){
    int n,val,target,testcases;
    cout << "Enter number of testcases: ";
    cin >> testcases;
    while(testcases>0){
        int comp=0;
        cout << "Enter the Size of array: ";
        cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Enter target to search: ";
        cin >> target;
        int found=binary(arr,target,comp);
        if(found==-1)
            cout << "The element " << target <<  " Not present..." << endl;
        else
            cout << "The element " << target << " is present at index: " << found << endl;
        cout << "Total number of Comparisions: " << comp << endl;
    testcases--;
    }
    return 0;
}