/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:35:15 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 23:35:17 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

int		ft_atoi(const char *str);
char	*ft_strlencpy(char *dest, char const *src, int len);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strchr(const char *s, int c);
long	ft_strtol(const char *str, char **endptr, int base);

#endif
