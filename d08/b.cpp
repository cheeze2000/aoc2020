#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

struct S {
  int x;
  int y;
  bool z;
};

int main() {
  ifstream file("input.txt");
  vector<ii> xs;

  string s;
  int i;
  while (file >> s >> i) {
    if (s == "acc") xs.push_back({ 0, i });
    else if (s == "jmp") xs.push_back({ 1, i });
    else xs.push_back({ 2, i });
  }

  queue<S> q;
  q.push({ 0, 0, true });

  while (true) {
    auto& [x, y, z] = q.front(); q.pop();
    if (x == xs.size()) {
      cout << y << "\n";
      return 0;
    }

    auto& [a, b] = xs[x];
    if (a == 0) {
      q.push({ x + 1, y + b, z });
    } else if (a == 1) {
      q.push({ x + b, y, z });
      if (z) q.push({ x + 1, y, false });
    } else {
      q.push({ x + 1, y, z });
      if (z) q.push({ x + b, y, false });
    }
  }
}
