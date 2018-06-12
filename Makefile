# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:19:31 by mzabalza          #+#    #+#              #
#    Updated: 2018/05/21 20:00:24 by mzabalza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = generator

LEM_NAME = lem-in
VISU_NAME = visu-hex

LIBFT = libft/libft.a

CC = clang $(INCLUDES)
FLAGS = -Wall -Werror -Wextra -g3


INCLUDES = -Iincludes


LEM_SRC = srcs/lem_in/main.c\
	srcs/lem_in/get_data.c\
	srcs/lem_in/add_glist.c\
	srcs/lem_in/print_graph.c\
	srcs/lem_in/get_next_line.c\
	srcs/lem_in/goto_alist.c\
	srcs/lem_in/show_path.c\
	srcs/lem_in/find_start.c\
	srcs/lem_in/search_graph/add_2_queue.c\
	srcs/lem_in/search_graph/breath_first_search.c\
	srcs/lem_in/search_graph/show_queue.c\
	srcs/lem_in/search_graph/create_path.c\
	srcs/lem_in/search_graph/reset_map.c\
	srcs/lem_in/show_answer.c\
	srcs/lem_in/get_nb_ants.c\
	srcs/lem_in/skip_comment.c\
	srcs/lem_in/is_integer.c\
	srcs/lem_in/solution_format.c\
	srcs/lem_in/ft_free.c\
	srcs/lem_in/new_info_line.c

LEM_OBJ = $(LEM_SRC:.c=.o)

# VISU_SRC = srcs/visualizer/main.c\
# 	srcs/lem_in/get_data.c\
# 	srcs/lem_in/add_glist.c\
# 	srcs/lem_in/print_graph.c\
# 	srcs/lem_in/get_next_line.c\
# 	srcs/lem_in/goto_alist.c\
# 	srcs/lem_in/get_nb_ants.c\
# 	srcs/lem_in/skip_comment.c\
# 	srcs/lem_in/is_integer.c

# VISU_OBJ = $(VISU_SRC:.c=.o)

HEADER = includes/lem_in.h

all: $(NAME)

$(NAME): $(LIBFT) $(LEM_NAME)

$(LIBFT):
	make -C libft

$(LEM_NAME): $(LEM_OBJ) $(HEADER)
	$(CC) $(FLAGS) $(LEM_OBJ) $(LIBFT) -o $(LEM_NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "graph compiled!"

# $(VISU_NAME): $(VISU_OBJ)
# 	$(CC) $(FLAGS) $(VISU_OBJ) $(LIBFT) -o $(VISU_NAME)
# 	@printf '\033[32m[ ✔ ] %s\n\033[0m' "graph compiled!"

$(LEM_OBJ) : $(HEADER)

$(VISU_OBJ) : $(HEADER)

clean:
	rm -f $(LEM_OBJ)
	rm -f $(VISU_OBJ)
	make -C libft clean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	make -C libft fclean
	rm -f $(LEM_NAME)
	rm -f $(VISU_NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

.PHONY: clean fclean re all generator
