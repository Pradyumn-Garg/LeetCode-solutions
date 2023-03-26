class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,max=INT_MIN,ans=0;
        for(auto i:prices){
            if(i<min){
                min=i;
                max=i;
                continue;
            }
            if(i>max){
                max=i;
                if(max-min>ans){
                    ans=max-min;
                }
            }
        }
        return ans;
    }
};