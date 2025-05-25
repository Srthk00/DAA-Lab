#include <iostream>
#include <vector>

using namespace std;

void printPath(int node,vector<int> &parent){
    if(node==-1)
        return;
    printPath(parent[node],parent);
    cout << node << " ";
}

vector<int> bellmanford(int v,int s,vector<vector<pair<int,int>>> &graph,vector<int> &parent){
    vector<int> dist(v,INT_MAX);
    dist[s]=0;
    parent[s]=-1;
    for(int i=0;i<v-1;i++){
        for(int u=0;u<v;u++) {
            for(auto &it:graph[u]){
                int n=it.first;
                int wt=it.second;
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[n]){
                    dist[n]=dist[u]+wt;
                    parent[n]=u;
                }
            }
        }
    }
    for(int u=0;u<v;u++){
        for(auto &it:graph[u]){
            int n=it.first;
            int wt=it.second;
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[n]){
                cout << "Graph contains a negative weight cycle!" << endl;
                return {};
            }
        }
    }
    return dist;
}

int main(){
    int v,e;
    cout << "Enter number of Vertices and Edges: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter Source, Destination, and Weigth: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    int source;
    cout << "Enter starting node: ";
    cin >> source;
    vector<int> parent(v,-1);
    vector<int> dist=bellmanford(v,source,graph,parent);
    if(!dist.empty()){
        cout << "\nShortest path from node " << source << ":\n";
        for(int i=0;i<v;i++){
            if(dist[i]==INT_MAX){
                cout << i << ": INF (No path)\n";
            }
            else{
                printPath(i,parent);
                cout << "; Distance=" << dist[i];
                cout << endl;
            }
        }
    }
    return 0;
}