#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(int s,vector<vector<int>> graph,int vis[],int v){
    cout << s << " ";
    vis[s]=1;
    for(int i=1;i<=v;i++){
        if(graph[s][i] && vis[i]==0){
            dfs(i,graph,vis,v);
        }
    }
}

int main(){
    int v,e;
    cout << "Enter number of Vertices/Nodes and Edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v+1,vector<int>(v+1,0));
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        graph[m][n]++;
        graph[n][m]++;
    }
    cout << "Matrix Representation of provided Graph: " << endl;
    for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    // BFS
    int *visited=(int*)calloc((v+1),sizeof(int));
    queue<int> que;
    int s;
    cout << "Enter Starting Node: ";
    cin >> s;
    que.push(s);
    visited[s]=1;
    while(!que.empty()){
        int node=que.front();
        que.pop();
        cout << node << " ";
        for(int i=1;i<=v;i++){
            if(graph[node][i] && visited[i]!=1){
                que.push(i);
                visited[i]=1;
            }
        }
    }

    // DFS using recursion
    int *vis=(int*)calloc((v+1),sizeof(int));
    int a;
    cout << "Enter Starting node: ";
    cin >> a;
    dfs(a,graph,vis,v);
    
    // // DFS using Stack
    // int *visi=(int*)calloc((v+1),sizeof(int));
    // stack<int> st;
    // int p;
    // cout << "Enter Starting node: ";
    // cin >> p;
    // st.push(p);
    // while(!st.empty()){
    //     int temp=st.top();
    //     st.pop();
    //     if(!visi[temp]){
    //         cout << temp << " ";
    //         visi[temp]=1;
    //     }
    // }
    return 0;
}