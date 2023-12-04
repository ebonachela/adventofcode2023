#include <bits/stdc++.h>

using namespace std;

int solve(string x) {
  int result = 0, number = 0, power = 1;
  bool is_winning_number = false;
  vector<int> winning_numbers;
  vector<int> guessed_numbers;

  for (int i = x.size() - 1; i >= 0; i--) {
    char c = x[i];

    if (c == ':') break;

    if (isdigit(c)) {
      number += (c - '0') * power;
      power *= 10;
    } else {
      if (number > 0) {
        if (is_winning_number) winning_numbers.push_back(number);
        else guessed_numbers.push_back(number);
      }

      number = 0;
      power = 1;
    }

    if (c == '|') {
      is_winning_number = true;
    }
  }

  for (int winning_number : winning_numbers) {
    bool has_number = count(guessed_numbers.begin(), guessed_numbers.end(), winning_number) > 0;

    if (has_number) result++;
  }

  return pow(2, result - 1);
}

int main() {
  string x;
  int total = 0;

  while (getline(cin, x)) {
    int num = solve(x);
    total += num;

    cout << num << endl;
  }

  cout << "Total: " << total << endl;

  return 0;
}