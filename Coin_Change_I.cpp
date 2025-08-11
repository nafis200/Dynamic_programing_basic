// #include <bits/stdc++.h>
// using namespace std;
// const int N = 55;
// const int M = 1005;
// int dp[N][M];
// int n, k;
// int coin[N];
// int value[N];
// const int mod = 100000007;

// int coinchange(int i, int sum)
// {
//     if (i == n + 1)
//     {
//         if (sum == k)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     if (dp[i][sum] != -1)
//     {
//         return dp[i][sum];
//     }
//     int ans = 0;
//     ans += coinchange(i + 1, sum) % mod;
//     for (int c = 1; c <= value[i]; c++)
//     {
//         ans += coinchange(i + 1, (sum % mod + (c * coin[i]) % mod) % mod);
//         ans = ans % mod;
//     }
//     return dp[i][sum] = ans;
// }

// int main()
// {
//     int Case = 1;
//     int t;
//     cin >> t;
//     while (t--)
//     {
       
//         memset(dp, -1, sizeof(dp));
//         cin >> n >> k;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> coin[i];
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cin >> value[i];
//         }
//         cout << "Case " << Case << ": ";
//         cout << coinchange(1, 0) << "\n";
//         Case++;
//     }
// }


#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = 1005;
int dp[N][M];
int n, k;
int coin[N];
int value[N];
const int mod = 100000007;

int main()
{
    int Case = 1;
    int t;
    cin >> t;
    while (t--)
    {
       
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> coin[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> value[i];
        }
        cout << "Case " << Case << ": ";
        dp[n + 1][k] = 1;
        for(int i = n; i >= 1; i--){
            for(int sum = k; sum >= 0; sum--){
                dp[i][sum] += dp[i + 1][sum]; 
                for(int c = 1; c <= value[i]; c++){
                    dp[i][sum] += dp[i + 1][sum % mod + (c * coin[i]) % mod] % mod;
                }
            }
        }
        cout << dp[1][0] << "\n";
        Case++;
    }
}
