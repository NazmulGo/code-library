

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct chash {
    const int random=(long long int)(make_unique<char>().get())
        ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long splitmix64(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    int operator()(int x) const {
        return splitmix64(x+random);
    }
    int operator()(pair<int,int> x) const {
        unsigned num=(x.first^(x.second>>1));
        return splitmix64(num+random);
    }
    //for vector as key I can also do the similarl thing for lower collision
    long long operator()(string s) const {
        const int p = 31;  
        //for only lowercase p=31,for lowercase+uppercase p=53
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;

        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
};
//for int as key: unordered_map<int,int,chash>mp; / gp_hash_table<int,int,chash>mp;

//for pair<int,int> as key: unordered_map<pair<int,int>,int,chash>mp; / gp_hash_table<pair<int,int>,int,chash>mp;

//for string as key: unordered_map<string,int,chash>mp; / gp_hash_table<string,int,chash>mp;

