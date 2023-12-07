# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 04:11:23 by dande-je          #+#    #+#              #
#    Updated: 2023/12/07 10:27:21 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                         := \033[0;31m
GREEN                       := \033[0;32m
YELLOW                      := \033[0;33m
CYAN                        := \033[0;36m
RESET                       := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

INCLUDES_DIR                := -I./include/ -I./lib/42_libft -I./lib/MLX42/include/MLX42
LINCLUDES                   := -L./lib/42_libft -lft
LIBFT_DIR                   := ./lib/42_libft/
MLX42_DIR                   := ./lib/MLX42/
MLX42_BUILD_DIR             := ./lib/MLX42/build/
OBJS_DIR                    := ./obj/
SRCS_MAIN_DIR               := ./src/

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM                          := rm -rf
MKDIR                       := mkdir -p
MAKE_NOPRINT                := $(MAKE) --no-print-directory
SLEEP                       := sleep 0.3

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)

NAME                        := fractol

HEADER                      := $(INCLUDES_DIR)

SRCS_FILES                  += $(addprefix $(SRCS_MAIN_DIR), main.c)

OBJS                        += $(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

DEPS                        := $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                       = 0
CLEAN_MESSAGE               := Fractol objects deleted
CLEAN_MLX42_MESSAGE         := MLX42 deleted
CLEAN_LIBFT_MESSAGE         := LIBFT deleted
FCLEAN_MESSAGE              := Fractol deleted
EXE_MESSAGE                 = Fractol compiled
COMP_MESSAGE                = Compiling fractol
RUN_MESSAGE                := Run fractol

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                          := cc
CFLAGS                      = -Wall -Wextra -Werror -Ofast -flto -MD -MP
DFLAGS                      = -Wall -Wextra -Werror -Ofast -flto -MD -MP -g3
MFLAGS                      := -ldl -lglfw -pthread -lm
LFLAGS                      := -march=native
FSANITIZE                   := -O1 -fno-omit-frame-pointer -g3
LDFLAGS                     := -fsanitize=address
COMPILE_OBJS                = $(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) -c $< -o $@
COMPILE_EXE                 = $(CC) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX42) $(LINCLUDES) $(CFLAGS) $(MFLAGS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS = $(DFLAGS)
endif

ifdef WITH_FSANITIZE
	COMPILE_OBJS = $(CC) $(CFLAGS) $(LFLAGS) $(FSANITIZE) -I $(HEADER) -c $< -o $@ $(LDFLAGS)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(SLEEP)
	printf "$(YELLOW)$(COMP_MESSAGE) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(OBJS)))))
	printf "\n"
endef

define comp_exe
	cd $(MLX42_DIR) && cmake -B build -DDEBUG=1
	cd $(MLX42_DIR) && cmake --build build -j4
	$(MAKE) -sC $(LIBFT_DIR)
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(GREEN)$(EXE_MESSAGE)\n$(RESET)"
endef

define eraseBins
	$(if $(NAME),@$(RM) $(NAME))
endef

define clean
	$(RM) $(MLX42_BUILD_DIR)
	printf "$(RED)$(CLEAN_MLX42_MESSAGE)\n$(RESET)"
	$(MAKE) fclean -C $(LIBFT_DIR)
	printf "$(RED)$(CLEAN_LIBFT_MESSAGE)\n$(RESET)"
	$(RM) $(OBJS_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)\n$(RESET)"
endef

define fclean
	$(call eraseBins)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define fsanitize
	$(call clean)
	$(call fclean)
	$(MAKE_NOPRINT) WITH_FSANITIZE=TRUE
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE_NOPRINT) WITH_DEBUG=TRUE
endef

define run
	printf "$(CYAN)$(RUN_MESSAGE)$(RESET)\n"
	./$(NAME)
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

fsanitize:
	$(call fsanitize)

debug:
	$(call debug)

run: fclean $(NAME)
	$(call run)

.PHONY: all clean fclean re fsanitize debug
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)
