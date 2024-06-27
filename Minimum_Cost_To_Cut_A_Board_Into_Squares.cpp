int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());

    int row = 1, col = 1;

    int i = 0, j = 0;
    int ans = 0;
    while (i < X.size() and j < Y.size())
    {
        if (X[i] >= Y[j])
        {
            ans += X[i] * row;
            col++;
            i++;
        }
        else
        {
            ans += Y[j] * col;
            row++;
            j++;
        }
    }

    while (i < X.size())
    {
        ans += X[i] * row;
        col++;
        i++;
    }

    while (j < Y.size())
    {
        ans += Y[j] * col;
        row++;
        j++;
    }

    return ans;
}