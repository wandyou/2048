#include "libft.h"

static int	get_nsize(unsigned int n)
{
	int	size;

	if (n < 10)
		size = 1;
	else
		size = get_nsize(n / 10) + 1;
	return (size);
}

char	*ft_itoa(int n, char *buff)
{
	int				len;
	int				is_neg;
	unsigned int	unbr;
	char			*dst = buff;

	is_neg = (n < 0);
	if (is_neg)
		unbr = (unsigned int)n * -1;
	else
		unbr = n;
	len = is_neg + get_nsize(unbr);
	if (is_neg)
		dst[0] = '-';
	len--;
	while (len >= is_neg)
	{
		dst[len] = unbr % 10 + '0';
		unbr /= 10;
		len--;
	}
	return (dst);
}
