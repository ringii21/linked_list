/
************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:43:35 by abonard           #+#    #+#             */
/*   Updated: 2022/02/22 21:10:43 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_list
{
	int	nbr;
	struct s_list *next;
	struct s_list *prev;
} t_list;

void	ft_print_list(t_list *guy)
{
	t_list *guyguy;

	guyguy = guy;
	while (guyguy->next != NULL)
	{
		printf("%d\n", guyguy->nbr);
		guyguy = guyguy->next;
	}
	printf("%d\n", guyguy->nbr);
}

void	ft_new(t_list *guy, int nb) // creer un nouveau maillon et le coller a la liste
{
	t_list	*lili;
	t_list	*guyguy;

	guyguy = guy;
	lili = malloc(sizeof(t_list));
	lili->next = NULL;
	lili->prev = NULL;
	lili->nbr = nb;
	while (guyguy->next != NULL)
	{
		guyguy = guyguy->next;
	}
	guyguy->next = lili;
	lili->prev = guyguy;
}

int	ft_count_list(t_list *guy)
{
	int	i;
	t_list	*guyguy;

	i = 0;
	guyguy = guy;
	while (guyguy)
	{
		guyguy = guyguy->next;
		i++;
	}
	printf("longueur de la liste : %d\n", i);
	return (i);
}


void	ft_delete_last_list(t_list	*guy)
{
	t_list	*guyguy;

	guyguy = guy;
	while(guyguy->next->next != NULL)
	{
		guyguy = guyguy->next;
	}
	guyguy->next = NULL;
	free(guyguy);
}

void	ft_sa(t_list *a)
{
	t_list	c;

	if (ft_count_list(a) < 2)
		return;
	c.nbr = a->nbr;
	a->nbr = a->next->nbr;
	a->next->nbr = c.nbr;
}

void	ft_sb(t_list *b)
{
	ft_sa(b);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sa(b);
}

void	ft_delete_head_node(t_list *list)
{
	t_list	*guyguy;

	guyguy = list;
	while (guyguy->next != NULL)
	{
		guyguy->nbr = guyguy->next->nbr;
		guyguy = guyguy->next;
	}
	guyguy = guyguy->prev;
	guyguy->next = NULL;
	free(guyguy);
}

void	ft_pa(t_list **a, t_list *b)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->prev = NULL;
	tmp->nbr = b->nbr;
	tmp->next = *a;
	(*a)->prev = tmp;
	(*a) = (*a)->prev;
	ft_delete_head_node(b);
}

void	ft_pb(t_list **b, t_list *a)
{
	ft_pa(b, a);
}

void	ft_ra(t_list *a)
{
	int		c;

	c = a->nbr;
	while (a->next != NULL)
	{
		a->nbr = a->next->nbr;
		a = a->next;
	}
	a = a->prev;
	a->next->nbr = c;
}

void	ft_rb(t_list *b)
{
	ft_ra(b);
}

void	ft_rr(t_list *a, t_list *b)
{
	ft_ra(a);
	ft_ra(b);
}


///////////////////////////////////////
void	ft_rra(t_list *a)
{
	int	c;

	while (a->next != NULL)
	{
		a = a->next;
	}
	c = a->nbr;
	while (a->prev != NULL)
	{
		a->nbr = a->prev->nbr;
		a = a->prev;
	}
	a = a->next;
	a->prev->nbr = c;
}

void	ft_rrb(t_list *b)
{
	ft_rra(b);
}

void	ft_rrr(t_list *a, t_list *b)
{
	ft_rra(a);
	ft_rra(b);
}
/////////////////////////////////////

long long int	add

/////////////////////////////////////

int	ft_push_swap(t_list *a)
{
	t_list	*b;
	int		median;
	int		n;
	
	n = ft_count_list(a);

	while (ft_count_list(a) <= (n / 2))
	{
		//top 
		if ()
	}
}

int	main (int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a  = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	a->prev = NULL;
	a->next = NULL;
	b->next = NULL;
	b->prev = NULL;

	a->nbr = 10;
	ft_new(a, 22);
	ft_new(a, 56);
//	ft_new(a, 78);

	b->nbr = 55;
	ft_new(b, 41);
	ft_new(b, 3);
//	ft_new(b, 77);

/*	ft_count_list(b);
	ft_delete_last_list(b);
	ft_count_list(b);*/

	ft_print_list(a);
	printf("------------------\n");
	ft_print_list(b);
	printf("--- BELOW CHANGED ---\n");
	ft_rrr(a, b);
	ft_print_list(a);
	printf("------------------\n");
	ft_print_list(b);

	return (0);
}
