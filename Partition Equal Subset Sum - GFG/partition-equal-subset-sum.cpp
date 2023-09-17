//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        vector<vector<int>> v(N+1, vector<int> ((sum/2)+1,-1));
        return rec(v,arr,N,0,sum/2);
    }
    
    bool rec(vector<vector<int>> &v, int arr[], int N,int curr,int remaining){
        if(remaining==0){
            return true;
        }
        if(remaining<0||curr==N){
            return false;
        }
        if(v[curr][remaining]==1){
            return true;
        }
        return v[curr][remaining]=rec(v,arr,N,curr+1,remaining-arr[curr])||rec(v,arr,N,curr+1,remaining);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends