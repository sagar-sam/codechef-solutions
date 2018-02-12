#include <iostream>
#include <vector>

using namespace std;

int maina()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<double> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&vec[i]);
		}
		double c, d, s;
		scanf("%lf%lf%lf",&c,&d,&s);
		double time = (double)(d)/(double)(s);
		//printf("%lf\n",time);
		double firdep=0,firarr=0,secdep=0,secarr=0;
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			{
				firarr=firdep+time;
				secarr=secdep+time;
			}
			secarr=secarr-firarr;
			firarr=0;
			firdep=firarr+(double)(vec[i]);
			if(secarr<firdep)
			{
				secdep=firdep+(double)(vec[i]);
			}
			else
			{
				secdep=secarr+(double)(vec[i]);
			}
		}
		double ans = secdep-firdep;
		c--;
		ans=ans*(double)(c);
		printf("%0.9lf\n",ans);
	}
	return 0;
} 

int main()
{
	//maina();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int lar=0;
		vector<long long int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&vec[i]);
			if(vec[i]>lar)
			{
				lar=vec[i];
			}
		}
		long long int c, d, s;
		scanf("%lld%lld%lld",&c,&d,&s);
		double time = (double)(d)/(double)(s);
		double ans = (double)(lar*(c-1));
		//printf("%0.9lf\n",time);
		double firarr=0.00,firdep=0.00,lasarr=0.00,lasdep=0.00;
		/*for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				firdep = (double)(vec[0]);
				lasdep = (double)(c)*(double)(vec[0]);
			}
			else
			{
				firarr = firdep + time;
				lasarr = lasdep + time;
				lasarr = lasarr -firarr;
				firarr = 0;
				firdep = firarr + (double)(vec[i]);
				lasdep = lasarr + (double)(vec[i]);
				if(vec[i]>vec[i-1])
				{
					long long int wait = vec[i]-vec[i-1];
					lasdep = lasdep + (double)((c-1)*wait);
				}
			}
		}*/
		//double ans = (lasdep-firdep);
		printf("%0.9lf\n",ans);
	}
}
