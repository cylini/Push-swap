# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 10:47:46 by cde-sous          #+#    #+#              #
#    Updated: 2024/10/30 15:40:44 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cylini <cylini@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 15:41:50 by carzhang          #+#    #+#              #
#    Updated: 2024/10/27 23:23:31 by cylini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = push_swap.h

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c f_clean.c f_call_all_algo.c f_all_type_op.c

OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror"

$(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	if [ -d $(OBJS_DIR) ]; then rm -rf $(OBJS_DIR); fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re