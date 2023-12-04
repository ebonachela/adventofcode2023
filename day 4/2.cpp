#include <bits/stdc++.h>
#define NOT_WINNING_NUMBER 0
#define IS_WINNING_NUMBER 1
#define GET_ID 3

using namespace std;

map<int,int> card_count;

int solve(string x) {
  int result = 0, number = 0, power = 1, card_id = -1;
  int action = NOT_WINNING_NUMBER;
  vector<int> winning_numbers;
  vector<int> guessed_numbers;

  for (int i = x.size() - 1; i >= 0; i--) {
    char c = x[i];

    if (c == ':') {
      action = GET_ID;
      continue;
    }

    if (action == GET_ID) {
      if (isdigit(c)) {
        number += (c - '0') * power;
        power *= 10;
      } else {
        card_id = number;
        break;
      }

      continue;
    }

    if (isdigit(c)) {
      number += (c - '0') * power;
      power *= 10;
    } else {
      if (number > 0) {
        if (action == IS_WINNING_NUMBER) winning_numbers.push_back(number);
        else guessed_numbers.push_back(number);
      }

      number = 0;
      power = 1;
    }

    if (c == '|') {
      action = IS_WINNING_NUMBER;
    }
  }

  for (int winning_number : winning_numbers) {
    bool has_number = count(guessed_numbers.begin(), guessed_numbers.end(), winning_number) > 0;

    if (has_number) result++;
  }

  for (int i = card_id; i <= card_id + result; i++) {
    int inc = 0;

    if (card_count.count(card_id) == 0) inc = 1;
    else inc = card_count[card_id];

    if (i == card_id) {
      card_count[i]++;
      continue;
    }

    card_count[i] += inc;
  }

  return card_count[card_id];
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