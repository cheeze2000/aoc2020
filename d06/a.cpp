#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int ans = 0;
  bool xs[26] = {};

  string s;
  while (getline(file, s)) {
    if (s == "") {
      for (bool& x : xs) x = false;
      continue;
    }

    for (char c : s) {
      if (xs[c - 'a']) continue;
      xs[c - 'a'] = true;
      ans++;
    }
  }

  cout << ans << "\n";
}
