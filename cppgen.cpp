#include <stdio.h>

unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		int arr[n][n]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				arr[i][j]=0;
		}
		for(int i=0;i<n;i++)
		{
			int min=1000000000;
			int ind;
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==0 && C[i][j]<min && i!=j)
				{
					min=C[i][j];
					ind=j;
				}
			}
			arr[i][ind]=arr[ind][i]=1;
		}
		int max=0;
		int x,y;
		for(int i=0;i<n;i++)
		{
			int count=0;
			for(int j=0;j<n;j++)
			{
				if(arr[i][j])
					count++;
			}
			if(count>=2)
			{
				for(int j=0;j<n;j++)
				{
				if(arr[i][j]==1 && C[i][j]>max)
				{
					max=C[i][j];
					x=i;
					y=j;
				}
				}
			}
		}
		arr[x][y]=arr[y][x]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		// solve here
	}
	
	return 0;
}
