#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(int s,vector<vector<int>> adj,vector<int> vis){
    cout << s << " ";
    vis[s]=1;
    for(auto it:adj[s]){
        if(vis[it]==0){
            dfs(it,adj,vis);
        }
    }
}

int main(){
    int v,e;
    cout << "Enter number of vertices/nodes and edges: ";
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    for(int i=1;i<=v;i++){
        cout << "Nodes connected from [" << i << "]: ";
        for(auto it:adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    // BFS
    int s;
    cout << "Enter starting node: ";
    cin >> s;
    queue<int> que;
    int *visited=(int*)calloc(v+1,sizeof(int));
    que.push(s);
    visited[s]=1;
    while(!que.empty()){
        int node=que.front();
        cout << node << " ";
        que.pop();
        for(auto it:adj[node]){
            if(visited[it]==0){
                que.push(it);
                visited[it]=1;
            }
        }
    }

    // // DFS using stack
    // int a;
    // cout << "Enter starting node: ";
    // cin >> a;
    // stack<int> st;
    // int *vis=(int*)calloc(v+1,sizeof(int));
    // st.push(a);
    // vis[a]=1;
    // while(!st.empty()){
    //     int node=st.top();
    //     cout << node << " ";
    //     st.pop();
    //     for(auto it:adj[node]){
    //         if(vis[it]==0){
    //             st.push(it);
    //             vis[it]=1;
    //         }
    //     }
    // }

    // DFS using recursion
    vector<int> vi(v+1,0);
    int p;
    cout << "Enter starting node: ";
    cin >> p;
    dfs(p,adj,vi);
    return 0;
}