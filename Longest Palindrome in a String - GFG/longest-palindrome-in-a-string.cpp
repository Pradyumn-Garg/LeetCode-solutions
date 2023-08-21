//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        string ans=S.substr(0,1);
        int len=1;
        for(int i=0;i<S.length();i++){
            int s=i-1,e=i+1;
            int curr=1;
            while(s>=0&&e<S.length()){
                if(S[s]==S[e]){
                    curr+=2;
                    if(curr>len){
                        ans=S.substr(s,curr);
                        len=curr;
                    }
                    s--;
                    e++;
                }
                else{
                    break;
                }
            }
        }
        
        for(int i=0;i<S.length()-1;i++){
            int s=i,e=i+1;
            int curr=0;
            while(s>=0&&e<S.length()){
                if(S[s]==S[e]){
                    curr+=2;
                    if(curr>len){
                        ans=S.substr(s,curr);
                        len=curr;
                    }
                    s--;
                    e++;
                }
                else{
                    break;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends