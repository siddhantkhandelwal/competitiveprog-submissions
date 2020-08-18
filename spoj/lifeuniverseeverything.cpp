#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 42)
        {
            break;
        }
        printf("%d\n", n);
    }
    return 0;
}