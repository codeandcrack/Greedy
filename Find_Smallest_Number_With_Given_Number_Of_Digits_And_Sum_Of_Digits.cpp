string smallestNumber(int S, int D)
{
    vector<int> vec(D, 0);

    vec[vec.size() - 1] = 1;

    int sum = 1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (sum == S)
        {
            break;
        }
        for (int j = 1; j <= 9; j++)
        {
            sum -= vec[i];
            sum += j;
            vec[i] = j;
            if (sum == S)
            {
                break;
            }
        }
    }

    if (sum != S)
    {
        return "-1";
    }
    else
    {
        string ans = "";

        for (int i = vec.size() - 1; i >= 0; i--)
        {
            ans += to_string(vec[i]);
        }

        return ans;
    }
}