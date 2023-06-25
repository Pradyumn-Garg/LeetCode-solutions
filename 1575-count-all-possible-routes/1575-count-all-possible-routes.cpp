class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector <vector<int>> dp(fuel+1,vector<int>(locations.size()+1,-1));
        return rec(locations, start, finish, fuel, dp);
    }
    int rec(vector <int> &locations,int curr, int finish, int fuel, vector<vector<int>> &dp){
        if(fuel==0){
            if(curr==finish){
                return 1;
            }
            return 0;
        }
        if(dp[fuel][curr]!=-1){
            return dp[fuel][curr];
        }
        int sum=0;
        for(int i=0;i<locations.size();i++){
            if(i==curr){
                continue; 
            }
            if(fuel-abs(locations[i]-locations[curr])>=0){
                sum=(sum+rec(locations,i,finish,fuel-abs(locations[i]-locations[curr]),dp))%1000000007;
            }
        }
        if(curr==finish){
            sum+=1;
        }
        return dp[fuel][curr]=sum;
    }
};