//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    vector<int> v(26,0);
    for(auto i:s){
        if(v[i-'a']==1){
            string ans;
            ans.push_back(i);
            return ans;
        }
        v[i-'a']++;
    }
    return "-1";
}