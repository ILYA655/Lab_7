#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>

using namespace std;

void BFSD(int** G, int n, int* dist, int s)
{
	queue<int> q;
	q.push(s);
    dist[s] = 0;
	cout << "BFSD result: ";
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		cout << s << " ";
		for (int j = 0; j < n; j++)
		{
			if (G[s][j] > 0 && dist[j] > dist[s] + G[s][j])
			{
				dist[j] = dist[s] + G[s][j];
				q.push(j);
			}
		}
	}
}

int** create(int n) 
{
	int** G, k = 1;
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++)
		{
			G[i][j] = (rand() % 10);
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			G[j][i] = G[i][j];
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

int** create_o(int n) 
{
	int** G, k = 1;
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++)
		{
			G[i][j] = (rand() % 10);
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			G[j][i] = (rand() % 10);
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

int** create_on(int n) 
{
	int** G, k = 1;
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++)
		{
			G[i][j] = (rand() % 2);
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			G[j][i] = (rand() % 2);
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

int** create_n(int n)
{
	int** G, k = 1;
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++)
		{
			G[i][j] = (rand() % 2);
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			G[j][i] = G[i][j];
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

int main(int argc, char *argv[])
{
	int n, s, ** t, ** t1, ** t2, ** t3;
	cout << "Enter array size: ";
	cin >> n;
	int* dist = (int*)malloc(n * sizeof(int));
	cout << "Enter vertex: ";
	cin >> s;
	for (int i = 0; i < n; i++)
		dist[i] = INT16_MAX;
	if(argc > 0){
		for (int i = 0; i < argc; ++i){
			if ((strcmp(argv[i], "0") == 0)){ //неориентированный взвешенный
				t = create(n);
				cout << endl;
				BFSD(t, n, dist, s);
				cout << endl;
			}
			if ((strcmp(argv[i], "1") == 0)){ //ориентированный взвешенный
				t1 = create_o(n);
				cout << endl;
				BFSD(t1, n, dist, s);
				cout << endl;
			}
			if ((strcmp(argv[i], "2") == 0)){ //ориентированный невзвешенный
				t2 = create_on(n);
				cout << endl;
				BFSD(t2, n, dist, s);
				cout << endl;
			}
			if ((strcmp(argv[i], "3") == 0)){ //неориентированный невзвешенный
				t3 = create_n(n);
				cout << endl;
				BFSD(t3, n, dist, s);
				cout << endl;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		free(t3[i]);
	free(t3);
	for (int i = 0; i < n; i++)
		free(t2[i]);
	free(t2);
	for (int i = 0; i < n; i++)
		free(t1[i]);
	free(t1);
	for (int i = 0; i < n; i++)
		free(t[i]);
	free(t);
	free(dist);
	system("pause");
	return 0;
}
