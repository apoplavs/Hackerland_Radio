#include <stdio.h>
#include <stdlib.h>

int 	compare(const void * x1, const void * x2)
{
	return ( *(int*)x1 - *(int*)x2 );
}

void	ft_solve(int n, int k, int *x)
{
	int b;
	int pos;
	int end;
	int count;

	b = 0;
	pos = 0;
	end = 0;
	count = 0;
	qsort(x, n, sizeof(int), compare);
	while (b < n)
	{
		count++;
		pos = b;
		while (pos < n - 1 && x[pos + 1] - x[b] <= k)
			pos++;
		end = pos;
		while (end < n-1 && x[end + 1] - x[pos] <= k)
			end++;
		b = end + 1;
	}
	printf("%d", count);
}

int 	main()
{
	int n; 
	int k; 
	scanf("%d %d",&n,&k);
	int *x = malloc(sizeof(int) * n);
	for(int x_i = 0; x_i < n; x_i++){
		scanf("%d",&x[x_i]);
	}
	ft_solve(n, k, x);
	return 0;
}

