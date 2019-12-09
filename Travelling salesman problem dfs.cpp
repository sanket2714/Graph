#include <bits/stdc++.h>
#define MAX 12
using namespace std;

void tsp(int dist[][MAX],bool vis[],int curr_pos,int n,int count,int cost,int &ans){
    if(count == n && dist[curr_pos][0]){
        
        ans = min(ans,cost+dist[curr_pos][0]);
        return;
    }   
    
    for(int i=0;i<n;i++){
        if(!vis[i] && dist[curr_pos][i]){
            vis[i]=true;
            tsp(dist,vis,i,n,count+1,cost+dist[curr_pos][i],ans);
            
            vis[i]=false;
        }
    }
    
}

int main() {
	long long t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int dist[n][MAX];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>dist[i][j];
	        }
	    }
	    
	    bool vis[n]={false};
	   
	    vis[0]=true;
	    int ans=INT_MAX;
	    tsp(dist,vis,0,n,1,0,ans);
	    cout<<ans<<endl;
	}
	return 0;
}
