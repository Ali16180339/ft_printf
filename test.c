#include "stdio.h"

int ft_printf(const char *format, ...);

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	ch;

// 	ch = (unsigned char)c;
// 	while (*s)
// 	{
// 		if (*s == ch)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*s == ch)
// 		return ((char *)s);
// 	return (NULL);
// }

int main()
{
    ft_printf("Alfabemizin ilk harfi %c%d",'A', 6, 123);

    return (0);
}