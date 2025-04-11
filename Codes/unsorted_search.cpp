#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr,int target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            return 1;
        }
    }
    return 0;
}

int main(){
    vector<int> arr;
    int n,target,value;
    cout << "Enter number of terms: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> value;
        arr.push_back(value);
    }
    cout << "Enter element to search: ";
    cin >> target;
    if(search(arr,target))
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}