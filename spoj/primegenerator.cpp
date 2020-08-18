#include <bits/stdc++.h>

using namespace std;

bool prime[35001];
vector<int> primesLessThan35000;

void SieveOfEratosthenes(int n)
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool isPrime(int n)
{
    if (n <= 35000)
        return prime[n];
    int k = (int)sqrt((double)n);
    for (int i = 0; i < primesLessThan35000.size(); i++)
    {
        int u = primesLessThan35000[i];
        if (u > k)
            break;
        if (n % u == 0)
            return false;
    }
    return true;
}

int main()
{
    SieveOfEratosthenes(35000);
    primesLessThan35000.clear();
    for (int i = 2; i <= 35000; i++)
    {
        if (prime[i])
        {
            primesLessThan35000.push_back(i);
        }
    }
    int t, m, n;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        cin >> m;
        cin >> n;
        for (int i = m; i <= n; i++)
        {
            if (isPrime(i))
            {
                printf("%d\n", i);
            }
        }
        if (z != t - 1)
            printf("\n");
    }
}