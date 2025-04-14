void primeFactors(ll n)
{
   vll fact;
   for(int i=0; i<primes.size(); i++)
   {
       if(1LL * primes[i] * primes[i] > n) break;
       if(n % primes[i] == 0)
       {
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                fact.pb(primes[i]);
            }
       }
   }
   if(n > 1) fact.pb(n);
}
