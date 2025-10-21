//a to b and value (a <= b).
ll AtoB_And(ll x, ll y) {
    ll res = 0; // Initialize result
 
    while (x && y) {
        // Find positions of MSB in x and y
        int msb_p1 = MSB_indexll(x);
        int msb_p2 = MSB_indexll(y);
 
        // If positions are not same, return
        if (msb_p1 != msb_p2)
            break;
 
        // Add 2^msb_p1 to result
        ll msb_val =  (1ll << msb_p1);
        res = res + msb_val;
 
        // subtract 2^msb_p1 from x and y.
        x = x - msb_val;
        y = y - msb_val;
    }
 
    return res;
}



//a to b and (&) value (where a <= b).
ll AtoB_And(ll x, ll y) {
    ll ans = 0; 
    int msb_x = MSB_indexll(x);
    int msb_y = MSB_indexll(y);
   
    if (msb_x != msb_y) return 0;
 
    for(int i=msb_x; i>=0; i--) {
        if(((1LL << i) & x ) != ((1LL << i) & y)) break;
        if(((1LL << i) & x ) && ((1LL << i) & y)) ans += (1LL << i);
    }
 
    return ans;
}
