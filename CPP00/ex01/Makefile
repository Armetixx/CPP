# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armetix <armetix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 12:08:39 by armetix           #+#    #+#              #
#    Updated: 2025/04/14 12:09:42 by armetix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
ECHO = echo

SOURCE =	contact phoneBook main

SRCS = $(addsuffix .cpp, $(SOURCE))
OBJS = $(addsuffix .o, $(SOURCE))

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
PINK = \033[1;35m
RED = \033[0;31m
RED_BOLD = \033[1;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
WHITE_BG = \033[47m
CLOSE = \033[0m

TOTAL_FILES 	:= $(words $(SOURCE))
CURRENT_FILE 	:= 0

define progress_bar
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r\e[2K$(PINK)Compiling $(NAME)... ⌛⌛⌛ |%-0s| %d/%d $(CLOSE)" $$(printf "█%.0s" $$(seq 1 $(CURRENT_FILE))) $(CURRENT_FILE) $(TOTAL_FILES)
    @if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) $(CFLAGS) -o $(NAME) $(SRCS)

%.o: %.cpp
	@$(CPP) $(CFLAGS) -c $< -o $@
	$(call progress_bar)

clean : 
	@$(RM) -r $(OBJS)
	@$(ECHO) "[$(NAME)] obj files cleaned."


fclean : clean
	@$(RM) $(NAME)
	@$(ECHO) "[$(NAME)] executable removed."


re : fclean all

.PHONY : all clean fclean re