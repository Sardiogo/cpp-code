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

enum class State
{
	kEmpty,
	kObstacle
};

// ParseLine function accepts a string as an argument.
// Use istringstream to parse a line by comma chars, and store the ints in a vector<int>.
// ParseLine should return the vector after parsing.
vector<State> ParseLine(string line)
{
	istringstream my_stream(line);
	vector<State> v;
	char c;
	int n;
	while (my_stream >> n >> c && c == ',')
	{
		switch (n)
		{
		case 0:
			v.push_back(State::kEmpty);
			break;
		default:
			v.push_back(State::kObstacle);
			break;
		}
	}
	return v;
}

// This function should accept a string argument, which represents the path to the file
// use ParseLine and return the board as a vector<vector<int>>
vector<vector<State>> ReadBoardFile(string path)
{
	vector<vector<State>> board;
	ifstream myfile(path);
	if (myfile)
	{
		string line;
		while (getline(myfile, line))
		{
			vector<State> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}

/**
 * Implementation of A* search algorithm
 * Search function which takes a board grid and two length 2 int arrays as
 * arguments. The int arrays will represent the start and goal coordinates
 * for the search.
 */
vector<vector<State>> Search(vector<vector<State>> grid, int initial_point[2], int goal_point[2])
{
	vector<vector<State>> board{};
	cout << "No path found!\n";
	return board;
}

// CellString function accepts a State as input
// and returns the following strings:
// "⛰️   " if the input equals a kObstacle,
//  "0   " otherwise.
string CellString(State cell)
{
	switch (cell)
	{
	case State::kObstacle:
		return "⛰️   ";
	default:
		return "0   ";
	}
}

void PrintBoard(const vector<vector<State>> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << CellString(board[i][j]);
		}
		cout << "\n";
	}
}

int main()
{

	int init[2] = { 0, 0 }; //vector<int> init{0, 0};
	int goal[2] = { 4, 5 }; //vector<int> goal{4, 5};
	string s = "C:/Users/diogo/OneDrive/Work/CS/OOP/cpp-code/test/test/files/1.board";
	//string s = "files/1.board"; // for linux command line this path is enough
	// vector<vector<int>> board;
	auto board = ReadBoardFile(s);
	auto solution = Search(board, init, goal);
	PrintBoard(solution);
}