class Solution
{
    struct TrieNode
    {
        TrieNode *children[26];
        string word;

        TrieNode()
        {
            word = "";
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size();
        int len = words.size();
        if (!m || !len)
        {
            return {};
        }
        int n = board[0].size();
        if (!n)
        {
            return {};
        }
        TrieNode *root = buildTrie(words);
        vector<string> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            TrieNode *cur = root;
            for (int j = 0; j < word.length(); j++)
            {
                char c = word[j] - 'a';
                if (cur->children[c] == NULL)
                {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> board, int i, int j, TrieNode *node, vector<string> &result)
    {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a'])
        {
            return;
        }
        node = node->children[c - 'a'];
        if (node->word.size() > 0)
        {
            result.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, node, result);
        if (j > 0)
            dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, node, result);
        board[i][j] = c;
    }
};