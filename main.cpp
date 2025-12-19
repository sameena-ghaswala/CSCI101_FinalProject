#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream inData;

	//open input file 
	inData.open("input_file.txt");

	//to check if the file is open or not
	if (!inData.is_open()) {
		cout << "Error: file is not open" << endl;
		return 1;
	}
	
	int maxX = 0;
	int maxY = 0;

	int x, y;
	char ch;

	//read x, and y coordinate into x and y. also read character into ch.
	while (inData >> x >> ch >> y) {
		if (x > maxX) {
			maxX = x;
		}
		if (y > maxY) {
			maxY = y;
		}
	}

	//close the input file
	inData.close();

	// open the input file
	inData.open("input_file.txt");

	//to check if the file is open or not
	if (!inData.is_open()) {
		cout << "Error: file is not open" << endl;
		return 1;
	}

	//create 2D array 
	vector<vector<char>> grid(maxY + 1, vector<char>(maxX + 1, ' '));

	//read x coordinate, character and y coordinate to fill in the array.
	while (inData >> x >> ch >> y) {
		grid[y][x] = ch;
	}

	//close the input file.
	inData.close();

	//print 2D array using a loop.
	for (int i = 0; i <= maxY; ++i) {
		for (int j = 0; j <= maxX; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}

