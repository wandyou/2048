#ifndef VECTOR_CONVERSIONS_H
# define VECTOR_CONVERSIONS_H
# include "ncurses.h"
# include "board_movement.h"


//fonction qui prends un enum en entrée et donne un vector contenant les incréments à appliquer à des coordonnés
//pour parcourir le tableau
t_vector enum_to_vector(int direction);
//fonction qui donne les coordonnées de départ du check en fonction de la direction
t_vector get_start(int direction, t_game *game);

#endif
