#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>

using namespace std;

queue<string> setup() {
  queue<string> pieces;
  string high[] = {"rook", "knight", "bishop", "queen",
                   "king", "bishop", "knight", "rook"};

  for (string &i : high) {
    pieces.push(i);
  }
  return pieces;
}

map<int, string> move(map<int, string> board) {
  int start;
  int end;
  cin >> start;
  cin >> end;
  board[end] = board[start];
  board[start] = "[]";
  return board;
}

int main() {
  queue<string> pieces = setup();
  map<int, string> board;
  for (int i = 1; i <= 64; i++) {
    if (i <= 8 || i >= 57) {
      pieces.push(pieces.front());
      board.insert(pair<int, string>(i, pieces.front()));
      pieces.pop();
    } else if (i <= 16 || (i >= 49 && i <= 56)) {
      board.insert(pair<int, string>(i, "pawn"));
    } else {
      board.insert(pair<int, string>(i, "[]"));
    }
  }

  map<int, string>::iterator itr;
  for (itr = board.begin(); itr != board.end(); ++itr) {
    cout << itr->second << ' ';
    if (itr->first % 8 == 0) {
      cout << '\n';
    }
  }
  while (1) {
    board = move(board);
    for (itr = board.begin(); itr != board.end(); ++itr) {
      cout << itr->second << ' ';
      if (itr->first % 8 == 0) {
        cout << '\n';
      }
    }
  }
  return 0;
}
