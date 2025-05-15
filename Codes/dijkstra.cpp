#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int V,int s,vector<vector<pair<int,int>>> &graph){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int currw=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        for(auto &it:graph[u]){
            int v=it.first;
            int w=it.second;
            if(dist[v]>currw+w){
                dist[v]=currw+w;
                pq.push({dist[v],v});
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
        cout << "Enter source, destination, and weight: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    vector<int> dist=dijkstra(v,source,graph);
    for(int i=0;i<v;i++){
        cout << i << ": " << dist[i] << endl;
    }
    return 0;
}