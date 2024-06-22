#include <bits/stdc++.h>
using namespace std;
#define int long long int
int dp[1001][1001];
int solve(int h, int a, string element)
{
    if (h <= 0 or a <= 0)
    {
        return 0;
    }

    if (dp[h][a] != -1)
    {
        return dp[h][a];
    }

    if (element == "a")
    {
        int first = 1 + solve(h - 5, a - 10, "w");
        int second = 1 + solve(h - 20, a + 5, "f");

        return dp[h][a] = max(first, second);
    }
    else
    {
        return dp[h][a] = 1 + solve(h + 3, a + 2, "a");
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int h, a;

        cin >> h >> a;
        memset(dp, -1, sizeof(dp));
        int ans = solve(h + 3, a + 2, "a");

        cout << ans << endl;
    }
}