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

void fillProfList(int n, int m, VI &arr, vector<VI> &profList)
{
  REP(i, n)
  {
    int j = 1;
    for (; j * j < arr[i]; ++j)
    {
      if (arr[i] % j != 0)
      {
        continue;
      }
      int j2 = arr[i] / j;
      if (j2 <= m)
      {
        profList[j2].push_back(arr[i]);
      }
      if (j <= m)
      {
        profList[j].push_back(arr[i]);
      }
    }
    if (j * j == arr[i] && j <= m)
    {
      profList[j].push_back(arr[i]);
    }
  }
}

int solve(int n, int m, VI &arr)
{
  if (m == 1)
  {
    return 0;
  }
  sort(ALL(arr));

  vector<VI> profList(m + 1);
  fillProfList(n, m, arr, profList);

  auto pComp = [&profList](const PII &a, const PII &b)
  {
    return profList[a.second][a.first] > profList[b.second][b.first];
  };
  priority_queue<PII, vector<PII>, decltype(pComp)> pqu(pComp);

  int minn = INT_MAX, maxx = INT_MIN;

  for (int i{1}; i <= m; ++i)
  {
    if (profList[i].size() == 0)
      return -1;
    if (profList[i].front() < minn)
    {
      minn = profList[i].front();
    }
    if (profList[i].front() > maxx)
    {
      maxx = profList[i].front();
    }
    pqu.push({0, i});
  }

  int ans = maxx - minn;

  PII tempqu;
  while (pqu.size() == m)
  {
    tempqu = pqu.top();
    pqu.pop();
    ++tempqu.first;
    if (profList[tempqu.second].size() > tempqu.first)
    {
      pqu.push({tempqu.first, tempqu.second});
      minn = profList[pqu.top().second][pqu.top().first];
      if (maxx < profList[tempqu.second][tempqu.first])
      {
        maxx = profList[tempqu.second][tempqu.first];
      }
      ans = min(ans, maxx - minn);
    }
  }

  return ans;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  int n, m;
  cin >> n >> m;
  VI arr(n);
  REP(i, n) { cin >> arr[i]; }
  cout << solve(n, m, arr) << '\n';
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
