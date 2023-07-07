class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        queue <int> t,f;
        int ans=INT_MIN,tsize=0,fsize=0;
        for(int i=0;i<answerKey.length();i++){
            if(answerKey[i]=='F'){
                ++fsize;
                while(t.size()>=k){
                    tsize=i-t.front()-1;
                    t.pop();
                }
                t.push(i);
                ++tsize;
                ans=max(ans,max(tsize,fsize));
            }
            else{
                ++tsize;
                while(f.size()>=k){
                    fsize=i-f.front()-1;
                    f.pop();
                }
                f.push(i);
                ++fsize;
                ans=max(ans,max(tsize,fsize));
            }
        }
        return ans;
    }
};