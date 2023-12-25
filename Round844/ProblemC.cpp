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
int getMinCh(VI &arr, int n)
{
  VI sarr = arr;
  sort(ALL(sarr), greater<int>());
  int nch{min(26, n)};
  int minCh{n - sarr[0]}, ich{1};
  FOR(i, 2, nch + 1, 1)
  {
    if (n % i != 0)
      continue;
    int len{n / i};
    int changes{0};
    int exLen{0};
    int j{0};
    while (sarr[j] >= len)
    {
      ++j;
    }
    for (; j < i; ++j)
    {
      changes += len - sarr[j];
    }
    changes += exLen;
    if (minCh > changes)
    {
      minCh = changes;
      ich = i;
    }
  }
  cout << minCh << '\n';
  return ich;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  VI arr(26, 0);
  REP(i, n)
  {
    ++arr[str[i] - 'a'];
  }
  int minCh{getMinCh(arr, n)};
  if (minCh == 0)
  {
    cout << str << '\n';
    return;
  }
  int len = n / minCh;
  VI ind(26);
  iota(ALL(ind), 0);
  sort(ALL(ind), [&arr](int a, int b)
       { return arr[a] > arr[b]; });
  USET<int> uset;
  VI req(26, 0), done(26, 0);
  queue<int> qu;
  REP(i, minCh)
  {
    uset.insert(ind[i]);
    if (arr[ind[i]] < len)
    {
      req[ind[i]] = len - arr[ind[i]];
      qu.push(ind[i]);
    }
  }
  REP(i, n)
  {
    int chin = str[i] - 'a';
    if (uset.find(chin) != uset.end() && done[chin] < len)
    {
      ++done[chin];
      cout << str[i];
    }
    else
    {
      cout << (char)(qu.front() + 'a');
      --req[qu.front()];
      if (req[qu.front()] == 0)
      {
        qu.pop();
      }
    }
  }
  cout << '\n';
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
