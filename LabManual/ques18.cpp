#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool dfs(int s,vector<vector<int>> &adj,vector<int> &vis,int parent){
    vis[s]=1;
    for(auto it:adj[s]){
        if(vis[it]==0){
            if(dfs(it,adj,vis,s)){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    vector<int> vis(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        if(vis[i]==0){
            if(dfs(i,adj,vis,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        graph[m].push_back(n);
        graph[n].push_back(m);
    }
    if(isCycle(graph)){
        cout << "The Graph contain cycle..." << endl; 
    }
    else{
        cout << "The Graph does Not contain cycle..." << endl; 
    }
    return 0;
    return 0;
}