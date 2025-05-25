#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

bool cmp(pair<int,pii> &a,pair<int,pii> &b){
    return a.second.second<b.second.second;
}

vector<int> activity(vector<int> &start,vector<int> &end){
    vector<pair<int,pii>> activities;
    for(int i=0;i<start.size();i++){
        activities.push_back({i+1,{start[i],end[i]}});
    }
    sort(activities.begin(),activities.end(),cmp);
    vector<int> result;
    result.push_back(activities[0].first);
    int last_end=activities[0].second.second;
    for(int i=1;i<start.size();i++){
        if(activities[i].second.first>=last_end){
            result.push_back(activities[i].first);
            last_end=activities[i].second.second;
        }
    }
    return result;
}

int main(){
    int n,val1,val2;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<int> start,end;
    cout << "Enter starting and finishing time:" << endl;
    for(int i=0;i<n;i++){
        cin >> val1 >> val2;
        start.push_back(val1);
        end.push_back(val2);
    }
    vector<int> result=activity(start,end);
    cout << "Number of activities selected: " << result.size() << endl;
    cout << "List of selected activities: ";
    for(int i:result){
        cout << i << ", ";
    }
    return 0;
}