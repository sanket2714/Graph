/*
The mother vertex is the vertex in a directed graph from which each and every vertex of a graph can be visited.
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
//#define graph(n) vector<int> adj[n]

//operations
#define mp make_pair
#define pll pair<ll, ll>
#define all(a) a.begin(),a.end()
#define pub push_back
#define pob pop_back
#define eb emplace_back
#define debug cout<<"debugging"<<endl;

using namespace std;


void dfs(int i, bool vis[], vector<int> adj[]) {
    vis[i]=true;
    
    for(auto j=adj[i].begin();j!=adj[i].end();++j) {
        if(!vis[*j]) {
            dfs(*j,vis,adj);
        }
    }
}

int findMother(int nodes,vector<int> adj[]) {
    int v=0;
	bool vis[nodes]={false};
	loop(i,0,nodes) {
	   if(!vis[i]){
	       dfs(i,vis,adj);
	       v=i;
	   }
	}
	    
	memset(vis,false,sizeof(vis));
	dfs(v,vis,adj);
	    
	loop(i,0,nodes) {
	   if(!vis[i]) {
	       return -1;
	   }
	}
	return v;
}

int main() {
    FASTIO;
    
	ll t;
	cin>>t;
	while(t--){
	    ll nodes,edges;
	    IN nodes>>edges;
	    
	    vector<int> adj[nodes];
	    memset(adj,0,sizeof(adj));
	    
	    loop(i,0,edges){
	        ll a,b;
	        IN a >> b;
	        adj[a].pub(b);
	    }
	    
	    int ans = findMother(nodes,adj);
	    
	    if(ans == -1)
	        OUT "NO MOTHER VERTEX" << endl;
	    else
	        OUT ans << endl;
	    
	}
	return 0;
}

/*

INPUT--->

1
7 8
0 1
0 2
1 3
4 1
6 4
5 6
5 2
6 0

OUTPUT--->
5

*/
