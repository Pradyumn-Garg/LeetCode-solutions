class Solution {
public:
    int secondHighest(string s) {
        int high=-1,sec=-1;
        for(auto i:s){
            int temp=(int(i));
            if(temp>=48&&temp<=57){
                if(temp>high){
                    sec=high;
                    high=temp;
                }
                else if(temp>sec&&temp!=high){
                    sec=temp;
                }
            }
        }
        if(sec==-1){
            return sec;
        }
        return sec-48;
    }
};