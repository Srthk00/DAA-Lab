#include <iostream>
#include <vector>

using namespace std;

int find_lower(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int num=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            if(nums[mid]==target)
                num=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return num;
}

int find_higher(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int num=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=target){
            if(nums[mid]==target)
                num=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return num;
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
        int left=find_lower(arr,target);
        int right=find_higher(arr,target);
        if(left==-1 || right==-1)
            cout << "The element " << target << " is Not present..." << endl;
        else
            cout << "The element " << target << " is present " << right-left+1 << " times..." << endl;
        testcases--;
    }
    return 0;
}