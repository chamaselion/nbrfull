char	*g_units[50];
char	*g_teens[50];
char	*g_tens[50];
char	*g_thousands[50];

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strcpy(char *str, char *loc)
{
    int i;
    i = 0;
    while (str[i] != '\n' && str[i] != 0)
    {
        loc[i] = str[i];
        i++;
    }
    loc[i] = 0;
    return i;
}
int handle_dict(void)
{
    char **units;
    char **teens;
    char **tens;
    char **thousands;
    units = malloc(50 * sizeof(char *));
    teens = malloc(50 * sizeof(char *));
    tens = malloc(50 * sizeof(char *));
    thousands = malloc(50 * sizeof(char *));
	int fd = open("/Users/bszikora/Documents/Projects/Rush02/weneed/main code/norminett/numbers.dict", O_RDONLY);
    char *buffer = (char *)malloc(1000);
    int i;
    int j;
    char *cptr;
	int c;

    j = 0;
    cptr = buffer;
    while (read(fd, cptr, 1) != 0)
    {
        cptr++;
        j++;
    }
    cptr = buffer;
    int dC = 0;
	tens[0] = "";
	tens[1] = "";
	teens[0] = "";
    while (*cptr != 0)
    {

		while (dC <= 10)
        {
            units[dC] = (char *)malloc(512);
            while (*cptr != ':' && *cptr != 0)
                cptr++;
            if (*cptr == 0) return -1;
            cptr++;
            while (*cptr == ' ')
                cptr++;
            i = ft_strcpy(cptr, units[dC]);
            cptr += i + 1;
            dC++;
        }
		dC = 12;
        while (dC <= 20)
        {
            teens[dC - 11] = (char *)malloc(512);
            while (*cptr != ':' && *cptr != 0)
                cptr++;
            if (*cptr == 0) return -1;
            cptr++;
            while (*cptr == ' ')
                cptr++;
            i = ft_strcpy(cptr, teens[dC - 11]);
            cptr += i + 1;
            dC++;
        }
		dC = 23;
        while (dC <= 30)
        {
            tens[dC - 21] = (char *)malloc(512);
            while (*cptr != ':' && *cptr != 0)
                cptr++;
            if (*cptr == 0) return -1;
            cptr++;
            while (*cptr == ' ')
                cptr++;
            i = ft_strcpy(cptr, tens[dC - 21]);
            cptr += i + 1;
            dC++;
        }
        while (dC <= 43 && dC > 30)
        {
            thousands[dC - 31] = (char *)malloc(512);
            while (*cptr != ':' && *cptr != 0)
                cptr++;
            if (*cptr == 0) return -1;
            cptr++;
            while (*cptr == ' ')
                cptr++;
            i = ft_strcpy(cptr, thousands[dC - 31]);
            cptr += i + 1;
            dC++;
        }
        cptr++;
	}

	c = 0;
    while (units[c] != NULL)
	{
    	g_units[c] = units[c];
		c++;
	}
	c = 0;
    while (teens[c] != NULL)
	{
        g_teens[c] = teens[c];
		c++;
	}
	c = 0;
    while (tens[c] != NULL)
	{
        g_tens[c] = tens[c];
		c++;
	}
	c = 0;
    while (thousands[c] != NULL)
	{
       g_thousands[c] = thousands[c];
		c++;
	}

}