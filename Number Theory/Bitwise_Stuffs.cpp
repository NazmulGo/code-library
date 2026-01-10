#define ONBIT(x, k) ((x) | (1ll << k))
#define OFFBIT(x, k) ((x) & (~ (1ll << k)))
#define ONOROFF(x, k) ((x) & (1ll << k))
#define FLIPBIT(x, k) ((x) ^ (1ll << k))
 
int pop_count(int x) { return __builtin_popcount(x); }
int pop_countll(ll x) { return __builtin_popcountll(x); }
int MSB_index(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int MSB_indexll(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int LSB_index(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int LSB_indexll(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
