//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int arr[], int n, int k) {
        sort(arr,arr+n);
        int result = INT_MAX, prefix[n+1] = {0,arr[0]};
        for(int i = 1; i<=n; i++)
            prefix[i] = arr[i-1] + prefix[i-1];
        for(int i = 0; i<n; i++){
            int element = arr[i]+k;
            int index = upper_bound(arr+i+1,arr+n, element) - arr;
            if(index == n){
                result = min(prefix[i], result);
                break;
            }
            //(sum of piles with number of coins>arr[i]+K) 
            //- (sum of those piles after removing sufficient coins to satisfy "max diff K" property) 
            //+ (sum of piles before i-1)
            int deleted = (prefix[n] - prefix[index]) - (n-index)*(element) + prefix[i];
            result = min(result,deleted);
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends