#include "ft_printf.h"
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <ulimit.h>
#include <locale.h>

#include "libft/ft_putnbr.c"
#include "libft/ft_margin.c"


int main(void) {


  //    printf("\nSTDIO\t%        s\n", s);
//    ft_printf("MINE\t%s\n", s);



//                                             DORABOTAT PLUS
//
//    printf("\n%zd", -234235);
//    printf("\n|%4.s|\n", 0);



//    ft_printf("%lld", 1844674407370955161);
//    printf("\n%lld", 1844674407370955161);

//    ft_printf("|%4.s|\n", 0);
//    printf("|%.4s|\n", 0);



   // ft_printf("|%0.u|\n", 23);15
//    printf("|%0.u|\n", 23);%%
//

//	ft_printf(s, 456, 15, "hello");

//    printf(q, printf(s, 15, 458, "hello"),ft_printf(s, 15 , 458,"hello"));		//THIs

//ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	int g = 0, h = 0, i;
//
//	setlocale(LC_ALL, "");
//	//char *string;
//	char *ctring;

//	ctring = L"Á±≥";
	//string = "Æ";

	g = printf("{%.*s}", -5, "42");
	printf("\n");
	h = ft_printf("{%.-5s}", "42");
	printf("\n\nMY =\t%d\tLIB =\t%d\n\n", h, g);

	g = printf("|%0.3d|", 0);
	printf("\n");
	h = ft_printf("|%0.3d|", 0);
	printf("\n\nMY =\t%d\tLIB =\t%d\n\n", h, g);






//
//	wchar_t q;
//	q = 128000;
//

//	int e;
//	e = 0;
//	i = 0;
//	while ((ctring[i] || ctring[i + 1] || ctring[i + 2] || ctring[i + 3])
//		   && i <= 12)
//	{
//		e = 0;
//		e +=   (unsigned char)ctring[i] << 0;
//		//printf("\n%d", ctring[i]);
//		e +=   ((int)((unsigned char)ctring[i + 1])) << 8;
//		//printf(" %d", ctring[i + 1]);
//		e +=   ((int)((unsigned char)ctring[i + 2])) << 16;	/* 13 027 014 */
//		//printf(" %d", ctring[i + 2]);
//		e +=  ((int)((unsigned char)ctring[i + 3])) << 24;
//		//printf("%d ", e);
//		//printf(" %d", ctring[i + 3]);
//		i += 4;
//	}
//
//	printf("| %C |\n", e);
//	ft_printf("| %C |\n", e);
//	ft_printf("\n\n\n|%lld| |%c| |%C|, %lld", e, e, 219,  *(L"ǔ"));
//	printf("|%lld| |%c| |%C|, %lld", e, e, 219,  *(L"ǔ"));

	/*
	  while (s[i * 4] || s[i * 4 + 1] || s[i * 4 + 2] || s[i * 4 + 3])
    {
        c = 0;
        c += (unsigned char)s[i * 4];
        c += ((int)((unsigned char)s[i * 4 + 1])) << 8;
        c += ((int)((unsigned char)s[i * 4 + 2])) << 16;
        c += ((int)((unsigned char)s[i * 4 + 3])) << 24;
        ret += ft_putchar_u(c);
        i++;
    }

	 */




	// 3321912064
	// 3321977600
	// 65536


//
//	write(1, &(ctring[0]), 1);
//	write(1, &(ctring[1]), 1);
//	write(1, &(ctring[2]), 1);
//	write(1, &(ctring[3]), 1);
//	write(1, &(ctring[4]), 1);
//	write(1, &(ctring[5]), 1);
//	write(1, &(ctring[6]), 1);



//	write(1, &(string[0]), 1);
//	write(1, &(string[1]), 1);
//	write(1, &(string[2]), 1);
//	write(1, &(string[3]), 1);
//	write(1, &(string[4]), 1);
//	write(1, &(string[5]), 1);
//	write(1, &(string[6]), 1);



	//while ()/* poka vse 4 ne nol */



//	write(1, string++, 1);
//	write(1, string, 1);
//
//	printf("%lc", string[4]);


//	printf("%S", L"Á±≥")
//
//
//	g =    printf("|%C%C%C%C%C%C%C%C%C|", 't', 'u', 'v', 'x', 'y', 'z', '{', '|', '}');
//	printf("\n");
//	h = ft_printf("|%C%C%C%C%C%C%C%C%C|", 't', 'u', 'v', 'x', 121, 122, '{', '|', '}');
//	printf("\n\nMY =\t%d\tLIB =\t%d\n\n", h, g);


//
//	ssize_t w = *(L"ś");
//	g = printf("\n\n\nm %d|%d|%d", *(L"Á±≥"), *((L"Á±≥") + 1), *((L"Á±≥") + 2));
//	printf("\n\n");


// | !"#$%&'()*+,-./0123 456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|

//
//	g = printf("|%C|", 128000);
//	printf("\n\n");
//	h = ft_printf("|%C|", 128000);
//	printf("\n\nMY =\t%d\tLIB =\t%d\n\n", h, g);
//
//	size_t kek1 = INT_MAX;
//	size_t kek2 = INT_MIN - 1;
//	size_t p = kek2 + 7;
//
//	printf("%lld\n", kek1);
//	printf("%lld\n", p);
//



//    int i = 1;
//    while (++i < 7)
//    {
//        printf("\nLIB %0d\n", arr[i]);
//        ft_printf("MIN %lX\n", arr[i]);
//        if (i == 6)
//        {
//            printf("\nLIB %0d\n", arr1[0]);
//            ft_printf("MIN %lX\n", arr1[0]);
//        }
//    }
//    ft_printf("MIN %p", arr1[0]);
//    printf("\nLIB %p\n\n", arr1[0]);
//    i = -2147483648;
//    //w = (size_t)i;
//    printf("\n%d", w);
//    i = ft_iselet('q', 4, 0, 0);
//    ft_putnbr(i);

//

//    printf("\n%a =%m", '+', '+');
//    printf("\n%a =%A", '+', '+');

//
//

    return 0;
}



/*
 170. FAIL ft_printf("%03.2d", 0);                       -> " 00"
 171. FAIL ft_printf("%03.2d", 1);                       -> " 01"
 172. FAIL ft_printf("%03.2d", -1);                      -> "-01"
 173. FAIL ft_printf("@moulitest: %.10d", -42);          -> "@moulitest: -0000000042"
 176. FAIL ft_printf("@moulitest: %5.d %5.0d", 0, 0);    -> "@moulitest:            "

 */


//char *penapple(char *str, )
