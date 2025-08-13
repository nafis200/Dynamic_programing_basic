#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][100006];
int a[N];
int n, x;
const int inf = 1e8;
int minimise_coin(int i, int sum)
{
    if (i == n + 1)
    {
        if (sum == x)
        {
            return 0;
        }
        return inf;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    int ans = minimise_coin(i + 1, sum);
    if (sum + a[i] <= x)
    {
        ans = min(ans, minimise_coin(i, sum + a[i]) + 1);
    }
    return dp[i][sum] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = minimise_coin(1, 0);
    cout << ans << "\n";
}