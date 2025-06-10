vector<bool> isPrime(N+1, true);
vector<ll> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(ll i=0; i*i<N; i++) {
        if(isPrime[i]) {
            for(int j = i+i; j<N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=N; i++) {
       if(isPrime[i]) primes.push_back(i);
    }
}
