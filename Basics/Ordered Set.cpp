// ORDERED SET : 

//// PBDS (Policy Based Data Structure - Ordered Set)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//oset <ll> s;  --> Declare ordered set
//s.order_of_key(val)  --> index of value val
//*(s.find_by_order(ind)) --> value at index ind
    oset<ll> s;
//-------------------------------------------------------------------------------------------------------------------------------

// ORDERED MULTI SET
//// PBDS (Policy Based Data Structure - Ordered Set)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//oset <ll> s;  --> Declare ordered set
//s.order_of_key(val)  --> index of value val
//*(s.find_by_order(ind)) --> value at index ind
   oset<ll> s;
