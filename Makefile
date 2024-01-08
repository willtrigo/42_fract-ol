# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 04:11:23 by dande-je          #+#    #+#              #
#    Updated: 2024/01/08 08:30:20 by dande-je         ###   ########.fr        #
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

INCLUDES_DIR                := -I./include/ -I ./lib/42_libft -I ./lib/MLX42/include/MLX42
LINCLUDES                   := -L./lib/42_libft -lft
LIBFT_DIR                   := ./lib/42_libft/
MLX42_DIR                   := ./lib/MLX42/
MLX42_BUILD_DIR             := ./lib/MLX42/build/
BUILD_DIR                   := ./build/
SRCS_MAIN_DIR               := ./src/
SRCS_INTERNAL_DIR           := ./src/internal/

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM                          := rm -rf
MKDIR                       := mkdir -p
MAKE_NOPRINT                := $(MAKE) --no-print-directory
SLEEP                       := sleep 0

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)

NAME                        := fractol

HEADER                      := $(INCLUDES_DIR)

SRCS_FILES                  += $(addprefix $(SRCS_MAIN_DIR), main.c)
SRCS_FILES                  += $(addprefix $(SRCS_INTERNAL_DIR), ft_assets.c \
	ft_canvas.c \
	ft_clean.c \
	ft_color.c \
	ft_control.c \
	ft_math.c \
	ft_parse_fractal.c \
	ft_render.c \
	ft_utils.c)

OBJS                        += $(SRCS_FILES:%.c=$(BUILD_DIR)%.o)

DEPS                        := $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                       = 0
CLEAN_MESSAGE               := Fractol objects deleted
FCLEAN_MESSAGE              := Fractol deleted
EXE_MESSAGE                 = Fractol compiled
COMP_MESSAGE                = Compiling
RUN_MESSAGE                 := Run fractol

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                          := cc
CFLAGS                      = -Wall -Wextra -Werror -Ofast -flto -MD -MP
DFLAGS                      = -Wall -Wextra -Werror -Ofast -flto -MD -MP -g3
MFLAGS                      := -ldl -lglfw -pthread -lm
LFLAGS                      := -march=native
COMPILE_OBJS                = $(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) -c $< -o $@
COMPILE_EXE                 = $(CC) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX42) $(LINCLUDES) $(CFLAGS) $(MFLAGS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS = $(DFLAGS)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define submodule_update_mlx42
	printf "$(YELLOW)Building mlx42 files\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach --recursive git fetch >/dev/null 2>&1 || true
	cd $(MLX42_DIR) && git reset --hard v2.3.3 >/dev/null 2>&1 || true
	sed -i 's/3\.18/3.16/g' $(MLX42_DIR)CMakeLists.txt >/dev/null 2>&1 || true
	cd $(MLX42_DIR) && cmake -B build -DDEBUG=1 >/dev/null 2>&1 || true
	cd $(MLX42_DIR) && cmake --build build -j4
	cd $(MLX42_DIR) && git restore CMakeLists.txt >/dev/null 2>&1 || true
endef

define submodule_update_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach --recursive git fetch >/dev/null 2>&1 || true
	cd $(LIBFT_DIR) && git reset --hard v2.4.1 >/dev/null 2>&1 || true
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(SLEEP)
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $(basename $(notdir $@)) \r$(RESET)\n" $$(echo $$(($(COUNT) * 100 / $(words $(OBJS)))))
endef

define comp_exe
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(GREEN)$(EXE_MESSAGE)\n$(RESET)"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)\n$(RESET)"
endef

define fclean
	$(RM) $(NAME)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE_NOPRINT) WITH_DEBUG=TRUE
endef

define run
	printf "$(CYAN)$(RUN_MESSAGE)$(RESET)\n"
	./$(NAME) $(map) $(v1) $(v2)
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(LIBFT) $(MLX42) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT):
	$(call submodule_update_libft)

$(MLX42):
	$(call submodule_update_mlx42)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

run: fclean $(NAME)
	$(call run)

.PHONY: all clean fclean re debug run
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)
