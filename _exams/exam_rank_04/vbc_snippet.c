node	*parse_add(char **s);

node	*parse_factor(char **s)
{
	node	*ret;
	node	n;

	if (isdigit(**s))
	{
		n.type = VAL;
		n.val = **s - '0';
		n.l = NULL;
		n.r = NULL;
		(*s)++;
		return (new_node(n));
	}
	if (accept(s, '('))
	{
		ret = parse_add(s);
		if (!ret)
			return (NULL);
		if (!expect(s, ')'))
		{
			destroy_tree(ret);
			return (NULL);
		}
		return (ret);
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
	while (accept(s, '*'))
	{
		right = parse_factor(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		n.type = MULTI;
		n.l = left;
		n.r = right;
		n.val = 0;
		left = new_node(n);
		if (!left)
			return (NULL);
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
		right = parse_term(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		n.type = ADD;
		n.l = left;
		n.r = right;
		n.val = 0;
		left = new_node(n);
		if (!left)
			return (NULL);
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
	if (*s)
		unexpected(*s);
...
	if (*s)
	{
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}
