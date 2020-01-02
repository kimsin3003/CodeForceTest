#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> result;
std::vector<std::string> cellState; 
int n, m;

void SetCellAsW(int i, int j);

void SetCellAsB(int i, int j)
{
	result[i][j] = 'B';
	if (i > 0 && cellState[i - 1][j] == '.')
	{
		SetCellAsW(i - 1, j);
	}
	if (j > 0 && cellState[i][j - 1] == '.')
	{
		SetCellAsW(i, j - 1);
	}
	if (i < n - 1 && cellState[i + 1][j] == '.')
	{
		SetCellAsW(i + 1, j);
	}
	if (j < m - 1 && cellState[i][j + 1] == '.')
	{
		SetCellAsW(i, j + 1);
	}
}

void SetCellAsW(int i, int j)
{
	result[i][j] = 'W';
	if (i > 0 && cellState[i - 1][j] == '.' && cellState[i - 1][j] != 'B')
	{
		SetCellAsB(i - 1, j);
	}
	if (j > 0 && cellState[i][j - 1] == '.' && cellState[i - 1][j] != 'B')
	{
		SetCellAsB(i, j - 1);
	}
	if (i < n - 1 && cellState[i + 1][j] == '.' && cellState[i - 1][j] != 'B')
	{
		SetCellAsB(i + 1, j);
	}
	if (j < m - 1 && cellState[i][j + 1] == '.' && cellState[i - 1][j] != 'B')
	{
		SetCellAsB(i, j + 1);
	}
}


int main()
{
	std::cin >> n;
	std::cin >> m;
	for (int i = 0; i < n; i++)
	{
		std::string line;
		std::cin >> line;
		cellState.push_back(line);
	}

	for (int i = 0; i < n; i++)
	{
		std::string initValue = "";
		for (int j = 0; j < m; j++)
		{
			initValue += '-';
		}
		result.push_back(initValue);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cellState[i][j] == '.' && result[i][j] == '-')
			{
				SetCellAsB(i, j);
			}
		}
		std::cout << result[i] << std::endl;
	}
}