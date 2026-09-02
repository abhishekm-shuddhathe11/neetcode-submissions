#include<bits/stdc++.h>
class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int, int>> st;

    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else {
            st.push( {val , min(st.top().second , val) } );
        }
    }
    
    void pop() {
        return st.pop();
    }
    
    int top() {
        if(st.empty())
        return -1;
        else{
            return st.top().first;
        }
    }
    
    int getMin() {
        return st.top().second;
    }
};
