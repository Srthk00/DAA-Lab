#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}

pair<int,vector<int>> scheduleTasks(vector<int> &time,vector<int> &deadline){
    int n=time.size();
    vector<pair<int,int>> tasks;
    for(int i=0;i<n;i++){
        tasks.push_back({time[i],deadline[i]});
    }
    sort(tasks.begin(),tasks.end(),cmp);
    vector<int> selected;
    int currentTime=0;
    for(int i=0;i<n;i++){
        if(currentTime+tasks[i].first<=tasks[i].second){
            selected.push_back(i+1);
            currentTime+=tasks[i].first;
        }
    }
    return {selected.size(),selected};
}

int main(){
    int n,t,d;
    cout << "Enter number of tasks: ";
    cin >> n;
    vector<int> time,deadline;
    cout << "Enter time and deadline for each task: " << endl;
    for(int i=0;i<n;i++){
        cin >> t >> d;
        time.push_back(t);
        deadline.push_back(d);
    }
    pair<int,vector<int>> result=scheduleTasks(time,deadline);
    cout << "Maximum tasks completed: " << result.first << endl;
    cout << "Selected tasks: ";
    for(int i:result.second){
        cout << i << ", ";
    }
    return 0;
}