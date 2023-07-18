//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_set <int> m;
        vector <int> ans;
        ans.push_back(0);
        m.insert(0);
        rec(0,adj,ans,m);
        return ans;
    }
    
    void rec(int curr, vector<int> adj[],vector <int> &ans,unordered_set <int> &m){
        for(auto i:adj[curr]){
            if(m.find(i)==m.end()){
                ans.push_back(i);
                m.insert(i);
                rec(i,adj,ans,m);
            }
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends