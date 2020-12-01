#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> xs;
  ifstream file("input.txt");

  int n;
  while (file >> n) {
    xs.push_back(n);
  }

  for (int i = 0; i < xs.size(); i++) {
    for (int j = 0; j < xs.size(); j++) {
      for (int k = 0; k < xs.size(); k++) {
        if (xs[i] + xs[j] + xs[k] == 2020) {
          cout << xs[i] * xs[j] * xs[k] << "\n";
          return 0;
        }
      }
    }
  }
}
