#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef unordered_map<string, int> mapping;
typedef vector<vector<ii>> al;

vector<int> dp;

int dfs(int n, al& ys) {
  if (dp[n] != -1) return dp[n];

  int ans = 0;
  for (auto& [x, y] : ys[n]) {
    ans += x * dfs(y, ys) + x;
  }
  dp[n] = ans;
  return ans;
}

void f(mapping& xs) {
  ifstream file("input.txt");
  int n = 0;

  string s;
  string t;
  while (file >> s >> t) {
    xs[s + t] = n++;
    getline(file, s);
  }
}

int main() {
  ifstream file("input.txt");
  mapping xs;
  vector<vector<ii>> ys;

  f(xs);

  int n = 0;
  string s;
  while (getline(file, s)) {
    vector<ii> zs;

    regex r0("contain |bags?,?.? ?");
    regex r1("([a-z]+) ([a-z]+)");

    s = regex_replace(s, r0, "");
    s = regex_replace(s, r1, "$1$2");
    stringstream ss(s);

    string c;
    int d;
    ss >> c;
    while (ss >> d >> c) zs.push_back({ d, xs[c] });
    ys.push_back(zs);
  }

  for (int i = 0; i < xs.size(); i++) {
    dp.push_back(-1);
  }

  int ans = dfs(xs["shinygold"], ys);
  cout << ans << "\n";
}
