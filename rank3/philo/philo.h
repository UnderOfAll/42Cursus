/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:59:08 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/06 19:35:29 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <pthread.h>

#define P_MAX 250

typedef	struct	s_table	t_table;

typedef struct	s_philos
{
	pthread_t		thread;
	int				index;
	int				last_time_eaten;
	int				n_ate;
	t_table			*table;
}				t_philos;

typedef	struct	s_table
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_to_eat;

	int				dead;
	int				warn;
	
	t_philos		*philos;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	reaper;
	pthread_mutex_t	ate;
	
	time_t			start;
}				t_table;

//Helpers
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
time_t		time_in_ms(void);
void		output_event(t_table *table, int type);
void		ft_eat(t_table *table);
int			should_stop(t_table *table);
int			philo_loop(t_table *table);
void		better_usleep(long ms, t_table *table);

//Parser
int			parser(char **av);
long		ft_atoi(const char *str);

//Init
void    	init_table(t_table *table, int ac, char ** av);
int			init_philos(t_table *table);

//Routine
void		do_sleep(t_table *table);
void		eat(t_table *table);
void		think(t_table *table);
void		*alone(t_table *table);
void		*routine(void *arg);

//Threads
void		threads(t_table *table);

#endif