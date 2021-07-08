#include "NQueensProblem.h"
#include <iostream>

QueensProblem::QueensProblem(int _numOfQueens)
			:numOfQueens(_numOfQueens)
{
	chessTable.resize(numOfQueens);
	for (auto & chessRow : chessTable)
		chessRow.resize(numOfQueens);
}

void QueensProblem::solve()
{
	if (setQueens(0))
		printQueens();
	else
		cout << "There is no solution";
}

bool QueensProblem::setQueens(int colIndex)
{
	if (numOfQueens == colIndex)
		return true;
	for (int rowIndex = 0; rowIndex < numOfQueens; ++rowIndex)
	{
		if (isPlaceValid(rowIndex, colIndex))
		{
			chessTable[rowIndex][colIndex] = 1;
			if (setQueens(colIndex + 1))
			{
				return true;
			}
		}
		chessTable[rowIndex][colIndex] = 0;
	}

	return false;
}

bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const
{
	for (int i = 0; i < colIndex; i++)
	{
		if (chessTable[rowIndex][i] == 1)
			return false;
	}

	for (int i = rowIndex, j = colIndex; i >=0 && j >=0; i--, j--)
	{
		if (chessTable[i][j] == 1)
			return false;
	}

	for (int i = rowIndex, j = colIndex; i <numOfQueens && j >= 0; i++, j--)
	{
		if (chessTable[i][j] == 1)
			return false;
	}
	
	return true;
}

void QueensProblem::printQueens() const
{
	for (int i = 0; i < chessTable.size(); i++)
	{
		for (int j = 0; j < chessTable.size(); j++)
		{
			if (chessTable[i][j] == 1)
				cout << " * ";
			else
				cout << " - ";
		}
		cout << "\n";
	}
}
