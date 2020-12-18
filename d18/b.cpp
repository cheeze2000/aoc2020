#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, char> t;

ll f(vector<t>& xs) {
  stack<char> ys;
  vector<t> zs;

  for (auto& [a, b] : xs) {
    if (b == 0) {
      zs.push_back({ a, b });
    } else if (b == '(') {
      ys.push(b);
    } else if (b == ')') {
      while (ys.top() != '(') {
        zs.push_back({ 0, ys.top() });
        ys.pop();
      }

      ys.pop();
    } else if (b == '*') {
      while (!ys.empty() && ys.top() != '(') {
        zs.push_back({ 0, ys.top() });
        ys.pop();
      }

      ys.push(b);
    } else {
      while (!ys.empty() && ys.top() == '+') {
        zs.push_back({ 0, ys.top() });
        ys.pop();
      }

      ys.push(b);
    }
  }

  while (!ys.empty()) {
    zs.push_back({ 0, ys.top() });
    ys.pop();
  }

  stack<ll> ws;
  for (auto& [a, b] : zs) {
    if (b == 0) {
      ws.push(a);
    } else {
      ll x = ws.top(); ws.pop();
      ll y = ws.top(); ws.pop();
      if (b == '+') ws.push(x + y);
      else ws.push(x * y);
    }
  }

  return ws.top();
}

bool o(char c) {
  return c == '+' || c == '*'
      || c == '(' || c == ')';
}

int main() {
  ifstream file("input.txt");
  ll ans = 0;

  string s;
  while (getline(file, s)) {
    vector<t> xs;

    for (char c : s) {
      if (c == ' ') continue;

      if (o(c)) xs.push_back({ 0, c });
      else xs.push_back({ c - '0', 0 });
    }

    ans += f(xs);
  }

  cout << ans << "\n";
}
