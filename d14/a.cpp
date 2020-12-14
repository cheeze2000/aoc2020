#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(string& m, ll& v) {
  ll l = 0;
  ll n = 1;

  for (int i = m.size() - 1; i >= 0; i--) {
    if (m[i] == 'X') l += n * (v & 1);
    else l += n * (m[i] - '0');

    v >>= 1;
    n <<= 1;
  }

  v = l;
}

int main() {
  ifstream file("input.txt");
  string m;
  unordered_map<ll, ll> xs;

  string s;
  while (getline(file, s)) {
    regex r0("mask = (.+)");
    regex r1("mem\\[(\\d+)\\] = (.+)");
    smatch sm;

    if (s[1] == 'a') {
      regex_match(s, sm, r0);
      m = sm[1];
    } else {
      regex_match(s, sm, r1);
      ll a = stol(sm[1]);
      ll v = stol(sm[2]);

      f(m, v);
      xs[a] = v;
    }
  }

  ll ans = 0;
  for (auto& [_, x] : xs) ans += x;

  cout << ans << "\n";
}
