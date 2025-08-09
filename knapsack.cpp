#include<bits/stdc++.h> 
using namespace std; 
const int N = 105; 
#define int long long 
int n, W,w[N],v[N]; 
int dp[N][100005]; 
int rec(int i, int weight){ 
    if(i == n + 1) 
    return 0; 
    if(dp[i][weight] != -1) 
    return dp[i][weight]; 
    int ans = rec(i + 1, weight); 
    if(weight + w[i] <= W){ 
        ans = max(ans,rec(i+1, weight + w[i]) + v[i]); 
    } 
    return dp[i][weight] = ans; 
} 
int32_t main(){ 
    memset(dp, -1, sizeof(dp)); 
    cin >> n >> W; 
    for(int i = 1; i <= n; i++){ 
        cin >> w[i] >> v[i]; 
    } 
    cout << rec(1, 0) << "\n"; 
} 