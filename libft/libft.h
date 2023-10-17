/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:58:58 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 05:49:42 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_atoi(const char *str);
char	*ft_strlencpy(char *dest, char const *src, int len);
size_t	ft_strlen(const char *str);

#endif
