class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>seen(51,false);
        int cnt=0;
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]){
                cnt++;
                ans.push_back(cnt);
                continue;
            }
            if(seen[A[i]]){
                cnt++;
            }
            else{
                seen[A[i]]=true;
            }
            if(seen[B[i]]){
                cnt++;
            }
            else{
                seen[B[i]]=true;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
