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
int getAnswer(VLL &arr, int n)
{
  int ans{1};
  for (int i{0}; i < n; ++i)
  {
    UMAP<LL, int> umap;
    UMAP<LL, int>::iterator itr;
    for (int j{i + 1}; j < n; ++j)
    {
      LL diff = arr[j] - arr[i];
      for (LL k = 1; k * k <= diff; ++k)
      {
        if (diff % k != 0)
          continue;
        LL l = diff / k;
        if ((k & 1) != (l & 1))
          continue;
        LL a = (k + l) >> 1;
        LL b = l - a;
        if (a > b)
          swap(a, b);
        LL toInstert = a * a - arr[i];
        if (toInstert < 0)
          continue;
        itr = umap.find(toInstert);
        if (itr != umap.end())
        {
          ++itr->second;
        }
        else
        {
          umap.insert({toInstert, 2});
        }
      }
    }
    for (auto &it : umap)
    {
      if (it.second > ans)
        ans = it.second;
    }
  }
  return ans;
}

/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n;
  cin >> n;
  VLL arr(n);
  REP(i, n) { cin >> arr[i]; }
  cout << getAnswer(arr, n) << '\n';
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
