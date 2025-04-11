#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int linear(vector<int> arr,int a,int b,int target){
    for(int i=a;i<=b;i++){
        if(arr[i]==target){
            return i;
        }
        else if(arr[i]>target){
            return -1;
        }
    }
    return -1;
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
    int n,val,target,testcases;
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
        cout << "Enter element to search: ";
        cin >> target;
        int found=jump(arr,target);
        if(found==-1)
            cout << "The Element " << target << " is Not present..." << endl;
        else
            cout << "The Element " << target << " is present at index: " << found << endl;
        testcases--;
    }
    return 0;   
}
