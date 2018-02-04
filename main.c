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
void	ft_check_args(t_contrast *tc)
{
	if (!tc->inputfile)
		ft_usage();
	if (tc->contrastlvl > 100 || tc->contrastlvl < 0)
	{
		ft_putstr("contrast_value should be from 0 to 100\n");
		exit(0);
	}
}

void	ft_read_args(int argc, char **argv, t_contrast *tc)
{
	int		i;

	i = 1;
	if (i + 1 < argc)
		while (i + 1 < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == 'f' && !tc->inputfile)
				tc->inputfile = ft_strdup(argv[i + 1]);
			else if (argv[i][0] == '-' && argv[i][1] == 'o' && !tc->outputfile)
				tc->outputfile = ft_strdup(argv[i + 1]);
			else if (argv[i][0] == '-' && argv[i][1] == 'c' && tc->contrastlvl == -1)
				tc->contrastlvl = ft_atoi(argv[i + 1]);
			else 
				ft_usage();
			i += 2;
		}
	else
		ft_usage();
}

int		main(int argc, char **argv)
{
	t_contrast	*tc;
	int			fdi;
	int			fdo;

	tc = malloc(sizeof(t_contrast));
	tc->inputfile = NULL;
	tc->outputfile = NULL;
	tc->contrastlvl = -1;
	ft_read_args(argc, argv, tc);
	ft_check_args(tc);
	if ((fdi = open(tc->inputfile, O_RDONLY)) < 0)
	{
		ft_putstr("Can't open file ");
		ft_putendl(tc->inputfile);
	}
	fdo = (tc->outputfile) ? open(tc->inputfile,  O_WRONLY | O_CREAT) : 0;
	if (fdo < 0)
	{
		ft_putstr("Can't open file ");
		ft_putendl(tc->inputfile);
	}
	
	return(0);
}