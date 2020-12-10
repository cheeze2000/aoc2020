#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  priority_queue<int> xs;

  int n;
  while (file >> n) xs.push(n);
  xs.push(0);

  long ys[xs.top() + 3] = {};
  ys[xs.top()] = 1;
  xs.pop();

  while (!xs.empty()) {
    int t = xs.top(); xs.pop();
    ys[t] = ys[t + 1] + ys[t + 2] + ys[t + 3];
  }

  cout << ys[0] << "\n";
}
