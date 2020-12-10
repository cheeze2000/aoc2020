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

    if (d == 1) {
      a++;
    } else if (d == 2) {
      a += 2;
    } else {
      b++;
    }

    m = t;
  }

  cout << a * b << "\n";
}
