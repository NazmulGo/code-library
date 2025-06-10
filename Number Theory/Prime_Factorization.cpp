vll primeFactors(ll n) {
   vector<ll> fact;
   for(int i=0; i<primes.size(); i++) {
       if(1LL * primes[i] * primes[i] > n) break;
       if(n % primes[i] == 0) {
            while(n % primes[i] == 0) {
                n /= primes[i];
                fact.push_back(primes[i]);
            }
       }
   }
   if(n > 1) fact.push_back(n);
   return fact;
}
