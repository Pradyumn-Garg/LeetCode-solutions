//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        int temp=N,count=1;
        // if(temp&1==1){
        //     return 100;
        // }
        // if(temp&1==0){
        //     return 200;
        // }
        while(temp!=0){
            if(count<=R&&count>=L){
                if(temp&1==1){
                    N-=(1<<(count-1));
                }
                else{
                    N+=(1<<(count-1));
                }
            }
            temp=temp>>1;
            count++;
        }
        return N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends