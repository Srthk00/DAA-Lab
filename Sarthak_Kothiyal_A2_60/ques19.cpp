#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> dijkstra(int V,int s,vector<vector<pair<int,int>>> &graph,vector<int> &parent){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    pq.push({0,s});
    parent[s]=-1;
    while(!pq.empty()){
        int currw=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        for(auto &it:graph[u]){
            int v=it.first;
            int w=it.second;
            if(dist[v]>currw+w){
                dist[v]=currw+w;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int v,e;
    cout << "Enter number of Houses and Roads: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter source, destination, and weight: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    vector<int> parent(v);
    int fri,akshay;
    cout << "Enter Akshay's location: ";
    cin >> akshay;
    cout << "Enter friend's location: ";
    cin >> fri;
    vector<int> dist=dijkstra(v,fri,graph,parent);
    stack<int> path;
    cout << "\nShortest Distance to Akshay's House: " << dist[akshay] << endl;
    cout << "Path: ";
    for (int i=akshay;i!=-1;i=parent[i]){
        path.push(i);
    }
    while(!path.empty()){
        cout << path.top();
        path.pop();
        if(!path.empty()){ 
            cout<< "->";
        }
    }
    cout << endl;
    return 0;
}