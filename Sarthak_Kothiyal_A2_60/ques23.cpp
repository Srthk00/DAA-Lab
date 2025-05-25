#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> extractedges(const vector<vector<int>> &graph){
    vector<vector<int>> edges;
    for(auto &it:graph){
        int w=it[0],m=it[1],n=it[2];
        edges.push_back({w,m,n});
    }
    return edges;
}

int find(int x,vector<int> &parent){
    if(parent[x]!=x){
        parent[x]=find(parent[x],parent);
    }   
    return parent[x];
}

void UNION(int a,int b,vector<int> &parent,vector<int> &SIZE){
    int x=find(a,parent);
    int y=find(b,parent);
    if(x==y){
        return;
    }
    if(SIZE[x]>SIZE[y]){
        parent[y]=x;
    }
    else if(SIZE[x]<SIZE[y]){
        parent[x]=y;
    }
    else{
        parent[x]=y;
        SIZE[y]++;
    }
}

void kruskals(vector<vector<int>> &edges,vector<int> &parent,vector<int> &SIZE){
    int mst=0;
    for(auto &it:edges){
        int w=it[0];
        int u=it[1];
        int v=it[2];
        if(find(u,parent)!=find(v,parent)){
            mst+=w;
            UNION(u,v,parent,SIZE);
        }
    }
    cout << "Cost of Minimum Spanning Tree is: " << mst;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph;
    for(int i=0;i<e;i++){
        int w,m,n;
        cout << "Enter weight, source, and destination: ";
        cin >> w >> m >> n;
        graph.push_back({w,m,n});
    }
    vector<vector<int>> edges=extractedges(graph);
    sort(edges.begin(),edges.end());
    vector<int> parent(v);
    vector<int> SIZE(v,0);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    kruskals(edges,parent,SIZE);
    return 0;
}