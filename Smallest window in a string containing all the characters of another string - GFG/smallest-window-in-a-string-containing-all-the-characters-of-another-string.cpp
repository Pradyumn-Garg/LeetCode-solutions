//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if (s.length() < p.length()) {
            return "-1";
        }
    
        vector<int> hash_pat (26,0);
        vector<int> hash_str (26,0);

        for (int i = 0; i < p.length(); i++){
            hash_pat[p[i]-'a']++;
        }
    
        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0; 
        for (int j = 0; j < s.length(); j++) {
            hash_str[s[j]-'a']++;
            if (hash_str[s[j]-'a'] <= hash_pat[s[j]-'a']){
                count++;
            }
            if (count == p.length()) {
                while (hash_str[s[start]-'a'] > hash_pat[s[start]-'a'] || hash_pat[s[start]-'a'] == 0) {
                    if (hash_str[s[start]-'a'] > hash_pat[s[start]-'a']){
                        hash_str[s[start]-'a']--;
                    }
                    start++;
                }
                int len_window = j - start + 1;
                if (min_len > len_window){
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        
        if (start_index == -1) {
            return "-1";
        }
        return s.substr(start_index, min_len);
        
        // 2) throws TLE in cpp
        
        // if(s.length()<p.length()){
        //     return "-1";
        // }
        // int flag=1,count=0;
        // string ans=s,curr;
        // map<char,int> m;
        // for(auto i:p){
        //     if(m.find(i)==m.end()){
        //         count++;
        //     }
        //     m[i]+=1;
        // }
        // int b=0,e=0;
        // while(e<s.length()){
        //     curr.push_back(s[e]);
        //     if(m.find(s[e])!=m.end()){
        //         m[s[e]]-=1;
        //         if(m[s[e]]==0){
        //             count--;
        //         }
        //     }
        //     while(count==0){
        //         flag=0;
        //         if(ans.length()>curr.length()){
        //             ans=curr;
        //         }
        //         if(m.find(s[b])!=m.end()){
        //             m[s[b]]+=1;
        //             if(m[s[b]]==1){
        //                 count++;
        //             }
        //         }
        //         ++b;
        //         curr.erase(curr.begin());
        //     }
        //     ++e;
        // }
        // if(flag==1){
        //     return "-1";
        // }
        // return ans;
    }
    
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends