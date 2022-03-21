NAME    = 2048

SRC     = $(addprefix srcs/, \
				main.c signal_handling.c\
				$(addprefix board/,			ft_is_ascii_possible.c ft_get_max_size_tile.c ft_init_board.c board.c board_movement.c check_board_status.c randomizer.c vector_conversions.c) \
				$(addprefix core/,			ft_keypress.c) \
				$(addprefix game/,  		ft_game_loop.c ft_launch_game.c) \
				$(addprefix leaderboard/, 	file_scoring.c  ft_leaderboard.c) \
				$(addprefix lib/, 			ft_print_title.c ft_too_small.c ft_init.c ft_break_line.c  ft_break_lines.c  ft_clear.c  ft_debug.c  ft_get_win_size.c  ft_init_struct.c  ft_print_center.c ft_vertical_align.c) \
				$(addprefix libft/, 		ft_numlen.c ft_atoi.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c  ft_isdigit.c  ft_isspace.c  ft_itoa.c  ft_putnbr_fd.c  ft_strdup.c  ft_strlcpy.c  ft_strlen.c  get_next_line.c  get_next_line_utils.c ft_memset.c) \
				$(addprefix menus/, 		ft_lost_menu.c ft_win_menu.c	ft_select_menu.c  ft_size_menu.c  ft_start_menu.c) \
				$(addprefix tiles/,			ft_print_nb_ascii.c ft_print_tile_ascii.c))

OBJ     := $(SRC:.c=.o)

CC       = cc
CFLAGS = $(CC) $(DEPFLAGS) -Iincludes -Wall -Wextra -Werror

%.o : %.c
	$(CFLAGS) -c $< -o $@

all : $(NAME)


$(DEPFILES):

include $(DEPFILES)

$(NAME) :  $(OBJ)
	$(CFLAGS) $(OBJ) -o $(NAME) -lncurses


re : fclean all

clean :
	-rm -f $(OBJ)

fclean : clean
	-rm -f $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPDIR): | $(OBJDIR)
	@mkdir $(DEPDIR)


.PHONY: all re clean fclean
