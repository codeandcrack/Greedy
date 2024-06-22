bool find(vector<int> &vec, int num)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == num)
        {
            return true;
        }
    }

    return false;
}
void erase(vector<int> &vec, int num)
{
    int idx = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == num)
        {
            idx = i;
            break;
        }
    }

    vec.erase(vec.begin() + idx);
    return;
}
int pageFaults(int N, int C, int pages[])
{

    vector<int> vec;

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        bool finder = find(vec, pages[i]);

        if (finder)
        {
            erase(vec, pages[i]);
        }
        else
        {
            if (vec.size() >= C)
            {
                vec.erase(vec.begin());
            }

            ans++;
        }
        vec.push_back(pages[i]);
    }

    return ans;
}