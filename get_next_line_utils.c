//
// Created by jimmy on 02/02/2023.
//
#include "get_next_line.h"
#include "stdio.h"



int ft_strlen(const char *string)
{
	int index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}