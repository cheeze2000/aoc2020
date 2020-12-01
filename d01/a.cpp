#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> xs;
  ifstream file("input.txt");

  int n;
  while (file >> n) {
    xs.push_back(n);
  }

  sort(xs.begin(), xs.end());

  int i = 0;
  int j = xs.size() - 1;

  while (true) {
    int s = xs[i] + xs[j];
    if (s == 2020) {
      cout << xs[i] * xs[j] << "\n";
      break;
    } else if (s < 2020) {
      i++;
    } else {
      j--;
    }
  }
}
