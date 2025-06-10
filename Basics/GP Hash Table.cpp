#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
int main()
{
   gp_hash_table<ll, ll> mp;
   mp[10] =1;
   mp[20] = 9;
   mp[30] = 90;
   for(auto u : mp)
   {
      cout << u.first << " : " << u.second << endl;
   }
}
