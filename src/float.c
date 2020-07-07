#include "ft_printf.h"

int       ft_pow(int nbr, int n)
{
    int tmp;

    tmp = nbr;
    while (n > 1)
    {
        nbr *= tmp;
        n--;
    }
    return nbr;
}

int leng(int nbr)
{
    int len;
    int n;

    len = 0;
    n = nbr;
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return len;
}

void    width(char c, int w)
{
    int i;

    i = 0;
    while (i < w)
    {
        ft_putchar(c);
        i++;
    }
}

void    look_at_flag(t_print *print)
{
	if (print->flag->plus == 1)
        if (print->minus == 0)
            ft_putchar('+');
	if (print->minus == 1)
        ft_putchar('-');
//	if (**format == '#')
//		print->flag->ortokop = 1;
//	if (**format == ' ')
//		print->flag->probel = 1;
//	if (**format == '0')
//		print->flag->zero = 1;
}

void    ft_putfloat(int integ, int br, int pres, int *count, t_print *print)
{
    int len;
    int len2;

    if (br % 10 > 4) 
        br += (br % 10 != 9) ? 11 : 1;
    br /= 10;
    if (br / ft_pow(10, pres) != 0)
    {
        br %= ft_pow(10, pres);
        integ++;
    }
    len = leng(br);
    len2 = leng(integ);
    *count = *count + pres + len2 + 1;
//    look_at_width(len + len2 + 1, print->width, print, 0);
    if (print->width > len + len2 + 1 && print->flag->minus == 0)
        (print->flag->zero == 0) ? width(' ', print->width - *count) : width('0', print->width - *count);
    look_at_flag(print);
    ft_putnbr(integ);
    ft_putchar('.');
    while (pres - len > 0)
    {
        ft_putchar('0');
        pres--;
    }
    if (br != 0) ft_putnbr(br);
}

void	work_with_float(t_print *print, va_list list, int *count)//works with different nbrs & prs
{
    double      nbr;
    int         br;
    int         n;

    nbr = va_arg(list, double);
    n = (nbr > 0) ? (int)nbr : (int)(-nbr);
    if (nbr < 0)
    {
        print->minus = 1;
        *count = *count + 1;
        nbr = -nbr;
    }
    if (print->precision == 0)
        print->precision = 6;
    nbr = nbr - n;
    nbr = nbr * ft_pow(10, print->precision + 1);
    br = (int)nbr;
    ft_putfloat(n, br, print->precision, count, print);
}




/*long long int dbuffer(t_print *p, va_list list)
{
	long long int lld;
	signed char a;
	if ((p->razmer[0] == ' ' && p->razmer[1] == ' ') || (p->razmer[0] == 'l' && p->razmer[1] == 'h'))
	{
		lld = (int)va_arg(list, int);
		return ((int)lld);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		lld = (long int)va_arg(list, long int);
		return ((long int)lld);
	}
    if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || ((p->razmer[0] == 'j' || p->razmer[0] == 'z') && p->razmer[1] == 'h'))
	{
		lld = (long long int)va_arg(list, long long int);
		return ((long long int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		lld = (short int)va_arg(list, int);
		return ((short int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		a = (signed char)va_arg(list, int);
        lld = (int)a;
		return ((int)lld);
	}
	return (0);
}*/