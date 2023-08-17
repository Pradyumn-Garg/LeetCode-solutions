//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        // vector <int> a(26,0);
        // for(auto i:S){
        //     a[int(i)-96]+=1;
        // }
        // for(auto i:S){
        //     if(a[int(i)-96]==1){
        //         return i;
        //     }
        // }
        // return '$';

        int h[26]={0};
    	    
        //using hash table to store count of each character.
        for(int i = 0;i<S.length();i++){
            h[S[i]-'a']++;
        }

        //iterating over the string.
        for(int i = 0;i<S.length();i++)
        {
            //if count of current character is 1, we return it. 
            if(h[S[i]-'a'] == 1){
                return S[i];
            }
        }
        //if there is no non-repeating character then we return '$'.
            return '$';

    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends