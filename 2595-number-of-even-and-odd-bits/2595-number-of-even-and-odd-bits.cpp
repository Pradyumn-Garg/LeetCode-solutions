class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0,odd=0,temp=1,curr;
        for(int i=0;i<10;i++){
            if(i%2==0){
                if((n&temp)==temp){
                    even++;
                }
            }
            else{
                if((n&temp)==temp){
                    odd++;
                }
            }
            temp=temp<<1;
        }
        vector <int> ans {even,odd};
        return ans;
    }
};