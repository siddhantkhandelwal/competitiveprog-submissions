#include "bits/stdc++.h"

using namespace std;

int main()
{
    vector<int> yr = {2010, 2015, 2016, 2017, 2019};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (binary_search(yr.begin(), yr.end(), n))
        {
            cout << "HOSTED" << endl;
        }
        else
        {
            cout << "NOT HOSTED" << endl;
        }
    }
    return 0;
}