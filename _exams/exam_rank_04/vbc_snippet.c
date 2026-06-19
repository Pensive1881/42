node	*parse_add(char **s);

node	*parse_factor(char **s)
{
	node	n;
	node	*ret;

	if (isdigit(**s))
	{
		
	}
	if (accept(s, '('))
	{
		
	}
	unexpected(**s);
	return (NULL);
}

node	*parse_term(char **s)
{
	node	*left;
	node	*right;
	node	n;

	left = parse_factor(s);
	if (!left)
		return (NULL);
	while ()
	{
		
	}
	return (left);
}

node	*parse_add(char **s)
{
	node	*left;
	node	*right;
	node	n;

	left = parse_term(s);
	if (!left)
		return (NULL);
	while (accept(s, '+'))
	{
		
	}
	return (left);
}

...

node	*parse_expr(char *s)
{
	node	*ret;

	ret = parse_add(&s);
	if (!ret)
		return (NULL);

...
	if (*s)
	{
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}
