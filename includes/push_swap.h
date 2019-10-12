/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:30:06 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 21:40:15 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OK 3
# define ERROR 4
# define BUFF_SIZE 1000
# define ATOP (*psa)->order
# define ASEC a->second->order
# define ALAST a->last->order
# define ANEXTDIST tmp->anextdist
# define APREVDIST tmp->aprevdist
# define BNEXTDIST tmp->bnextdist
# define BPREVDIST tmp->bprevdist
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct			s_push
{
	int					order;
	int					data;
	int					position;
	int					turn;
	int					aprevdist;
	int					anextdist;
	int					bprevdist;
	int					bnextdist;
	int					result;
	struct s_push		*next;
	struct s_push		*prev;
}						t_push;

typedef struct			s_ptrs
{

	int					biggest_ord;
	int					middle;
	int					middle_ord;
	t_push				*second;
	t_push				*last;
	t_push				*faster;
}						t_ptrs;

/*
** push_swap.c
*/

int						main(int ac, char **av);

/*
** checker.c
*/

int						main(int ac, char **av);
void					gnl_executor(t_push **psa, t_push **psb,
							char *line, char *av);

/*
** validator.c
*/

void					valid_and_push_arg(char *av, t_push **ps, int *order);
int						valid_arg(char *av, t_push **ps, int *order);
void					check_num(char *av, int *i, t_push **ps, int *order);
void					error_output(void);

/*
** manipulate_struct.c
*/

void					struct_init(t_push **ps, int *order, char *buf);
void					add_node(t_push **ps, int *order, char *buf);
t_push					*ps_lstnew(t_push **ps, int order, char *buf);
void					ps_deletehead(t_push **ps);
t_push					*create_zero(void);

/*
** sort_order.c
*/

void					sort_order(t_push **ps, int order);
void					sort_arr(int *tmp, int order);
void					reinit_order(int *tmp, t_push **ps, int order);
void					biggest_and_middle(t_push **ps);

/*
** get_next_line.c
*/

int						get_next_line(const int fd, char **line);

/*
** commander.c
*/

void					commander(char *line, t_push **psa, t_push **psb);
void					small_commander(char *line, t_push **ps);
void					is_it_sorted(t_push *psa, t_push *psb);
void					ok_output(void);
void					ko_output(void);
void					go_to_head(t_push **ps);

/*
** orders.c
*/

void					order_sa_sb(t_push **ps);
void					sa_sb_swap(t_push **ps, t_push *psn,
							t_push **next);
void					order_ss(t_push **psa, t_push **psb);
void					order_pa_pb(t_push **psa, t_push **psb);
void					pa_pb_with_next(t_push **psa, t_push **psb,
							t_push **nexta);
void					order_ra_rb(t_push **psa);
void					order_rr(t_push **psa, t_push **psb);
void					order_rra_rrb(t_push **psa);
void					order_rrr(t_push **psa, t_push **psb);

/*
** write_orders.c
*/

void					write_order_ra(t_push **psa);
void					write_order_rra(t_push **psa);
void					write_order_sa(t_push **psa);
void					write_order_rb(t_push **psb);
void					write_order_rrb(t_push **psb);
void					write_order_sb(t_push **psb);
void					write_order_pa (t_push **psb, t_push **psa);
void					write_order_pb(t_push **psa, t_push **psb);
void					write_order_ss(t_push **psa, t_push **psb);
void					write_order_rr(t_push **psa, t_push **psb);
void					write_order_rrr(t_push **psa, t_push **psb);

/*
** sort_algorithm.c
*/

void					sort_algorithm(t_push **psa, t_push **psb);
int						is_it_sorted2(t_push **psa, t_ptrs *a);
void					init_ptrs(t_push **psa, t_ptrs **a);
void					init_sec_and_last(t_push **psa, t_ptrs **a);
void					push_stack_b(t_push **psa, t_ptrs *a, t_push **psb);
void					where_you_go(t_push **psa, t_ptrs *a);
void					sort_three_elem(t_push **psa, t_ptrs *a);
void					sort_stacks(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs **b);
void					last_rotate(t_push **psa, t_ptrs *a);
void					push_stack_a(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
int						find_shortest_way(t_push **psa, t_ptrs *a);
void					rr_or_rrr(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					ss_sa_or_sb(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					no_ways_rr(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					no_ways_rrr(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					check_rr(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					check_rrr(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
int						half_sort_a(t_push **psa);
int						half_sort_b(t_ptrs *b);
void					find_links(t_push **psa, t_ptrs *a, t_push **psb,
							t_ptrs *b);
void					refresh_links(t_push **ps);

/*
** analize_stack_a.c
*/

void					analize_stack_a(t_push **psa, t_ptrs **a, t_push **psb);
void					analize_stack_a1(t_push **psa, t_ptrs **a,
							t_push **tmpb, t_push *tmpa);
void					sort_three_elem2(t_push **psa, t_ptrs *a,
							t_push *smallest);

/*
** analize_stack_b.c
*/

void					analize_stack_b(t_push **psb, t_ptrs **b, int turndown);
void					stack_len(t_push **ps, t_ptrs **p);

/*
** which_way.c
*/

void					which_way(t_push **psa, t_push **psb, int turndown);
void					the_best_result(t_push **psa, t_push **psb);
void					distributor(t_push **best, t_push **psa, t_push **psb);
void					sort_less_5_ints(t_push **psa, t_ptrs *a, t_push **psb);
void					where_is_smallest(t_push **psa, t_ptrs *a,
							t_push **psb);

/*
** commands.c
*/

void					command1(t_push **best, t_push **psa, t_push **psb);
void					command2(t_push **best, t_push **psa, t_push **psb);
void					command3(t_push **best, t_push **psa, t_push **psb);
void					command4(t_push **best, t_push **psa, t_push **psb);
void					init_positions(t_push **ps);

/*
** vizualization.c
*/

void					vizualization(t_push *psa, t_push **psb);
void					only_a(t_push **a);
void					only_b(t_push **b);
void					end_of_vizualization(int order);

/*
** colors.c
*/

void					red(void);
void					green(void);
void					reset(void);
void					cyan(void);

#endif
