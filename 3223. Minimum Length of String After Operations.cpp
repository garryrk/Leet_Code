class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>cnt(26,0);
        for(auto &i:s){
            cnt[i-'a']++;
        }
        
        int ans=n;
        for(int i=0;i<26;i++){
            if(cnt[i]>2){
                if(cnt[i]%2==1){
                    ans=ans-cnt[i]+1;
                }
                else{
                    ans=ans-cnt[i]+2;
                }
            }
        }
        return ans;
    }
};
