#include <stdio.h>
/**
 * main - Print the arguments
 * @ac: Entry point
 * @av: Pointer
 * Return: 0.
 */
int main(int ac, char **av)
{
	int i;
	// Iteraating throught the arguments
	for (i = 1; av[i] != NULL; ++i)
	{
		printf("Argument %d: %s\n", i, av[i]);
	}
	return 0;
}
