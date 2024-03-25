#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define ASSERT(val) check( (val), #val, __FILE__, __LINE__ )
void	check(int val, const char *str, const char *file, int line)
{
	if (val)
		return ;
	fprintf(stderr, "\033[31mError at %s:%d: %s\n\033[0m", file, line, str);
	exit(1);
}

#endif
