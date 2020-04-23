#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m, n;
	scanf_s("%d %d", &m, &n);

	bool* eratos = (bool*)malloc(sizeof(bool) * n);

	for (int i = 0; i < n; i++)
		eratos[i] = true;

	eratos[0] = false;

	for (int i = 1; i <= n; i++)
	{
		if (eratos[i - 1] == false)
			continue;

		for (int j = 2; j*i <= n; j++)
			eratos[i*j - 1] = false;
	}

	for (; m <= n; m++)
	{
		if (eratos[m - 1] == true)
			printf("%d\n", m);
	}

	free(eratos);

	return 0;
}