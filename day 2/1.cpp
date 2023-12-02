#include <bits/stdc++.h>

using namespace std;

int MAX_RED = 12;
int MAX_GREEN = 13;
int MAX_BLUE = 14;

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

int get_number(string x, int i) {
  int result = 0, power = 1;

  while (i >= 0) {
    char c = x[i];

    if (isdigit(c)) {
      result += (c - '0') * power;
      power *= 10;
    } else {
      break;
    }

    i--;
  }

  return result;
}

int solve(string x) {
  int id = 0, c_red = 0, c_green = 0, c_blue = 0;
  char last2 = x[0], last1 = x[1];
  
  for (int i = 2; i < x.size(); i++) {
    char c = x[i];

    if (c == ':') {
      id = get_number(x, i - 1);
    }

    if (c == 'r' && string_search(x, "red", i)) {
      c_red += get_number(x, i - 2);
    }

    if (c == 'g' && string_search(x, "green", i)) {
      c_green += get_number(x, i - 2);
    }

    if (c == 'b' && string_search(x, "blue", i)) {
      c_blue += get_number(x, i - 2);
    }

    if (c == ';' || i + 1 == x.size()) {
      cout << "R: " << c_red << " G: " << c_green << " B: " << c_blue << endl;

      if (!(c_red <= MAX_RED && c_green <= MAX_GREEN && c_blue <= MAX_BLUE)) {
        return 0;
      }

      c_red = 0; 
      c_green = 0; 
      c_blue = 0;
    }

    last1 = c;
    last2 = x[i - 1];
  }

  return id;
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