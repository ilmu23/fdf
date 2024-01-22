# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 14:05:22 by ivalimak          #+#    #+#              #
#    Updated: 2024/01/22 14:54:55 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

BUILD	=	debug

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address -static-libsan
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

LDFLAGS	=	-L$(LIBDIR) -lm -lmlx -framework OpenGL -framework AppKit -lft

LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	$(SRCDIR)/main.c \
			$(SRCDIR)/frame.c \
			$(SRCDIR)/actions.c \
			$(SRCDIR)/pixel.c \
			$(SRCDIR)/map.c

OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MOBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBDIR) --no-print-directory BUILD=$(BUILD)

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make -C $(LIBDIR) clean --no-print-directory
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean --no-print-directory
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
