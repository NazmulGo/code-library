    
     // 6 2
     //zabfzz
     // ans : abfz

    ll n, k; cin >> n >> k;
    string s; cin >> s;
    
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(k == 0 || st.empty() || st.top() <= s[i]) {
            st.push(s[i]);
        }
        else{
            while( 1 ) {
                if(k && st.size() && st.top() > s[i]) {
                    st.pop();
                    k--;
                }
                else break;
            }
            st.push(s[i]);
        }
    }
 
    string ans_string;
    while(!st.empty()) {
        ans_string.push_back(st.top());
        st.pop();
    }

    reverse(all(ans_string));
 
    if(k) {
        while(k) {
            ans_string.pop_back();
            k--;
        }
    }   
    cout << ans_string << endl; 
