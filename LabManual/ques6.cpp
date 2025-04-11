#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int count_pair(vector<int> arr,int target){
    unordered_set<int> st;
    int c=0;
    for(int i:arr){
        st.insert(i);
    }
    for(int i:arr){
        if(st.find(i+target)!=st.end()){
            c++;
        }
    }
    return c;
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
        cout << "Enter target: ";
        cin >> target;
        int result=count_pair(arr,target);
        cout << "Number of pairs whose difference is equal to " << target << " are: " << result << endl; 
        testcases--;
    }
    return 0;
}