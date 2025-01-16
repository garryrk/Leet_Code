class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        if(m&1){
            for(int i=0;i<n;i++){
                ans=ans^nums1[i];
            }
        }
        if(n&1){
            for(auto &it:nums2){
                ans=ans^it;
            }
        }
        return ans;
    }
};
