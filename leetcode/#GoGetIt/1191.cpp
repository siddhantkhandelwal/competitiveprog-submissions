class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        long result = 0, cur_max = 0, sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++)
        {
            cur_max = max(cur_max + arr[i], (long)arr[i]);
            result = max(result, cur_max);
            sum += arr[i];
        }

        if (k < 2)
            return result % M;

        if (sum > 0)
            return (result + (k - 1) * sum) % M;

        for (int i = 0; i < arr.size(); i++)
        {
            cur_max = max(cur_max + arr[i], (long)arr[i]);
            result = max(result, cur_max);
        }

        return result % M;
    }
};