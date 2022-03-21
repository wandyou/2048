
#include "vector_conversions.h"


//POSTIT	X = COLUMNS
// 			Y = LINES

//fonction qui prends un enum en entrée et donne un vector contenant les incréments à appliquer à des coordonnés
//pour parcourir le tableau
t_vector enum_to_vector(int direction)
{
	t_vector ret;
	switch(direction)
	{
		case KEY_UP:
		{
			ret.x = 0;
			ret.y = -1; //decrementer Y fait aller vers le haut dans un tableau
			break;
		}
		case KEY_DOWN:
		{
			ret.x = 0;
			ret.y = 1; // incrementer Y fait aller vers le bas dansun tableau
			break;
		}
		case KEY_LEFT:
		{
			ret.x = -1; // decrementer x fait aller vers la gauche dans un tableau
			ret.y = 0;
			break;
		}
		case KEY_RIGHT:
		{
			ret.x = 1; // incrémenter x fait aller vers la droite dans un tableau
			ret.y = 0;
			break;
		}
	}
	return ret;
}

//fonction qui donne les coordonnées de départ du check en fonction de la direction
t_vector get_start(int direction, t_game *game)
{
	t_vector ret;
	switch (direction)
	{
		case KEY_UP:
		{
			ret.x = 0;
			ret.y = 0;
			break;
		}
		case KEY_DOWN:
		{
			ret.x = 0;
			ret.y = game->board.line_nb - 1;
			break;
		}
		case KEY_LEFT:
		{
			ret.x = 0;
			ret.y = 0;
			break;
		}
		case KEY_RIGHT:
		{
			ret.x = game->board.col_nb - 1;
			ret.y = 0;
			break;
		}
	}
	return ret;
}
