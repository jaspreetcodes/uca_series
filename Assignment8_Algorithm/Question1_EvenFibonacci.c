long long int EvenFibonacci(long long int n) {
	long long int i, fn, ln, temp;
	ln = 0;
	fn = 2;
	for(i = 0; i < n; i++)
	{
	    temp = fn;
	    printf("%lld ",fn);
	    fn = (fn*4) + ln;
	    ln = temp;
	}
	return ln;

}
