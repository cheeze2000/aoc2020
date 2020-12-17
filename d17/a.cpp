#include <bits/stdc++.h>
using namespace std;

typedef array<array<array<bool, 15>, 22>, 22> grid;

int c(int x, int y, int z, grid& xs) {
  int a = -xs[x][y][z];
  int ds[] = { -1, 0, 1 };

  for (int i : ds) {
    for (int j : ds) {
      for (int k : ds) {
        a += xs[x + i][y + j][z + k];
      }
    }
  }

  return a;
}

grid f(grid& xs) {
  grid ys = xs;
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j < 21; j++) {
      for (int k = 1; k < 14; k++) {
        int a = c(i, j, k, xs);
        if (ys[i][j][k]) {
          if (a == 2 || a == 3) continue;
          ys[i][j][k] = false;
        } else {
          if (a == 3) ys[i][j][k] = true;
        }
      }
    }
  }

  return ys;
}

int main() {
  ifstream file("input.txt");
  grid xs = {};

  int x = 7;

  string s;
  while (file >> s) {
    for (int i = 7; i < 15; i++) {
      xs[x][i][7] = s[i - 7] == '#';
    }
    x++;
  }

  for (int i = 0; i < 6; i++) xs = f(xs);

  int ans = 0;
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j < 21; j++) {
      for (int k = 1; k < 14; k++) {
        ans += xs[i][j][k];
      }
    }
  }

  cout << ans << "\n";
}

