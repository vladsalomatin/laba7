#define _CRT_SECURE_NO_WARNINGS
#define _CTR_NONSTDC_NO_WARNINGS
#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <random>
#include <malloc.h>
#include <locale>

void dfs(int v, int **mat, int *vershins, int m) {
	vershins[v] = true;
	printf("%d ", v);
	for (int i = 0; i < m; i++)
	{
		if (mat[v][i] == 1 && vershins[i] == 0)
		{
			dfs(i, mat, vershins, m);
		}
	}

}
int main()
{
	int **mat;
	int *vershins;
	int m;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("input size: ");
	scanf_s("%d", &m);
	mat = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		mat[i] = (int*)malloc(m * sizeof(int));
	}
	vershins = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				mat[i][j] = rand() % 2;
				if (mat[i][j] == 0)
					mat[i][j] = mat[i][j];
				else
					mat[i][j] = rand() % 2;
			}
			mat[j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %4d", mat[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		vershins[i] = false;
	}
	int v;
	printf("¬ведите вершину: ");
	scanf_s("%d", &v);
	dfs(v, mat, vershins, m);


	getchar();
	getchar();
	return 0;

}
