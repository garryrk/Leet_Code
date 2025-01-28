class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        stack<int>special,st;
        if(n&1) return false;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(locked[i]=='0')  special.push(i);
            else if(s[i]=='(')  st.push(i);
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(!special.empty()){
                    special.pop();
                }
                else return false;
            }
        }
        while(!special.empty() and !st.empty() and special.top()>st.top()){
            special.pop();
            st.pop();
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
    
};
