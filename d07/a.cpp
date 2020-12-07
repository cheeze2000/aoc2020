#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> mapping;
typedef vector<vector<int>> al;

void f(mapping& xs, al& ys) {
  ifstream file("input.txt");
  int n = 0;

  string s;
  string t;
  while (file >> s >> t) {
    xs[s + t] = n++;
    getline(file, s);

    vector<int> zs;
    ys.push_back(zs);
  }
}

int main() {
  ifstream file("input.txt");
  mapping xs;
  vector<vector<int>> ys;

  f(xs, ys);

  int n = 0;
  string s;
  while (getline(file, s)) {
    regex r0("contain |bags?,?.? ?");
    regex r1("([a-z]+) ([a-z]+)");

    s = regex_replace(s, r0, "");
    s = regex_replace(s, r1, "$1$2");
    stringstream ss(s);

    string c;
    int d;
    ss >> c;
    while (ss >> d >> c) ys[xs[c]].push_back(n);
    n++;
  }

  bool zs[xs.size()] = {};
  queue<int> q;

  for (int i : ys[xs["shinygold"]]) q.push(i);

  int ans = 0;
  while (!q.empty()) {
    int i = q.front(); q.pop();
    if (zs[i]) continue;

    zs[i] = true;
    ans++;

    for (int y : ys[i]) q.push(y);
  }

  cout << ans << "\n";
}
