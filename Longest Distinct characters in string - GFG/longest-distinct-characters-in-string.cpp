//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    vector<int> a(26,0);
    int ans=0,s=0;
    for(int i=0;i<S.length();i++){
        if(a[S[i]-'a']==1){
            while(S[s]!=S[i]){
                a[S[s]-'a']=0;
                ++s;
            }
            ++s;
            ans=max(ans,i-s+1);
        }
        else{
            a[S[i]-'a']=1;
            ans=max(ans,i-s+1);
        }
    }
    return ans;
}