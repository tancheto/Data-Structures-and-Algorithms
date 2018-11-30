// labirinT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

int main()
{
	int m, n, k;

	std::cin >> m;
	std::cin >> n;
	std::cin >> k;

	bool** arr = new bool*[m];
	int ** indx = new int*[m];
	bool** visited = new bool*[m];

	int visitedNum = 0;
	int visitableAll=m*n;

	for (int i = 0; i < m; i++)
	{
		arr[i] = new bool[n];
		indx[i] = new int[n];
		visited[i] = new bool[n];

		for (int j = 0; j < n; j++)
		{
			std::cin >> arr[i][j];
			if (arr[i][j])
			{
				visitableAll--;
			}
			indx[i][j] = 0;
			visited[i][j] = false;
		}
	}

	std::queue<std::vector<int>> myQ;

	myQ.push({0,0});

	visited[0][0] = true;
	indx[0][0] = 0;

	int level = 0;
	int i, j;

	while (visitedNum < visitableAll)
	{
		std::vector<int> last;
		last = myQ.front();
		i = last[0];
		j = last[1];
		level++;

		if (i-1>=0 && !visited[i-1][j] && !arr[i-1][j])
		{
			last[0] = i - 1;
			last[1] = j;

			visited[i - 1][j] = true;
			visitedNum++;

			indx[i - 1][j] = level;

			myQ.push(last);
		}
		if (j+1<=n && !visited[i][j + 1] && !arr[i][j + 1])
		{
			last[0] = i;
			last[1] = j + 1;

			visited[i][j + 1] = true;
			visitedNum++;

			indx[i][j + 1] = level;

			myQ.push(last);
		}
		if (i+1<=m && !visited[i + 1][j] && !arr[i + 1][j])
		{
			last[0] = i + 1;
			last[1] = j;

			visited[i + 1][j] = true;
			visitedNum++;

			indx[i + 1][j] = level;

			myQ.push(last);
		}
		if (j-1>=0 && !visited[i][j - 1] && !arr[i][j - 1])
		{
			last[0] = i;
			last[1] = j - 1;

			visited[i][j - 1] = true;
			visitedNum++;

			indx[i][j - 1] = level;

			myQ.push(last);
		}
	}

	int x;
	int y;

	for (int s = 0; s < k; s++)
	{
		std::cin >> x;
		std::cin >> y;

		std::cout<<indx[x][y]<<std::endl;
	}

	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
		delete[] indx[i];
		delete[] visited[i];
	}

	delete[] arr;
	delete[] indx;
	delete[] visited;

    return 0;
}

