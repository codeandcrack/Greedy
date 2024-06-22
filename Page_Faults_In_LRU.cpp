int pageFaults(int N, int C, int pages[])
{

    deque<int> dq;

    int pf = 0;

    for (int i = 0; i < N; i++)
    {
        auto it = find(dq.begin(), dq.end(), pages[i]);
        if (it != dq.end())
        {
            dq.erase(it);
        }
        else
        {
            if (dq.size() >= C)
            {
                dq.pop_front();
            }
            pf++;
        }
        dq.push_back(pages[i]);
    }

    return pf;
}

int32_t main()
{
    int N = 9, C = 4;

    vector<int> pages{5, 0, 1, 3, 2, 4, 1, 0, 5};

    cout << pageFaults(N, C, pages.data()) << endl;
}