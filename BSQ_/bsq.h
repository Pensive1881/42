/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbigeon <mbigeon@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:22:59 by mbigeon           #+#    #+#             */
/*   Updated: 2025/03/11 01:43:31 by mbigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H
# define BUFFER_SIZE 1024

# include <stdlib.h>   // For exit(), malloc(), free()
# include <unistd.h>   // For fork(), execlp(), dup2(), read(), write(), close()
# include <fcntl.h>    // For open() (if needed for file handling)

// Declare other functions and structures here
// int	main(int argc, **argv); does not need to be mentionned
void	get_data(const char *filename, int *height, int *width, char ***map);
void	find_values(char **ptr, int *height, int *width);
void	get_map(char ***map, int width, int height, char **ptr);

#endif
