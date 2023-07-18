//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack,
                  vector<int> adj[]) {
        // if the current vertex is not visited.
        if (visited[v] == false) {
            // marking the current node as visited and part of recursion stack.
            visited[v] = true;
            recStack[v] = true;

            // calling function recursively for all the vertices
            // adjacent to this vertex.
            for (int i = 0; i < (int)adj[v].size(); ++i) {
                if (!visited[adj[v][i]] &&
                    isCyclicUtil(adj[v][i], visited, recStack, adj))
                    return true;
                else if (recStack[adj[v][i]])
                    return true;
            }
        }
        // removing the vertex from recursion stack.
        recStack[v] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // marking all vertices as not visited and not a part of recursion stack
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // calling the recursive helper function to detect cycle in
        // different DFS trees.
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack, adj)) return true;

        return false;
    }

    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<int> v2(V,0);
    //     vector<int> v(V,0);
    //     for(int i=0;i<V;i++){
    //         if(v2[i]==0){
    //             v2[i]=1;
    //             if(dfs(adj,v2,v,i)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    // bool dfs(vector <int> adj[],vector<int> &v2,vector<int> v,int curr){
    //     v[curr]=1;
    //     for(auto i:adj[curr]){
    //         if(v[i]==0&&v2[i]==0){
    //             v2[i]=1;
    //             if(dfs(adj,v2,v,i)){
    //                 return true;
    //             }
    //         }
    //         else if(v[i]==1){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
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