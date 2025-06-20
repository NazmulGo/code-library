//Knapsack (use ith index only 1 time) 
ll ways(ll pos, ll sum) {
    if(n == 0) {
        if(sum == 0) return 1;
        else return 0;
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];
    if(sum >= v[pos - 1]) return dp[pos][sum] = (ways(pos - 1, sum - v[pos - 1]) + ways(pos - 1, sum));
    else return dp[pos][sum] = ways(pos - 1, sum);
}

//unbounded Knapsack (use ith index multiple time)
ll ways(ll pos, ll sum) {
    if(n==0) {
        if(sum == 0) return 1;
        else return 0;
    }
    if( dp[pos][sum] != -1) return dp[pos][sum];
    if(sum >= v[pos-1]) return dp[pos][sum] = (ways(pos, sum - v[pos-1]) + ways(pos - 1, sum));
    else return dp[pos][sum] = ways(pos - 1, sum);
}
