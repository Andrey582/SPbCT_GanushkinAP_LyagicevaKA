#include "Visualisation.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

Visualisation::Visualisation()
{
	n = 0;
	m = 0;
	int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
}

Visualisation::Visualisation(int** tabb, int n, int m)
{
	this->n = n;
	this->m = m;
	this->tab = tabb;
	//int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
}


int Visualisation::fillTable(int** tab)
{
	srand(time(0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
	return**tab;
}

void Visualisation::putIntoFile(int** tab) {
	fout.open("forTable.txt");
	fout << "x,y\n";
	for (int i = 0; i < n; i++)
	{
		fout << tab[i][0] << ",";
		fout << tab[i][1] << "\n";
	}
	fout.close();
}

void Visualisation::outOfFile(int** tab)
{
	int count = 0;
	int j = 0;
	char* buffer = new char[8];
	char* buffer2 = new char[3];

	fin.open("forTable.txt");
	fin.seekg(5, ios_base::beg);
	for (int i = 0; i < n; i++)
	{
		fin.getline(buffer, 8, '\n');
		for (int i = 0; i < 8; i++)
		{

				buffer2[count] = buffer[i];
				count++;


			if (buffer[i] == ',')
			{
				tab[j][0] = stoi(buffer2);
				count = 0;
				for (int c = 0; c < 3; c++)
					buffer2[c] = '\0';
				continue;
			}

			if (buffer[i] == '\0')
			{
				tab[j][1] = stoi(buffer2);
				count = 0;
				j++;
				for (int c = 0; c < 3; c++)
					buffer2[c] = '\0';
				break;
			}
		}
	}
	fin.close();
	delete[] buffer;
	delete[] buffer2;
}


Visualisation::~Visualisation()
{
	delete[] tab;
}