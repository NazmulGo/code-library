ll SumOfDivisors(ll n) {
    ll ans = 1;
    for(int i=0; i<primes.size(); i++) {
        if(1LL * primes[i] * primes[i] > n) break;
        if(n % primes[i] == 0) {
            ll pwr = 1, sum = 1;
            while(n % primes[i] == 0) {
                n /= primes[i];
                pwr *= primes[i];
                sum += pwr;
            }
            ans *= sum;
        }
    }
    if(n > 1) ans *= (n+1);
    return ans;

}

