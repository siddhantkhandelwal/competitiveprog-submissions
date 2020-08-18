#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t)
    {
        stack<char> s;
        char c;
        while ((c = getchar()) != '\n')
        {
            if (c == '(')
            {
                continue;
            }
            else if (c == ')')
            {
                if (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                s.push(c);
            }
            else
            {
                cout << c;
            }
        }
        while (!s.empty())
        {
            s.pop();
        }
        cout << "\n";
        t--;
    }
    return 0;
}