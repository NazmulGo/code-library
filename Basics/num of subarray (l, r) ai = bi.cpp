 ll ans = 0, len = 0;

    for(int i=0; i<n; i++) {
        if(a[i] == b[i]) {
            len++;
            ans += len;
        }
        else len = 0;
    }
