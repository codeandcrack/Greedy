#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;

        vector<int> wid, hei;

        wid.push_back(0);
        hei.push_back(0);

        for (int i = 0; i < n; i++)
        {
            int wd, ht;
            cin >> wd >> ht;
            wid.push_back(wd);
            hei.push_back(ht);
        }

        sort(wid.begin(), wid.end());
        sort(hei.begin(), hei.end());

        wid.push_back(w);
        hei.push_back(h);

        int maxw = 0, maxh = 0;

        for (int i = 1; i < wid.size(); i++)
        {
            maxw = max(maxw, wid[i] - wid[i - 1] - 1);
            maxh = max(maxh, hei[i] - hei[i - 1] - 1);
        }

        int ans = maxw * maxh;

        cout << ans << endl;
    }
}