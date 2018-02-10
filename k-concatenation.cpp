#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long int maxSubArraySum(vector<long long int> a, int size)
{
    long long int max_so = INT_MIN, max_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_here = max_here + a[i];
        if (max_so < max_here)
            max_so = max_here;

        if (max_here < 0)
            max_here = 0;
    }
    return max_so;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<long long int> vec(n);
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&vec[i]);
			sum+=vec[i];
		}

		if(k==1)
		{
			long long int ans=maxSubArraySum(vec,n);
			printf("%lld\n",ans);
			continue;
		}
		
		for(int i=0;i<n;i++)
		{
			vec.push_back(vec[i]);
		}
		long long int ind=-1;

		long long int max_so = INT_MIN, max_here = 0;

	    for (int i = 0; i < 2*n; i++)
	    {
	        max_here = max_here + vec[i];
	        if (max_so < max_here)
	        {
	        	ind=i;
	            max_so = max_here;
	        }

	        if (max_here < 0)
	            max_here = 0;
	    }
//	    return max_so;

//		long long int sub=maxSubArraySum(vec,2*n);
		long long int ans=max_so;
		if(sum>0)
		{
			if(ind<n)
			ans=ans+(k-1)*sum;
			else if(ind>=n)
				ans=ans+(k-2)*sum;
		}
		printf("%lld\n",ans);
	}
}