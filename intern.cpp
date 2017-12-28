#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
	double a=(double)(x2-x1)*(double)(x2-x1);
	double b=(double)(y2-y1)*(double)(y2-y1);

	float ans=sqrt(a+b);
	//printf("%lf\n",ans);
	return ans;
//	return sqrt((float)((float)(x2)-(float)(x1))*(float)((float)(x2)-(float)(x1))+(float)((float)(y2)-(float)(y1))*(float)((float)(y2)-(float)(y1)));
}

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> vec(n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vec[i]=make_pair(a,b);
	}
//	int indx;
	int ind;
	float max=0;
	for(int i=1;i<n;i++)
	{
		if(dist(vec[0].first,vec[0].second,vec[i].first, vec[i].second)>max)
		{
			max=dist(vec[0].first, vec[0].second, vec[i].first, vec[i].second);
			ind=i;
		}
	}
	for(int i=1;i<n;i++)
	{
		ind++;
		if(dist(vec[i].first, vec[i].second, vec[ind%n].first,vec[ind%n].second)>max)
		{
			max=dist(vec[i].first, vec[i].second, vec[ind%n].first, vec[ind%n].second);
		}
	}
	//printf("%f\n",max);
	float ans=max/2;
	ans=ans/(max+1);
	printf("%0.3f\n",ans);
}