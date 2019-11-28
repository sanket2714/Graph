#include <bits/stdc++.h>

using namespace std;
#define MAX 100
struct Point{
    int x;
    int y;
};

struct qNode{
    Point pt;
    int dist;
};

bool isValid(int r,int c,int n,int m){
    if(r>=0  && r<n && c>=0 && c<m){
        return true;
    }
    
    return false;
}
int rowName[]={0,1,0,-1};
int colName[]={1,0,-1,0};
long long BFS(int mat[][MAX],Point src,Point dest,long long n,long long m){
    if(src.x<0 || src.x>n || src.y<0 || src.y>m || dest.x<0 || dest.x>n || dest.y<0 || dest.y>m)
        return -1;
    
    if(mat[src.x][src.y] == 0 || mat[dest.x][dest.y] == 0 )
        return -1;
    
    bool visited[n][m];
    memset(visited,false,sizeof(visited));
    
    queue<qNode> q;
    qNode node = {src,0};
    q.push(node);
    
    while(!q.empty()){
        qNode front = q.front();
        Point pt=front.pt;
        
        if(pt.x == dest.x && pt.y == dest.y)
            return front.dist;
        
        q.pop();
        for(int i=0;i<4;i++){
            int row = pt.x + rowName[i];
            int col = pt.y + colName[i];
            
            if(isValid(row,col,n,m) && mat[row][col] && !visited[row][col]){
                visited[row][col] = true;
                qNode newNode = {{row,col},1+front.dist};
                q.push(newNode);
            }
        }
    }
    return -1;
}

int main() {
    long long n,m;
    cin>>n>>m;
    int mat[n][MAX];
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int source_x,source_y,dest_x,dest_y;
    cin>>source_x>>source_y>>dest_x>>dest_y;
    Point source={source_x,source_y};
    Point dest={dest_x,dest_y};
    // Point source={0,0};
    // Point dest={2,2};
    long long result = BFS(mat,source,dest,n,m);
     if (result != INT_MAX) 
        cout << result ; 
    else
        cout << -1 ; 
  
    return 0; 
}

/*
INPUT--------

9 10
1 0 1 1 1 1 0 1 1 1
1 0 1 0 1 1 1 0 1 1
1 1 1 0 1 1 0 1 0 1
0 0 0 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 0
1 0 1 1 1 1 0 1 0 0
1 0 0 0 0 0 0 0 0 1
1 0 1 1 1 1 0 1 1 1
1 1 0 0 0 0 1 0 0 1
0 0
3 4

OUTPUT----

11
*/
