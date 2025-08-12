#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    long long n; cin >> n;
    long long a[n + 1];
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long p[n + 1] = {0};
    
    long long r[n + 1] = {0};
    for(long long i = 1; i <= n; i++){
        p[i] = p[i - 1] + a[i];
    }

    

    if(p[n] % 3){
        cout << "0" << "\n";
        return 0;
    }
    
    long long ans = 0;
    long long sum = p[n] / 3;

    for(long long i = 1; i <= n; i++){
        if(p[i] == sum){
            r[i] = 1;
        }
        r[i] = r[i] + r[i - 1];
    }

    for(long long j = 2; j < n; j++){
        if(p[j] == 2 * sum){
            ans += r[j - 1];
        }
    }
    cout << ans << "\n";
}