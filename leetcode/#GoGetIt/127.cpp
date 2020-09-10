class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto w = q.front();
                q.pop();
                if (w == endWord)
                {
                    return ladder;
                }
                for (int i = 0; i < w.length(); i++)
                {
                    char c = w[i];
                    for (int j = 0; j < 26; j++)
                    {
                        w[i] = j + 'a';
                        if (dict.find(w) != dict.end())
                        {
                            q.push(w);
                            dict.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};