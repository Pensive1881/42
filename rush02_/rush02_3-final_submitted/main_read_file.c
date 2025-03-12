#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct entries
{
	char num[500];
	char word[500];
};

int	is_valid_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';//src[i];
	return(dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i]-s2[i]);
}

int	str_to_int(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;

	while (str[i]>='0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

char	*ft_strcat(char	*dest, char *src)
{
	unsigned int	i;
	unsigned int 	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i+j] = '\0';
	return (dest);
}

void	print_upto_three(char *toSearch, int totalLines, struct entries entriesArray[])
{

	int	i;
	int	toSearchLen;
	int	lineNumber;
	int	toSearchParsed;
	char	lastTwo[3];
	char	hundredth[2];
	char	tenth[2];
	char	oneth[2];

	i = 0;
	toSearchLen = ft_strlen(toSearch);
	lineNumber = totalLines;
	toSearchParsed = str_to_int(toSearch);
                
	if (toSearchLen == 3)
	{
		lastTwo[0] = toSearch[1];
		lastTwo[1] = toSearch[2];
		lastTwo[2] = '\0';
		toSearchParsed = str_to_int(lastTwo);
		hundredth[0] = toSearch[0];
		hundredth[1] = '\0';

		i = 0;
		while (i < lineNumber)
		{
			if (ft_strcmp(entriesArray[i].num, hundredth) == 0)
				printf("%s hundred", entriesArray[i].word);
			i++;
		}
			toSearch[0] = toSearch[1];
			toSearch[1] = toSearch[2];
			toSearch[2] = '\0';
	}
	if (toSearchParsed <= 20)
	{
		if (toSearch[0] == '0')
		{
			toSearch[0] = toSearch[1];
			toSearch[1] = '\0';
		}
		i = 0;
		while (i < lineNumber)
		{
			if (ft_strcmp(entriesArray[i].num, toSearch) == 0)
				printf(" %s", entriesArray[i].word);
			i++;
		}
	}
	else
	{
		i = 0;
		tenth[0] = toSearch[0];
		tenth[1] = '\0';
		ft_strcat(tenth,"0") ;
		while (i<lineNumber)
		{
			if (ft_strcmp(entriesArray[i].num, tenth) == 0)
			{
				printf(" %s", entriesArray[i].word);
				break;
			}
			i++;
		}
		i = 0;
		while (i < lineNumber)
		{
			oneth[0] = toSearch[1];
			oneth[1] = '\0';
			if (ft_strcmp(entriesArray[i].num, oneth) == 0)
			{
				printf(" %s", entriesArray[i].word);
				break;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	char	buffer[700];
	int i;
	char	num[500];
	char	word[500];
	int	numCounter;
	int	wordCounter;
	int	colonFound;
	char	line[500];
	int	lineCounter;
	int	lineNumber;
	int	fd;
	struct entries entriesArray[50];
	char	*toSearch;
	int	input_length;
	int	mod3;
	int	totalChunks;
	char	chunk[1024];
	int	chunk_i;

	i = 0;
	while (i<700)
	{
		buffer[i]=0;
		i++;
	}

	fd = 0;
	i = 0;
	if (argc < 2 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		argv[1] = argv[2];
	}
	else
		fd = open("numbers.dict", O_RDONLY);



	if (fd<0)
	{
		printf("Dict Error\n");
		return (1);
	}

	if (!is_valid_number(argv[1]))
	{
		printf("Error\n");
		return (1);
	}
	read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	numCounter = 0;
	wordCounter = 0;
	colonFound = 0;
	lineCounter = 0;
	lineNumber = 0;

	i = 0;
	while (buffer[i])
	{
		while (buffer[i]!='\n')
		{
			line[lineCounter] = buffer[i];
			lineCounter++;
			if (buffer[i] == ':')
			{
				num[numCounter] = '\0';
				colonFound = 1;
			} 
			else if (buffer[i] == ' ')
			{
				i++;
				continue;
			}
			else
			{
				if (colonFound)
				{
					word[wordCounter]=buffer[i];	
					wordCounter++;
				}
				else
				{
					num[numCounter]=buffer[i];
					numCounter++;
				}
			}
			i++;
		}
		word[wordCounter] = '\0';
		ft_strcpy(entriesArray[lineNumber].num, num, numCounter);
		ft_strcpy(entriesArray[lineNumber].word, word, wordCounter);

		// printf("\n:%s:\n", num);
		// printf("\n:%s:\n", word);

		line[lineCounter] = '\0';
		lineCounter = 0;
		i++;
		lineNumber++;
		colonFound = 0;
		wordCounter = 0;
		numCounter = 0;
	}

	i = 0;	
	toSearch = argv[1];
	input_length = ft_strlen(toSearch);
	
	mod3 = input_length%3;
	totalChunks = (input_length-mod3)/3;
	
	i = 0;
	while (i < mod3)
	{
		chunk[i] = toSearch[i];
		i++;
	}

	if (i > 0)
	{
		chunk[i] = '\0';	
		print_upto_three(chunk, lineNumber, entriesArray);
		if (27 + totalChunks > 28)
			printf("%s",entriesArray[28 + totalChunks].word);
	}
	chunk_i = 0;
	while (totalChunks > 0)
	{
		chunk[0] = toSearch[(chunk_i*3) + mod3];
		chunk[1] = toSearch[(chunk_i*3) + mod3 + 1];
		chunk[2] = toSearch[(chunk_i*3) + mod3 + 2];
		chunk[3] = '\0';
		print_upto_three(chunk,lineNumber,entriesArray);
		if (27 + totalChunks > 28)
			printf("%s",entriesArray[27+totalChunks].word);
		
		totalChunks--;
		chunk_i++;
	}
}
