
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //prepare
        int days = temperatures.size();
        stack<int>st;
        vector<int>ans(days,0);

        //move
        for(int i= days-1; i>=0; i-- ){
            //pop
            while(!st.empty() && temperatures[st.top()]<= temperatures[i]){
                st.pop();
            }
            //push
            if(!st.empty()){
                ans[i] = st.top()-i;
            }
            st.push(i);
        }

        //return ans
        return ans;
        
    }
};
