//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        //1: O(number of bits), O(1)
        // int temp=N,count=1;
        // while(temp!=0){
        //     if(count<=R&&count>=L){
        //         if(temp&1==1){
        //             N-=(1<<(count-1));
        //         }
        //         else{
        //             N+=(1<<(count-1));
        //         }
        //     }
        //     temp=temp>>1;
        //     count++;
        // }
        // return N;
        
        //2: O(1),O(1)
        // calculating a number 'num' having 'r'
        // number of bits and bits in the range l
        // to r are the only set bits
        int num = ((1 << R) - 1) ^ ((1 << (L - 1)) - 1);
    
        // toggle bits in the range l to r in 'n'
        // and return the number
        // Besides this, we can calculate num as: num=(1<<r)-l .
        return (N ^ num);

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