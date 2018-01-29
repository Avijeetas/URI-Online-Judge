#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  long long u, v;
  long long w;
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const long long MN = 200000;
long long p[MN];

long long fs(long long x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

long long js(long long x, long long y) {
  if (fs(x) == fs(y)) return false;
  p[fs(x)] = fs(y);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;
  while (cin >> n >> m && (n + m)) {
    vector<edge> e(m);
    for (auto &i : e) cin >> i.u >> i.v >> i.w;
    for (long long i = 0; i < n; ++i) p[i] = i;
    sort(e.begin(), e.end());
    long long ans = 0;
    for (auto &i : e)
      if (js(i.v, i.u)) ans += i.w;
    cout << ans << endl;
  }
  return 0;
}