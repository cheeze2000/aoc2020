#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  ifstream file("input.txt");
  int ans = 0, i = 0;

  string s;
  while (file >> s) {
    if (s[i] == '#') ans++;
    i += n;
    i %= 31;
  }

  return ans;
}

int main() {
  ifstream file("input.txt");
  int a = 0, i = 0;

  string s;
  string t;
  while (file >> s >> t) {
    if (s[i] == '#') a++;
    i += 1;
    i %= 31;
  }

  long ans = a;
  ans *= f(1) * f(3) * f(5) * f(7);

  cout << ans << "\n";
}
