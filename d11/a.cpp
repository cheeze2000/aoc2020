#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int g(vector<vi>& xs, int r, int c) {
  if (r < 0 || c < 0) return 0;
  if (r >= xs.size() || c >= xs[0].size()) return 0;
  return xs[r][c] == 2 ? 1 : 0;
}

bool f(vector<vi>& xs) {
  bool a = false;
  int r = xs.size();
  int c = xs[0].size();

  vector<vi> ys;
  for (int i = 0; i < r; i++) {
    vi zs;
    for (int j = 0; j < c; j++) {
      int m = xs[i][j];
      if (m == 0) {
        zs.push_back(0);
        continue;
      }

      int s = 0;
      for (int k = 0; k < 8; k++) {
        s += g(xs, i + dx[k], j + dy[k]);
      }

      if (m == 1) {
        if (s == 0) {
          a = true;
          zs.push_back(2);
        } else {
          zs.push_back(1);
        }
      } else if (m == 2) {
        if (s > 3) {
          a = true;
          zs.push_back(1);
        } else {
          zs.push_back(2);
        }
      }
    }

    ys.push_back(zs);
  }

  xs = ys;
  return a;
}

int main() {
  ifstream file("input.txt");
  vector<vi> xs;

  string s;
  while (file >> s) {
    vi ys;
    for (char c : s) {
      int y;
      switch (c) {
        case '.': y = 0; break;
        case 'L': y = 1; break;
        case '#': y = 2; break;
      }
      ys.push_back(y);
    }
    xs.push_back(ys);
  }

  while (f(xs)) {}

  int ans = 0;
  for (auto ys : xs) {
    for (auto y : ys) {
      ans += y == 2 ? 1 : 0;
    }
  }

  cout << ans << "\n";
}
