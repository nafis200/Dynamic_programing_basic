#include<bits/stdc++.h> 
using namespace std; 
const int N = 2e5 + 9; 
struct seg{ 
    int l, r, reward; 
}a[N]; 
#define ll long long 
ll dp[N]; 
ll pref[N]; 
int32_t main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin >> n; 
    for(int i = 1; i <= n; i++){ 
        cin >> a[i].l >> a[i].r >> a[i].reward; 
    } 
    // cout << "before sort " << "\n"; 
    // for(int i = 1; i <= n; i++){ 
    //     cout << a[i].l << " " << a[i].r << " " << a[i].reward << "\n"; 
    // } 
    // cout << "after sort " << "\n"; 
    sort(a + 1, a + n + 1, [&](seg x, seg y){ 
           return x.r < y.r; 
    }); 
    //  for(int i = 1; i <= n; i++){ 
    //  cout << a[i].l << " " << a[i].r << " " << a[i].reward << "\n"; 
    // } 
    for(int i = 1; i <= n; i++){ 
          dp[i] = a[i].reward; 
          ll mx = 0; 
        //   for(int j = i - 1; j >= 1; j--){ 
        //     if(a[j].r < a[i].l){ 
        //         dp[i] = max(dp[i], dp[j] + a[i].reward); 
        //     } 
        //   } 
        int l = 1, h = i - 1, j = 0; 
        while(l <= h){ 
            int mid = (l + h) / 2; 
            if(a[mid].r < a[i].l){ 
                j = mid; 
                l = mid + 1; 
            } 
            else 
            h = mid - 1; 
        } 
        mx = pref[j]; 
        mx += a[i].reward; 
        dp[i] = max(dp[i], mx); 
        pref[i] = max(pref[i - 1], dp[i]); 
    } 
    ll ans = 0; 
    for(int i = 1; i <= n; i++){ 
        ans = max(ans, dp[i]); 
    } 
 
    cout << ans << "\n"; 
}