class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0,max=0;
        for(auto i:nums){
            if(i==1){
                count++;
                if(count>max){
                    max=count;
                }
            }
            else{
                count=0;
            }
        }
        return max;
    }
};