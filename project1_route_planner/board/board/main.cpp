#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

// ParseLine function accepts a string as an argument.
// Use istringstream to parse a line by comma chars, and store the ints in a vector<int>.
// ParseLine should return the vector after parsing.
vector<int> ParseLine(string line)
{
	istringstream my_stream(line);
	vector<int> v;
	char c;
	int n;
	while (my_stream >> n >> c)
	{
		v.push_back(n);
		//v.push_back(c);
		// Uncomment to include ',' comas
	}
	return v;
}

// This function should accept a string argument, which represents the path to the file
vector<vector<int>> ReadBoardFile(string path)
{
	vector<vector<int>> board;
	ifstream myfile(path);
	if (myfile)
	{
		string line;
		while (getline(myfile, line))
		{
			vector<int> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}

void PrintBoard(const vector<vector<int>> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

//#include "test.cpp" // For testing.

int main()
{
	vector<vector<int>> board;
	//string s = "files/1.board"; // for linux command line this path is enough
	string s = "C:/Users/diogo/OneDrive/Work/CS/OOP/cpp-code/project1_route_planner/board/board/files/1.board";
	board = ReadBoardFile(s);
	PrintBoard(board);
}