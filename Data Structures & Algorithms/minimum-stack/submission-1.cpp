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


// =========================================================================================


// Approach 2 using 2 stacks

// #include<bits/stdc++.h>
// class MinStack{
// public:
//     MinStack(){}

//     stack<int> MainStack;
//     stack<int> minStack;

//     void push(int val){
//         MainStack.push(val);
//         if(minStack.empty() || val<=minStack.top() ){
//             minStack.push(val);
//         }
//     }

//     void pop(){

//         if(!MainStack.empty()){
//             if(minStack.top() == MainStack.top()){
//                 minStack.pop();
//             }
//             MainStack.pop();
//         }
//     }

//     int top(){
//         return MainStack.top();
//     }

//     int getMin(){
//         return minStack.top();
//     }
// };

//=================================================================================================

// Optimal Solution 

#include<bits/stdc++.h>
class MinStack{
public:
    MinStack(){}

    stack<long long> st;
    long long mini = INT_MAX;

    void push(int val){
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else if( val< mini){
            st.push(2LL * val - mini);   //ENCODE
            mini = val;
        }
        else{
            st.push(val);
        }
    }

    void pop(){
        if(st.empty()){
            return ;
        }

        long long top = st.top();
        st.pop();

     if( top < mini){
            mini = 2LL * mini - top;
        }
    }

   int top() {
        if (st.empty()) {
            return -1;
        }

        long long top = st.top();

        if (top < mini) {
            return static_cast<int>(mini);
        }
        return static_cast<int>(top);
    }

    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return static_cast<int>(mini);
    }
};
