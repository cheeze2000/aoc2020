#include <bits/stdc++.h>
using namespace std;

typedef array<array<array<array<bool, 15>, 15>, 22>, 22> grid;

int c(int x, int y, int z, int w, grid& xs) {
  int a = -xs[x][y][z][w];
  int ds[] = { -1, 0, 1 };

  for (int i : ds) {
    for (int j : ds) {
      for (int k : ds) {
        for (int l : ds) {
          a += xs[x + i][y + j][z + k][w + l];
        }
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
        for (int l = 1; l < 14; l++) {
          int a = c(i, j, k, l, xs);
          if (ys[i][j][k][l]) {
            if (a == 2 || a == 3) continue;
            ys[i][j][k][l] = false;
          } else {
            if (a == 3) ys[i][j][k][l] = true;
          }
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
      xs[x][i][7][7] = s[i - 7] == '#';
    }
    x++;
  }

  for (int i = 0; i < 6; i++) xs = f(xs);

  int ans = 0;
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j < 21; j++) {
      for (int k = 1; k < 14; k++) {
        for (int l = 1; l < 14; l++) {
          ans += xs[i][j][k][l];
        }
      }
    }
  }

  cout << ans << "\n";
}

