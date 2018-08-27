/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:55:27 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 09:59:35 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_play
{
	int			place;
	int			dst;
	int			coords[3];
}				t_plays;

typedef struct	s_moves
{
	int				y;
	int				x;
	struct s_moves	*next;
}				t_moves;

typedef	struct	s_filler
{
	char		me;
	char		enemy;
	int			map_x;
	int			map_y;
	int			token_x;
	int			token_y;
	int			trim_token_y;
	int			trim_token_x;
	int			off[4];
	char		**map;
	char		**token;
	char		**trim_token;
	int			game_over;
	t_plays		*play;
}				t_filler;

void			push_back(t_moves **head, t_moves *node);
void			memory_manage(t_filler *f);
void			get_map(t_filler *f, int fd, char **line);
void			read_player(t_filler *f, int fd);
t_filler		*init_filler();
t_moves			*new_node(int y, int x);
int				best_move(t_filler *f, t_moves *head);
int				pythagoras(int l, int m, int *coords);
int				dst(t_filler *f, int l, int m);
void			compare_dst(t_filler *f, int l, int m);
void			get_token(t_filler *f, int fd);
void			get_trim_token(t_filler *f);
int				moves(t_filler *f);
void			place(t_filler *f, int i, int j);
long long		ft_sqr(int n);
void			dst_move(t_filler *f, int i, int j);
int				check_overlap(t_filler *f, int l, int m);
void			calculate_offset(t_filler *f);
#endif
