#include "checker.h"
#include "../libasm/libasm.h"

int	main(void)
{
	{	// FT_STRLEN
		ASSERT(ft_strlen("") == 0);
		ASSERT(ft_strlen("Hello World!") == 12);
		ASSERT(ft_strlen("Hello\0World!") == 5);

		printf("\033[32m[+] ft_strlen\n\033[0m");
	}

	{	// FT_STRCPY
		char	buf[13];

		ASSERT(ft_strcpy(buf, "Hello World!") == buf);
		ASSERT(strcmp(buf, "Hello World!") == 0);

		ASSERT(ft_strcpy(buf, "") == buf);
		ASSERT(strcmp(buf, "") == 0);

		printf("\033[32m[+] ft_strcpy\n\033[0m");
	}

	{	// FT_STRCMP
		ASSERT(ft_strcmp("", "") == 0);
		ASSERT(ft_strcmp("Hello World!", "Hello World!") == 0);
		ASSERT(ft_strcmp("Hello World!", "") > 0);
		ASSERT(ft_strcmp("", "Hello World!") < 0);
		ASSERT(ft_strcmp("Hello World!", "Hello") > 0);
		ASSERT(ft_strcmp("Hello", "Hello World!") < 0);

		printf("\033[32m[+] ft_strcmp\n\033[0m");
	}

	{	// FT_WRITE
		int		fd[2];
		char	buf[13] = "Hello World!";
		char	buf2[13];

		pipe(fd);
		memset(buf2, 0, sizeof(buf2));

		ASSERT(ft_write(fd[1], buf, 0) == 0);

		ASSERT(ft_write(fd[1], buf, 4) == 4);
		ASSERT(read(fd[0], buf2, 4) == 4);
		ASSERT(strncmp(buf2, buf, 4) == 0);

		ASSERT(ft_write(fd[1], buf, -1) == -1);
		ASSERT(errno == EFAULT);

		ASSERT(ft_write(fd[1], NULL, -1) == -1);
		ASSERT(errno == EFAULT);

		ASSERT(ft_write(4242, buf, 13) == -1);
		ASSERT(errno == EBADF);

		printf("\033[32m[+] ft_write\n\033[0m");
	}

	{	// FT_READ
		int		fd[2];
		char	buf[13] = "Hello World!";
		char	buf2[13];

		memset(buf2, 0, sizeof(buf2));
		pipe(fd);
		write(fd[1], buf, sizeof(buf));

		ASSERT(ft_read(fd[0], buf2, 0) == 0);

		ASSERT(ft_read(fd[0], buf2, 4) == 4);
		ASSERT(strncmp(buf, buf2, 4) == 0);

		ASSERT(ft_read(fd[0], buf2+4, 9) == 9);
		ASSERT(strncmp(buf+4, buf2+4, 9) == 0);

		ASSERT(ft_read(fd[0], buf2, -1) == -1);
		ASSERT(errno == EFAULT);

		ASSERT(ft_read(fd[0], NULL, -1) == -1);
		ASSERT(errno == EFAULT);

		ASSERT(ft_read(4242, buf2, 10) == -1);
		ASSERT(errno == EBADF);

		printf("\033[32m[+] ft_read\n\033[0m");
	}

	{	// FT_STRDUP
		char	*str;

		str = ft_strdup("Hello World!");
		ASSERT(strcmp(str, "Hello World!") == 0);
		free(str);

		str = ft_strdup("");
		ASSERT(str != NULL);
		ASSERT(strcmp(str, "") == 0);
		free(str);

		printf("\033[32m[+] ft_strdup\n\033[0m");
	}

	return (0);
}