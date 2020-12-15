#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  ifstream file("input.txt");
  unordered_map<int, ii> xs;
  vector<int> ys;

  int i = 0;
  string s;
  while (file.good()) {
    getline(file, s, ',');
    int n = stoi(s);

    xs[n] = { i, i };
    ys.push_back(n);
    i++;
  }

  int ans = ys.back();
  for (i = ys.size(); i < 30000000; i++) {
    auto& [a, b] = xs[ans];
    ans = b - a;

    if (xs.count(ans) == 0) xs[ans] = { i, i };
    auto& [c, d] = xs[ans];
    xs[ans] = { d, i };
  }

  cout << ans << "\n";
}
