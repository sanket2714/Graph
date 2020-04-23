/*
Strongly connected component is a graph which is cyclic in nature and it reaches to the initial vertex 
by traversing all the other vertices.
*/
#include<bits/stdc++.h>
using namespace std;

// function to detect SCC by using every element popped out from stack
void dfs(int i, bool vis[], vector<int> tran[]) {
    vis[i]=true;
    //cout<<i<<" "; //to print SCC
    
    for(auto j=tran[i].begin();j!=tran[i].end();++j) {
        if(!vis[*j]) {
            dfs(*j,vis,tran);
        }
    }
}

//function to transpose a graph
void transpose(vector<int> tran[], int V, vector<int> adj[]) {
    for(int v=0;v<V;v++) {
        for(auto i=adj[v].begin();i!=adj[v].end();++i) {
            tran[*i].push_back(v);
        }
    }
}

//function to fill the stack in a dfs manner
void fill(int i,bool vis[],stack<int> &s,vector<int> adj[]) {
    vis[i] = true;
    
    for(auto j=adj[i].begin();j!=adj[i].end();j++) {
        if(!vis[*j]) {
            fill(*j,vis,s,adj);
        }
    }
    s.push(i);
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    bool vis[V]={false};
    
    for(int i=0;i<V;i++) {
        if(!vis[i]) {
            fill(i,vis,s,adj); //call dfs for filling the stack
        }
    }
    
    vector<int> tran[V];
    memset(tran,0,sizeof(tran));
    
    transpose(tran,V,adj); // transpose the graph i.e. reverse all the directions of graph
    
    memset(vis,false,sizeof(vis));
    int con=0;
    while(!s.empty()) {
        int fr=s.top();
        s.pop();
        if(!vis[fr]){
            dfs(fr,vis,tran); // dfs call for SCC
            //cout<<endl;
            con++;
        }
    }
    return con;
}

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}
