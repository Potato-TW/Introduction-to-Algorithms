#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int t, stu, cap, comb;
vector<int> path;
vector<vector<bool>> avail;
vector<int> avail_time;
vector<int> flow;
vector<vector<bool>> v;
bool booooo(int i, vector<bool> &is_visit)
{
    int flag = false;
    if (path[i] != -1)
        flag = true;
    for (int index = 0; index < avail_time.size(); ++index)
    {
        int time = avail_time[index];
        if (is_visit[time] || !avail[i][time])
            continue;
        is_visit[time] = true;
        if (flow[time] < cap)
        {
            v[time][i] = true;
            ++flow[time];
            if (flag)
            {
                v[path[i]][i] = false;
                --flow[path[i]];
            }
            path[i] = time;
            return true;
        }
        for (int j = 0; j < v[time].size(); ++j)
        { // every student using the time
            if (v[time][j])
            {
                if (booooo(j, is_visit))
                {
                    v[time][i] = true;
                    ++flow[time];
                    if (flag)
                    {
                        v[path[i]][i] = false;
                        --flow[path[i]];
                    }
                    path[i] = time;
                    return true;
                }
            }
        }
    }
    return false;
}
int max_floooow(void)
{
    for (int i = 0; i < path.size(); i++)
        path[i] = -1;
    for (int i = 0; i < flow.size(); i++)
        flow[i] = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            v[i][j] = false;
    }
    for (int i = 0; i < stu; ++i)
    {
        vector<bool> temp(t, false);
        bool v = booooo(i, temp);
    }
    int sum = 0;
    for (auto it : flow)
        sum += it;
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> t >> stu >> cap >> comb)
    {
        v.clear();
        v.resize(t);
        path.clear();
        path.resize(stu);
        flow.clear();
        flow.resize(t);
        avail.clear();
        avail.resize(stu);
        for (int i = 0; i < t; ++i)
            v[i].resize(stu);
        for (int i = 0; i < stu; ++i)
            avail[i].resize(t);
        for (int i = 0; i < stu; ++i)
            for (int j = 0; j < t; ++j)
                avail[i][j] = false;
        for (int _ = 0; _ < stu; ++_)
        {
            int i, n;
            cin >> i >> n;
            for (int j = 0; j < n; ++j)
            {
                int temp;
                cin >> temp;
                avail[i][temp] = true;
            }
        }
        for (int _ = 0; _ < comb; ++_)
        {
            int n;
            cin >> n;
            avail_time.clear();
            for (int __ = 0; __ < n; ++__)
            {
                int t;
                cin >> t;
                avail_time.push_back(t);
            }
            cout << stu - max_floooow() << endl;
            /*for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v[i].size(); j++)
                    cout << v[i][j] << " ";
                cout << endl;
            }
            for (auto it : flow) cout << it << " ";
            cout << endl;*/
        }
    }
    return 0;
}