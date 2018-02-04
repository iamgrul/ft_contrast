#include "ft_contrast.h"

void	usage(void)
{
	ft_putstr("usage:  .\\ft_contrast -f src_file.pgm -c contrast_value -o dest_file.pgm\n\t.\\ft_contrast -f src_file.pgm -c contrast_value\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 5)
	{
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
		if (!g_src || !g_contr)
			usage();
	}
	else if (argc == 7)
	{
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
		if (!g_src || !g_dest || !g_contr)
		 usage();
	}
	else
		usage();
	return(0);
}