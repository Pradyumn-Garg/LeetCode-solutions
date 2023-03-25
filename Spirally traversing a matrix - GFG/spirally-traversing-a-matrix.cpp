//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int tempr=0,tempc=0,flag=0,flag2=1;
        while(flag2){
            flag2=0;
            flag=0;
            if(flag==0){
                while(tempc!=c){
                    if(matrix[tempr][tempc]==-1){
                        break;
                    }
                    ans.push_back(matrix[tempr][tempc]);
                    matrix[tempr][tempc]=-1;
                    flag2=1;
                    tempc++;
                }
                tempc--;
                tempr++;
                flag=1;
            }
            if(flag==1){
                while(tempr!=r){
                    if(matrix[tempr][tempc]==-1){
                        break;
                    }
                    ans.push_back(matrix[tempr][tempc]);
                    matrix[tempr][tempc]=-1;
                    flag2=1;
                    tempr++;
                }
                tempr--;
                tempc--;
                flag=2;
            }
            if(flag==2){
                while(tempc>=0){
                    if(matrix[tempr][tempc]==-1){
                        break;
                    }
                    ans.push_back(matrix[tempr][tempc]);
                    matrix[tempr][tempc]=-1;
                    flag2=1;
                    tempc--;
                }
                tempc++;
                tempr--;
                flag=3;
            }
            if(flag==3){
                while(tempr>=0){
                    if(matrix[tempr][tempc]==-1){
                        break;
                    }
                    ans.push_back(matrix[tempr][tempc]);
                    matrix[tempr][tempc]=-1;
                    flag2=1;
                    tempr--;
                }
                tempr++;
                tempc++;
                flag=0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends