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
    bool f = t[a - 1] == s[0];
    bool g = t[b - 1] == s[0];
    if (f ^ g) ans++;
  }

  cout << ans << "\n";
}
