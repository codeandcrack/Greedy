int solve(int idx, vector<int> &nums, int total, int target)
{
    if (idx < 0)
    {
        if (total == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int pos = solve(idx - 1, nums, total + nums[idx], target);
    int neg = solve(idx - 1, nums, total - nums[idx], target);

    return pos + neg;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size() - 1;
    int total = 0;
    return solve(n, nums, total, target);
}