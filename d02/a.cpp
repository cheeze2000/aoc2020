#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");

  int a;
  int b;
  char z;
  string s;
  string t;

  int ans = 0;
  while (file >> a >> z >> b >> s >> t) {
    int n = 0;
    for (char c : t) {
      if (c == s[0]) n++;
    }
    if (a <= n && n <= b) ans++;
  }

  cout << ans << "\n";
}
