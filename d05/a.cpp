#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int ans = 0;

  string s;
  while (file >> s) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < 7; i++) {
      a <<= 1;
      if (s[i] == 'B') a++;
    }
    for (int i = 7; i < 10; i++) {
      b <<= 1;
      if (s[i] == 'R') b++;
    }
    ans = max(ans, a * 8 + b);
  }

  cout << ans << "\n";
}
