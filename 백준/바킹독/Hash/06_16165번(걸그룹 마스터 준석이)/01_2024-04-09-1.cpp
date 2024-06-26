#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, mems;
    string team, member;
    unordered_map<string, string> m2t;
    unordered_map<string, vector<string>> t2m;
    cin >> N >> M;
    while (N--)
    {
        cin >> team >> mems;
        while (mems--) 
        {
            cin >> member;
            m2t[member] = team;
            t2m[team].push_back(member);
        }
        sort(t2m[team].begin(), t2m[team].end());
    }

    string quiz;
    int c;
    while (M--) 
    {
        cin >> quiz >> c;
        if (c)
            cout << m2t[quiz] << '\n';
        else
            for (string m : t2m[quiz]) cout << m << '\n';
    }
}