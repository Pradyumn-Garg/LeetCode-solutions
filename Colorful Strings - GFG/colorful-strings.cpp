//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long possibleStrings(int n, int r, int b, int g) {
        long long fact[n+1];
        fact[0] = 1;
        for (long long i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i;
        }
        long long left = n - (r+g+b);
        long long sum = 0;
        for (long long i = 0; i <= left; i++)
        {
            for (long long j = 0; j<= left-i; j++)
            {
                long long k = left - (i+j);
                sum = sum + fact[n] /(fact[i+r]*fact[j+b]*fact[k+g]);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r, g, b;
        cin >> n >> r >> g >> b;
        Solution ob;
        cout << ob.possibleStrings(n, r, b, g) << endl;
    }
    return 0;
}

// } Driver Code Ends