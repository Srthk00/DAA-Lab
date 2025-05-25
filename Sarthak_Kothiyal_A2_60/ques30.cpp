#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

pair<int,double> find(vector<int> &nums){
    unordered_map<int,int> map;
    int n=nums.size();
    for(int i=0;i<n;i++){
        map[nums[i]]++;
    }
    int majority=-1;
    for(auto x:map){
        if(x.second>n/2){
            majority=x.first;
            break;
        }
    }
    sort(nums.begin(),nums.end());
    double median;
    if(n%2==0){
        median=(nums[n/2-1]+nums[n/2])/2.0;
    }
    else{
        median=nums[n/2];
    }
    return {majority,median};
}

int main(){
    int n,val;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums;
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++){
        cin >> val;
        nums.push_back(val);
    }
    pair<int,double> result=find(nums);
    if(result.first==-1){
        cout << "No majority element found." << endl;
    }
    else{
        cout << "Majority element: " << result.first << endl;
    }
    cout << "Median: " << result.second << endl;
    return 0;
}
