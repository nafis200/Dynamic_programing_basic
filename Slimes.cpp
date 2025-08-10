#include<bits/stdc++.h>
using namespace std;
const int N = 420;
long long a[N];
long long pref[N];
long long dp[N][N];

long long Smiles(long long l, long long r){
     if(l == r){
        return 0;
     }
     if(dp[l][r] != -1){
        return dp[l][r];
     }
     long long ans = 1e17;
     long long sum = pref[r] - pref[l - 1];
     for(int i = l; i < r; i++){
        ans = min(ans, sum + Smiles(l, i) + Smiles(i + 1, r));
     }
     return dp[l][r] = ans;
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
         cin >> a[i];
    }
    pref[0] = 0;

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    cout << Smiles(1, n) << "\n";

}