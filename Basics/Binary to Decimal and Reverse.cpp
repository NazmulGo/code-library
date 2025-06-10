ll binaryToDecimal(string &s) {
    ll ans = 0;
    ll base = 1; 

    for (ll i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            ans += base;
        }
        base *= 2;
    }
    return ans;
}

string decimalToBinary(ll n) {
    bitset<10> b(n);
    string s = b.to_string();
    return s;
}

