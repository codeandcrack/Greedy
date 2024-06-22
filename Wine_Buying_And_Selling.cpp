#include <bits/stdc++.h>
using namespace std;
long long int wineSelling(vector<int> &Arr, int N)
{
    long long int buyer = 0, seller = 0;
    long long int ans = 0;
    while (buyer < N and seller < N)
    {
        while (buyer < N and Arr[buyer] <= 0)
        {
            buyer++;
        }

        while (seller < N and Arr[seller] >= 0)
        {
            seller++;
        }

        if (buyer == N or seller == N)
        {
            break;
        }

        long long int diff = abs(buyer - seller);

        if (Arr[buyer] == abs(Arr[seller]))
        {
            ans += diff * Arr[buyer];
            Arr[buyer] = 0;
            Arr[seller] = 0;
        }
        else if (Arr[buyer] > abs(Arr[seller]))
        {
            ans += diff * abs(Arr[seller]);
            Arr[buyer] = Arr[buyer] - abs(Arr[seller]);
            Arr[seller] = 0;
        }
        else
        {
            ans += diff * Arr[buyer];
            Arr[seller] = (abs(Arr[seller]) - Arr[buyer]) * (-1);
            Arr[buyer] = 0;
        }
    }

    return ans;
}
int32_t main()
{
    vector<int> Arr{5, -4, 1, -3, 1};

    long long int ans = wineSelling(Arr, Arr.size());

    cout << "Ans: " << ans << endl;
}