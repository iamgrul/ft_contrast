#include "ft_contrast.h"

typedef struct s_contrast
{
	char *inputfile;
	char *outputfile;
	int contrastlvl;
	char *flags;
}	t_contrast;

void	ft_usage(void)
{
	ft_putstr("usage:  ./ft_contrast -f input_file.pgm -c contrast_value -o output_file.pgm\n\t./ft_contrast -f input_file.pgm -c contrast_value\n");
	exit(0);
}

void	ft_check_argv(int argc, char **argv, t_contrast *tc)
{
	int		i;

	i = 1;
	if (i + 1 < argc)
	{
		while (i + 1 < argc)
		{
			if (argv[i][1] == 'f')
				tc->inputfile = ft_strdup(argv[i + 1]);
			else if (argv[i][1] == 'o')
				tc->outputfile = ft_strdup(argv[i + 1]);
			else if (argv[i][1] == 'c')
				tc->contrastlvl = ft_atoi(argv[i + 1]);
			i += 2;
		}
	}
	else
		ft_usage();
}

int		main(int argc, char **argv)
{
	t_contrast *tc;

	tc = malloc(sizeof(t_contrast));
	ft_check_argv(argc, argv, tc);
	
	return(0);
}