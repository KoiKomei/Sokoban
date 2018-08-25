#include "Map.h"
#include <iostream>
#include "SceneManager.h"
#include "Input.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_acodec.h"
using namespace std;

int main(int argc, char** argv) {
	const float fps = 30.0f;
	
	ALLEGRO_DISPLAY *display;
	if (!al_init()) {
		al_show_native_message_box(NULL, "NOPE", "NOPE", "Allegro non è partito", NULL, NULL);
		return -1;
	}

	display = al_create_display(WIDTH, HEIGHT);

	if (!display) {
		al_show_native_message_box(NULL, "NOPE", "NOPE", "Nessun display", NULL, NULL);
		return -1;
	
	}

	al_set_window_position(display, 100, 100);

	ALLEGRO_TIMER *timer=al_create_timer(1.0f/fps);

	ALLEGRO_EVENT_QUEUE *queue=al_create_event_queue();

	ALLEGRO_KEYBOARD_STATE keyboard;

	al_install_keyboard();
	al_install_mouse();

	al_init_image_addon();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));

	bool done = false;
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	Input input;
	SceneManager::GetInstance().Initialize();
	SceneManager::GetInstance().LoadContent();


	al_start_timer(timer);
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);
		al_get_keyboard_state(&keyboard);
		if (input.isKeyReleased(ev, ALLEGRO_KEY_ESCAPE)) {
			done = true;
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		SceneManager::GetInstance().Update(ev);
		SceneManager::GetInstance().Draw(display);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	SceneManager::GetInstance().Unload();

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);



	/*al_init();

	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(512, 512);
	al_init_primitives_addon();
	int a[4][4];
	
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	int i = 0;
	while (i < 4) {
		al_draw_circle((512/4) * i+(512/8), (512/4) * i+(512/8), 10, al_map_rgb(0, 0, 0), 20);
		i++;
		al_flip_display();
	}
	al_rest(5.0f);

	al_destroy_display(display);

	*/
	return 0;
	

}