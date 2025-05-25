#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,vector<vector<int>>& graph,vector<bool> &vis){
    vis[node]=true;
    for(int u:graph[node]){
        if(!vis[u]){
            dfs(u,graph,vis);
        }
    }
}

int findMother(int n,vector<vector<int>>& graph){
    vector<bool> vis(n,false);
    int mother=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,graph,vis);
            mother=i;
        }
    }
    fill(vis.begin(),vis.end(),false);
    dfs(mother,graph,vis);
    for(bool v:vis){
        if(!v){
            return -1;
        }
    }
    return mother;
}

int main() {
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v);
    cout << "Enter source and destination:" << endl;
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        graph[m].push_back(n);
    }
    int mother=findMother(v,graph);
    if(mother==-1){
        cout << "No Mother Vertex exists..";
    }
    else{
        cout << "Mother Vertex is: " << mother;
    }
    return 0;
}