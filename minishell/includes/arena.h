/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:39:52 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:39:53 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdlib.h>

typedef struct s_arena_chunk
{
	void	*memory;
	size_t	size;
	size_t	used;
	struct s_arena_chunk	*next;
}	t_arena_chunk;

typedef struct	s_arena
{
	t_arena_chunk	*chunks;
	size_t	chunk_size;
}	t_arena;

// lifecycle
t_arena	*arena_create(size_t chunk_size);
void	arena_destroy(t_arena *arena);
void	arena_reset(t_arena *arena);

// allocation
void	*arena_alloc(t_arena *arena, size_t size);
char	*arena_strdup(t_arena *arena, const char *s);

#endif
