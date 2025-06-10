vector<ll> cnt(N+1);

void Hermonic() {
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j+=i) {
            cnt[j]++;
        }
    }
}
