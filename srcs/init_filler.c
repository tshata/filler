#include "../includes/filler.h"

void	read_player(t_filler *filler)
{
	int 	i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (line[i] == '1')
	{
		filler->me = 'o';
		filler->enemy = 'x';
	}
	else
	{
		filler->me = 'x';
		filler->enemy = 'o';
	}
}

t_filler *init_filler(void)
{
	t_filler *filler;

	filler = (t_filler *)ft_memalloc(sizeof(t_filler));
	filler->me = '-';
	filler->enemy = '-';
	filler->map_x = 0;
	filler->map_y = 0;
	filler->token_x = 0;
	filler->token_y = 0;
	filler->map = NULL;
	filler->token = NULL;
	filler->game_over = 0;
	filler->off[0] = 0;
	filler->off[1] = 0;
	filler->off[2] = 0;
	filler->off[3] = 0;
	filler->play = ft_memalloc(sizeof(t_plays));
	filler->play->place = 0;
	filler->play->dst = 20000000;
	filler->play->coords = ft_memalloc(sizeof(int) * 3);
	return (filler);
}
