// 1 to n all numbers divisors counts sum
ll SNOD(ll n) {
    ll score = 0;
    for(ll i=1; i*i <= n; i++) {
        ll contri_i = (n/i)-i;
        score += contri_i;
    }
    score * 2;
    score += sqrtl(n);
    return score;
}
