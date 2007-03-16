#include <stdio.h>
#include <assert.h>

#define M            3
#define L            27    /* 3^M */
#define N            12

int solution[N];
int used[L];
int negations[L];
int counts[M][3];
int scales[L][M];
int max_capacity[3] = { 4, 4, 4 };
int num_backtracks = 0;

void
print_scales (int i)
{
    int j;

    for (j = 0; j < M; ++j)
	printf("%d", scales[i][j]);
}

void
work (int n)
{
    int i, j, k;

    if (n == N)
    {
	printf("(%d) ", num_backtracks);

	for (i = 0; i < N; ++i)
	{
	    print_scales(solution[i]);
	    printf(" ");
	}
	printf("\n");

	return;
    }

    for (i = 1; i < L; ++i)
    {
	if (used[i] || used[negations[i]])
	    goto next_try;

	for (j = 0; j < M; ++j)
	    if (counts[j][scales[i][j]] == max_capacity[scales[i][j]])
		goto next_try;

	used[i] = used[negations[i]] = 1;
	for (j = 0; j < M; ++j)
	    ++counts[j][scales[i][j]];

	solution[n] = i;

	work(n + 1);

	used[i] = used[negations[i]] = 0;
	for (j = 0; j < M; ++j)
	    --counts[j][scales[i][j]];
    next_try:
    }

    ++num_backtracks;
}

int
main (void)
{
    int i, j, k;

    for (i = 0; i < M; ++i)
	counts[i][0] = counts[i][1] = counts[i][2] = 0;

    for (i = 0; i < M; ++i)
	scales[0][i] = 0;
    for (i = 1; i < L; ++i)
    {
	for (j = 0; j < M; ++j)
	    scales[i][j] = scales[i - 1][j];
	for (j = 0; j < M; ++j)
	    if (scales[i][j] < 2)
	    {
		++scales[i][j];
		break;
	    }
	    else
		scales[i][j] = 0;
    }

    for (i = 1; i < L; ++i)
    {
	for (j = 0; j < L; ++j)
	{
	    for (k = 0; k < M; ++k)
		if (!((scales[i][k] == 0 && scales[j][k] == 0)
		      || (scales[i][k] == 1 && scales[j][k] == 2)
		      || (scales[i][k] == 2 && scales[j][k] == 1)))
		    break;

	    if (k == M)
		break;
	}

	assert(j < L);

	negations[i] = j;
    }

    for (i = 0; i < L; ++i)
	used[i] = 0;

    /*
    for (i = 0; i < L; ++i)
    {
	print_scales(i);
	printf(" ");
    }
    printf("\n");
    for (i = 0; i < L; ++i)
    {
	print_scales(i);
	printf("-");
	print_scales(negations[i]);
	printf(" ");
    }
    printf("\n\n");
    */

    work(0);

    return 0;
}
