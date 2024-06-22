deque<int> dq;

int ans = 0;

for (int i = 0; i < N; i++)
{
    auto it = find(dq.begin(), dq.end(), pages[i]);

    if (it == dq.end())
    {
        ans++;

        if (dq.size() == C)
        {
            dq.pop_front();
        }
    }
    else
    {
        dq.erase(it);
    }

    dq.push_back(pages[i]);
}

return ans;