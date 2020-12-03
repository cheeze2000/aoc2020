#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int ans = 0, i = 0;

  string s;
  while (file >> s) {
    if (s[i] == '#') ans++;
    i += 3;
    i %= 31;
  }

  cout << ans << "\n";
}
