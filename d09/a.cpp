#include <bits/stdc++.h>
using namespace std;

bool f(vector<long>& xs, long a, long b) {
  bool g = true;

  int i = 0, j = xs.size() - 1;
  while (i < j) {
    long s = xs[i] + xs[j];
    if (s == a) {
      g = false;
      break;
    } else if (s < a) {
      i++;
    } else {
      j--;
    }
  }

  if (g) return true;

  for (i = 0; i < xs.size(); i++) {
    if (xs[i] == b) {
      xs[i] = a;
      while (++i < xs.size()) {
        if (xs[i] > xs[i - 1]) break;
        long t = xs[i];
        xs[i] = xs[i - 1];
        xs[i - 1] = t;
      }
      break;
    }

    if (xs[i] < a) continue;

    long t = xs[i];
    xs[i] = a;
    a = t;
  }

  return false;
}

int main() {
  vector<long> xs(25);
  queue<long> ys;

  ifstream file("input.txt");
  for (int i = 0; i < xs.size(); i++) {
    long n;
    file >> n;
    xs[i] = n;
    ys.push(n);
  }

  sort(xs.begin(), xs.end());

  long n;
  while (file >> n) {
    long m = ys.front(); ys.pop();
    ys.push(n);

    bool b = f(xs, n, m);
    if (b) {
      cout << n << "\n";
      return 0;
    }
  }
}
