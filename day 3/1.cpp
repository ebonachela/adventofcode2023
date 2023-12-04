#include <bits/stdc++.h>

using namespace std;

bool is_valid(vector<string> data, int number, int length, int x, int y) {
  int rows = data.size();
  int cols = data[x].size();

  for (int i = 0; i < length; i++) {
    // down
    if (x + 1 < rows && data[x + 1][y + i] != '.' && !isdigit(data[x + 1][y + i])) return true;

    // up
    if (x - 1 >= 0 && data[x - 1][y + i] != '.' && !isdigit(data[x - 1][y + i])) return true;

    // right
    if (y + i + 1 < cols && data[x][y + i + 1] != '.' && !isdigit(data[x][y + i + 1])) return true;

    // left
    if (y + i - 1 >= 0 && data[x][y + i - 1] != '.' && !isdigit(data[x][y + i - 1])) return true;

    // upper right diagonal 
    if (x - 1 >= 0 && y + i + 1 < cols && data[x - 1][y + i + 1] != '.' && !isdigit(data[x - 1][y + i + 1])) return true;

    // upper left diagonal 
    if (x - 1 >= 0 && y + i - 1 >= 0 && data[x - 1][y + i - 1] != '.' && !isdigit(data[x - 1][y + i - 1])) return true;

    // down right diagonal 
    if (x + 1 < rows && y + i + 1 < cols && data[x + 1][y + i + 1] != '.' && !isdigit(data[x + 1][y + i + 1])) return true;

    // down left diagonal 
    if (x + 1 < rows && y + i - 1 >= 0 && data[x + 1][y + i - 1] != '.' && !isdigit(data[x + 1][y + i - 1])) return true;
  }

  return false;
}

int solve(vector<string> data) {
  int result = 0, c_number = 0, l_number = 0, l_position = -1, power = 1;

  for (int i = 0; i < data.size(); i++) {
    // reset line
    if (l_position != -1 && is_valid(data, c_number, l_number, i - 1, l_position)) {
      result += c_number;
    }

    c_number = 0;
    l_number = 0;
    power = 1;
    l_position = -1;

    for (int j = data[i].size() - 1; j >= 0; j--) {
      char c = data[i][j];

      if (isdigit(c)) {
        c_number += (c - '0') * power;
        power *= 10;
        l_number++;
        l_position = j;
      } else {
        // check if current number is valid
        if (is_valid(data, c_number, l_number, i, j + 1)) {
          result += c_number;
        }

        c_number = 0;
        l_number = 0;
        power = 1;
        l_position = -1;
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