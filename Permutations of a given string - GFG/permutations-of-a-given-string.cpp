//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
            set <string> ans;
            vector <int> v(52,0);
            for(auto i:S){
                if(i-'a'<0){
                    v[i-'A']+=1;
                }
                else{
                    v[i-'a'+26]+=1;
                }
            }
            rec(ans,v,"");
            vector<string>output;
            for(auto i:ans){
                output.push_back(i);
            }
            return output;
            
            // // 2nd method
            // vector<string>res;
            // // sort the string in lexicographically order
            // sort(S.begin(), S.end());
            // res.push_back(S);
            // while(next_permutation(S.begin(), S.end())){
            //     // keep adding while there is next permutation
            //     res.push_back(S);
            // }
            // return res;
		}
		
		void rec(set <string> &ans, vector <int> v, string curr){
		    int flag=0;
		    for(int i=0;i<v.size();i++){
		        if(v[i]==0){
		            continue;
		        }
		        flag=1;
		        if(i<26){
		            curr.push_back(char(i+65));
		        }
		        else{
		            curr.push_back(char(i+97-26));
		        }
		        v[i]-=1;
		        rec(ans,v,curr);
		        v[i]+=1;
		        curr.pop_back();
		    }
		    if(flag==0){
		        ans.insert(curr);
		    }
		    return;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends