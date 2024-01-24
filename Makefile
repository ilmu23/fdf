# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 14:05:22 by ivalimak          #+#    #+#              #
#    Updated: 2024/01/24 22:00:50 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

BUILD	=	fast

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft

CC				=	cc
ifeq ($(shell uname),Linux)
	cflags.common	=	-Wall -Wextra -Werror -D __LINUX__ -Imlx-linux
	cflags.asan		=	$(cflags.debug) -fsanitize=address
else
	cflags.common	=	-Wall -Wextra -Werror
	cflags.asan		=	$(cflags.debug) -fsanitize=address -static-libsan
endif
cflags.fast		=	-Ofast
cflags.debug	=	-g
cflags.debugm	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

ifeq ($(shell uname),Linux)
	LDFLAGS	=	-L$(LIBDIR) -Lmlx-linux -lmlx_Linux -lXext -lX11 -lm -lz -lft
else
	LDFLAGS	=	-L$(LIBDIR) -lm -lmlx -framework OpenGL -framework AppKit -lft
endif

LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	$(SRCDIR)/main.c \
			$(SRCDIR)/frame.c \
			$(SRCDIR)/actions.c \
			$(SRCDIR)/rainbow.c \
			$(SRCDIR)/color.c \
			$(SRCDIR)/pixel.c \
			$(SRCDIR)/init.c \
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
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean --no-print-directory
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean --no-print-directory
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
