#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;
int sudokuBoard[9][9];
set<int> remainingRow[9];
set<int> remainingCol[9];
set<int> remainingBox[3][3];
int numSolutions(int row, int col) {
  if(row >= 9) return 1;

  set<int> remaining;
  for(int x=1;x<=9;x++) {
    bool inRow = remainingRow[row].count(x);
    bool inCol = remainingCol[col].count(x);
    bool inBox = remainingBox[row/3][col/3].count(x);
    if(inRow && inCol && inBox) {
      remaining.insert(x);
    }
  }

  if(sudokuBoard[row][col] != -1) {
    return numSolutions(row + (col == 8), (col+1)%9);
  }

  int solutions = 0;
  for (auto &x: remaining) {
    sudokuBoard[row][col] = x;
    remainingRow[row].erase(x);
    remainingCol[col].erase(x);
    remainingBox[row/3][col/3].erase(x);
    solutions += numSolutions(row + (col == 8), (col+1)%9);
    remainingBox[row/3][col/3].insert(x);
    remainingCol[col].insert(x);
    remainingRow[row].insert(x);
    sudokuBoard[row][col] = -1;
  }
  
  return solutions;
}

int main() {

  for(int i=0;i<9;++i) {
    remainingRow[i] = set<int>();
    remainingCol[i] = set<int>();
    auto &row = remainingRow[i];
    auto &col = remainingCol[i];
    for(int x=1;x<=9;++x) {
      row.insert(x);
      col.insert(x);
    }
  }
  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
      remainingBox[i][j] = set<int>();
      auto &s = remainingBox[i][j];
      for(int x=1;x<=9;++x){
        s.insert(x);
      }
    }
  }

  cout<<"Enter the values in your sudoku board. For any empty cells, use a value of -1.\n";
  for(int i=0;i<9;++i) {
    for(int j=0;j<9;++j) {
      cin>>sudokuBoard[i][j];
      if(sudokuBoard[i][j] == -1) continue;
      remainingRow[i].erase(sudokuBoard[i][j]);
      remainingCol[j].erase(sudokuBoard[i][j]);
      remainingBox[i/3][j/3].erase(sudokuBoard[i][j]);
    }
  }

  cout<<"Your sudoku board has "<<numSolutions(0,0)<<" possible solution(s).\n";
  return 0;

}