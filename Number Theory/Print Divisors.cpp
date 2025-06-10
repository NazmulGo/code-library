void solve()
{
   vll arr[N+1];
   for(int i=1; i*i<= N; i++) {
      for(int j=i*i; j <= N; j+=i) {
         arr[j].pb(i);
         if( (j / i) != i) {
            arr[j].pb(j/i);
        }
      }
   }

   for(int i=1; i<=100; i++) {
    cout << i << ": ";
    for(int j=0; j<arr[i].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
   }
}
