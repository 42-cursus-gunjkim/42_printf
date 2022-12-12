#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int c = 10;
	ft_printf("%d%s %c  \n\n\n%X%x%u %p",123, "what are yuou doing", '\n', -2147483648, 2147483647, 1234123, &c);
	printf("\n %X %x %p",-2147483648, 2147483647, &c);
}