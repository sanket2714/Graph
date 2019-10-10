// Finding connected components using DFS

#include <bits/stdc++.h>
typedef long long ll;
const int N=100000;
bool visited[N];
using namespace std;

void dfs(ll u,vector<ll> adj[]){
    cout<<u<<" ";
    visited[u]=true;
    for(ll j=0;j<adj[u].size();j++){
        ll v=adj[u][j];
        if(visited[v]!=true){
            dfs(v,adj);
        }
    }
    
}

int main() {
    ll nodes,edges;
    cin>>nodes>>edges;
    vector<ll> adj[nodes];
    ll a,b;
    for(ll i=1;i<=edges;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll connectedComponents=0;
    for(ll i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(i,adj);
            connectedComponents++;
            cout<<endl;
        }
    }
    cout<<"Connected components are= "connectedComponents;
}

/* INPUT
7 5
1 2
1 3
4 3
1 4
5 6

OUTPUT
0 
1 2 3 4 
5 6 
Connected components are= 3
*/
