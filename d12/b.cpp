#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii f(int n, ii xs) {
  if (n == 0) return xs;
  auto [a, b] = xs;
  return f(n - 1, { b, -a });
}

int main() {
  ifstream file("input.txt");
  int x0 = 10, y0 = 1, x1 = 0, y1 = 0;

  char c;
  int n;
  while (file >> c >> n) {
    switch (c) {
      case 'N': y0 += n; break;
      case 'S': y0 -= n; break;
      case 'E': x0 += n; break;
      case 'W': x0 -= n; break;
      case 'L': {
        auto [a, b] = f(n / 30, { x0, y0 });
        x0 = a; y0 = b;
        break;
      }
      case 'R': {
        auto [a, b] = f(n / 90, { x0, y0 });
        x0 = a; y0 = b;
        break;
      }
      case 'F': {
        x1 += n * x0;
        y1 += n * y0;
        break;
      }
    }
  }

  cout << abs(x1) + abs(y1) << "\n";
}
