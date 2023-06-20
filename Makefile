#colors-----------------------------------------

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

RM = /bin/rm -rf

FLAGS = -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

NAME = so_long

LIBFT = libft.a

MINILIBX = libmlx.a

#paths-----------------------------------------

LBT_F = Libft/
MLX_F = minilibx-linux/
SRC_F = source/
BNS_F = source_bonus/
OBJ_S_F = obj_s/
OBJ_B_F = obj_b/
TXT_F = txt/

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

#----------------------------------------------

LIBFT := $(addprefix $(LBT_F),$(LIBFT))
MINILIBX := $(addprefix $(MLX_F),$(MINILIBX))

#objects---------------------------------------

OBJ_S = $(SRC:.c=.o)
OBJ_B = $(BNS:.c=.o)
OBJ_S := $(addprefix $(OBJ_S_F),$(OBJ_S))
OBJ_B := $(addprefix $(OBJ_B_F),$(OBJ_B))

$(OBJ_S_F)%.o : $(SRC_F)%.c
	$(CC) -c $(FLAGS) $< -o $@

$(OBJ_B_F)%.o : $(BNS_F)%.c
	$(CC) -c $(FLAGS) $< -o $@

#rules-----------------------------------------

all: bonus

$(NAME): obj_s libcomp $(OBJ_S)
		$(CC) $(FLAGS) $(OBJ_S) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
		echo "$(TCOL)$(NAME) (std. version) $(CMP)"

#bonus------
bonus: obj_b libcomp $(OBJ_B) maps logo
		$(CC) $(FLAGS) $(OBJ_B) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
		echo "$(TCOL)$(NAME) (bonus version) $(CMP)"

logo:
		echo "$(GREEN)"
		cd $(TXT_F) && cat $(LOGO)
		echo "$(NOCOL)"

maps:
		cd maps && ls *.ber -a > ../$(TXT_F)$(LSTM)
		echo "$(TCOL)$(LSTM) $(UPD)"
#-----------	

clean: libclean
		make clean -C $(MLX_F)
		make clean -C $(LBT_F)
		$(RM) $(OBJ_S)
		$(RM) $(OBJ_B)
		$(RM) $(OBJ_S_F)
		$(RM) $(OBJ_B_F)

fclean:   	clean libfclean
		make fclean -C $(LBT_F)
		make clean -C $(MLX_F)
		if [ -f $(NAME) ]; then\
			$(RM) $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi
		$(RM) $(TXT_F)$(LSTM)

re: fclean all

#libft and MLX------
libcomp:
		make -C $(LBT_F)
		make -C $(MLX_F)

libfclean:
		make fclean -C $(LBT_F)

libclean:
		make clean -C $(LBT_F)
		make clean -C $(MLX_F)
#-------------------

obj_s:
	mkdir $(OBJ_S_F)

obj_b:
	mkdir $(OBJ_B_F)

.PHONY: all $(NAME) re clean fclean bonus maps logo libcomp libclean libfclean obj_s obj_b

.SILENT: