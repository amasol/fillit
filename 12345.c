#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
static void		qwert(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != '\n')
			i++;
		else if (*s == '\n' && i != 4)
		{
			printf("error\n");
			exit(1);
		}
		else
			i = 0;
		s++;
	}
}

int		main(int argc, char **argv)
{
//	char *s;

	char str[] = "...#.\n";

//	s = &str[0];
	// if (argc != 2)
	// {
	// 	printf("There must be one parameter!\n");
	// 	exit(1);
	// }
	qwert(str);
	return (0);
}
*/


/*
static void		 qwert(char *s) // проверка на валидность \n..не больше одного пробела после тетрм
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
//	char *s;

	char str[] = "\n\n";

//	s = &str[0];
	// if (argc != 2)
	// {
	// 	printf("There must be one parameter!\n");
	// 	exit(1);
	// }
	qwert(str);
	return (0);
}

 */



/*char	open(char *str, char argv)
{
	int		fd;
//	char 	*str;
	size_t	schet;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("errot\n");
		exit(1);
	}
	str = ft_memalloc(sizeof(char) * (550)); // ставить после (char *) или не ставить 
	schet = read(fd, str, 550);
	if (read < 20 || read > 545)
	{
		printf("error\n");
		exit(1);
	}
	close(fd);
	return (str); 
}

int		main()
{
	// if (argc != 2)
	// {
	// 	ft_putstr("There must be one parameter!\n");
	// 	exit(1);
	// }
	open(str);
	return (0);
}
*/


int		main(void)
{
	char str[] = "...";
	printf("%d", ft_check_three(str));
}





