#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_native_dialog.h"
#include "Map.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	al_init();

	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(512, 512);
	al_init_primitives_addon();
	int a[4][4];
	
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	int i = 0;
	while (i < 500) {
		al_draw_circle((512/8) * i+(512/16), (512/8) * i+(512/16), 10, al_map_rgb(0, 0, 0), 20);
		i++;
	}
	al_rest(5.0f);

	al_destroy_display(display);


	return 0;
	

}