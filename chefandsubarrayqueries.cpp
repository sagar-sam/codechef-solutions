#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,q,l,r;
	scanf("%d%d%d%d",&n,&q,&l,&r);
	vector<int> vec(n);
	for(int i=0;i<n;i++)
	{
		if(0<=r && 0>=l)
		{
			vec[i]=1;
		}
	}
	//printf("1 ");
	while(q--)
	{
		//printf("2 ");
		int type;
		int x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type==1)
		{
		//	printf("3 ");
			if(y<=r && y>=l)
			{
				vec[x-1]=1;
			}
			else if(y<l)
			{
				vec[x-1]=0;
			}
			else if(y>r)
			{
				vec[x-1]=2;
			}
		}
		else
		{
			//printf("4 ");
			long long int ans=0;
			x--;
			y--;
			for(int i=x;i<=y;i++)
			{
				//printf("5 ");
				if(vec[i]==0 || vec[i]==1)
				{
					int j=i;
					int count=0;
					int count1=0;
					int ind;
					while(i<=y && (vec[i]==1 || vec[i]==0))
					{
						count++;
						if(vec[i]==1)
						{
							ind = i-j;
							count1++;
							ans=ans+(long long int)count;
						}
						else if(vec[i]==0)
						{
							if(count1!=0)
							{
								ans=ans+(long long int)(ind+1);
							}
						}
						i++;
					}
					i--;
				}
			}
			printf("%lld\n",ans);
		}
	}
}