class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans=0,curr_min=INT_MAX,n=prices.size(),curr_max=INT_MIN,flag=0;
        for(int i=0;i<n;i++){
            if(flag==1){
                if(curr_max-prices[i]>fee){
                    ans+=curr_max-curr_min-fee;
                    curr_min=prices[i];
                    curr_max=INT_MIN;
                    flag=0;
                    continue;
                }
            }
            if(prices[i]<curr_min){
                curr_min=prices[i];
            }
            else if((prices[i]-curr_min>fee)&&(i==n-1||prices[i]>prices[i+1])&&prices[i]>curr_max){
                curr_max=prices[i];
                flag=1;
            }
        }
        
        if(flag==1){
            ans+=curr_max-fee-curr_min;
        }
        // else if(i==n-2&&prices[i]-curr>fee){
        //     if(prices[n-1]>prices[n-2]){
        //         ans+=prices[n-1]-curr-fee;
        //     }
        //     else{
        //         ans+=prices[i]-curr-fee;
        //     }
        //     curr=INT_MAX;
        // }

        
        // if(curr!=INT_MAX){
        //     if(prices[n-1]-curr>fee){
        //         ans+=prices[n-1]-fee-curr;
        //     }
        // }
        return ans;
    }
};