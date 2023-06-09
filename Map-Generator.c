#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include<fcntl.h>

#define MAP_SIZE_MAX 40

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}


size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str && !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*b;

	i = 0;
	b = malloc(ft_strlen((char *)s1) + 1);
	if (!b)
		return (0);
	while (s1[i])
	{
		b[i] = s1[i];
		i++;
	}
	b[i] = 0;
	return (b);
}

int	replace(int z, int p, int i, char **map)
{
	if (map[z][i + 1] == '0' || map[z][i + 1] == 'C' || map[z][i + 1] == 'E')
	{
		map[z][i + 1] = 'P';
		p = 1;
	}
	if (map[z][i - 1] == '0' || map[z][i - 1] == 'C' || map[z][i - 1] == 'E')
	{
		map[z][i - 1] = 'P';
		p = 1;
	}
	if (map[z + 1][i] == '0' || map[z + 1][i] == 'C' || map[z + 1][i] == 'E')
	{
		map[z + 1][i] = 'P';
		p = 1;
	}
	if (map[z - 1][i] == '0' || map[z - 1][i] == 'C' || map[z - 1][i] == 'E')
	{
		map[z - 1][i] = 'P';
		p = 1;
	}
	return (p);
}

int	ft_strchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'E' || str[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

int	path_finder(char **map)
{
	int	p;
	int	i;
	int	z;

	p = 1;
	z = 0;
	i = 0;
	while (p == 1)
	{
		p = 0;
		z = 0;
		while (map[z])
		{
			i = 0;
			while (map[z][i])
			{
				if (map[z][i] == 'P')
				{
					p = replace(z, p, i, map);
				}
				i++;
			}
			z++;
		}
	}
	i = 0;
	while (map[i])
	{
		if (ft_strchar(map[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	**generate_map(int rows, int columns,int coine)
{
	int		i;
	int		j;
	char	**map;
	int		x;
	int		k;
	int		z;

	map = calloc(sizeof(char *), rows + 1);
	i = rows;
	while (--i >= 0)
	{
		j = columns;
		free(map[i]);
		map[i] = calloc(sizeof(char), j + 1);
		while (--j >= 0)
		{
			map[i][j] = '0';
		}
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][ft_strlen(map[i]) - 1] == '0')
			map[i][ft_strlen(map[i]) - 1] = '1';
		if (map[i][0] == '0')
			map[i][0] = '1';
		while (map[i][j])
		{
			if (map[0][j] == '0')
				map[0][j] = '1';
			if (map[rows - 1][j] == '0')
				map[rows - 1][j] = '1';
			j++;
		}
		i++;
	}
	i = 1;
	x = 0;
	k = 0;
	z = 0;
	x = coine;
	while (i < x)
	{
		k = rand() % rows;
		z = rand() % columns;
		if (k < rows && k > 0 && z < columns && z > 0 && map[k][z] == '0')
		{
			map[k][z] = 'C';
		}
		i++;
	}
	x = 1;
	while (x)
	{
		k = rand() % (rows - 1);
		z = rand() % (columns - 1);
		if (k < rows && k > 0 && z < columns && z > 0 && map[k][z] == '0')
		{
			map[k][z] = 'P';
			x = 0;
		}
	}
	x = 1;
	while (x)
	{
		k = rand() % (rows - 1);
		z = rand() % (columns - 1);
		if (k < rows && k > 0 && z < columns && z > 0 && map[k][z] == '0')
		{
			map[k][z] = 'E';
			x = 0;
		}
	}
	i = 1;
	x = (rows * columns) / 2;
	while (i < x)
	{
		k = rand() % (rows - 1);
		z = rand() % (columns - 1);
		if (k < rows && k > 0 && z < columns && z > 0 && map[k][z] == '0')
		{
			map[k][z] = '1';
		}
		i++;
	}
	return (map);
}

char	**bckup(char **old_map, int rows)
{
	int		i;
	int		j;
	char	**map;

	map = calloc(sizeof(char *), rows + 1);
	i = 0;
	while (old_map[i])
	{
		map[i] = ft_strdup(old_map[i]);
		i++;
	}
	return (map);
}
void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print(char *str)
{
	int i;
	i = 0;
   while (str[i] != '\0') 
   {
		printf("%c",str[i]);
   		fflush(stdout);
   		usleep(10000);
		i++;
   }
}
int	main(void)
{
	char	**map;
	char	**backup;
	int		rows;
	int		columns;
	int		i;
	int		x;
    int     coine;
	i = 0;
	x = 1;
    coine = 0;
	system("chmod 777 .doflamingo.sh");
	system("./.doflamingo.sh");
	print("\033[0;31mDO🦩> \033[0;37m\033[0;32mUsage: Do not enter a number greater than 40 and less than 3. It does not apply to coins you can enter 0 in coins for random number\033[0;37m \n");
	printf("============================================\n");
	print("Enter the number of rows:\033[0;31m DO🦩>\033[0;37m  ");
	scanf("%d", &rows);
	print("Enter the number of columns:\033[0;31m DO🦩>\033[0;37m  ");
	scanf("%d", &columns);
	print("Enter the number of coin :\033[0;31m DO🦩>\033[0;37m  ");
	scanf("%d", &coine);
	printf("============================================\n");
    if(coine == 0)
        coine = (rows * columns) / 3;
	if (rows > MAP_SIZE_MAX || columns > MAP_SIZE_MAX || rows <= 3 || columns <= 3  || coine > (rows * columns) || coine == 0)
	{
		print("{\033[0;31m Error Please do not enter a number greater than 40 and less than 3. It does not apply to coins, you can enter 0 in coins for a random number \033[0;37m}\n");
		return (1);
	}
	map = generate_map(rows, columns,coine);
	backup = bckup(map, rows);
	while (x)
	{
		free_all(backup);
		backup = bckup(map, rows);
		if (path_finder(map) == 0)
			x = 0;
		else
		{
			free_all(map);
			map = generate_map(rows, columns,coine);
		}
	}
	int fd = open("map.ber",O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0644);
	i = 0;
	while(backup[i])
	{
		ft_putstr_fd(backup[i],fd);
		if(backup[i + 1])
			write(fd,"\n",1);
		i++;
	}
	print("\033[0;31mDO🦩> \033[0;32mThe file was created successfully. Check the file named {map.ber}.\033[0;37m");
	close(fd);
}
