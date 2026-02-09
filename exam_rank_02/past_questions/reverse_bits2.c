
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	result;
	int	i;

	i = 8;
	while (i--)
	{
		result = (result << 1) | (octet &)
		octet = octet >> 1;
	}
	return (result);
}

