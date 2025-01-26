class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        function<int(int)>func=[&](int ind)->int{
            unordered_set<int>children;
            children.insert(leftChild.begin(),leftChild.end());
            children.insert(rightChild.begin(),rightChild.end());
            for(int i=0;i<n;i++){
                if(children.find(i)==children.end()){
                    return i;
                }
            }
            return -1;
        
        };
        int root=func(0);
        if(root==-1)    return false;
        queue<int>q;
        unordered_set<int>st;
        st.insert(root);
        q.push(root);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vector<int>children={leftChild[node],rightChild[node]};
            for(int child:children){
                if(child!=-1){
                    if(st.find(child)!=st.end()){
                        return false;
                    }
                    q.push(child);
                    st.insert(child);
                }
            }
        }
        return st.size()==n;
    }
};
