#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &arr)
{
  vector<int> dp(n);
  dp[0] = 1;
  for (int i{1}; i < n; ++i)
  {
    vector<int> cnt(n);
    int maxCnt{0};
    for (int j{i - 1}; j >= 0; --j)
    {
      if (arr[i] == arr[j])
      {
        if (dp[j] == 0 || (i - j - 1) & 1 || maxCnt > (i - j - 1) >> 1)
          continue;
        dp[i] = max(dp[i], dp[j] + 1);
      }
      ++cnt[arr[j]];
      maxCnt = max(maxCnt, cnt[arr[j]]);
    }
    if (!(i & 1) && i >> 1 >= maxCnt)
      dp[i] = max(dp[i], 1);
  }
  vector<int> cnt(n);
  int maxCnt{0};
  for (int i{n - 1}; i >= 0; --i)
  {
    if (dp[i] != 0 && ((n - 1 - i) & 1 || (maxCnt > ((n - 1 - i) >> 1))))
      dp[i] = 0;
    ++cnt[arr[i]];
    maxCnt = max(maxCnt, cnt[arr[i]]);
  }
  int ans{0};
  for (int i{0}; i < n; ++i)
    ans = max(dp[i], ans);
  return ans;
}

void inputOutput()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i{0}; i < n; ++i)
  {
    cin >> arr[i];
    --arr[i];
  }
  cout << solve(n, arr) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t{};
  cin >> t;
  while (t--)
    inputOutput();
  return 0;
}
