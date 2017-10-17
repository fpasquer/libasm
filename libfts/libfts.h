/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:25:43 by fpasquer          #+#    #+#             */
/*   Updated: 2017/10/17 15:05:53 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <string.h>

void						ft_bzero(void *s, size_t n);
char						*ft_strcat(char *s1, char const *s2);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_tolower(int c);
int							ft_toupper(int c);
int							ft_puts(char const *str);

size_t						ft_strlen(char const *str);
void						*ft_memset(void *b, int c, size_t len);
void						*ft_memcpy(void *dest, void const *src, size_t n);
char						*ft_strdup(char const *str);
void						ft_cat(int fd);

char						*ft_strncat(char *s1, char const *s2, size_t n);
int							ft_putstr(char const *str);
char						*ft_strjoin(char const *s1, char const *s2);
void						ft_memdel(void **ptr);
char						*ft_strcpy(char *dest, char const *src);
char						*ft_strncpy(char *dest, char const *src, size_t n);
int							ft_strcmp(char const *s1, char const *s2);
//int						ft_strncmp(char const *s1, char const *s2, size_t n);
char						*ft_strchr(char const *str, int c);
char						*ft_strrchr(char const *str, int c);

#endif
