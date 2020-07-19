#pragma once


#define SPRITE_PLAYER						 \
			"    \xDB    ",				 \
			"\xDB\xDC\xDC\xDB\xDB\xDB\xDC\xDC\xDB",  \
			"\xDB  \xDB\xDB\xDB  \xDB"
			/*
					#    
				#########
				#  ###  #
			*/
#define PLAYER_SIZE_X 9
#define PLAYER_SIZE_Y 3


#define SPRITE_ENEMY				   \
			" \xFE\xFE\xFE\xFE\xFE ",  \
			"\xFE \xFE\xFE\xFE \xFE",  \
			" \xFE   \xFE "
			/*
				 #####  
				# ### #  
				 #   #
			*/
#define ENEMY_SIZE_X 7
#define ENEMY_SIZE_Y 3


#define SPRITE_GAMEOVER \
			" \xDB\xDB\xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB    \xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB\xDB\xDB      \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB    \xDB\xDB \xDB\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB", \
			"\xDB\xDB       \xDB\xDB   \xDB\xDB \xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB \xDB\xDB          \xDB\xDB    \xDB\xDB \xDB\xDB    \xDB\xDB \xDB\xDB      \xDB\xDB   \xDB\xDB \xDB\xDB", 						   \
			"\xDB\xDB   \xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB \xDB\xDB\xDB\xDB\xDB       \xDB\xDB    \xDB\xDB \xDB\xDB    \xDB\xDB \xDB\xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB", 	   \
			"\xDB\xDB    \xDB\xDB \xDB\xDB   \xDB\xDB \xDB\xDB  \xDB\xDB  \xDB\xDB \xDB\xDB          \xDB\xDB    \xDB\xDB  \xDB\xDB  \xDB\xDB  \xDB\xDB      \xDB\xDB   \xDB\xDB   ", 							   \
			" \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB   \xDB\xDB \xDB\xDB      \xDB\xDB \xDB\xDB\xDB\xDB\xDB\xDB\xDB      \xDB\xDB\xDB\xDB\xDB\xDB    \xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB   \xDB\xDB \xDB\xDB"
			/*
				 ######   #####  ###    ### #######      ######  ##    ## ####### ######  ##
				##       ##   ## ####  #### ##          ##    ## ##    ## ##      ##   ## ##
				##   ### ####### ## #### ## #####       ##    ## ##    ## #####   ######  ##
				##    ## ##   ## ##  ##  ## ##          ##    ##  ##  ##  ##      ##   ##   
				 ######  ##   ## ##      ## #######      ######    ####   ####### ##   ## ##
			*/
#define GAMEOVER_SIZE_X 76
#define GAMEOVER_SIZE_Y 5


#define SPRITE_YOUWON \
			"\xDB\xDB    \xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB    \xDB\xDB     \xDB\xDB     \xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB    \xDB\xDB \xDB\xDB", \
			" \xDB\xDB  \xDB\xDB  \xDB\xDB    \xDB\xDB \xDB\xDB    \xDB\xDB     \xDB\xDB     \xDB\xDB \xDB\xDB    \xDB\xDB \xDB\xDB\xDB\xDB   \xDB\xDB \xDB\xDB", 	       \
			"  \xDB\xDB\xDB\xDB   \xDB\xDB    \xDB\xDB \xDB\xDB    \xDB\xDB     \xDB\xDB  \xDB  \xDB\xDB \xDB\xDB    \xDB\xDB \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB",       \
			"   \xDB\xDB    \xDB\xDB    \xDB\xDB \xDB\xDB    \xDB\xDB     \xDB\xDB \xDB\xDB\xDB \xDB\xDB \xDB\xDB    \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB   ",             \
			"   \xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB       \xDB\xDB\xDB \xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB   \xDB\xDB\xDB\xDB \xDB\xDB"
			/*
				##    ##  ######  ##    ##     ##     ##  ######  ###    ## ## 
				 ##  ##  ##    ## ##    ##     ##     ## ##    ## ####   ## ## 
				  ####   ##    ## ##    ##     ##  #  ## ##    ## ## ##  ## ## 
				   ##    ##    ## ##    ##     ## ### ## ##    ## ##  ## ##    
				   ##     ######   ######       ### ###   ######  ##   #### ##
			*/
#define YOUWON_SIZE_X 62
#define YOUWON_SIZE_Y 5


/*
// 57, 5
#define SPACESHOOTER_SPRITE								     \
			"   ____                    ___ _              _          ",	     \
			"  / __/__  ___ ________   / __/ /  ___  ___  / /____ ____",	     \
			" _\\ \\/ _ \\/ _ `/ __/ -_) _\\ \\/ _ \\/ _ \\/ _ \\/ __/ -_) __/", \
			"/___/ .__/\\_,_/\\__/\\__/ /___/_//_/\\___/\\___/\\__/\\__/_/   ",  \
			"   /_/                                                   "
*/

/*
// 56, 5
#define SPACESHOOTER_SPRITE							    \
			" _____                    _____ _           _           ", \
			"|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ ", \
			"|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|", \
			"|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  ", \
			"      |_|                                               "
*/

// 70, 6
#define SPRITE_SPACESHOOTER										    \
			"  ____                           ____  _                 _            ",	    \
			" / ___| ____   ____  ___ ___    / ___|| |__   ___   ___ | |_ ___ ____ ",	    \
			" \\___ \\|  _ \\ / _  |/ __/ _ \\   \\___ \\|  _ \\ / _ \\ / _ \\| __/ _ \\  __|", \
			"  ___) | |_) | (_| | (_|  __/    ___) | | | | (_) | (_) | ||  __/ |   ",	    \
			" |____/|  __/ \\____|\\___\\___|   |____/|_| |_|\\___/ \\___/ \\__\\___|_|   ",    \
			"       |_|                                                          "
			/*
				 ____                           ____  _                 _
				/ ___| ____   ____  ___ ___    / ___|| |__   ___   ___ | |_ ___ ____
				\___ \|  _ \ / _  |/ __/ _ \   \___ \|  _ \ / _ \ / _ \| __/ _ \  __|
				 ___) | |_) | (_| | (_|  __/    ___) | | | | (_) | (_) | ||  __/ |
				|____/|  __/ \____|\___\___|   |____/|_| |_|\___/ \___/ \__\___|_|
				      |_|
			*/
#define SPACESHOOTER_SIZE_X 70
#define SPACESHOOTER_SIZE_Y 6
