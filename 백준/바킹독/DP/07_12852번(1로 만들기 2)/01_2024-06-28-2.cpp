#include <iostream>
#include <stack>
using namespace std;

int n;
int d[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 0;
    for (int i = 2; i <= n; i++) 
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) 
        {
            d[i] = d[i / 2] + 1;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) 
        {
            d[i] = d[i / 3] + 1;
        }
    }

    cout << d[n] << '\n';

    stack<int> s;
    int cur = n;
    while (cur > 1)
    {
        s.push(cur);
        if (cur % 3 == 0 && d[cur] == d[cur / 3] + 1)
        {
            cur = cur / 3;
        }
        else if (cur % 2 == 0 && d[cur] == d[cur / 2] + 1) 
        {
            cur = cur / 2;
        }
        else 
        {
            cur = cur - 1;
        }
    }
    s.push(1);

    while (!s.empty()) 
    {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
