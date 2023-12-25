#include <bits/stdc++.h>

using namespace std;

/*********************************** ShortCuts for basic things ***********************************/
/**************************** Variable Shortcuts ****************************/
#define LL long long
#define UL unsigned long
#define ULL unsigned long long
#define LD long double
#define PII pair<int, int>
#define PLLLL pair<LL, LL>
#define VI vector<int>
#define VB vector<bool>
#define VD vector<double>
#define VLL vector<LL>
#define USET unordered_set
#define UMAP unordered_map
/**************************** Inbuilt Function Shortcuts ****************************/
#define LB lower_bound
#define UB upper_bound
/**************************** Common Function Shortcuts ****************************/
#define SIZE(x) ((int)x.size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, start, endExc, inc) for (int i = start; i < endExc; i += inc)
#define RFOR(i, start, endInc, dec) for (int i = start; i >= endInc; i -= dec)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FORI(itr, start, end) for (auto itr = start; itr != end; ++itr)
#define REPI(itr, obj) FORI(itr, ALL(obj))
#define FOREACH(it, l) for (auto const &it : l)
#define MFOREACH(it, l) for (auto &it : l)

/*********************************** Main Solution Starts Here ***********************************/
UMAP<int, LL>::iterator gitr;

LL getMaxVal(vector<VI> &adj, vector<UMAP<int, LL>> &umap, VI &score, int par, int k)
{
  gitr = umap[par].find(k);
  if (gitr != umap[par].end())
  {
    return gitr->second;
  }
  int noCh = adj[par].size();
  LL curScore = (LL)score[par] * k;
  if (noCh == 0)
  {
    return umap[par][k] = curScore;
  }
  int k1 = k / noCh;
  int k2 = k1 * noCh;
  if (k2 == k)
  {
    FOREACH(it, adj[par])
    {
      curScore += getMaxVal(adj, umap, score, it, k1);
    }
    return umap[par][k] = curScore;
  }
  VLL a(noCh), b(noCh), c(noCh);
  VI idx(noCh);
  iota(ALL(idx), 0);
  REP(i, noCh)
  {
    a[i] = getMaxVal(adj, umap, score, adj[par][i], k1);
    b[i] = getMaxVal(adj, umap, score, adj[par][i], k1 + 1);
    c[i] = b[i] - a[i];
  }
  sort(ALL(idx), [&c](const int &aa, const int &bb)
       { return c[aa] > c[bb]; });
  int ch3 = k - k2;
  REP(i, ch3) { curScore += b[idx[i]]; };
  FOR(i, ch3, noCh, 1) { curScore += a[idx[i]]; };
  return umap[par][k] = curScore;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n, k;
  cin >> n >> k;
  vector<VI> adj(n, VI());
  vector<UMAP<int, LL>> umap(n);
  int temp;
  REP(i, n - 1)
  {
    cin >> temp;
    adj[temp - 1].push_back(i + 1);
  }
  VI score(n);
  REP(i, n) { cin >> score[i]; }
  cout << getMaxVal(adj, umap, score, 0, k) << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
