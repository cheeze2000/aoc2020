#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int c = 0, d = 1023, e = 0;

  string s;
  while (file >> s) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < 7; i++) {
      a = a << 1;
      if (s[i] == 'B') a++;
    }
    for (int i = 7; i < 10; i++) {
      b = b << 1;
      if (s[i] == 'R') b++;
    }
    int j = a * 8 + b;
    c += j;
    d = min(j, d);
    e = max(j, e);
  }

  int ans = (e - d + 1) * (e + d) / 2 - c;
  cout << ans << "\n";
}
