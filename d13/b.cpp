#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll e(ll a, ll b, ll c = 1, ll d = 0) {
  return b == 0 ? c : e(b, a % b, d, c - d * (a / b));
}

int main() {
  ifstream file("input.txt");
  ll ans = 0;
  vector<ii> xs;

  string s;
  getline(file, s);

  int i = -1;
  ll a = 1;
  while (file.good()) {
    i++;
    getline(file, s, ',');
    if (s == "x") continue;

    int n = stoi(s);
    a *= n;
    xs.push_back({ -i, n });
  }

  for (auto [x, y] : xs) {
    ll n = a / y;
    ans += n * x * e(n, y);
  }

  while (ans > a) ans -= a;
  while (ans < 0) ans += a;
  cout << ans << "\n";
}
