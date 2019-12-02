/*
 *
 *  URL: https://leetcode.com/contest/weekly-contest-165/problems/number-of-burgers-with-no-waste-of-ingredients/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		float total_jumbo, total_small;
		total_jumbo = ((float)tomatoSlices - (float)cheeseSlices*2) / 2;
		total_small = (float)cheeseSlices - total_jumbo;
		if(total_jumbo >=0 && total_small>=0 && ceilf(total_jumbo) == total_jumbo && ceilf(total_small) == total_small)
			return {(int)total_jumbo, (int)total_small};
		else return {};
    }
};


int main() {
	Solution S1;
	int tomatoSlices1 = 16, cheeseSlices1 = 7;
	vector<int> sol1 = S1.numOfBurgers(tomatoSlices1, cheeseSlices1);
	cout << "[" << sol1[0] << ", " << sol1[1] << "] \n";

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


