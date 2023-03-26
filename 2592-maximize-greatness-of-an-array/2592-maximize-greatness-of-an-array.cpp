class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int extra=0,ans=n-1,curr=nums[n-1],temp=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==curr){
                temp++;
                if(extra){
                    extra--;
                    continue;
                }
                ans--;
            }
            else{
                extra+=temp;
                temp=0;
                curr=nums[i];
            }
        }
        return ans;
    }
};