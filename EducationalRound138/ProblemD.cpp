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

/**************************** For Debugging ****************************/
void __PRINT(int x) { cerr << x; }
void __PRINT(long x) { cerr << x; }
void __PRINT(LL x) { cerr << x; }
void __PRINT(unsigned x) { cerr << x; }
void __PRINT(UL x) { cerr << x; }
void __PRINT(ULL x) { cerr << x; }
void __PRINT(float x) { cerr << x; }
void __PRINT(double x) { cerr << x; }
void __PRINT(LD x) { cerr << x; }
void __PRINT(char x) { cerr << '\'' << x << '\''; }
void __PRINT(const char *x) { cerr << '\"' << x << '\"'; }
void __PRINT(const string &x) { cerr << '\"' << x << '\"'; }
void __PRINT(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __PRINT(const pair<T, V> &x)
{
  cerr << '{';
  __PRINT(x.first);
  cerr << ',';
  __PRINT(x.second);
  cerr << '}';
}
template <typename T>
void __PRINT(const T &x)
{
  int f = 0;
  cerr << '{';
  for (auto const &i : x)
    cerr << (f++ ? "," : ""), __PRINT(i);
  cerr << "}";
}
void _PRINT() { cerr << "]\n"; }
template <typename T, typename... V>
void _PRINT(T t, V... v)
{
  __PRINT(t);
  if (sizeof...(v))
    cerr << ", ";
  _PRINT(v...);
}
#ifndef ONLINE_JUDGE
#define DEBUG(x...)             \
  cerr << "[" << #x << "] = ["; \
  _PRINT(x)
#else
#define DEBUG(x...)
#endif

/*********************************** Main Solution Starts Here ***********************************/
LL mod = 998244353;
void sieve(VLL &prime, LL n, LL m)
{
  FOR(i, 2, n + 1, 1)
  {
    if (prime[i] != 1)
    {
      LL temp = i * 2;
      while (temp <= n)
      {
        prime[temp] = 1;
        temp += i;
      }
    }
  }
  FOR(i, 3, n + 1, 1)
  {
    if (m / prime[i] < prime[i - 1])
    {
      prime[i] = m + 9999;
      break;
    }
    prime[i] = prime[i] * prime[i - 1];
  }
}
LL calcInitAns(LL n, LL m)
{
  LL ans{0};
  LL mPow{1};
  m = m % mod;
  REP(i, n)
  {
    mPow = (mPow * m) % mod;
    ans = (ans + mPow) % mod;
  }
  return ans;
}
/**************************** Input/Output Handler ****************************/
void inputOutput()
{
  LL n, m;
  cin >> n >> m;
  VLL prime(n + 1);
  iota(ALL(prime), 0);
  // DEBUG(prime);
  sieve(prime, n + 1, m);
  // DEBUG(prime);
  LL ans{calcInitAns(n, m)};
  // DEBUG(ans);
  LL ts{1}, prev{1};
  LL temp{0}, temp1{};
  REP(i, n)
  {
    temp1 = (m / prime[i + 1]) % mod;
    if (temp1 == 0)
      break;
    temp = (temp1 * prev) % mod;
    ans = (ans - temp + mod) % mod;
    prev = temp;
  }
  cout << ans << '\n';
}

/**************************** Main Function *************************/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int TC{1};
  // cin >> TC;
  for (int tc{1}; tc <= TC; ++tc)
  {
    // cout << "Case #" << tc << ": ";
    inputOutput();
  }
  return 0;
}
