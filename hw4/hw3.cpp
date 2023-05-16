#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    int b;
    int diff;
    int min_;
    node(int f, int s)
    {
        a = f;
        b = s;
        diff = abs(f - s);
        min_ = min(f, s);
    }
};

bool cmp(node *a, node *b)
{
    return a->diff > b->diff;
}

struct mycmp
{
    bool operator()(node *a, node *b)
    {
        return a->diff > b->diff;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    // vector<node *> v;
    // for (int i = 0; i < n; ++i)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     node *temp = new node(a, b);
    //     v.push_back(temp);
    // }

    // vector<node *> a, b;
    priority_queue<node *, vector<node *>, mycmp> pa, pb;
    int ca = 0, cb = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        node *temp = new node(a, b);
        if (a < b)
        {
            pa.push(temp);
            ca++;
        }
        // a.push_back(temp);
        else
        {
            pb.push(temp);
            cb++;
        }
        // b.push_back(temp);
    }

    while (ca < n / 2)
    {
        pa.push(pb.top());
        ca++;
        pb.pop();
        cb--;
    }
    while (cb < n / 2)
    {
        pb.push(pa.top());
        cb++;
        pa.pop();
        ca--;
    }

    long long sum = 0;
    while (!pb.empty())
    {
        sum += pb.top()->b;
        pb.pop();
    }
    while (!pa.empty())
    {
        sum += pa.top()->a;
        pa.pop();
    }

    cout << sum << "\n";

    return 0;
}