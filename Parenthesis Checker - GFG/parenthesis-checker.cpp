//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack <char> s;
        for(int i:x){
            if(i=='{'||i=='['||i=='('){
                s.push(i);
            }
            else if(i=='}'){
                if(s.empty()||s.top()!='{'){
                    return false;
                }
                else{
                    s.pop();
                }
            }
            else if(i==']'){
                if(s.empty()||s.top()!='['){
                    return false;
                }
                else{
                    s.pop();
                }
            }
            else{
                if(s.empty()||s.top()!='('){
                    return false;
                }
                else{
                    s.pop();
                }
            }
        }
        if(!s.empty()){
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends