#include <iostream>
#include <vector>

using namespace std;

void print_index(vector<int> arr){
    int n=arr.size();
    int i,j;
    bool flag=true;
    for(int k=n-1;k>=2;k--){
        int sum=arr[k];
        i=0;
        j=k-1;
        while(i<j){
            if(arr[i]+arr[j]==sum){
                flag=false;
                cout << "The i, j, k indices are: ";
                cout << i+1 << "," << j+1 << "," << k+1 << endl;
                return;
            }
            else if(arr[i]+arr[j]>sum)
                j--;
            else
                i++;
        }
    }
    if(flag)
        cout << "No sequence found..." << endl;
}

int main(){
    int n,val,testcases;
    cout << "Enter number of testcases: ";
    cin >> testcases;
    while(testcases>0){
        cout << "Enter size of array: ";
        cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        print_index(arr);
        testcases--;
    }
    return 0;
}