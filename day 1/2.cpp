#include <bits/stdc++.h>

using namespace std;

int total = 0;

bool string_search(string x, string search, int i) {
  bool result = false;
  int search_i = 0;

  while (i < x.size()) {
    if (x[i] == search[search_i]) {
      i++; 
      search_i++;
    } else {
      break;
    }

    if (search_i == search.size()) return true;
  }

  return result;
}

int check_number(string x, int i) {
  int result = -1;

  switch((char)x[i]) {
    case 'o':
      if (string_search(x, "one", i)) return 1;

      break;
    case 't':
      if (string_search(x, "two", i)) return 2;
      if (string_search(x, "three", i)) return 3;

      break;
    case 'f':
      if (string_search(x, "four", i)) return 4;
      if (string_search(x, "five", i)) return 5;

      break;
    case 's':
      if (string_search(x, "six", i)) return 6;
      if (string_search(x, "seven", i)) return 7;

      break;
    case 'e':
      if (string_search(x, "eight", i)) return 8;

      break;
    case 'n':
      if (string_search(x, "nine", i)) return 9;

      break;
    default:
      break;
  }

  return result;
}

int solve(string x) {
  string result = "";
  vector<int> numbers;

  for (int i = 0; i < x.size(); i++) {
    char current = x[i];

    if (isdigit(current)) {
      numbers.push_back(current  - '0');
    }

    int c_number = check_number(x, i);

    if (c_number != - 1) {
      numbers.push_back(c_number);
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