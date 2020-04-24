/*
  This algorithm is similar to dijkstra algorith but the main difference is that it can also handle negative weight cycle
  and also time complexity of dijkstra algorithm is O(VlogV) but its time complexity is O(VE).
*/

#include <bits/stdc++.h>

//fast input/output
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

//initializers
#define MOD 1e9+7;
#define IN cin>>
#define OUT cout<<
#define ll long long
#define endl '\n'

// loops
#define loop(i,a,n) for(long long i=a; i<n; i++)
#define rloop(i,a,n) for(long long i=a; i>=n; i--)

//data structures
#define vll vector<ll> 
#define vvll vector< vector < long long > >
#define mpl map<ll>
#define mpll map<ll,ll>
#define mpls map<ll,string>
#define graph(n) vector<int> adj[n]

//operations
#define mp make_pair
#define pll pair<ll, ll>
#define all(a) a.begin(),a.end()
#define pub push_back
#define pob pop_back
#define eb emplace_back
#define debug cout<<"debugging"<<endl

using namespace std;

void BellmanFord(vector<pair<int,int>> adj[], int src,int n,int e) {
    
    int dist[n]={INT_MAX};
    dist[src] = 0;
    int u,v,w;
    
   // The loop given under is able to determine all the shortest paths
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n;j++) {
            for(auto it=adj[j].begin();it!=adj[j].end();++it){
              u=j;
              v=(*it).first;
              w=(*it).second;
              if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                  dist[v]=dist[u]+w;
              }
            }
            
        }
    }
    
    /* 
    After calculating all the shortest paths we check the distances againg if ther is still any path 
    which is shorter then the calculated path then ther is a negative weight cycle
    */
    for(int j=0;j<n;j++) {
        for(auto it=adj[j].begin();it!=adj[j].end();++it){
          u=j;
          v=(*it).first;
          w=(*it).second;
          if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
              cout<<1<<endl;
              return;
          }
        }
    }
    cout<<0<<endl;
}
int main(){
    ll t;
    IN t;
    while(t--){
        int n,e;
        cin>>n>>e;
        
        vector<pair<int,int>> adj[n]; 
        loop(i,0,e) {
            int u,v,w;
            cin>>u>>v>>w;
            
            adj[u].pub({v,w});
        }
        
        BellmanFord(adj,0,n,e);
        
    }
    return 0;
}
