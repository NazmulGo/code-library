ll n; cin >> n;
ll score = 0;
ll sq = sqrt(n);
for(int i=1; i<= sq; i++)
{
    ll contri_i = (n/i) - i;
    score += contri_i;
}
score *= 2;
score += sq;
cout << score << endl;
