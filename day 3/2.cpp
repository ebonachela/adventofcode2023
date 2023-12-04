#include <bits/stdc++.h>

using namespace std;

int get_number(vector<string> data, int position, bool check[3], int x, int y) {
  int col = data[x].size(), number = 0, power = 1;

  // go to leftmost number
  int i = y;
  while (i < col && isdigit(data[x][i])) {
    i++;
  }

  i--;

  // construct number
  while (i >= 0) {
    char c = data[x][i];

    if (!isdigit(c)) break;

    number += (c - '0') * power;
    power *= 10;

    if (position == 2) {
      if (i == y) check[2] = true;
      if (i == y - 1) check[1] = true;
      if (i == y - 2) check[0] = true;
    }

    if (position == 1) {
      if (i == y + 1) check[2] = true;
      if (i == y) check[1] = true;
      if (i == y - 1) check[0] = true;
    }

    if (position == 0) {
      if (i == y) check[0] = true;
      if (i == y + 1) check[1] = true;
      if (i == y + 2) check[2] = true;
    }

    i--;
  }

  return number;
}

int is_valid(vector<string> data, int x, int y) {
  int result = 1, count_parts = 0;
  int rows = data.size(), cols = data[x].size();
  bool top_check[3] = { false }, bot_check[3] = { false };

  // upper right diagonal 
  if (top_check[2] == false && x - 1 >= 0 && y + 1 < cols && isdigit(data[x - 1][y + 1])) {
    result *= get_number(data, 2, top_check, x - 1, y + 1);
    count_parts++;
  }

  // up
  if (top_check[1] == false && x - 1 >= 0 && isdigit(data[x - 1][y])) {
    result *= get_number(data, 1, top_check, x - 1, y);
    count_parts++;
  }

  // upper left diagonal 
  if (top_check[0] == false && x - 1 >= 0 && y - 1 >= 0 && isdigit(data[x - 1][y - 1])) {
    result *= get_number(data, 0, top_check, x - 1, y - 1);
    count_parts++;
  }

  // down right diagonal 
  if (bot_check[2] == false && x + 1 < rows && y + 1 < cols && isdigit(data[x + 1][y + 1])) {
    result *= get_number(data, 2, bot_check, x + 1, y + 1);
    count_parts++;
  }

  // down
  if (bot_check[1] == false && x + 1 < rows && isdigit(data[x + 1][y])) {
    result *= get_number(data, 1, bot_check, x + 1, y);
    count_parts++;
  }

  // down left diagonal 
  if (bot_check[0] == false && x + 1 < rows && y- 1 >= 0 && isdigit(data[x + 1][y - 1])) {
    result *= get_number(data, 0, bot_check, x + 1, y - 1);
    count_parts++;
  }

  // right
  if (y + 1 < cols && isdigit(data[x][y + 1])) {
    int i = y + 1, number = 0, power = 1, col = data[x].size();

    // go to leftmost number
    while (i < col && isdigit(data[x][i])) {
      i++;
    }

    i--;

    // construct number
    while (i >= 0) {
      char c = data[x][i];

      if (!isdigit(c)) break;

      number += (c - '0') * power;
      power *= 10;

      i--;
    }

    result *= number;
    count_parts++;
  }

  // left
  if (y - 1 >= 0 && isdigit(data[x][y - 1])) {
    int i = y - 1, number = 0, power = 1;
    
    // construct number
    while (i >= 0) {
      char c = data[x][i];

      if (!isdigit(c)) break;

      number += (c - '0') * power;
      power *= 10;

      i--;
    }

    result *= number;
    count_parts++;
  }

  if (count_parts != 2) return 0;

  return result;
}

int solve(vector<string> data) {
  int result = 0;

  for (int i = 0; i < data.size(); i++) {
    for (int j = data[i].size() - 1; j >= 0; j--) {
      char c = data[i][j];

      if (c == '*') {
        result += is_valid(data, i, j);
      }
    }
  }

  return result;
}

int main() {
  vector<string> data;
  string x;

  while (getline(cin, x)) {
    data.push_back(x);
  }

  int total = solve(data);

  cout << "Total: " << total << endl;

  return 0;
}