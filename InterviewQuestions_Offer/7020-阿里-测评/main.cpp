#include <iostream>
#include <math.h>

//int numMethods(int N, int P, int T, int M)
//{
//	if (abs(P-T))
//	{
//	}
//}
//
//
//
//int main()
//{
//	int N = 5, P = 1, T = 3, M = 2;
//
//
//}

//int n,p,m,t,i,j;   
//while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF){   
//	int dp[110][110];   
//	memset(dp,0,sizeof(dp));   
//	dp[0][p]=1;     
//	for(i=1;i<=m;++i)     //i分钟   
//		for(j=1;j<=n;++j) //第j位置   
//			dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1];//表示第i分钟到第j位置的移动方案总数为两边的移动方案之和   
//	printf("%d\n",dp[m][t]);   
//}   
//return 0;   
//http://blog.csdn.net/m0_37541228/article/details/77356715
#include <iostream>   
int main ()
{   
	//int N, P, T, M;
	//std::cin >> N >> P >> T >> M;

	int N = 3, P = 2, T = 2, M = 4;
	int i, j;
	int DataArray[110][110];
	memset(DataArray,0,sizeof(DataArray));
	DataArray[0][P] = 1;

	for(i=1; i<=M; ++i)
	{
		for(j=1;j<=N;++j)
		{
			DataArray[i][j] = DataArray[i-1][j+1] + DataArray[i-1][j-1];
		}
	}

	std::cout << DataArray[M][T] << std::endl;

	return 0;   
}  