//
// Created by jimmy on 02/02/2023.
//

#ifndef GET_NEXT_LINE_H

//Add includes
# include "stdlib.h"
# include "unistd.h"

# define BUFFER_SIZE 50

typedef enum t_boolean
{
	false,
	true,
}	t_boolean;


typedef struct s_char_list
{
	char				letter;
	struct s_char_list	*next;
}						t_char_list;

char	*get_next_line(int fd);
size_t	ft_fill_list(int fd, t_char_list *char_list);
char	*ft_parse_and_show_list(t_char_list *char_list, t_boolean cancel, int return_state);
void	ft_lstnew(t_char_list *char_list, char current_char);
void	ft_free_list(t_char_list *char_list);
t_boolean ft_contain_line_break(t_char_list *tmp);

//utility functions
int			ft_strlen(const char string[]);
# define GET_NEXT_LINE_H
#endif
