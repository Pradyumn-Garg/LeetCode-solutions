//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_set <int> m;
        queue <int> q;
        for(int i=0;i<V;i++){
            if(m.find(i)==m.end()){
                q.push(i);
                m.insert(i);
                if(bfs(q,m,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool bfs(queue <int> &q, unordered_set <int> &m, vector<int> adj[]){
        while(!q.empty()){
            int count=0;
            for(auto i:adj[q.front()]){
                if(m.find(i)==m.end()){
                    q.push(i);
                    m.insert(i);
                }
                else{
                    ++count;
                    if(count>1){
                        return true;
                    }
                }
            }
            q.pop();
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends