class Solution
{
public:
    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        unordered_map<int, int> mp;
        for (auto a : A)
        {
            mp[a]++;
        }
        for (auto b : B)
        {
            mp[b]++;
        }
        vector<int> reqNo;
        for (auto m : mp)
        {
            if (m.second >= n)
            {
                reqNo.push_back(m.first);
            }
        }
        mp.clear();
        if (reqNo.size() == 0)
        {
            return -1;
        }
        int minRot = INT_MAX;
        for (auto r : reqNo)
        {
            int t = 0;
            int i;
            for (i = 0; i < A.size(); i++)
            {
                if (A[i] != r)
                {
                    if (B[i] == r)
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (i == A.size())
                minRot = min(minRot, t);
        }
        for (auto r : reqNo)
        {
            int t = 0;
            int i;
            for (i = 0; i < B.size(); i++)
            {
                if (B[i] != r)
                {
                    if (A[i] == r)
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (i == B.size())
                minRot = min(minRot, t);
        }
        if (minRot == INT_MAX)
        {
            return -1;
        }
        return minRot;
    }
};