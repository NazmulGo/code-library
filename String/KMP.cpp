//https://cses.fi/alon/task/1753
#include <bits/stdc++.h>
using namespace std;

int kmp(string s, string t) {
    vector<int> lps(t.size(), 0);
    for (int i = 1, len = 0; i < t.size(); ) {
        if (t[i] == t[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }

    int ans = 0;
    for (int i = 0, j = 0; i < s.size(); ) {
        if (s[i] == t[j]) i++, j++;
        if (j == t.size()) ans++, j = lps[j - 1];
        else if (i < s.size() && s[i] != t[j]) j ? j = lps[j - 1] : i++;
    }

    return ans;
}

void solve() {
    string s, t;
    cin >> s >> t;
    cout << kmp(s, t) << endl;
}

int main() {
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}
