#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }

        int oneCount = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 1)
            {
                oneCount++;
            }
        }

        sort(vec.begin(), vec.end());

        vector<int> ans;

        for (int i = 0; i < oneCount; i++)
        {
            ans.push_back(1);
        }

        if (n - oneCount == 2 and vec[oneCount] == 2 and vec[oneCount + 1] == 3)
        {
            ans.push_back(2);
            ans.push_back(3);
        }
        else
        {
            for (int k = vec.size() - 1; k >= 0 and vec[k] != 1; k--)
            {
                ans.push_back(vec[k]);
            }
        }

        for (auto x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }
}