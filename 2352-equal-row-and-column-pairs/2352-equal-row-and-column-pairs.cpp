class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        vector<int> count(n,0);
        for(int i=0;i<n;i++){
            int curr=0,flag2=0,st;
            for(int j=0;j<n;j++){
                if(grid[i][0]==grid[0][j]){
                    bool flag= check(grid,i,j,n);
                    if(flag){
                        if(count[j]!=0){
                            ans+=count[j];
                            break;
                        }
                        else{
                            if(flag2==0){
                                st=j;
                                flag2=1;
                            }
                            curr+=1;
                        }
                    }
                }
            }
            if(flag2!=0){
                count[st]=curr;
                ans+=curr;
            }
        }
        return ans;
    }
    bool check(vector<vector<int>>& grid,int a,int b,int n){
        for(int i=0;i<n;i++){
            if(grid[a][i]!=grid[i][b]){
                return false;
            }
        }
        return true;
    }
};