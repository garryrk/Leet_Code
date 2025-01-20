class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        int last_ind=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int result=INT_MAX;
        for(int i=0;i<mat.size();i++){
            last_ind=INT_MIN;
            for(int j=0;j<mat[0].size();j++){
                int val=mat[i][j];
                last_ind=max(last_ind,mp[val]);
            }
            result=min(last_ind,result);
        }
    
        for(int i=0;i<mat[0].size();i++){
            last_ind=INT_MIN;
            for(int j=0;j<mat.size();j++){
                int val=mat[j][i];
                last_ind=max(last_ind,mp[val]);
            }
            result=min(last_ind,result);
        }
    
    return result;
}
};
