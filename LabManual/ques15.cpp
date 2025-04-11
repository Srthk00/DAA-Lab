#include <iostream>
#include <vector>

using namespace std;

vector<int> intersection(vector<int> arr1,vector<int> arr2){
    vector<int> arr3;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]==arr2[j]){
            arr3.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return arr3;
}

int main(){
    int m,n,testcases,val;
    cout << "Enter number of testcases: ";
    cin >> testcases;
    while(testcases>0){
        vector<int> arr1,arr2;
        cout << "Enter size of first array: ";
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> val;
            arr1.push_back(val);    
        }
        cout << "Enter size of second array: ";
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> val;
            arr2.push_back(val);    
        }
        vector<int> result=intersection(arr1,arr2);
        cout << "Common elements in both arrays: ";
        for(int i:result){
            cout << i << " ";
        }
        cout << endl;
        testcases--;
    }
    return 0;
}