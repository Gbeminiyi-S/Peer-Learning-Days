#include "3-calc.h"

int main(int argc, char **argv)
{
	int a = atoi(argv[1]);
	int b = atoi(argv[3]);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (!get_op_func(argv[2]))
	{
		printf("Error\n");
		exit(99);
	}

	if ((*(argv[2]) == '/') || (*(argv[2]) == '%'))
	{
		if (b == 0)
		{
			printf("Error\n");
			exit(100);
		}
	}
	printf("%d\n", (get_op_func)(argv[2])(a, b));
	return (0);
}
