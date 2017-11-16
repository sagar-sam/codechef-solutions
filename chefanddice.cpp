#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int flag=0;
		scanf("%d",&n);
		set<int> vec[7];
		int a;
		scanf("%d",&a);
		int b;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&b);
			if(a==b)
			{
				flag=1;
			}
			vec[a].insert(b);
			vec[b].insert(a);
			a=b;
		}
		if(flag==1)
		{
			printf("-1\n");
			continue;
		}
		int ans[7]={0};
		vector<int> va[7];
		for(int i=1;i<7;i++)
		{
			if(vec[i].size()>4)
			{
				flag=1;
				break;
			}
			else{
				set<int>::iterator it=vec[i].begin();
				for(int j=1;j<7;j++)
				{
					if(i!=j)
					{
						if(*it!=j)
						{
							va[i].push_back(j);
						}
						else{
							it++;
						}
					}
				}
			}
		}
		if(flag==1)
		{
			printf("-1\n");
			continue;
		}
		for(int i=0;i<va[1].size();i++)
		{
			for(int j=0;j<va[2].size();j++)
			{
				for(int k=0;k<va[3].size();k++)
				{
					for(int l=0;l<va[4].size();l++)
					{
						for(int m=0;m<va[5].size();m++)
						{
							for(int n=0;n<va[6].size();n++)
							{
								int temp[7]={0};
								temp[1]=va[1][i];
								temp[2]=va[2][j];
								temp[3]=va[3][k];
								temp[4]=va[4][l];
								temp[5]=va[5][m];
								temp[6]=va[6][n];
								int f=0;
								for(int o=1;o<7;o++)
								{
									if(temp[temp[o]]!=o)
									{
										f=1;
										break;
									}
								}
								if(f==0)
								{
									ans[1]=va[1][i];
									ans[2]=va[2][j];
									ans[3]=va[3][k];
									ans[4]=va[4][l];
									ans[5]=va[5][m];
									ans[6]=va[6][n];
									flag=2;
									break;
								}
							}
							if(flag==2)
								break;
						}
						if(flag==2)
							break;
					}
					if(flag==2)
						break;
				}
				if(flag==2)
					break;
			}
			if(flag==2)
				break;
		}
		if(flag==2)
		{
			for(int i=1;i<7;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		else printf("-1\n");
	}
}