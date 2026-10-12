class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(string token: tokens){
            if(token=="+"|| token== "-" || token=="*"||token=="/" ){
                //add second number  to the top 
                int b = st.top();
                st.pop();

                //add first number to the top
                int a = st.top();
                st.pop();

                //whenever the operand comes, place it between the numbers
                int result;
                if(token=="+"){
                    result = a+b;
                }
                else if(token=="-"){
                    result = a-b;
                }
                else if(token=="*"){
                    result = a*b;
                }
                else {
                    result = a/b;
                }

                //push the result to a stack and go on reading the string again and continue the process
                st.push(result);
            }
            else{
                //it's a number then 
                int num = stoi(token);
                //push it to stack
                st.push(num);
            }

        }
        return st.top();
    }
};