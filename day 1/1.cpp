#include <bits/stdc++.h>

using namespace std;

int total = 0;

int solve(string x) {
  string result = "";
  vector<int> numbers;

  for (char c : x) {
    if (isdigit(c)) {
      numbers.push_back(c  - '0');
    }
  }

  return numbers.front() * 10 + numbers.back();
}

int main() {
  string x;

  while (cin >> x) {
    int num = solve(x);
    total += num;

    cout << num << endl;
  }

  cout << "Total: " << total << endl;

  return 0;
}