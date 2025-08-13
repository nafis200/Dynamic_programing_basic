#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 1e9 + 7;
int n, dp[N][(N * (N + 1)) / 4];
int f(int i, int s)
{
    if (i == n + 1)
    {
        return s == 0;
    }
    int &ans = dp[i][s];
    if (ans != -1)
        return ans;
    ans = f(i + 1, s);
    if (s >= i)
    {
        ans += f(i + 1, s - i);
        ans = ans % mod;
    }
    return ans;
}
int power(int a, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans = (1LL * ans * a) % mod;
        }
        a = (1LL * a * a) % mod;
        p >>= 1;
    }
    return ans % mod;
}
int inverse(int x)
{
    return power(x, mod - 2);
}
int main()
{
    cin >> n;
    int tot = (n * (n + 1)) / 2;
    int sum_find = tot / 2;
    if (tot % 2)
    {
        cout << 0 << "\n";
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << 1LL * f(1, sum_find) * inverse(2) % mod << "\n";
}