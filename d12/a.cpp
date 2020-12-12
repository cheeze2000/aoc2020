#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int d = 0, x = 0, y = 0;

  int dx[] = { 1, 0, -1, 0 };
  int dy[] = { 0, -1, 0, 1 };

  char c;
  int n;
  while (file >> c >> n) {
    switch (c) {
      case 'N': y += n; break;
      case 'S': y -= n; break;
      case 'E': x += n; break;
      case 'W': x -= n; break;
      case 'L': d += n / 30; d %= 4; break;
      case 'R': d += n / 90; d %= 4; break;
      case 'F': x += n * dx[d];
                y += n * dy[d];
                break;
    }
  }

  cout << abs(x) + abs(y) << "\n";
}
