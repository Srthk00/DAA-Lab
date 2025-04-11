#include <iostream>
#include <vector>

using namespace std;

int linear(vector<int> arr,int target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target)
            return i;
    }
    return -1;
}

int main(){
    int n,val,target,testcases;
    cout << "Enter number test-cases: ";
    cin >> testcases;
    while(testcases>0){
        cout << "Enter the Size of array: ";
        cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Enter target to search: ";
        cin >> target;
        int found=linear(arr,target);
        if(found==-1)
            cout << "The element " << target <<  " Not present..." << endl;
        else
            cout << "The element " << target << " is present at index: " << found << endl;
        testcases--;
    }
    return 0;
}