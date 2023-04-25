#include "get_next_line.h"
#include "stdio.h"

char	*get_next_line(int fd)
{
	static t_char_list	*char_list;
	int					return_state;
	t_boolean			cancel;

	cancel = false;
	if (BUFFER_SIZE < 0)
		return (NULL);
	if (char_list == NULL)
		char_list = malloc(sizeof(t_char_list *));
	while ((char_list)->next != NULL && (char_list)->letter != '\n')
	{
		char_list = (char_list)->next;
	}
	if (char_list->next != NULL)
		char_list = (char_list)->next;

	while (!ft_contain_line_break(char_list))
	{
		return_state = ft_fill_list(fd, char_list);
		if (return_state == -1 || return_state == 0)
		{
			cancel = true;
			break;
		}
	}

	if (!cancel)
		return_state = ft_fill_list(fd, char_list);
	return (ft_parse_and_show_list(char_list, cancel, return_state));
}

t_boolean	ft_contain_line_break(t_char_list *char_list)
{
	t_char_list	*tmp;
	tmp = char_list;

	while (tmp->next != NULL && tmp->letter != '\n')
		tmp = tmp->next;
	if (tmp->letter == '\n')
		return (true);
	else
		return (false);
}

char *ft_parse_and_show_list(t_char_list *char_list, t_boolean cancel, int return_state)
{
	t_char_list *tmp;
	char *string;
	int index;

	tmp = char_list;
	while (tmp->next != NULL && tmp->letter != '\n')
	{
		tmp = tmp->next;
		index++;
	}
	string = malloc((sizeof(char) * index + 1));
	tmp = char_list;
	index = 0;
	while (tmp != NULL && tmp->letter != '\n')
	{
		string[index] = tmp->letter;
		tmp = tmp->next;
		index++;
	}
	if (cancel)
		string[index] = '\0';
	else
		string[index] = '\n';
	return (string);
}

size_t	ft_fill_list(int fd, t_char_list *char_list)
{
	char	*buffer;
	size_t	return_state;
	int		index;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (-1);
	return_state = read(fd, buffer, BUFFER_SIZE);
	index = 0;
	while (buffer[index] != '\0')
	{
		ft_lstnew(char_list, buffer[index]);
		index++;
	}
	free(buffer);
	return (return_state);
}

void	ft_lstnew(t_char_list *char_list, char current_char)
{
	t_char_list	*new_char_list;
	t_char_list	*tmp;

	if ((char_list)->letter == '\0')
	{
		(char_list)->letter = current_char;
		return ;
	}
	new_char_list = malloc(sizeof(t_char_list));
	new_char_list->letter = current_char;
	new_char_list->next = NULL;
	tmp = char_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_char_list;
}