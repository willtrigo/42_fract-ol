# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 04:11:23 by dande-je          #+#    #+#              #
#    Updated: 2024/01/18 07:48:44 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                REQUIREMENTS                                  #
#******************************************************************************#

LIBFT_VERSION                   := 2.4.3
MLX42_VERSION                   := 2.3.3
CMAKE_VERSION                   := 3.16

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_MAIN_DIR                   := src/
SRCS_INTERNAL_DIR               := src/internal/
INCS                            := src/ src/internal/ bonus/ bonus/internal/ bonus/internal/control/ lib/42_libft/include/ lib/MLX42/include/
SRCS_MAIN_BONUS_DIR             := bonus/
SRCS_INTERNAL_BONUS_DIR         := bonus/internal/
SRCS_INTERNAL_CONTROL_BONUS_DIR := bonus/internal/control/
BUILD_DIR                       := build/
MLX42_DIR                       := lib/MLX42/
MLX42_BUILD_DIR                 := lib/MLX42/build/
LIBFT_DIR                       := lib/42_libft/

#******************************************************************************#
#                                  COMMANDS                                    #
#******************************************************************************#

RM                              := rm -rf
MKDIR                           := mkdir -p
MAKEFLAGS                       += --no-print-directory
SLEEP                           := sleep 0.01

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)
LIBS                            := ./lib/42_libft/libft.a \
	./lib/MLX42/build/libmlx42.a

NAME                            = fractol
NAME_BONUS                      = fractol_bonus

SRCS_FILES                      += $(addprefix $(SRCS_MAIN_DIR), main.c)
SRCS_FILES                      += $(addprefix $(SRCS_INTERNAL_DIR), ft_assets.c \
	ft_canvas.c \
	ft_clean.c \
	ft_color.c \
	ft_control.c \
	ft_math.c \
	ft_parse_fractal.c \
	ft_render.c \
	ft_utils.c)

SRCS_BONUS_FILES                += $(addprefix $(SRCS_MAIN_BONUS_DIR), main.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_INTERNAL_BONUS_DIR), ft_assets_bonus.c \
	ft_canvas_bonus.c \
	ft_clean_bonus.c \
	ft_color_bonus.c \
	ft_math_bonus.c \
	ft_parse_fractal_bonus.c \
	ft_render_bonus.c \
	ft_utils_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_INTERNAL_CONTROL_BONUS_DIR), ft_control_bonus.c \
	ft_control_color_bonus.c \
	ft_control_moviment_bonus.c)

OBJS                            += $(SRCS_FILES:%.c=$(BUILD_DIR)%.o)

OBJS_BONUS                      += $(SRCS_BONUS_FILES:%.c=$(BUILD_DIR)%.o)

DEPS                            := $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                           = 0
CLEAN_MESSAGE                   := Fractol objects deleted
CLEAN_MLX42_OBJS_MESSAGE        := Library MLX42 objects deleted
CLEAN_MLX42_MESSAGE             := Library MLX42 deleted
FCLEAN_MESSAGE                  := Fractol deleted
EXE_MESSAGE                     = $(RESET)[100%%] $(GREEN)Built target fractol
EXE_BONUS_MESSAGE               = [100%%] $(GREEN)Built target fractol_bonus
COMP_MESSAGE                    = Building C object
COMP_BONUS                      = $(CYAN)[BONUS]$(RESET) $(YELLOW)Building C object

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                             := cc
CFLAGS                         = -Wall -Wextra -Werror -Ofast
CPPFLAGS                       := $(addprefix -I,$(INCS)) -MMD -MP
DFLAGS                         := -g3
LDFLAGS                        := $(addprefix -L,$(dir $(LIBS)))
LDLIBS                         := -lft -lmlx42 -ldl -lglfw -pthread -lm
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE                    = $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS += $(DFLAGS)
endif

ifdef WITH_BONUS
	NAME                       = $(NAME_BONUS)
	OBJS                       = $(OBJS_BONUS)
	COMP_MESSAGE               = $(COMP_BONUS)
	EXE_MESSAGE                = $(EXE_BONUS_MESSAGE)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define submodule_update_mlx42
	printf "$(PURPLE)Building library MLX42\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach -q --recursive \
		'branch="$(git config -f $toplevel/.gitmodules submodule.MLX42)"; \
		git pull origin master; \
		git fetch; \
		git checkout v$(MLX42_VERSION)' \
		>/dev/null 2>&1 || true
	sed -i 's/3\.18/$(CMAKE_VERSION)/g' $(MLX42_DIR)CMakeLists.txt >/dev/null 2>&1 || true
	$(SLEEP)
	cd $(MLX42_DIR) && cmake -B build -DDEBUG=1 >/dev/null 2>&1 || true
	cd $(MLX42_DIR) && cmake --build build -j4
	cd $(MLX42_DIR) && git restore CMakeLists.txt >/dev/null 2>&1 || true
endef

define submodule_update_libft
	printf "$(PURPLE)Building library Libft\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach -q --recursive \
		'branch="$(git config -f $toplevel/.gitmodules submodule.42_libft)"; \
		git pull origin main; \
		git fetch; \
		git checkout v$(LIBFT_VERSION)' \
		>/dev/null 2>&1 || true
	$(SLEEP)
	$(MAKE) -C $(LIBFT_DIR)
endef

define bonus
	$(MAKE) WITH_BONUS=TRUE
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(SLEEP)
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $$(($(COUNT) * 100 / $(words $(OBJS)))))
endef

define comp_exe
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(EXE_MESSAGE)\n$(RESET)"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(MLX42_BUILD_DIR)
	printf "$(RED)$(CLEAN_MLX42_OBJS_MESSAGE)\n$(RESET)"
	printf "$(RED)$(CLEAN_MLX42_MESSAGE)\n$(RESET)"
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)\n$(RESET)"
endef

define fclean
	$(RM) $(NAME) $(NAME_BONUS)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
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

bonus:
	$(call bonus)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

.PHONY: all clean fclean re debug bonus
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)
