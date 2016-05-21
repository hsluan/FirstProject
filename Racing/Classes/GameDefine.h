#ifndef __GAME_DEFINE_H_

#define __GAME_DEFINE_H_

#define IMG_SERIAL_CAR_BLACK		"Cars/car_black_%d.png"
#define IMG_SERIAL_CAR_BLUE			"Cars/car_blue_%d.png"
#define IMG_SERIAL_CAR_GREEN		"Cars/car_green_%d.png"
#define IMG_SERIAL_CAR_RED			"Cars/car_red_%d.png"
#define IMG_SERIAL_CAR_YELLOW		"Cars/car_yellow_%d.png"
#define IMG_MOTORCYCLES_BLACK		"Motorcycles/motorcycle_black.png"
#define IMG_MOTORCYCLES_BLUE		"Motorcycles/motorcycle_blue.png"
#define IMG_MOTORCYCLES_GREEN		"Motorcycles/motorcycle_green.png"
#define IMG_MOTORCYCLES_RED			"Motorcycles/motorcycle_red.png"
#define IMG_MOTORCYCLES_YELLOW		"Motorcycles/motorcycle_yellow.png"

#define IMG_SERIAL_ROAD_ALPHA		"Tiles/AsphaltRoad/road_asphalt%02d.png"
#define IMG_SERIAL_ROAD_DIRT		"Tiles/DirtRoad/road_dirt%02d.png"
#define IMG_SERIAL_ROAD_SAND		"Tiles/SandRoad/road_sand%02d.png"

#define SET_MIN_MAX(min, var, max)		if( var <= min ) {var = min;} else if( var >= max ) {var = max;}

#endif // __GAME_DEFINE_H_