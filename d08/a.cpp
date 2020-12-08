#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  ifstream file("input.txt");
  int ans = 0;
  vector<ii> xs;

  string s;
  int i;
  while (file >> s >> i) {
    if (s == "acc") xs.push_back({ 0, i });
    else if (s == "jmp") xs.push_back({ 1, i });
    else xs.push_back({ 2, i });
  }

  bool ys[xs.size()] = {};
  i = 0;

  while (!ys[i]) {
    ys[i] = true;
    auto& [x, y] = xs[i];

    if (x == 0) {
      ans += y;
      i++;
    } else if (x == 1) {
      i += y;
    } else {
      i++;
    }
  }

  cout << ans << "\n";
}
