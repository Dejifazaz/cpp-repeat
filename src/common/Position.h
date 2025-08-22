#ifndef POSITION_H
#define POSITION_H

#include <iostream>         // March 2022
using namespace std;

/**
 * Position struct for representing 2D coordinates
 * - used by Bug classes for tracking position on the board
 * - provides basic coordinate operations
 */

struct Position 
{
	int x;
	int y;
	
	Position() : x(0), y(0) {}
	Position(int xPos, int yPos) : x(xPos), y(yPos) {}
	
	bool operator==(const Position& other) const 
	{
		return x == other.x && y == other.y;
	}
	
	bool operator!=(const Position& other) const 
	{
		return !(*this == other);
	}
	
	friend ostream& operator<<(ostream& os, const Position& pos) 
	{
		os << "(" << pos.x << "," << pos.y << ")";
		return os;
	}
};

#endif // POSITION_H
