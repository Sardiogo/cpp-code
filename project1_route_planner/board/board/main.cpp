#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> // for sort

using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

enum class State
{
	kEmpty,
	kObstacle,
	kClosed,
	kPath
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
 * bool Compare function to compare the f-value of two nodes.
 *  accepts two nodes of type vector<int> as arguments.
 * It should return a boolean true if the f-value of the first argument is greater than the f-value of the second, and it should return false otherwise.
 * Recall that the f-value is the sum of the cost and heuristic: f = g + h.
*/

bool Compare(vector<int> node_1, vector<int> node_2)
{
	// nodes {x, y, g, h}
	int g_node_1 = node_1[2];
	int h_node_1 = node_1[3];
	int f_node_1 = g_node_1 + h_node_1;

	int g_node_2 = node_1[2];
	int h_node_2 = node_2[3];
	int f_node_2 = g_node_2 + h_node_2;

	if (f_node_1 > f_node_2)
		return true; // any number != 0 ; default is 1.
	else
		return false; // 0
}

/**
 * The CellSort function uses the Compare function to determine the sorting order.
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>>* v)
{
	sort(v->begin(), v->end(), Compare); // Sorts the elements in the range [first, last] in ascending order.
}

/**
 * Heuristic function that is used to guide the A* search.
 * In general, any admissible function can be used for the heuristic,
 * but for this project, it takes a pair of 2D coordinates on the grid
 * (x1, y1, x2, y2) and returns the Manhattan Distance from one coordinate
 * to the other: ∣x2 − x1∣ + ∣y2 − y1∣.
 * (The Euclidean distance is the unique shortest path actually)
*/
int Heuristic(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

/**
 *  In order to expand your A* search from the current node to neighboring nodes, you first will need to check that neighboring grid cells are not closed, and that they are not an obstacle.
 * CheckValidCell accepts two ints for the x and y coordinates and a reference to the grid
 * The function should do two things:
 *      - Check that the (x, y) coordinate pair is on the grid.
 *      - Check that the grid at (x, y) is kEmpty (this is the default case if the grid cell is not kClosed or a kObstacle). If both of these conditions are true, then CheckValidCell should return true. Otherwise, it should return false.
*/
bool CheckValidCell(int x, int y, vector<vector<State>>& grid)
{
	// Check that the (x, y) coordinate pair is on the grid.
	bool on_grid_x = (x >= 0 && x < grid.size());
	bool on_grid_y = (y >= 0 && y < grid[0].size());
	if (on_grid_x && on_grid_y)
		// Check that the grid at (x, y) is kEmpty
		return grid[x][y] == State::kEmpty;
	return false;
}

/**
 * A* search, the search algorithm keeps a list of potential board cells to search through.
 * A board cell is a node and each node will consist of the following values which are needed for the A* algorithm: an x and y coordinate, the g value (or cost) that has accumulated up to that cell and the h value for the cell, given by the heuristic function.
 * AddToOpen function which accepts the following arguments:
 *      - x, y, g, and h values
 *      - References to one vector<vector<int>> for the vector of open nodes.
 *      - Reference to one vector<vector<State>> for the grid.
 * The AddToOpen function should do two things:
 *      - Create a vector<int> node with the form {x, y, g, h} and push the node to the back of the open vector.
 *      - Set the grid value for the x and y coordinates to the enum value kClosed.
*/
void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& open, vector<vector<State>>& grid)
{
	vector<int> node{ x, y, g, h };
	open.push_back(node);
	grid[x][y] = State::kClosed;
}

/**
 * Implementation of A* search algorithm.
 *  A* search works by sorting the open list using the f-value, and using the node with the lowest f-value as the next node in the search. This process continues until the goal node has been found or the open list runs out of nodes to use for searching.
 * Search function which takes a board grid and two length 2 int arrays as arguments.
 * The int arrays will represent the start and goal coordinates for the search.
 */
vector<vector<State>> Search(vector<vector<State>> grid, int initial_point[2], int goal_point[2])
{
	vector<vector<int>> open{}; // Create the vector of open nodes.
	// Initialize the starting node  {x, y, g, h}.
	int x = initial_point[0];
	int y = initial_point[1];
	int x_goal_point = goal_point[0];
	int y_goal_point = goal_point[1];
	int g = 0;
	int h = Heuristic(x, y, x_goal_point, y_goal_point);
	// Use AddToOpen to add the starting node to the open vector.
	AddToOpen(x, y, g, h, open, grid);
	// while open vector is non empty
	while (open.size() > 0)
	{
		// Sort the open list using CellSort, and get the current node {x, y, g, h}.
		CellSort(&open);
		auto current = open.back(); // access the last node
		open.pop_back();            // removes the last node
		// Get the x and y values from the current node, and set grid[x][y] to kPath.
		x = current[0];
		y = current[1];
		grid[x][y] = State::kPath;
		// Check if we're done. Check if you've reached the goal. If so, return grid.
		if (x == x_goal_point && y == y_goal_point)
		{
			return grid;
		}
		// If we're not done, expand search to current node's neighbors. This step will be completed later.
		// ExpandNeighbors
	}
	// We've run out of new nodes to explore and haven't found a path.
	vector<vector<State>> board{};
	cout << "No path found!\n";
	return board;
}

// CellString function accepts a State as input
// and returns the following strings:
// "⛰️   " if the input equals a kObstacle,
// "🚗   " if the input equals a kPath,
//  "0   " otherwise.
string CellString(State cell)
{
	// To use UTF-8 string literals you need to prefix them with u8 
	switch (cell)
	{
	case State::kObstacle:
		return u8"⛰️   ";
	case State::kPath:
		return u8"🚗   ";
	default:
		return "0   ";
	}
}

void PrintBoard(const vector<vector<State>> board)
{
	// std::vector<T>::size() returns the type size_t which is unsigned. Use size_t instead of int in for cycle.
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			cout << CellString(board[i][j]);
		}
		cout << "\n";
	}
}

#include "test.cpp" // For testing solution

int main()
{
	int init[2] = { 0, 0 }; //vector<int> init{0, 0};
	int goal[2] = { 4, 5 }; //vector<int> goal{4, 5};
	string s = "D:/OneDrive/Work/CS/OOP/cpp-code/project1_route_planner/board/board/files/1.board";
	//string s = "files/1.board"; // for linux command line this path is enough
	// vector<vector<int>> board;
	auto board = ReadBoardFile(s);
	auto solution = Search(board, init, goal);
	PrintBoard(solution);
	// Tests
	TestHeuristic();
	TestAddToOpen();
	TestCompare();
	TestSearch();
	TestCheckValidCell();
}