//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        int s=1,l=str.length();
        vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,INT_MAX));
        rec(dp,str,s,l);
        return dp[s][l];
    }
    
    int rec(vector<vector<int>> &dp,string str, int s,int l){
        if(s>l){
            return 0;
        }
        if(dp[s][l]!=INT_MAX){
            return dp[s][l];
        }
        if(str[s-1]==str[l-1]){
            return dp[s][l]=min(rec(dp,str,s+1,l-1),1+min(rec(dp,str,s,l-1),rec(dp,str,s+1,l)));
        }
        else if(str[s-1]!=str[l-1]){
            return dp[s][l]=1+min(rec(dp,str,s,l-1),rec(dp,str,s+1,l));
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends