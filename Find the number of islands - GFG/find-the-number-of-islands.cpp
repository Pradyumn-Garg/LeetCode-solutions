//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    if(grid[i][j]=='1'){
                        ans++;
                        dfs(grid,visited,n,m,i,j);
                    }
                    visited[i][j]=true;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int n,int m,int i,int j){
        if(visited[i][j]){
            return;
        }
        visited[i][j]=true;
        if(i-1>-1){
            if(j-1>-1&&grid[i-1][j-1]=='1'){
                dfs(grid,visited,n,m,i-1,j-1);
            }
            if(grid[i-1][j]=='1'){
                dfs(grid,visited,n,m,i-1,j);
            }
            if(j+1<m&&grid[i-1][j+1]=='1'){
                dfs(grid,visited,n,m,i-1,j+1);
            }
        }
        if(i+1<n){
            if(grid[i+1][j]=='1'){
                dfs(grid,visited,n,m,i+1,j);
            }
        }
        if(j-1>-1){
            if(grid[i][j-1]=='1'){
                dfs(grid,visited,n,m,i,j-1);
            }
            if(i+1<n&&grid[i+1][j-1]=='1'){
                dfs(grid,visited,n,m,i+1,j-1);
            }
        }
        if(j+1<m){
            if(grid[i][j+1]=='1'){
                dfs(grid,visited,n,m,i,j+1);
            }
            if(i+1<n&&grid[i+1][j+1]=='1'){
                dfs(grid,visited,n,m,i+1,j+1);
            }
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends