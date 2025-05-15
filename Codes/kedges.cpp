#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// int kedges(vector<vector<pair<int,int>>>& graph,int s,int d,vector<int> &visited,int k){
//     queue<int> que;
//     que.push(s);
//     int cost=0;
//     while(!que.empty()){
//         int SIZE=que.size();
//         if(k==0){
//             return cost;
//         }
//         while(SIZE>0){
            
//         }
//     }
// }

// static int sum=0;

// void kedges(vector<vector<pair<int,int>>>& graph,int s,pair<int,int> d,vector<int> &visited,vector<int> &pathvisit,int k){
//     visited[s]=1;
//     pathvisit[s]=1;
//     k--;
//     if(k==0 && s==d.first){
//         cost.push_back(sum);
//         sum-=d.second;
//         return;
//     }
//     else if(k==0 && s!=d.first){
//         sum-=d.second;
//         return;
//     }
//     for(auto &it:graph[s]){
//         if(!visited[it.first]){
            
//         }
//     }
// }

vector<int> cost;

int kedges(vector<vector<pair<int,int>>> &graph,int k,int s,int d,int sum,vector<int> &path){
    path[s]=1;
    if(s==d && k==0){
        cost.push_back(sum);
        path[s]=0;
        return 0;
    }
    k--;
    for(auto &it:graph[s]){
        sum+=it.second;
        kedges(graph,k,it.first,d,sum,path);
    }
    path[s]=0;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter source, destination, and weight: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    int source,dest,k;
    cout << "Enter source node, destination node, and k: ";
    cin >> source >> dest >> k;
    vector<int> visited(v,0);
    vector<int> pathvisit(v,0);
    
    return 0;
}