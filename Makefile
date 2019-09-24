# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 20:37:00 by jormond-          #+#    #+#              #
#    Updated: 2019/09/24 19:28:05 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap.a
PUSH_SWAP	=	push_swap
CHECKER		=	checker
CC = gcc
# FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(addprefix $(LIBFT_DIRECTORY), $(LIBFT))

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST =  validator.c manipulate_struct.c sort_order.c \
				get_next_line.c commander.c orders.c orders2.c \
				sort_algorithm.c sort_algorithm2.c vizualization.c \
				write_orders1.c write_orders2.c write_orders3.c \
				analize_stack_a.c analize_stack_b.c which_way.c \
				commands.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCE_PS = $(addprefix $(SOURCES_DIRECTORY), push_swap.c)
SOURCE_CH = $(addprefix $(SOURCES_DIRECTORY), checker.c)

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST) push_swap.c checker.c)
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
	@$(CC) $(FLAGS) -o $(PUSH_SWAP) $(SOURCE_PS) $(NAME) $(LIBFT)
	@echo "\n$(PUSH_SWAP): $(GREEN)launch file were created$(RESET)"
	@echo "$(PUSH_SWAP): $(GREEN)$(PUSH_SWAP) was created$(RESET)"
	@$(CC) $(FLAGS) -o $(CHECKER) $(SOURCE_CH) $(NAME) $(LIBFT)
	@echo "\n$(CHECKER): $(GREEN)launch file were created$(RESET)"
	@echo "$(CHECKER): $(GREEN)$(CHECKER) was created$(RESET)"	

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all