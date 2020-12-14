#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> f(string& m, ll& v) {
  vector<ll> xs;
  xs.push_back(0);

  stack<char> s;
  for (int i = m.size() - 1; i >= 0; i--) {
    if (m[i] == '0') s.push('0' + (v & 1));
    else s.push(m[i]);

    v >>= 1;
  }

  while (!s.empty()) {
    for (ll& x : xs) x <<= 1;

    char c = s.top(); s.pop();
    if (c == 'X') {
      vector<ll> ys;
      for (ll x : xs) ys.push_back(x);
      for (ll y : ys) xs.push_back(y + 1);
    } else {
      for (ll& x : xs) x += c - '0';
    }
  }

  return xs;
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

      for (ll x : f(m, a)) xs[x] = v;
    }
  }

  ll ans = 0;
  for (auto& [_, x] : xs) ans += x;

  cout << ans << "\n";
}
