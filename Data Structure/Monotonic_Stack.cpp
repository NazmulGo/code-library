// 1
vll NextGreterEle(vll &v) {  
    // stack decreasing
    ll n = v.size();
    vll ans(n);
    stack<ll> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && (st.top() <= v[i])) st.pop();
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(v[i]);
    } 
    return ans;
}
// 2
vll NextGreterEleIndex(vll &v) {  
    // stack decreasing
    ll n = v.size();
    vll ans(n);
    stack<ll> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && (v[st.top()] <= v[i])) st.pop();
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    } 
    return ans;
}
// 3
vll NextSmallerEle(vll &v) {  
    // stack Increasing
   ll n = v.size();
   vll ans(n);
   stack<ll> st;
   for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top() >= v[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(v[i]);
   }
   return ans;
}
// 4
vll NextSmallerEleIndx(vll &v) {  
    // stack Increasing
   ll n = v.size();
   vll ans(n);
   stack<ll> st;
   for(int i=n-1; i>=0; i--) {
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
   }
   return ans;
}
