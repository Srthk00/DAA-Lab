#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> insertion(vector<int> &arr){
    vector<int> data;
    int shift=0,comp=0;
    for(int i=1;i<arr.size();i++){
        int j=i;
        while(j>0){
            comp++;
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                shift++;
                j--;
            }
            else{
                break;
            }
        }
    }
    data.push_back(shift);
    data.push_back(comp);
    return data;
}

int main(){
    int n,val,testcases;
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
        cout << "Elements before sorting: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;;
        vector<int> data=insertion(arr);
        cout << "Elements in sorted order: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        cout << "Number of Shifts: " << data[0] << endl;
        cout << "Number of Comparisions: " << data[1] << endl;
        testcases--;
    }
    return 0;
}