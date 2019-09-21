//Dijkstra algorithm for shortest path

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f //for infinity

using namespace std;
vector<bool> visited;

void addEdge(vector<pair<int,int>> adj[],int a,int b,int wt){
    adj[a].push_back(make_pair(b,wt));
    adj[b].push_back(make_pair(a,wt));
}

void DijkstraShortestPath(vector<pair<int,int>> adj[],int V,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //stl syntax for min heap
    
    vector<int> dist(V,INF);
    
    vector<bool> visited(V,false);
    
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        
        for(auto x: adj[u]){
            int v=x.first;
            int wt=x.second;
            
            if(visited[v]==false && dist[v]>(dist[u]+wt)){
                dist[v]=dist[u]+wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    
    cout<<"Node   Shortest Distance from root node"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"        "<<dist[i]<<endl;
    }
}


int main() {
    int v=9;
    
    vector<pair<int,int>> adj[v];
    
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7);
    
    DijkstraShortestPath(adj,v,0);
    return 0;
}

/* OUTPUT

Node   Shortest Distance from root node
0        0
1        4
2        12
3        19
4        21
5        11
6        9
7        8
8        14

*/
