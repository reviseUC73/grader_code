#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000;

bool board[MAXN][MAXN];

struct Coord {
  int row;
  int column;
  Coord(int row, int column) : row(row), column(column) {}
};

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = false;
    }
  }

  vector<Coord> fireCoords;
  for (int i = 0; i < k; i++) {
    int row, column;
    cin >> row >> column;
    Coord newFire = Coord(row - 1, column - 1);
    fireCoords.push_back(newFire);
    board[row - 1][column - 1] = true;
  }

  int sec = 0;
  bool finished = false;
  while (!finished) {
    vector<Coord> newFires;
    for (const auto& coord : fireCoords) {
      int row = coord.row;
      int column = coord.column;
      if (row + 1 < n && !board[row + 1][column]) {
        Coord newCoord = Coord(row + 1, column);
        newFires.push_back(newCoord);
        board[row + 1][column] = true;
      }
      if (row - 1 >= 0 && !board[row - 1][column]) {
        board[row - 1][column] = true;
        Coord newCoord = Coord(row - 1, column);
        newFires.push_back(newCoord);
      }
      if (column + 1 < n && !board[row][column + 1]) {
        board[row][column + 1] = true;
        Coord newCoord = Coord(row, column + 1);
        newFires.push_back(newCoord);
      }
      if (column - 1 >= 0 && !board[row][column - 1]) {
        board[row][column - 1] = true;
        Coord newCoord = Coord(row, column - 1);
        newFires.push_back(newCoord);
      }
    }
    if (newFires.empty()) {
      finished = true;
    } else {
      fireCoords = move(newFires);
      sec++;
    }
  }

  cout << sec << endl;
  return 0;
}
