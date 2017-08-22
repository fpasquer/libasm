/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:24:17 by fpasquer          #+#    #+#             */
/*   Updated: 2017/08/04 22:43:44 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts/libfts.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

#define LEN_TAB 10

typedef struct				s_test
{
	int						i;
	char					tab[LEN_TAB + 1];
	double					val;
	void					*ptr;
}							t_test;

void						print_tests(t_test const test, char const *name)
{
	if (name == NULL)
		return ;
	printf("\t%s.i = %d\n\t%s.tab='%s'\n\t%s.val = %f\n\t%s.ptr = %p'\n\n",
			name, test.i, name, test.tab, name, test.val, name, test.ptr);
}



int							main(void)
{
///////////////////////////////////////////////////////////////////////////////
//	ft_bzero
///////////////////////////////////////////////////////////////////////////////
	printf("ft_bzero\n");
	t_test					test1;
	test1.i = 12;
	test1.tab[0] = '\0'; //pour pouvoir faire fonctionner strncat
	strncat(test1.tab, "Florian Pasquereau", LEN_TAB);
	test1.val = 12312.908;
	test1.ptr = &test1;
	print_tests(test1, "bzero_init");
	ft_bzero(&test1, 0);
	print_tests(test1, "bzero size 0");
	ft_bzero(&test1, sizeof(test1));
	print_tests(test1, "bzero size test1");


///////////////////////////////////////////////////////////////////////////////
//	ft_strcat
///////////////////////////////////////////////////////////////////////////////
	printf("ft_strcat\n");
	char					tab[LEN_TAB + 1] = "S ";

	printf("\tTab init = %p\n", tab);
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "Florian"));
	ft_bzero(tab, sizeof(tab));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "tutut"));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));

///////////////////////////////////////////////////////////////////////////////
//	ft_isalpha
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_isalpha\n");
	char					truc[] = "AxZsP.* \\^";
	size_t					i;

	for(i = 0; truc[i] != '\0'; i++)
		printf("\tft_isalpha = %5s = %5s pour '%c'\n", ft_isalpha(truc[i]) == 1 ? "true" : "false", isalpha(truc[i]) == 1 ? "true" : "false", truc[i]);

///////////////////////////////////////////////////////////////////////////////
//	ft_isdigit
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_isdigit\n");
	for(i = '.'; i < ';'; i++)
		printf("\tft_isdigit = %5s = %5s pour '%c'\n", ft_isdigit(i) == 1 ? "true" : "false", isdigit(i) == 1 ? "true" : "false", (int)i);

///////////////////////////////////////////////////////////////////////////////
//	ft_isalnum
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_isalnum\n");
	char					truc2[] = "<w~P.68 7* as['?";

	for(i = 0; truc2[i] != '\0'; i++)
		printf("\tft_isalnum = %5s = %5s pour '%c'\n", ft_isalnum(truc2[i]) == 1 ? "true" : "false", isalnum(truc2[i]) == 1 ? "true" : "false", truc2[i]);

///////////////////////////////////////////////////////////////////////////////
//	ft_isascii
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_isascii\n");
	int					truc3[LEN_TAB] = {-12, 'a', 'T', 128, 0, 127, INT_MAX, INT_MIN, '$', '\t'};

	for(i = 0; i < LEN_TAB; i++)
		printf("\tft_isacii = %5s = %5s pour '%d'\n", ft_isascii(truc3[i]) == 1 ? "true" : "false", isascii(truc3[i]) == 1 ? "true" : "false", truc3[i]);

///////////////////////////////////////////////////////////////////////////////
//	ft_isprint
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_isprint\n");
	int					truc4[LEN_TAB] = {30, 31, 32, 33, 125, 126, 127, INT_MIN, -12, 73};

	for(i = 0; i < LEN_TAB; i++)
		printf("\tft_isprint = %5s = %5s pour '%d'\n", ft_isprint(truc4[i]) == 1 ? "true" : "false", isprint(truc4[i]) == 1 ? "true" : "false", truc4[i]);

///////////////////////////////////////////////////////////////////////////////
//	ft_toupper
///////////////////////////////////////////////////////////////////////////////
	char					tab123[LEN_TAB] = "";
	char					base_123[] = "12F*&G fhg";
	printf("\nft_toupper\n");
	ft_bzero(tab, sizeof(tab));
	ft_strncat(tab, base_123, LEN_TAB);
	ft_strncat(tab123, base_123, LEN_TAB);
	for(i = 0; tab[i] != '\0'; i++)
	{
		tab[i] = ft_toupper(tab[i]);
		tab123[i] = toupper(tab123[i]);
	}
	printf("\ttab    = %s\n", tab);
	printf("\ttab123 = %s\n", tab123);

///////////////////////////////////////////////////////////////////////////////
//	ft_tolower
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_tolower\n");
	for(i = 0; tab[i] != '\0'; i++)
	{
		tab[i] = ft_tolower(tab[i]);
		tab123[i] = tolower(tab123[i]);
	}
	printf("\ttab    = %s\n", tab);
	printf("\ttab123 = %s\n", tab123);

///////////////////////////////////////////////////////////////////////////////
//	ft_strlen
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strlen\n");
	char					s0[] = "";
	char					s1[] = "gajkdgjasgdjhas";
	char					s2[] = "asd";

	printf("\t'%s' len = %zu\n", s0, ft_strlen(s0));
	printf("\t'%s' len = %zu\n", s1, ft_strlen(s1));
	printf("\t'%s' len = %zu\n", s2, ft_strlen(s2));

///////////////////////////////////////////////////////////////////////////////
//	ft_puts
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_puts\n");
	printf("%d = ret ft_puts\n", ft_puts("Je suis florian"));
	printf("%d = ret    puts\n", puts("Je suis florian"));
	printf("%d = ret ft_puts\n", ft_puts(""));
	printf("%d = ret    puts\n", puts(""));

///////////////////////////////////////////////////////////////////////////////
//	ft_memset
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_memset\n");
	test1.i = 12123;
	test1.tab[0] = '\0'; //pour pouvoir faire fonctionner strncat
	strncat(test1.tab, "Jean de la moulassan", LEN_TAB);
	test1.val = 312.908;
	test1.ptr = ft_memset;
	print_tests(test1, "memset_init");
	ft_memset(&test1, 0, sizeof(test1));
	print_tests(test1, "memset done");

///////////////////////////////////////////////////////////////////////////////
//	ft_memcpy
///////////////////////////////////////////////////////////////////////////////
	t_test					test2;
	printf("\nft_memcpy\n");
	print_tests(test1, "memcpy_init");
	ft_memcpy(&test2, &test1,sizeof(test2));
	print_tests(test2, "memcpy_done");

///////////////////////////////////////////////////////////////////////////////
//	ft_strdup
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strdup\n");
//	char					src[] = "Je suis florian PasquEREAU";
	char					*ret1 = ft_strdup("je suis une pomme rouge");
	char					*ret2 = ft_strdup("");
	printf("dest = %s ret2 = '%s'\n", ret1, ret2);
	ft_memdel((void**)&ret1);
	ft_memdel((void**)&ret2);

///////////////////////////////////////////////////////////////////////////////
//	ft_strncat
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strncat\n");
	ft_bzero(tab, sizeof(tab));
	printf("\tTab init = %p\n", tab);
	printf("\tTab init = %s, %p\n", tab, ft_strncat(tab, "Florian Pasquereau", LEN_TAB));
	ft_bzero(tab, sizeof(tab));
	printf("\tTab init = %s, %p\n", tab, ft_strncat(tab, "", LEN_TAB));
	printf("\tTab init = %s, %p\n", tab, ft_strncat(tab, "tututhgdasjhgfgsa jdfg sj", LEN_TAB));
	printf("\tTab init = %s, %p\n", tab, ft_strncat(tab, "", LEN_TAB));

///////////////////////////////////////////////////////////////////////////////
//	ft_strjoin
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strjoin\n");
	char					s10[] = "Je suis une";
	char					s11[] = "";
	char					*s12 = NULL;
	char					s20[] = " pomme";
	char					*ret = ft_strjoin(s10, s20);
	char					*ret11 = ft_strjoin(s11, s20);
	char					*ret12 = ft_strjoin(s12, s20);

	printf("\tret   ft_strjoin = %s\n", ret);
	printf("\tret11 ft_strjoin = %s\n", ret11);
	printf("\tret12 ft_strjoin = %s\n", ret12);
	ft_memdel((void**)&ret);
	ft_memdel((void**)&ret11);
	ft_memdel((void**)&ret12);

///////////////////////////////////////////////////////////////////////////////
//	ft_strchr
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strchr\n");
	char					s100[] = "ffgwqjhge jhqwg ej";
	int						c = '\0';
	int						c1 = 'f';
	int						c11 = '[';
	printf("\ts100 = '%s'adr = %p need  %c\n\tret = %p\n", s100, s100, c, ft_strchr(s100, c));
	printf("\ts100 = '%s'adr = %p need1 %c\n\tret = %p\n", s100, s100, c1, ft_strchr(s100, c1));
	printf("\ts100 = '%s'adr = %p need2 %c\n\tret = %p\n", s100, s100, c11, ft_strchr(s100, c11));

///////////////////////////////////////////////////////////////////////////////
//	ft_strrchr
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strrchr\n");
	printf("\ts100 = '%s'adr = %p need  %c\n\tret = %p\n", s100, s100, c, ft_strrchr(s100, c));
	printf("\ts100 = '%s'adr = %p need1 %c\n\tret = %p\n", s100, s100, c1, ft_strrchr(s100, c1));
	printf("\ts100 = '%s'adr = %p need2 %c\n\tret = %p\n", s100, s100, c11, ft_strrchr(s100, c11));

///////////////////////////////////////////////////////////////////////////////
//	ft_strcpy
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strcpy\n");
	char					s300[] = "Je suis moi";
	char					dest300[50];
	char					*ret300;
	char					s301[] = "";
	char					dest301[50];
	char					*ret301;

	for(int k = 0; k < 50; k++)
	{
		dest300[k] = '*';
		dest301[k] = '*';
	}
	ret300 = ft_strcpy(dest300, s300);
	ret301 = ft_strcpy(dest301, s301);
	printf("\tdest = '%s' %p %s, ret = %p\n", dest300, dest300, s300, ret300);
	printf("\tdest = '%s' %p %s, ret = %p\n", dest301, dest301, s301, ret301);

///////////////////////////////////////////////////////////////////////////////
//	ft_strncpy
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_strncpy\n");

	for(int k = 0; k < 50; k++)
	{
		dest300[k] = '\0';
		dest301[k] = '\0';
	}
	ret300 = ft_strncpy(dest300, s300, 120);
	ret301 = ft_strncpy(dest301, s300, 2);
	printf("\tdest = '%s' %p, ret = %p\n", dest300, dest300, ret300);
	printf("\tdest = '%s' %p, ret = %p\n", dest301, dest301, ret301);

///////////////////////////////////////////////////////////////////////////////
//	ft_cat
///////////////////////////////////////////////////////////////////////////////
	printf("\nft_cat\n");
	int						fd;
	ft_cat(1);
	if ((fd = open("libfts/libfts.h", O_RDONLY)) > -1)
	{
		ft_cat(fd);
		close(fd);
	}
	if ((fd = open("libfts/libfts.h", O_WRONLY)) > -1)
	{
		ft_cat(fd);
		close(fd);
	}
	ft_cat(-1);
	return (EXIT_SUCCESS);
}
