#include <bits/stdc++.h>

using namespace std;

#define RODS 3
#define N 3
int dp[N+1][RODS+1][RODS+1];

void intialize()
{
	for(int i = 0; i <= N; i++){
		for(int j = 1; j <= RODS; j++){
			for(int k = 1; k <= RODS; k++){
				dp[i][j][k] = INT_MAX;
			}
		}
	}
}

int mincost(int idx, int src, int dest, int costs[RODS][RODS])
{
	if (idx > N)
		return 0;

	if(dp[idx][src][dest] != INT_MAX)
		return dp[idx][src][dest];

	int rem = 6 - (src + dest);
	int ans = INT_MAX;

	int case1 = costs[src - 1][dest - 1]
				+ mincost(idx + 1, src, rem, costs)
				+ mincost(idx + 1, rem, dest, costs);

	int case2 = costs[src - 1][rem - 1]
				+ mincost(idx + 1, src, dest, costs)
				+ mincost(idx + 1, dest, src, costs)
				+ costs[rem - 1][dest - 1]
				+ mincost(idx + 1, src, dest, costs);

	ans = min(case1, case2);
	dp[idx][src][dest] = ans;

	return ans;
}

int main()
{
	int costs[RODS][RODS] = {{0,1,2},{2,0,1},{3,2,0}};
	intialize();
	cout << mincost(1, 1, 3, costs);
	return 0;
}