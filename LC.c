/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:43:35 by abonard           #+#    #+#             */
/*   Updated: 2022/02/22 02:07:12 by abonard          ###   ########.fr       */
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

void	ft_les_pointyeurs(int *nbr)
{
	*nbr = 69;
}

void	ft_delete_last_list(t_list	*guy)
{
	t_list	*guyguy;

	guyguy = malloc(sizeof(t_list));
	guyguy = guy;
	while(guyguy->next->next != NULL)
	{
		guyguy = guyguy->next;
	}
	guyguy->next = NULL;
	free(guy);
}

void	ft_sa(t_list *a)
{
	t_list	c;

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
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->next = NULL;
	tmp = list->next;
	list = tmp;
	free(tmp);

	ft_print_list(list);
}

void	ft_pa(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->next = NULL;

	if (b != NULL)
	{
		tmp->nbr = b->nbr;
		tmp->next = a;
		a = tmp;
		ft_delete_head_node(b);
	}
	free(tmp);
}

void	ft_pb(t_list *b, t_list *a)
{
	ft_pa(b, a);
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
	ft_new(a, 78);

	b->nbr = 55;
	ft_new(b, 41);
	ft_new(b, 3);
	ft_new(b, 77);

/*	ft_count_list(guy);
	ft_delete_last_list(guy);
	ft_count_list(guy);
*/	ft_print_list(a);

	return (0);
}
