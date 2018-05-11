LEM_NAME = lem-in

VISU_NAME = visu-hex


FLAGS = -Wall -Werror -Wextra

#revisar en 42 proyecto push_swap
CC = gcc -Iincludes

LIBFT = libft/libft.a

LEM_SRC = srcs/lem_in/main.c\
	srcs/lem_in/get_data.c\
	srcs/lem_in/add_glist.c\
	srcs/lem_in/print_graph.c\
	srcs/lem_in/get_next_line.c\
	srcs/lem_in/goto_alist.c\
	srcs/lem_in/show_path.c\
	srcs/lem_in/search_graph/any_path.c\
	srcs/lem_in/search_graph/dijkstra_path.c


LEM_OBJ = $(LEM_SRC:.c=.o)

VISU_SRC = srcs/visualizer/main.c\
	srcs/lem_in/get_data.c\
	srcs/lem_in/add_glist.c\
	srcs/lem_in/print_graph.c\
	srcs/lem_in/get_next_line.c\
	srcs/lem_in/goto_alist.c\


VISU_OBJ = $(VISU_SRC:.c=.o)

all: $(LIBFT) $(LEM_NAME) $(VISU_NAME)

$(LIBFT):
	make -C libft

$(LEM_NAME): $(LEM_OBJ)
	$(CC) $(FLAGS) $(LEM_SRC) -L./libft -lft -o $(LEM_NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "graph compiled!"

$(VISU_NAME): $(VISU_OBJ)
	$(CC) $(FLAGS) $(VISU_SRC) -L./libft -lft -o $(VISU_NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "graph compiled!"

clean:
	/bin/rm -rf $(LEM_OBJ)
	/bin/rm -rf $(VISU_OBJ)
	make -C libft clean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	@/bin/rm -rf $(LEM_NAME)
	@/bin/rm -rf $(VISU_NAME)
	make -C libft fclean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean
	make

.PHONY: clean fclean re all
