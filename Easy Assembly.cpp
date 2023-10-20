#include <bits/stdc++.h>
using namespace std;

struct num
{
    int x, y, number, index;
};

bool rule(num a, num b)
{
    return a.number > b.number;
}

int main()
{
    int n,n_t;
    cin >> n;
    n_t = n;
    vector <num> sorted;
    while (n--)
    {
        int length_t = 0;
        cin >> length_t;
        while (length_t--)
        {
            num input;
            cin >> input.number;
            input.x = n; input.y = length_t;
            sorted.push_back(input);
        }
    }
    sort(sorted.begin(), sorted.end(), rule);
    map <int, map<int, num>> tower;
    map <int, map<int, num>>::iterator it_x;
    map<int, num>::iterator it_y;
    int s = 0, c = 0;
    for (int i = 0; i < sorted.size(); i++)
    {
        sorted[i].index = i;
        tower[sorted[i].x][sorted[i].y] = sorted[i];
    }
    for (it_x = tower.begin(); it_x != tower.end(); it_x++)
    {
        for (it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
        {
            auto it_temp = it_y;
            if (it_y != it_x->second.end())
            {
                it_temp++;
                if (it_temp != it_x->second.end())
                {
                    if (it_temp->second.index - it_y->second.index != 1)
                    {
                        s++;
                    }
                }
            }
        }
    }
    cout << s << " " << n_t + s - 1 << endl;
}