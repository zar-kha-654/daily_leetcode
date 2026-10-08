class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {

    }
    void push(int value) {
        //always store the normal stack 
        st.push(value);
        //what about the minimum one, when it's pushed/
        if(minst.empty() || value<=minst.top()){
            minst.push(value);
        }
    }
    
    void pop() {
        // what you want to remove
        //firstly the values of minst when st is also minst
        if(minst.top() == st.top()){
            minst.pop();
        }
        //always remove the top value from normal string
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */