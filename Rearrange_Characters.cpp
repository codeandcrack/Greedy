string rearrangeString(string str)
{
    int n = str.length();
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
    }

    priority_queue<pair<int, char>> pq;

    for (auto x : mp)
    {
        pq.push({x.second, x.first});
    }

    string ans = "";
    while (pq.size() > 1)
    {
        pair<int, char> one = pq.top();
        pq.pop();
        pair<int, char> two = pq.top();
        pq.pop();

        ans += one.second;
        ans += two.second;

        one.first--;
        two.first--;

        if (one.first)
        {
            pq.push({one.first, one.second});
        }

        if (two.first)
        {
            pq.push({two.first, two.second});
        }
    }

    if (pq.size() == 1 and pq.top().first > 1)
    {
        return "-1";
    }

    if (pq.size() == 1 and pq.top().first == 1)
    {
        ans += pq.top().second;
    }

    return ans;
}