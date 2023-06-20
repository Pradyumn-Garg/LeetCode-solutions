class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        vector<int> ans(n,-1);
        if(n<(2*k+1)){
            return ans;
        }
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }
        for(int i=k;i<n-k;i++){
            ans[i]=sum/((2*k)+1);
            if(i!=(n-k-1)){
                sum-=nums[i-k];
                sum+=nums[i+k+1];
            }
        }
        return ans;
    }
};