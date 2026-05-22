/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:41:32 by acasper           #+#    #+#             */
/*   Updated: 2026/05/12 17:22:32 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arena.h"
#include <string.h>

static t_arena_chunk	*new_chunk(size_t size)
{
	t_arena_chunk	*chunk;

	chunk = malloc(sizeof(t_arena_chunk));
	if (!chunk)
		return (NULL);
	chunk->memory = malloc(size);
	if (!chunk->memory)
	{
		free(chunk);
		return (NULL);
	}
	chunk->size = size;
	chunk->used = 0;
	chunk->next = NULL;
	return (chunk);
}

t_arena	*arena_create(size_t chunk_size)
{
	t_arena	*arena;

	arena = malloc(sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->chunks = new_chunk(chunk_size);
	if (!arena->chunks)
	{
		free(arena);
		return (NULL);
	}
	arena->chunk_size = chunk_size;
	return (arena);
}

void	arena_destroy(t_arena *arena)
{
	t_arena_chunk	*chunk;
	t_arena_chunk	*next;

	if (!arena)
		return ;
	chunk = arena->chunks;
	while (chunk)
	{
		next = chunk->next;
		free(chunk->memory);
		free(chunk);
		chunk = next;
	}
	free(arena);
}

void	arena_reset(t_arena *arena)
{
	t_arena_chunk	*chunk;

	if (!arena)
		return ;
	chunk = arena->chunks;
	while (chunk)
	{
		chunk->used = 0;
		chunk = chunk->next;
	}
}

void	*arena_alloc(t_arena *arena, size_t size)
{
	t_arena_chunk	*chunk;
	void			*ptr;

	if (!arena || size == 0)
		return (NULL);
	chunk = arena->chunks;
	while (chunk)
	{
		if (chunk->size - chunk->used >= size)
		{
			ptr = (char *)chunk->memory + chunk->used;
			chunk->used += size;
			return (ptr);
		}
		if (!chunk->next)
			break ;
		chunk = chunk->next;
	}
	chunk->next = new_chunk(arena->chunk_size);
	if (!chunk->next)
		return (NULL);
	chunk = chunk->next;
	ptr = chunk->memory;
	chunk->used = size;
	return (ptr);
}

char	*arena_strdup(t_arena *arena, const char *s)
{
	size_t	len;
	char	*copy;

	if (!s)
		return (NULL);
	len = strlen(s) + 1;
	copy = arena_alloc(arena, len);
	if (!copy)
		return (NULL);
	memcpy(copy, s, len);
	return (copy);
}
