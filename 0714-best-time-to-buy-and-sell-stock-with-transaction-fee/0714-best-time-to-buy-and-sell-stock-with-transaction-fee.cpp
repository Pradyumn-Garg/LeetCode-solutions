class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans=0,n=prices.size(),flag=0,min=INT_MAX,max=INT_MIN;
        for(int i=0;i<n;i++){
            if(flag==1){
                if(max-prices[i]>fee){
                    ans+=max-min-fee;
                    min=prices[i];
                    max=INT_MIN;
                    flag=0;
                    continue;
                }
            }
            if(prices[i]<min){
                min=prices[i];
            }
            else if((prices[i]-min>fee)&&(i==n-1||prices[i]>prices[i+1])&&prices[i]>max){
                max=prices[i];
                flag=1;
            }
        }
        if(flag==1){
            ans+=max-fee-min;
        }
        return ans;
    }
};