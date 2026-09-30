// Taken from CS141.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct chessBoard {
    bool arr[8][8] = {false};           // letter, number (0 = open, 1 = taken)
};


const vector<pair<int, int>> possibleMoves = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

pair<int, int> convertToSquare(const string& str) {
    return {str[0] - 'a', str[1] - '1'};
}

bool canMove(chessBoard& board, int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && board.arr[y][x] != 1);
}

void blockSquare(chessBoard& board, string& position) {
    char column = position[0];              // letters are columns
    char row = position[1];                 // rows are numbers

    int colIndex = column - 'a';
    int rowIndex = row - '1';

    board.arr[rowIndex][colIndex] = 1;
}

void clearBoard(chessBoard& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board.arr[i][j] = 0;
        }
    }
}

void printBoard(const chessBoard& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board.arr[i][j] << " ";
        }
        cout << endl;
    }
}

int calculateMoves(chessBoard& board, string start, string end) {
    pair<int, int> startPos = convertToSquare(start);
    pair<int, int> endPos = convertToSquare(end);
    vector<vector<int>> dist(8, vector<int>(8, -1));                // keeps track of all the possible move choices and if it's been visited before

    queue<pair<int, int>> q;            // using a queue to implement breadth first search
    q.push(startPos);
    dist[startPos.second][startPos.first] = 0;          // starting position is 0

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == endPos.first && y == endPos.second) {
            return dist[y][x];
        }

        for (const pair<int, int>& move : possibleMoves) {
            int moveX = move.first;
            int moveY = move.second;

            int newX = x + moveX;
            int newY = y + moveY;

            if (canMove(board, newX, newY) && dist[newY][newX] == -1) {         // if move is available and it hasn't been visited yet
                dist[newY][newX] = dist[y][x] + 1;
                q.push({newX, newY});
            }
        }
    }
    return -1;
}

int main() {
    int numTaken = 0;
    int boardCount = 1;
    chessBoard board;
    string blocked;
    string start;
    string target;
    pair<int, int> startPos;
    pair<int, int> targetPos;
    vector<int> listOfBoards;

    cin >> numTaken;

    while (numTaken != -1) { 
        for (int i = 0; i < numTaken; i++) {
            cin >> blocked;
            blockSquare(board, blocked);
        }
        cin >> start >> target;

        int numMoves = calculateMoves(board, start, target);

        listOfBoards.push_back(numMoves);

        clearBoard(board);

        cin >> numTaken;
    }

    for (int i = 0; i < listOfBoards.size(); i++) {
        if (listOfBoards[i] == -1) {
            cout << "Board " << i + 1 << ": not reachable" << endl;
        } else {
            cout << "Board " << i + 1 << ": " << listOfBoards[i] << " moves" << endl;
        }
    }

    

    return 0;
}