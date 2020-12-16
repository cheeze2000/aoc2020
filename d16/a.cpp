#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> f(vector<ii>& xs) {
  vector<ii> ys;

  for (int i = 0; i < xs.size(); i++) {
    auto& [a, b] = xs[i];
    if (ys.size() == 0) {
      ys.push_back({ a, b });
      continue;
    }

    auto& [c, d] = ys.back();
    if (a > d) ys.push_back({ a, b });
    else d = max(b, d);
  }

  return ys;
}

bool g(int n, vector<ii>& xs) {
  for (auto& [x, y] : xs) {
    if (n <= x || y <= n) return false;
  }

  return true;
}

int main() {
  ifstream file("input.txt");
  vector<ii> xs;

  string s;
  while (true) {
    getline(file, s);
    if (s == "") break;

    regex r(".+ (\\d+)-(\\d+).+ (\\d+)-(\\d+)");
    smatch sm;

    regex_match(s, sm, r);
    xs.push_back({ stoi(sm[1]), stoi(sm[2]) });
    xs.push_back({ stoi(sm[3]), stoi(sm[4]) });
  }

  sort(xs.begin(), xs.end());
  xs = f(xs);

  for (int i = 0; i < 4; i++) getline(file, s);

  int ans = 0;
  while (getline(file, s)) {
    stringstream ss(s);
    while (getline(ss, s, ',')) {
      int n = stoi(s);
      ans += g(n, xs) ? 0 : n;
    }
  }

  cout << ans << "\n";
}
