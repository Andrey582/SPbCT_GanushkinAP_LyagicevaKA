#pragma once
#include <string>
using namespace std;

ref class Visualisation
{
public:
	Visualisation(int**, int, int);
	Visualisation();
	~Visualisation();
	int fillTable(int**);
	void putIntoFile(int**);
	void outOfFile(int**);
private:
	int** tab;
	int n, m;
};

