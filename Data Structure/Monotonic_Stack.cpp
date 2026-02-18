vll NextGreterEle(vll &v) {  
    // stack design Decreasing  (Down to Up)
    ll n = v.size();
    vll ans(n);
    stack<ll> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && (st.top() <= v[i])) {
            st.pop();
        }
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(v[i]);
    } 

    return ans;
}
