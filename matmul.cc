#include<bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[], int i, int j)
{
	if(i == j)
		return 0;

	int min = INT8_MAX;
	int count;

	for (int k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) +
				MatrixChainOrder(p, k+1, j) +
				p[i-1]*p[k]*p[j];

		if (count < min)
			min = count;
	}
}