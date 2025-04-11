#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> selection(vector<int> &arr){
    vector<int> data;
    int swp=0,comp=0;
    for(int i=0;i<arr.size();i++){
        int min=i;
        for(int j=i+1;j<arr.size();j++){
            comp++;
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
            swp++;
        }
    }
    data.push_back(swp);
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
        cout << "]" << endl;
        vector<int> data=selection(arr);
        cout << "Elements in sorted order: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        cout << "Number of Swaps: " << data[0] << endl;
        cout << "Number of Comparisions: " << data[1] << endl;
        testcases--;
    }
    return 0;
}