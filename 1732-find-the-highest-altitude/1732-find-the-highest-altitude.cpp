class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,curr=0;
        for(auto i:gain){
            curr+=i;
            if(curr>ans){
                ans=curr;
            }
        }
        return ans;
    }
};