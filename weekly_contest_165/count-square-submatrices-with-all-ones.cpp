/*
 *
 *  URL: https://leetcode.com/contest/weekly-contest-165/problems/count-square-submatrices-with-all-ones/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

void print(vector<vector<int>> board) {
	int r = board.size(), c = board[0].size();
	cout << endl;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

class Solution {
	public:
		int min(int x, int y, int z) {
			return (x<y)? ((x<z)? x : z) : ((y<z)? y : z);
		}

		int countSquares(vector<vector<int>>& matrix) {
			int r = matrix.size(), c = matrix[0].size(), square_submatrices_cnt = 0;
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
					if(i==0 || j==0)
						square_submatrices_cnt += matrix[i][j];
					else if(matrix[i][j]){
						matrix[i][j] = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]) + 1;
						square_submatrices_cnt += matrix[i][j];
					}
			//print(matrix);
			return square_submatrices_cnt;
		}
};


int main() {
	Solution S1;
	vector<vector<int>> matrix1{
			{0,1,1,1},
			{1,1,1,1},
			{0,1,1,1}};
	//cout << "Square Submatrices Count(matrix1): " << S1.countSquares(matrix1) << endl;
	vector<vector<int>> matrix2{
			{1,0,1},
			{1,1,0},
			{1,1,0}};
	cout << "Square Submatrices Count(matrix2): " << S1.countSquares(matrix2) << endl;


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


