/*
 *
 *  URL: https://leetcode.com/contest/weekly-contest-165/problems/find-winner-on-a-tic-tac-toe-game/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

void print(vector<vector<char>> board) {
	int r = board.size(), c = board[0].size(), i, j;
	cout << endl;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}


class Solution {
	public:
		string tictactoe(vector<vector<int>>& moves) {
			vector<vector<char>> tictac(3, vector<char> (3, '?'));

			for(int i=0; i<moves.size(); i++) {
				if(i%2 == 0)
					tictac[moves[i][0]][moves[i][1]] = 'A';
				else
					tictac[moves[i][0]][moves[i][1]] = 'B';
			}
			//print(tictac);

			if(tictac[1][1] != '?')
			{
				if(tictac[1][1] == tictac[0][0] && tictac[1][1] == tictac[2][2])
					return string(1, tictac[1][1]);
				if(tictac[1][1] == tictac[0][2] && tictac[1][1] == tictac[2][0])
					return string(1, tictac[1][1]);
			}
			for(int i=0; i<3; i++) {
				if(tictac[i][0] != '?' && tictac[i][0] == tictac[i][1] && tictac[i][0] == tictac[i][2])
					return string(1, tictac[i][0]);
				if(tictac[0][i] != '?' && tictac[0][i] == tictac[1][i] && tictac[0][i] == tictac[2][i])
					return string(1, tictac[0][i]);
			}
			if (moves.size() == 9) return "Draw";
			else return "Pending";
		}
};



int main() {
	Solution S1;
	vector<vector<int>> moves1{{0,0},{2,0},{1,1},{2,1},{2,2}};
	cout << "Output(moves1): " << S1.tictactoe(moves1) << endl;

	vector<vector<int>> moves2{{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
	cout << "Output(moves2): " << S1.tictactoe(moves2) << endl;

	vector<vector<int>> moves3{{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
	cout << "Output(moves3): " << S1.tictactoe(moves3) << endl;

	vector<vector<int>> moves4{{0,0},{1,1}};
	cout << "Output(moves4): " << S1.tictactoe(moves4) << endl;

#if GET_EXEC_TIME
	auto start = high_resolution_clock::now();
	// Invoke the code API here
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Duration: "<< duration.count() << " microseconds." << endl;
#endif

	return 0;
}




/*
 $> g++ -g sample.cpp -o sample.out
 $> gdb sample.out

 */


