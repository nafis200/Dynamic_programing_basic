#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int dp[N][2][2];
int n;

int neighbour_house(int i, int previous_house, int first_house)
{
    if (i == n + 1)
    {
        return 0;
    }
    if (dp[i][previous_house][first_house] != -1)
    {
        return dp[i][previous_house][first_house];
    }
    int ans = neighbour_house(i + 1, 0, first_house);
    if (i == n)
    {
        if (previous_house != 1 && first_house != 1)
        {
            ans = max(ans, neighbour_house(i + 1, 1, first_house) + a[i]);
        }
    }
    else
    {
        if (i == 1 && first_house == 1)
        {
            ans = max(ans, neighbour_house(i + 1, 1, first_house) + a[i]);
        }
        else if (previous_house != 1)
        {
            ans = max(ans, neighbour_house(i + 1, 1, first_house) + a[i]);
        }
    }
    return dp[i][previous_house][first_house] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = neighbour_house(1, 0, 1);
    int ans1 = neighbour_house(1, 1, 0);
    cout << max(ans, ans1) << "\n";
}