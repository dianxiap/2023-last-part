#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node
{
    int t1;
    int t2;

};

bool cmp(const Node& a, const Node& b)
{
    return a.t2 > b.t2;
}

vector<Node> multi(vector<Node> p1, vector<Node> p2)
{
    vector<Node> res;
    for (int i = 0; i < p1.size(); i++)
    {
        for (int j = 0; j < p2.size(); j++)
        {
            Node t;
            t.t1 = p1[i].t1 * p2[j].t1;
            t.t2 = p1[i].t2 + p2[j].t2;
            res.push_back(t);
        }
    }
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < res.size() - 1; i++)
    {
        if (res[i].t2 == res[i + 1].t2)
        {
            res[i + 1].t1 += res[i].t1;
            res[i].t1 = 0;
        }
    }
    return res;
}

vector<Node> add(vector<Node> p1, vector<Node> p2)
{
    vector<Node> res;
    int i = 0, j = 0;
    while (i < p1.size() || j < p2.size())
    {
        if (i >= p1.size() || (j<p2.size() && p2[j].t2>p1[i].t2))
        {
            res.push_back(p2[j]);
            j++;
        }
        else if (j >= p2.size() || (i<p1.size() && p2[j].t2<p1[i].t2))
        {
            res.push_back(p1[i]);
            i++;
        }
        else
        {
            Node t;
            t.t1 = p1[i].t1 + p2[j].t1;
            t.t2 = p1[i].t2;
            res.push_back(t);
            i++, j++;

        }
    }
    return res;
}

int main()
{
    vector<Node> v1, v2;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v1.push_back({ a,b });
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v2.push_back({ a,b });
    }

    vector<Node> res1 = multi(v1, v2);
    vector<Node> res2 = add(v1, v2);
    for (int i = 0; i < res1.size(); i++)
    {
        if (res1[i].t1 != 0)
        {
            cout << res1[i].t1 << " " << res1[i].t2;
            if (i < res1.size() - 1)cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < res2.size(); i++)
    {
        if (res2[i].t1 != 0)
        {
            cout << res2[i].t1 << " " << res2[i].t2;
            if (i < res2.size() - 1)cout << " ";
        }
    }
}
