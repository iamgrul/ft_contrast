#include "ft_contrast.h"

void	itoa_str(int num, char *ret, int *i)
{
	if (num >= 10000)
	{
		ret[*i] = (num / 10000) % 10 + '0';
		*i += 1;
	}
	if (num >= 1000)
	{
		ret[*i] = (num / 1000) % 10 + '0';
		*i += 1;
	}
	if (num >= 100)
	{
		ret[*i] = (num / 100) % 10 + '0';
		*i += 1;
	}
	if (num >= 10)
	{
		ret[*i] = (num / 10) % 10 + '0';
		*i += 1;
	}
	ret[*i] = num % 10 + '0';
	*i += 1;
}

void	ft_cgl(char *mem)
{
	char	*str;
	float	num;
	int		i;

	str = mem;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			num = 0;
			while (ft_isdigit(str[i]))
				num = (num * 10) + (str[i++] - '0');
			g_cgl = ft_max(g_cgl, num);
		}
		i++;
	}
}

void	ft_contrast(char *mem)
{
	char	*str;
	char	*ret;
	float	num;
	int		i;

	str = mem;

	if (!(ret = ft_strnew(ft_strlen(str))))
		return ;
	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (*str != 0)
			{
				num = 0;
				while (ft_isdigit(*str))
					num = (num * 10) + (*str++ - '0');
				num = num * (g_cgl / g_mgl * g_contr / 100);
			}
			itoa_str(num, ret, &i);
		}
		else
			ret[i++] = *str++;
	}
	ret[i] = '\0';
	mem = ret;
	ft_putstr_fd(mem, g_dest);
}

void	usage(void)
{
	ft_putstr("usage:  .\\ft_contrast -f src_file.pgm -c contrast_value -o dest_file.pgm\n\t.\\ft_contrast -f src_file.pgm -c contrast_value\n");
	exit(0);
}

void	fargs(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'f')
				g_src = open(argv[i + 1], O_RDONLY);
			if (argv[i][1] == 'c')
				g_contr = ft_atoi(argv[i + 1]);
		}
		i++;
	}
	if (!g_src || !g_contr || g_contr > 100 || g_contr <= -1)
		usage();
}

void	sargs(int argc, char **argv)
{
	int		i;
	
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'f')
				g_src = open(argv[i + 1], O_RDONLY);
			if (argv[i][1] == 'o')
				g_dest = open(argv[i + 1], O_WRONLY | O_CREAT, 0755);
			if (argv[i][1] == 'c')
				g_contr = ft_atoi(argv[i + 1]);
		}
		i++;
	}
	if (!g_src || !g_dest || !g_contr || g_contr > 100 || g_contr <= -1)
		usage();
}

int		*readcgl(int *lsik)
{
	int		rid;
	char	mem[LINE_SIZE + 1];

	rid = 0;
	while ((rid = read(g_src, mem, LINE_SIZE)))
	{
		*lsik -= rid;
		mem[rid] = '\0';
		ft_cgl(mem);
	}
	return (lsik);
}

void	readcontr(int lsik)
{
	int		rid;
	char	mem[LINE_SIZE + 1];

	lseek(g_src, lsik, SEEK_END);
	rid = 0;
	while ((rid = read(g_src, mem, LINE_SIZE)))
	{
		mem[rid] = '\0';
		ft_contrast(mem);
	}
}

int		main(int argc, char **argv)
{
	int		lsik;

	lsik = 0;
	if (argc == 5)
		fargs(argc, argv);
	else if (argc == 7)
		sargs(argc, argv);
	else
		usage();
	g_mgl = 10;
	readcgl(&lsik);
	g_mgl = ft_max(g_mgl, g_cgl);
	readcontr(lsik);
	close(g_src);
	close(g_dest);
	return(0);
}
