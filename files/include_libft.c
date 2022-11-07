// this file cause im to stupid to include actual libft
// -> do later

#include "../head/fdf.h"

/**
compares 2 char arrays if one of them is greater, less or equal
stop point is a fixed variable n
for extendet ascii using unsigned char
e.g. 
"abc" > "aba"   ->    returns 1
  ""  =  ""     ->    returns 0
 "a"  < "abc"   ->    returns -1
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)(s1[i]) - ((unsigned char)s2[i]));
		}
	i++;
	}
	return (0);
}

/**
 * @brief returns lengh of str
 * 
 * @param str 
 * @return size_t lengh of str
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d > s)
	{
		while (n)
		{
			n = n - 1;
			d[n] = s[n];
		}
	}
	else
	{
		while (n)
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	while (s2[j] && s2[j] != '\n')
		j++;
	if (s2[j] && s2[j] == '\n')
		j++;
	str = (char *)malloc(sizeof(char) *(ft_strlen(s1) + j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] && s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free ((void *)s1);
	return (str);
}

/**
 * @brief   function searches for the FIRST occurrence in str for character c
            if str doesnt end with NUL program might crash 
 * @param str string where c should get found
 * @param c the character we are searching for 
 * @return char*    returns pointer to string at the position where 'c' was found
                    returns NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[0] == (char) c)
		return ((char *) str);
	while (str[i] != '\0')
	{
		if ((c == '\0') && (str[i + 1] == '\0'))
			return ((char *) str + i + 1);
		if (str[i] == (char)c)
		{
			return ((char *) str + i);
		}
		i++;
	}
	return ((char *) '\0');
}

/**
 * @brief function converts string argument to integer type(returns int)
 * stops if it reaches a no digit character, or a not '-' '+' character
 * spaces & tabs are okay only BEFORE argument
 * valid arguments: "423", "-273", "+765", "   -765"
 * @param str char string
 * @return int converted char string if given argument is valid, else returns 0
 */
int	ft_atoi(const char *str)
{
	int		val;
	int		minus;
	int		i;

	val = 0;
	minus = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		val = 10 * val + str[i] - 48;
		i++;
	}
	return (val * minus);
}