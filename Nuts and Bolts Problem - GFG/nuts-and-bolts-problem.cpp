//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void matchPairs(char nuts[], char bolts[], int n) {
        char arr[9] = {'!', '#' , '$', '%' , '&', '*','@' ,'^','~'} ;
        
     unordered_set<char>st;
     
     for(int i=0; i<n;i++)
     st.insert(nuts[i]);
     int j=0;
     for(int i=0; i<9;i++){
         if(st.find(arr[i])!=st.end()){
             if(j>=n)
             break;
             nuts[j]=arr[i];
             bolts[j]=arr[i];
             j++;
         }
     }
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends