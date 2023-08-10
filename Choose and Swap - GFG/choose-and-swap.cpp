//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        vector <int> v(26,0);
        for(auto i:a){
            v[int(i)-97]=1;
        }
        string ans=a;
        int c=-1,b=-1,flag=0;
        for(int i=0;i<a.length();i++){
            for(int j=0;j<int(a[i])-97;j++){
                if(v[j]==1){
                    c=j;
                    b=int(a[i])-97;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                v[int(a[i])-97]=0;
            }
            else if(flag==1){
                break;
            }
        }
        if(c==-1||b==-1){
            return a;
        }
        for(int i=0;i<a.length();i++){
            int temp=int(ans[i])-97;
            if(temp==c){
                ans[i]=char(b+97);
            }
            else if(temp==b){
                ans[i]=char(c+97);
            }
        }
        return ans;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends