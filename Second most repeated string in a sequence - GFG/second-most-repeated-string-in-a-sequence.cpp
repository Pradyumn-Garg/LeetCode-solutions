//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        if(m.size()<2){
            return "";
        }
        map<int,string,greater<int>>m2;
        for(auto i:m){
            m2[i.second]=i.first;
        }
        return (++m2.begin())->second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends