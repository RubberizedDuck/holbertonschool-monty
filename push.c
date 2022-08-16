void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return;

	/* assign data to new node */
	new->next = *head;
	new->prev = NULL;

	/* check to see if head if not NULL to assign correctly */
	if (*head != NULL)
		(*head)->prev = new;

	*head = new;
}
