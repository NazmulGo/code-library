ll fact[N], i_fact[N];
ll MOD = 1e9+7;

ll bigmod(ll a, ll b, ll mod) {
   ll ans = 1;
   while(b) {
   if(b & 1) ans = (ans * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
   }
   return ans;
}

void factorial() {
    fact[0] = 1;
    for(int i=1; i<N; i++) {
        fact[i] = (1ll * fact[i-1] * i) % MOD;    
    }

    i_fact[N-1] = bigmod(fact[N-1], MOD-2, MOD);
    for(int i=N-2; i>=0; i--) {
        i_fact[i] = (1ll * i_fact[i+1] * (i+1)) % MOD;
    }
}

ll nCr(ll n, ll r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * (i_fact[r] * i_fact[n-r] % MOD) % MOD;
}

ll nPr(ll n, ll r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * i_fact[n-r] % MOD;
}
