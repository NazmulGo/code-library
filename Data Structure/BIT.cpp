#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()

template<typename T = int>
struct binary_index_tree {
	#define LSONE(x) ((x) & -(x))

	int N;
	vector<T> t;

	binary_index_tree() {}
    
	binary_index_tree(int n) {
        N = n;
		t.resize(N + 1);
	}

	binary_index_tree(vector<int>& arr) {
		N = int(arr.size());
		t.resize(N + 1);

		for (int i = 1; i <= N; i++)
			update(i, arr[i - 1]);
	}

	void update(int i, T x) {
		while (i <= N) {
			t[i] += x;
			i += LSONE(i);
		}
	}

	T query(int i) {
		T summ = 0;
		while (i > 0) {
			summ += t[i];
			i -= LSONE(i);
		}
		return summ;
	}

	void range_update(int l, int r, T x) {
		update(l, x);
		update(r + 1, -x);
	}
};

void solve() {
    ll n, q; cin >> n >> q;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    binary_index_tree<ll> BIT(arr);
    while (q--) {
        int idc, l, r, x;
        cin >> idc;

        if (idc == 1) {
            cin >> l >> x;
            BIT.update(l, -arr[l - 1]);
            arr[l - 1] = x;
            BIT.update(l, x);
        } 
        else {
            cin >> l >> r;
            cout << BIT.query(r) - BIT.query(l - 1) << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; //cin >> tc;
    while(tc--) {
        solve();
    }
}
