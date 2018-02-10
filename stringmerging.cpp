#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		char a[5005];
		char b[5005];
		scanf("%s",a);
		scanf("%s",b);
		vector<char> prev(n+1);
		vector<int> ans(n+1);
		prev[0]='\0';
		ans[0]=0;
		prev[1]=a[0];
		ans[1]=1;
		for(int i=1;i<n;i++)
		{
			int as=ans[i];
			if(a[i]!=a[i-1])
				as++;
			prev[i+1]=a[i];
			ans[i+1]=as;
		}
		for(int i=0;i<m;i++)
		{
			int as=ans[0];
			if(i==0)
				as++;
			else if(b[i]!=b[i-1])
				as++;
			prev[0]=b[i];
			ans[0]=as;
			for(int j=1;j<=n;j++)
			{
				int ascur=ans[j-1];
				if(a[j-1]!=prev[j-1])
					ascur++;
				int asprev=ans[j];
				if(b[i]!=prev[j])
					asprev++;
				if(ascur<asprev)
				{
					prev[j]=a[j-1];
					ans[j]=ascur;
				}
				else
				{
					prev[j]=b[i];
					ans[j]=asprev;
				}
			}
		}
		printf("%d\n",ans[n]);
	}
}
