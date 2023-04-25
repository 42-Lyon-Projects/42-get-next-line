#include <stdio.h>
#include "fcntl.h"
#include "../get_next_line.h"


void	print_line(char *buffer)
{
	static int line = 72;
	printf("%s", buffer);
	line++;
}

int main()
{

	int		file_descriptor = open("/home/jimmy/CLionProjects/GNL/tests/texts/no_nl.txt", O_RDONLY);
	int test = 10;
	while(test > 0)
	{
		print_line(get_next_line(file_descriptor));
		test--;
	}
	return (0);

}
