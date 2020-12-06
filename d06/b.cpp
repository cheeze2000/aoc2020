#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int ans = 0;
  int n = 0;
  int xs[26] = {};

  string s;
  while (getline(file, s)) {
    if (s == "") {
      for (int& x : xs) {
        if (x == n) ans++;
        x = 0;
      }
      n = 0;
      continue;
    }

    for (char c : s) xs[c - 'a']++;
    n++;
  }

  for (int x : xs) {
    if (x == n) ans++;
  }

  cout << ans << "\n";
}
