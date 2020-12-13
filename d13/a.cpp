#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  vector<int> xs;

  string s;
  getline(file, s);
  int n = stoi(s);

  while (file.good()) {
    getline(file, s, ',');
    if (s == "x") continue;

    xs.push_back(stoi(s));
  }

  int b = 0, m = 0;
  for (int x : xs) {
    int g = (n / x + 1) * x - n;
    if (b == 0 || g < m) {
      b = x;
      m = g;
    }
  }

  cout << b * m << "\n";
}
