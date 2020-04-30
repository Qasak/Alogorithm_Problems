#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;

struct edge {
    int l;
    int r;
};
set<edge> s;
set<edge>::iterator iter;
bool operator <(const edge& a, const edge& b)
{
    return a.r < b.l;
}

void merge(edge & temp)
{
    if ((iter = s.find(temp)) != s.end())
    {
      temp.l = min(temp.l, iter->l);
      temp.r = max(temp.r, iter->r);
      s.erase(iter);
      merge(temp);
    }
    else
    {
      s.insert(temp);
      return;
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      edge temp;
      cin >> temp.l >> temp.r;
      merge(temp);
      cout << (i?" ":"") << s.size();
    }
    return 0;
}
