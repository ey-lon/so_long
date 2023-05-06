#----------------------------------------------

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
YELL = \e[0;33m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)
UPD = $(GREEN)successfully $(YELL)updated$(NOCOL)

#----------------------------------------------

CC = cc

RM = /bin/rm -f

FLAGS = -no-pie -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

NAME = so_long

LIBFT = libft.a

MINILIBX = libmlx.a

#paths-----------------------------------------

LBT_F = Libft/
MLX_F = minilibx-linux/
SRC_F = source/
BNS_F = source_bonus/

#files-----------------------------------------

SRC =	game.c \
	deal_imgs.c \
	deal_mat.c \
	deal_key.c \
	check_mat.c \
	floodfill.c \
	sl_utils.c
	
BNS =	main_bonus.c \
	game_bonus.c \
	end_screen_bonus.c \
	deal_imgs_bonus.c \
	deal_mat_bonus.c \
	deal_key_bonus.c \
	deal_menu_bonus.c \
	deal_enemy_bonus.c \
	display_menu_bonus.c \
	check_mat_bonus.c \
	floodfill_bonus.c \
	sl_utils_bonus.c
	
LSTM = list_maps.txt

LOGO = eylon_logo.txt

#prefix----------------------------------------

LIBFT := $(addprefix $(LBT_F),$(LIBFT))
MINILIBX := $(addprefix $(MLX_F),$(MINILIBX))
SRC := $(addprefix $(SRC_F),$(SRC))
BNS := $(addprefix $(BNS_F),$(BNS))

#rules-----------------------------------------

all: bonus

$(NAME): libcomp comp

logo:
		echo "$(GREEN)"
		cd txt && cat $(LOGO)
		echo "$(NOCOL)"

maps:
		cd maps && ls *.ber -a > ../txt/$(LSTM)
		echo "$(TCOL)$(LSTM) $(UPD)"

libcomp:
		@make -C Libft

comp:
		$(CC) $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
		echo "$(TCOL)$(NAME) (std. version) $(CMP)"
	
bonus: libcomp maps logo
		$(CC) $(FLAGS) $(BNS) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
		echo "$(TCOL)$(NAME) (bonus version) $(CMP)"

libclean:
		make clean -C Libft
		
clean:		libclean

libfclean:
		make fclean -C Libft

fclean:   	clean
		if [ -f $(NAME) ]; then\
			$(RM) $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi
		$(RM) txt/$(LSTM)
		
re: fclean all

.PHONY: all re clean fclean bonus maps

.SILENT: