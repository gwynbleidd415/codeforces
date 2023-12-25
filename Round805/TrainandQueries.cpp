#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void inputOutput()
{
  int n{}, q{};
  cin >> n >> q;
  unordered_map<int, pair<int, int>> umap;
  int temp1{}, temp2{};
  for (int i{0}; i < n; ++i)
  {
    cin >> temp1;
    if (umap.count(temp1))
      umap[temp1].second = i;
    else
      umap[temp1].first = umap[temp1].second = i;
  }
  for (int i{0}; i < q; ++i)
  {
    cin >> temp1 >> temp2;
    if (umap.count(temp1) && umap.count(temp2) && umap[temp1].first <= umap[temp2].second)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  int t{};
  cin >> t;
  while (t--)
    inputOutput();
  return 0;
}
