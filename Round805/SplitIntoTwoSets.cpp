#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
  vector<int> par, size;

public:
  DisjointSet(int n)
  {
    par.resize(n), size.resize(n);
    for (int i{0}; i < n; ++i)
      par[i] = i, size[i] = 1;
  }
  int find(int i)
  {
    if (par[i] == i)
      return i;
    return par[i] = find(par[i]);
  }
  int getSize(int i)
  {
    return size[i];
  }
  void unite(int a, int b)
  {
    a = find(a), b = find(b);
    if (a == b)
      return;
    if (size[a] < size[b])
      swap(a, b);
    par[b] = a;
    size[a] += size[b];
  }
};

void inputOutput()
{
  int n{};
  cin >> n;
  vector<int> count(n + 1, 0);
  int temp1{}, temp2{};
  bool isPossible{true};
  DisjointSet dsj(n + 1);
  for (int i{0}; i < n; ++i)
  {
    cin >> temp1 >> temp2;
    if (temp1 == temp2)
      isPossible = false;
    ++count[temp1], ++count[temp2];
    dsj.unite(temp1, temp2);
  }
  for (int i{1}; i <= n; ++i)
    if (count[i] != 2)
      isPossible = false;
  if (!isPossible)
  {
    cout << "NO\n";
    return;
  }
  for (int i{1}; i <= n; ++i)
  {
    if (dsj.find(i) == i && (dsj.getSize(i) & 1))
    {
      isPossible = false;
      break;
    };
  }
  cout << (isPossible ? "YES" : "NO") << '\n';
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
