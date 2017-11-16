#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> vec[m];
	vector<int> arr[m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				int a;
				scanf("%d",&a);
				arr[i].push_back(a);
			}
		}
	}
	int a=n*n/m;
	int end=a;
	int start=0;
	for(int i=0;i<m;i++)
	{
		int ind=-1;
		int max=0;
		for(int j=start;j<end;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[i][j];
				ind=j;
			}
		}
		start=ind+1;
		end=end+a;
		int x=ind/n;
		int y=ind%n;
		printf("%d %d\n",x+1,y+1);
	}

/*
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int max=0;
			int indj;
			for(int k=0;k<n;k++)
			{
				int a;
				scanf("%d",&a);
				arr[i][j][k]=a;
				if(a>max)
				{
					indj=k;
					max=a;
				}
			}
			vec[i].push_back(indj);
		}
	}
	int a=0;
	int b=0;
	if(m==50)
	{
		for(int i=0;i<m;i++)
		{
			printf("%d %d\n",i+1,vec[i][i]+1);
		}
	}
	else 
	{
		int l=0;
		int r=0;
		for(int i=0;i<m;i++)
		{
			int max=0;
			int ind;
			for(int j=r;j<r+5;j++)
			{
				if(arr[i][l][j]>max)
				{
					max=arr[i][l][j];
					ind=j;
				}
			}
			printf("%d %d\n",l+1,ind+1);
			r=r+5;
			if(r==50)
			{
				l++;
				r=0;
			}
		}
	/*for(int i=0;i<m;i++)
	{
		printf("%d %d\n",a+1,b+1);
		a++;
		if(a==n)
		{
			b++;
			a=0;
		}
	}
		printf("-1 -1\n");*/
}