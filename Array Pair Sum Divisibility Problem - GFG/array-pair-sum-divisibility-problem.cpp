//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()%2!=0){
            return false;
        }
        map <int,int> m;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%k;
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.first==0){
                if(i.second%2!=0){
                    return false;
                }
            }
            else{
                if(i.second!=m[k-(i.first)]){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends