#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void twosum(vector<int> arr,int target){
    sort(arr.begin(),arr.end());
    int low=0,high=arr.size()-1;
    while(low<high){
        int sum=arr[low]+arr[high];
        if(sum==target){
            cout << "Values: " << arr[low] << " and " << arr[high] << " sum up to target: " << target << endl;
            return;
        }
        else if(sum<target){
            low++;
        }
        else{
            high--;
        }
    }
    cout << "No such Elements exist in the Array..." << endl;
}

int main(){
    int testcases,n,val,target;
    cout << "Enter number of testcase: ";
    cin >> testcases;
    while(testcases>0){
        cout << "Enter size of array: ";
        cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Enter target element: ";
        cin >> target;
        twosum(arr,target);
        testcases--;
    }
    return 0;
}