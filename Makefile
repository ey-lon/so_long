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

NAME = so_long

LIBFT = Libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

SRC =	source/game.c \
	source/deal_imgs.c \
	source/deal_mat.c \
	source/deal_key.c \
	source/check_mat.c \
	source/floodfill.c \
	source/sl_utils.c
	
BNS =	source_bonus/main_bonus.c \
	source_bonus/game_bonus.c \
	source_bonus/end_screen_bonus.c \
	source_bonus/deal_imgs_bonus.c \
	source_bonus/deal_mat_bonus.c \
	source_bonus/deal_key_bonus.c \
	source_bonus/deal_menu_bonus.c \
	source_bonus/deal_enemy_bonus.c \
	source_bonus/display_menu_bonus.c \
	source_bonus/check_mat_bonus.c \
	source_bonus/floodfill_bonus.c \
	source_bonus/sl_utils_bonus.c
	
LSTM = list_maps.txt

LOGO = eylon_logo.txt
	
FLAGS = -no-pie -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

all: $(NAME)

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

fclean:   	libfclean
		if [ -f $(NAME) ]; then\
			rm -rf $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi
		rm -rf txt/$(LSTM)
		
re: fclean all

.PHONY: all re clean fclean bonus maps

.SILENT: