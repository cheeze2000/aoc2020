#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("input.txt");
  int a = 0, b = 1;
  priority_queue<int> xs;

  int n;
  while (file >> n) xs.push(-n);

  int m = 0;
  while (!xs.empty()) {
    int t = -xs.top(); xs.pop();
    int d = t - m;

    if (d == 3) b++;
    else a += d;

    m = t;
  }

  cout << a * b << "\n";
}
