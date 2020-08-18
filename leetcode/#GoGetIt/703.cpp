class KthLargest
{
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        kth = k;
        for (auto num : nums)
        {
            pq.push(num);
            if (pq.size() > kth)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > kth)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */