//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> v2(V,0);
        vector<int> v(V,0);
        for(int i=0;i<V;i++){
            if(v2[i]==0){
                v2[i]=1;
                if(dfs(adj,v2,v,i)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector <int> adj[],vector<int> &v2,vector<int> &v,int curr){
        v[curr]=1;
        for(auto i:adj[curr]){
            if(v[i]==0&&v2[i]==0){
                v2[i]=1;
                if(dfs(adj,v2,v,i)){
                    return true;
                }
            }
            else if(v[i]==1){
                return true;
            }
        }
        v[curr]=0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends