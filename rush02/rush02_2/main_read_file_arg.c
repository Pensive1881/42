#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
struct entries {
  char num[500];
  char word[500];
};

int is_valid_number(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;  
        }
        str++;
    }
    return 1;
}

char	*ft_strcpy(char *dest, char *src, int n)
{
	int	i;
	
	i = 0;
	while(src[i] &&i<n)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';//src[i];
	return(dest);
}
int ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}
int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i]-s2[i]);
}

int str_to_int(char *str)
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
	return num ;
}
char	*ft_strcat(char	*dest, char	*src)
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

int	main(int argc, char *argv[])
// int main(void)
{
	
	printf("%s",argv[0]);
	printf("%d",argc);

	printf("%s", argv[1]);
	if (argc < 2 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	char buffer[700]={0};
	int fd = 0;
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		argv[1] = argv[2];
	}
	else
		fd = open("numbers.dict", O_RDONLY);

	if (!is_valid_number(argv[1]))
        {
                printf("Error\n");
                return (1);
        }
	read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
//	printf("%s", buffer);
	struct entries entriesArray[50];

	//entriesArray using entries
/*	entriesArray[0].num  = "0";
	entriesArray[0].word = "zero";

	entriesArray[1].num ="1";
	entriesArray[1].word ="one";
*/
// return(0);
		
	int i=0;
	char num[500];
	char word[500];
	int numCounter=0;
	int wordCounter = 0;
	int colonFound =0;
	char line[500];
	int lineCounter;
	lineCounter=0;	
	int lineNumber;
	lineNumber=0;
	/*
	while (i<2)
	{
               printf("%dnum: %s, val: %s\n",i,entriesArray[i].num, entriesArray[i].word);
		i++;
	}
	*/
	i=0;
	while (buffer[i])
	{
	//	printf("\nbuffer char: %c",buffer[i]);
		//i++;
		
		 
		//line[lineCounter] = buffer[i];
		while(buffer[i]!='\n')
		{
			line[lineCounter] = buffer[i];
			lineCounter++;
			//printf("\nline: %s\n", line);
			
			if (buffer[i] == ':')
			{
				num[numCounter] = '\0';
				colonFound = 1;
				
			} 
			else {	
				if (colonFound) {
					word[wordCounter]=buffer[i];	
					wordCounter++;
				}
				else {
					num[numCounter]=buffer[i];
					numCounter++;
				}
			}
			i++;
		}
       		word[wordCounter]='\0';         
		//printf("\nline: %s\n", line);
		//printf("\n num: %s",num);
		//printf("\n word: %s", word);
		//printf("\nlinenumber %d",lineNumber);

		//entriesArray[lineNumber].num = num;
		
		//entriesArray[lineNumber].word = word;
		//printf("\nin between %s %s\n",num,word);
		ft_strcpy(entriesArray[lineNumber].num, num, numCounter);
		ft_strcpy(entriesArray[lineNumber].word, word, wordCounter);

               line[lineCounter] = '\0';//buffer[i];
		lineCounter=0;//++;
		i++;
		lineNumber++;
	//	printf("\nline number: %d",lineNumber);
		colonFound=0;
		wordCounter=0;
		numCounter=0;
	}
	// struct dict is ready
	i=0;	
	/*
	while (i<lineNumber)
	{
		printf("%dnum: %s, val: %s\n",i,entriesArray[i].num, entriesArray[i].word);
		i++;
	}
	*/
	
	char toSearch[500] = "689";
	int toSearchLen = ft_strlen(toSearch);

	if (ft_strlen(toSearch) == 1)
	{
		//printf("\nstr to int %d\n",str_to_int(toSearch));
		i = 0;
		while (i<lineNumber)
		{
			//printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
			if (ft_strcmp(entriesArray[i].num, toSearch) == 0)
			{
				printf("\nOutput: %s", entriesArray[i].word);
			}
			i++;
		}

	}
	else if (ft_strlen(toSearch)==2)
	{

		int toSearchParsed = str_to_int(toSearch);


		printf("\nstr to int %d\n",str_to_int(toSearch));
                if (toSearchParsed<=20)
		{

			i = 0;
        	        while (i<lineNumber)
                	{
                        	//printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
	                        if (ft_strcmp(entriesArray[i].num, toSearch) == 0)
        	                {
                	               	printf("\nOutput: %s", entriesArray[i].word);
                       		}
                        	i++;
                	}
		}
		else 
		{
			//int ten = toSearchParsed / 10;
			//int one = toSearchParsed % 10;
			//char tenth[10] = "";
			//tenth=((ten*10)+'0');
			//char oneth[10] = "";
			
			//oneth = (one + '0');
			printf("in else");

			i = 0;
			char tenth[2] = {toSearch[0],'\0'};
				ft_strcat(tenth,"0") ;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
				//printf("\ntosearch %s \n", tenth);
                                if (ft_strcmp(entriesArray[i].num, tenth) == 0)
                                {
                                        printf("\nOutput: %s", entriesArray[i].word);
					break;
                                }
                                i++;
			}
			i = 0;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
                                char oneth[2]={toSearch[1],'\0'};
			
				if (ft_strcmp(entriesArray[i].num, oneth) == 0)
                                {
                                        printf("\nOutput: %s", entriesArray[i].word);
					break;
                                }
                                i++;
                        }

		}
        }

	else if (toSearchLen == 3)
	{
		// int threeDigits = str_to_int(toSearch);
		char lastTwo[3] = {toSearch[1],toSearch[2],'\0'};
		int toSearchParsed = str_to_int(lastTwo);

                //printf("\nstr to int %d\n",str_to_int(toSearch));
                
		if (toSearchLen==3)
		{
			char hundredth[2] = {toSearch[0],'\0'};

			i = 0;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
                                if (ft_strcmp(entriesArray[i].num, hundredth) == 0)
                                {
                                        printf("%s hundred", entriesArray[i].word);
				

                                }

                                i++;
                        }

			toSearch[0]=toSearch[1];
			toSearch[1]=toSearch[2];
			toSearch[2]='\0';
			
		}
//		printf("%dtosearchparsed",toSearchParsed);
		if (toSearchParsed<=20)
                {
			if (toSearch[0]=='0')
			{
				toSearch[0] = toSearch[1];
				toSearch[1]='\0';
			}

                        i = 0;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
                                if (ft_strcmp(entriesArray[i].num, toSearch) == 0)
                                {
                                        printf(" %s", entriesArray[i].word);
                                }
                                i++;
                        }
                }
                else
                {



                        i = 0;
                        char tenth[2] = {toSearch[0],'\0'};
                                ft_strcat(tenth,"0") ;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
                                //printf("\ntosearch %s \n", tenth);
                                if (ft_strcmp(entriesArray[i].num, tenth) == 0)
                                {
                                        printf(" %s", entriesArray[i].word);
                                        break;
                                }
                                i++;
                        }
                        i = 0;
                        while (i<lineNumber)
                        {
                                //printf("\ncomparing %s  %s", entriesArray[i].num, toSearch);
                                char oneth[2]={toSearch[1],'\0'};

                                if (ft_strcmp(entriesArray[i].num, oneth) == 0)
                                {
                                        printf(" %s", entriesArray[i].word);
                                        break;
                                }
                                i++;
                        }

                }
		
	}
}



















/*
RANDOM IDEAS
dict[int][int] = [char]
dict[18]

if (n < 1000)
{
        400 = 4 * 100
        4 = dict[1][n] :: "four"
}

if (n > 1000)
{
        
}
*/


