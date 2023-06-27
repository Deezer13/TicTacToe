#pragma once

#include <vector>
#include <algorithm>

struct Vector2 {
	int x,
		y;
};

class GameMap
{
private:
	int** map;
	Vector2 size;
	int length;

public:
	GameMap();
	GameMap(Vector2, int);
	GameMap(int, int, int);
	~GameMap();

	bool SetPosition(Vector2, int);
	bool IsEmpty(Vector2);
	bool IsEmpty(int, int);
	void SetMap(Vector2, int);
	void SetMap(int, int, int);
	int GetValue(Vector2);
	int GetValue(int, int);
	int GetLength() { return length; };
	Vector2 GetSize() { return size; };
	int CheckList(std::vector<int> a);
	int CheckingWin();
	bool CanMove();
	Vector2 GetCenter();
};
