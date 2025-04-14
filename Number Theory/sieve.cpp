vector<bool> isPrime(N+1, true);
vll primes;

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    ll sq = sqrt(N);
    for(int i=0; i<=sq; i++)
    {
        if(isPrime[i])
        {
            for(int j = i+i; j<=N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=N; i++)
    {
       if(isPrime[i]) primes.pb(i);
    }
}
