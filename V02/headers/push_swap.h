#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include "sys/errno.h"
# include "limits.h"


typedef	struct s_len
{
	// int	stack_a;
	int	stack_len;
	// int	stack_b;
	// int	min;
	// int	max;
}	t_len;

typedef struct s_lst
{
	long long		content;
	// long long		LIS;
	// long long		parse_it;
	// long long		parse_it_back;
	// int				front;
	// int				back;
	t_len			lenght;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;




/// @brief
/// @param error_msg
/// @param garbg
void	ft_exit(char *error_msg, t_list **garbg);

/// @brief
/// @param pointer
/// @param garbg
/// @return
void	*ft_malloc(void *pointer, t_list **garbg);

/// @brief
/// @param garbg
/// @param stack
/// @param av
/// @param ac
/// @return
int	ft_parse(t_list **garbg, t_lst **stack, char **av, int ac);






t_len		ft_lis_controll(t_lst **stack_a, t_lst **stack_b, int ac); // V
void		get_lis(t_lst *list); // V
int			get_max_lis(t_lst *list); // V
int			check_lis_sorted(t_lst *list); // V
int			check_lis_rev_sorted(t_lst *list); // V
int			check_lis(t_lst *list); // V
int			sequence_len(t_lst *stack, int len); // V
void		lis_divide(t_lst **stack_a, t_lst **stack_b, int ac); // V
int			define_sequence(t_lst *list, int max_lis); // V

/*^^^^^^^^^^^^^^^^^^ DIR : sort_functions ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : push_functions.c >>>>>>>>>>>>>>>>>>*/
void		push_a(t_lst **stack_a, t_lst **stack_b);
void		push_b(t_lst **stack_b, t_lst **stack_a);

/*<<<<<<<<<<<<<<<<<< FILE : reverse_functions.c >>>>>>>>>>>>>>>>>>*/
void		reverse_b(t_lst **stack, int ind);
void		reverse_a(t_lst **stack, int ind);
void		rrr(t_lst **stack_a, t_lst **stack_b);

/*<<<<<<<<<<<<<<<<<< FILE : rotate_functions.c >>>>>>>>>>>>>>>>>>*/
void		rotate_a(t_lst **stack, int ind);
void		rotate_b(t_lst **stack, int ind);
void		rr(t_lst **stack_a, t_lst **stack_b);

/*<<<<<<<<<<<<<<<<<< FILE : swap_functions.c >>>>>>>>>>>>>>>>>>*/
void		swap_a(t_lst **head, int ind);
void		swap_b(t_lst **head, int ind);
void		ss(t_lst **stack_a, t_lst **stack_b);
void		ss(t_lst **head_a, t_lst **head_b);

/*^^^^^^^^^^^^^^^^^^ DIR : utils ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			still_digits(char *str); // V
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			min(int nbr1, int nbr2);
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
int			max(int nbr1, int nbr2); // V
/*<<<<<<<<<<<<<<<<<< FILE : utils.c >>>>>>>>>>>>>>>>>>*/
long long	ft_atolld(char **str); // V

/*<<<<<<<<<<<<<<<<<< FILE : ft_split_count.c >>>>>>>>>>>>>>>>>>*/
// char		**ft_split_count(char const *s, char c, int *count);

/*^^^^^^^^^^^^^^^^^^ DIR : controllers ^^^^^^^^^^^^^^^^^^*/

/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// t_len		ft_comb_controll(t_lst **stack_a, t_lst **stack_b, t_len lenght);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// void		get_combs_back(t_lst **stack_a, t_lst **stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// void		get_combs_front(t_lst **stack_a, t_lst **stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			combs_conditions(t_lst *stack_a, t_lst *stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_first_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_second_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_last_comb(t_lst *stack_a, t_lst *stack_b, t_len length);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			be_secondlast_comb(t_lst *stack_a, t_lst *stack_b);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
// int			select_small_comb(t_lst *stack, int len);
/*<<<<<<<<<<<<<<<<<< FILE :place_controller.c >>>>>>>>>>>>>>>>>>*/
void	check_places(t_lst *stack_a, t_lst *stack_b);
int		check_max_min_back(t_lst *stack_a, t_lst *stack_b, int place_b);
void	check_front_back(t_lst *stack_a, t_lst *stack_b);
void	check_back_back(t_lst *stack_a, t_lst *stack_b);


/*<<<<<<<<<<<<<<<<<< FILE : sort_controller.c >>>>>>>>>>>>>>>>>>*/
void		ft_sort_controller(t_lst *stack_a, int ac); // V
void		define_place(t_lst **stack_a, int i, int ind);
void		ft_sort_rev(t_lst *stack_a); // V
int			small_element(t_lst *stack); // V
int			define_small(t_lst *stack, int min); // V
int			high_element(t_lst *stack); // V
void		both_front(t_lst **stack_a, t_lst **stack_b, int ind); // V
void		both_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
void		b_front_a_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
int			check_place_in_a(t_lst *stack, int min); // V
void		a_front_b_back(t_lst **stack_a, t_lst **stack_b, int ind); // V
/*<<<<<<<<<<<<<<<<<< FILE : sort_controller.c >>>>>>>>>>>>>>>>>>*/
void		sort(t_lst **head_b, t_lst **head_a, t_len lenght);

/*<<<<<<<<<<<<<<<<<< FILE : stack_controller.c >>>>>>>>>>>>>>>>>>*/
void		print_stack(t_lst *tmp, t_lst *tmp1);
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_table(t_lst **stack, char **av, int ac); // V
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_check_input_dup(t_lst *stack, int ac); // V
/*<<<<<<<<<<<<<<<<<< FILE : input_controller.c >>>>>>>>>>>>>>>>>>*/
int			ft_check_input_digits(char **av, int ac); // V

/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		new_node(t_lst **head, long long nbr, int ind); // V
void		set_lenght(t_lst **stack, int ref); // V
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
// void		add_node(t_lst **head, long long nbr);
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
void		del_node(t_lst **head); // V
/*<<<<<<<<<<<<<<<<<< FILE : lists_controllers_functions.c >>>>>>>>>>>>>>>>>>*/
// void		ft_lstdup(t_lst **new_stack, t_lst *stack, int ac);


#endif
