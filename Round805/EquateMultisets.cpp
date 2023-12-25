#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void fillUmap(unordered_map<int, int> &umap, int num)
{
  while (num)
  {
    if (num & 1)
      ++umap[num];
    num >>= 1;
  }
}

// void inputOutput()
// {
//   int n{};
//   cin >> n;
//   vector<int> a(n), b(n);
//   for (int i{0}; i < n; ++i)
//     cin >> a[i];
//   for (int i{0}; i < n; ++i)
//     cin >> b[i];
//   unordered_map<int, int> umapa, umapb;
//   unordered_map<int, int>::iterator umitr;
//   int temp{};
//   bool isPossible{true};
//   for (int i{0}; i < n; ++i)
//   {
//     fillUmap(umapa, a[i]);
//     fillUmap(umapb, b[i]);
//   }
//   for (auto itr : umapa)
//   {
//     umitr = umapb.find(itr.first);
//     if (umitr == umapb.end() || umitr->second < itr.second)
//     {
//       isPossible = false;
//       break;
//     }
//   }
//   cout << (isPossible ? "YES" : "NO") << '\n';
// }

void inputOutput()
{
  int n{};
  cin >> n;
  unordered_map<int, int> umap;
  unordered_map<int, int>::iterator umitr;
  int temp{};
  for (int i{0}; i < n; ++i)
  {
    cin >> temp;
    while (!(temp & 1))
      temp >>= 1;
    ++umap[temp];
  }
  bool isPossible{true};
  for (int i{0}; i < n; ++i)
  {
    cin >> temp;
    if (isPossible)
    {
      while (temp)
      {
        if (temp & 1)
        {
          umitr = umap.find(temp);
          if (umitr != umap.end())
          {
            --umitr->second;
            if (umitr->second == 0)
              umap.erase(umitr);
            break;
          }
        }
        temp >>= 1;
      }
      if (!temp)
        isPossible = false;
    }
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

// 10
// 1
// 4
// 17
// 5
// 2 2 4 4 4
// 28 46 62 71 98
// 2
// 16 32
// 3 75
// 6
// 1 2 10 16 64 80
// 20 43 60 74 85 99
// 8
// 1 4 8 8 12 16 32 80
// 32 37 41 52 76 77 90 94
// 3
// 44 74 92
// 10 47 97
// 4
// 2 4 20 32
// 17 33 33 90
// 6
// 1 4 4 4 8 16
// 17 63 74 76 79 83
// 7
// 2 4 4 12 16 40 48
// 5 6 14 39 41 57 65
// 8
// 2 2 2 2 4 4 12 16
// 13 41 52 55 57 78 83 87