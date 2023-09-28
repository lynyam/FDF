//open, close, read, write,
//malloc, free, perror,
//strerror, exit

#include "data.h"

int     data_open_file(char *file_name)
{
	int	fd;

	printf("%s\n", file_name);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		report_exit_program("Can't open file");
	} 
	return fd;
}

void	count_line(char *buf, int *line)
{
	while (*buf != EOF && *buf != '\0')
	{
		if (*buf == '\n')
			*line += 1;
		else
			;
		buf++;
	}
}

int	count_row(char *buf, int *row)
{
	while (*buf != EOF && *buf != '\0' && *buf != '\n')
	{
		while (*buf != 32 && *buf != EOF && *buf != '\0' && *buf != '\n')
			buf++;
		if (*buf == 32)
			*row += 1;
		while (*buf == 32)
			buf++;
	}
	if (*buf == '\n')
	{
		*row += 1;
		return (-1);
	}
	return (0);
}

int	**allocate_matrix(int line, int row)
{
	int	**m;
	int	i;

	m = NULL;
	i = 0;
	m = (int **)malloc(line * sizeof(int *));
	if (m == NULL)
		return (NULL);
	while (i < line)
	{
		m[i++] = (int *)malloc(row * sizeof(int));
	}
	return m;
}

int	ft_strlen(char	*start, char *end)
{
	int	len;

	len = 0;
	while (start < end)
	{
		len++;
	}
	return (len);
}

int	put_str_to_int(char *start, char *end)
{
	int	nbr;
	int	len;
	char	*current;

	nbr = 0;
	len = end - start;
	printf("len est : %d\n", len);
	while (len >= 0)
	{
		nbr += (pow(10, len) * (*current - '0'));
		start++;
		len--;
	}
	return nbr;
}

void	print_matrix(int **matrix, int n, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int	init_matrix_with_file(int ***matrix, int line, int row, char *str)
{
	int	n;
	char buff[BUFSIZE];
	char	*start;
	char	*end;
	int	index_row;
	int	index_line;
	char	*curr;

	index_row = 0;
	index_line = 0;

	curr = str;
	while (*curr != '\0')
	{
		if (*curr != 32 && *curr != '\0')
		{
			start = curr;
		}
		while (*curr != 32 && *curr != '\0')
		{
			curr++;
		}
		if (*curr == 32 || *curr == '\0' || *curr =='\n')
		{
			end = curr - 1;
			if (index_line < line && index_row < row)
			{
				(*matrix)[index_line][index_row] = put_str_to_int(start, end);
			}
			else
			{
				return (0);
			}
               		if (*curr == 32)
			{
				index_row++;
			}
		}
		while (*curr == 32)
		{
			curr++;
		}
		if (*curr == '\n')
		{
			index_line++;
			index_row = 0;
			curr++;
		}
	}
		
	print_matrix(*matrix, line, row);
	return (1);
}

/*void	get_matrix_size(int fd, int *line, int *row, int *file_len)
{
	int	n;
	char	buf[BUFSIZE];
	int	first_line;

	first_line = 0;
	while ((n = read(fd, buf, BUFSIZE)) >  0)
	{
		printf("%s\n==============\n", buf);
		*file_len += n;
		count_line(buf, line);
		if (*row == 0 || first_line != -1)
			first_line = count_row(buf, row);
	}
}
*/
char	*ft_concat(char *s1, char *s2, int s1_len, int nbr_char_s2)
{
	char	*target;
	char	*rtn;
	
	rtn = (char *)malloc(sizeof(char) * (s1_len + nbr_char_s2 + 1));
	target = rtn;
	//if (target == NULL)
		//return NULL;
	target[s1_len + nbr_char_s2] = '\0';
	while (s1 && *s1 != '\0' && --s1_len >= 0)
	{
		*target++ = *s1++;
	}
	while (*s2 != '\0' && --nbr_char_s2 >= 0)
	{
		*target++ = *s2++;
	}
	return (rtn);
}

void	data_read_file(int fd)
{
	int	n;
	char	c;
	char	buf[BUFSIZE];
	int	line;
	int	row;
	int	first_line;
	int	**matrix;
	int	rtn_init;
	int	file_len;
	char	*file_str;
	int	index;
	int	old_n;

	line = 0;
	row = 0;
	first_line = 0;
	rtn_init = 0;
	file_len = 0;
	index = 0;
	old_n = 0;
	file_str = NULL;
	while ((n = read(fd, buf, BUFSIZE)) >  0)
	{
		printf("%s\n==============\n", buf);
		file_len += n;
		printf("%d\n==============\n", file_len);
		file_str = ft_concat(file_str, buf, old_n, n);
		printf("ligne est: %d \ncolonne est: %d \nfile_len est: %d\n", line, row, file_len);
		old_n = n;
		count_line(buf, &line);
		if (row == 0 || first_line != -1)
			first_line = count_row(buf, &row);
	}
	
	printf("ligne est: %d \ncolonne est: %d \nfile_len est: %d\n", line, row, file_len);

	matrix = allocate_matrix(line, row);
	if (matrix == NULL)
		return;
	file_str = NULL;
	printf("\n==================\n");
	printf("%s,\n", file_str);

	printf("\n==================\n");
	rtn_init = init_matrix_with_file(&matrix, line, row, file_str);
	if (rtn_init != 1)
	{	
		printf("matrix non initialiser\n");
		return;
	}
	else
	{
		print_matrix(matrix, line, row);
	}
	printf("\n==================\n");
}

