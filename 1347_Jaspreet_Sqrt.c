#include <stdio.h>
float squareRoot(int n, int p)
{
    //binary search for integral part of square root
	int start=0,end=n;
	int mid;
    double ans;
	while (start<=end) {
		mid=(start+end)/2;
		if (mid*mid==n) {
			ans=mid;
			return ans;
		}
		if (mid * mid < n) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}
	
	// for decimal part of square root upto given p
	float increment = 0.1;
	for (int i = 0; i < p; i++) {
		while (ans * ans <= n) {
			ans += increment;
		}
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}

//main
int main()
{
    int n ,p;
    scanf("%d %d",&n,&p);
    printf("%g",squareRoot(n,p));
	return 0;
}