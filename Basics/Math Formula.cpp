// an = a1 + (n - 1) * d ---> 1 3 5 7 9.... → a = 1, d = 2
ll incre_Nth_term(ll a, ll d, ll n) {
    return a + 1LL * (n - 1) * d;
}

// an = a1 - (n - 1) * d ---> 13 10 7 4... → a = 13, d = 3
ll decre_Nth_term(ll a, ll d, ll n) {
    return a - 1LL * (n - 1) * d;
}

// an = a * r^(n - 1) ---> 2 6 18 54 → a = 2, r = 3
ll geometric_nth_term(ll a, ll r, ll n) {
    return 1LL * a * big_mod(r, n - 1, 100000000); // mod-safe version
}
// 1 + 2 + ... + n ---> n(n+1)/2
ll sum_n(ll n) {
    return 1LL * n * (n + 1) / 2;
}

// 1 - 2 + 3 - 4 + 5 = 3
ll alt_sign_sum_start_pos(ll n) {
    return (n % 2 == 0) ? -n / 2 : (n + 1) / 2;
}

//  -1 + 2 - 3 + 4 - 5 = -3
ll alt_sign_sum_start_neg(ll n) {
    return (n % 2 == 0) ? n / 2 : -((n + 1) / 2);
}

// Sum of first n odd numbers: 1 + 3 + 5 + 7 ... --> n^2
ll sum_n_odd(ll n) {
    return 1LL * n * n;
}

// Sum of first n even numbers: 2 + 4 + 6 + ... ---> n(n+1)
ll sum_n_even(ll n) {
    return 1LL * n * (n + 1);
}

// Sum of squares: 1^2 + 2^2 + ... + n^2 --->  n(n+1)(2n+1)/6
ll sum_n_squares(ll n) {
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}

// Sum of cubes: 1^3 + 2^3 + ... + n^3 ---> (n(n+1)/2)^2
ll sum_n_cubes(ll n) {
    ll s = 1LL * n * (n + 1) / 2;
    return s * s;
}
