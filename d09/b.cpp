#include <bits/stdc++.h>
using namespace std;

constexpr long PART_ONE_ANSWER = 1124361034;

int main() {
  ifstream file("input.txt");
  deque<long> xs;

  long p = PART_ONE_ANSWER;
  long s = 0;
  while (true) {
    if (s == p) {
      long a = p, b = 0;
      for (long x : xs) {
        a = min(a, x);
        b = max(b, x);
      }
      cout << a + b << "\n";
      return 0;
    } else if (s > p) {
      s -= xs.front();
      xs.pop_front();
    } else {
      long n;
      file >> n;
      s += n;
      xs.push_back(n);
    }
  }
}
