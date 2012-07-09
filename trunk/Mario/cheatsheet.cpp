/*//
Coordinate axes. 
0 1 2 ...N -> x
1
2
...
N
|
y

//================================================================================
// Initializing
//================================================================================
	al_init(); 
	al_init_primitives_addon(); 
	al_install_keyboard();
	al_install_mouse(); 
	al_init_font_addon();
	al_init_ttf_addon(); 
	al_init_image_addon(); 

//================================================================================
// Display
//================================================================================
	ALLEGRO_DISPLAY *d = al_create_display(width, height); 
	al_destroy_display(d); 
	al_map_rgb(0,0,0); 
	al_map_rgba(0,0,0,0.5); 
	al_rest(5.0); 
	al_flip_display(); 
	width = al_get_display_width(d);
	height = al_get_display_height(d);
	al_clear_to_color(color); 

//================================================================================
// Keyboard
//================================================================================
	           0 , 1    , 2   ,  3
	enum KEYS{UP , DOWN , LEFT, RIGHT} 
	al_install_keyboard(); 

//================================================================================
// Mouse
//================================================================================
	al_install_mouse(); 
	al_hide_mouse_cursor(d); 
	ev.mouse.x; // x position of mouse 
	ev.mouse.y; // y position of mouse

//================================================================================
// Event Queue
//================================================================================

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source()); 
											al_get_display_event_source(d)
											al_get_mouse_event_source(); 
											al_get_timer_event_source(timer); 
											al_destroy_event_queue(event_queue); 
	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	al_destroy_event_queue(event_queue);

//================================================================================
// Event
//================================================================================
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev); 
	if( ev.type == ALLEGRO_EVENT_KEY_DOWN) // or ALLEGRO_EVENT_KEY_UP or ALLEGRO_EVENT_MOUSE_AXES or ALLEGRO_EVENT_MOUSE_BUTTON_DOWN
		switch(ev.keyboard.keycode)						if( ev.mouse.button & 2) // right click 
		 ALLEGRO_KEY_UP                                 if (ev.mouse.button & 1) // left click 
		 ALLEGRO_KEY_DOWN
		 ALLEGRO_KEY_LEFT
		 ALLEGRO_KEY_RIGHT
		 ALLEGRO_KEY_ESCAPE
		 ALLEGRO_EVENT_TIMER

//================================================================================
// Timers
//================================================================================
	FPS = 60; // standard
	ALLEGRO_TIMER *timer = NULL; 
	timer = al_create_timer(1.0/FPS); 
	al_start_timer(timer); 

//================================================================================
// Fonts 
//================================================================================
	<allegro5\allegro_font.h> <allegro5\allegro_ttf.h> 
	al_draw_text(font pointer, color, x, y, flags, message)
	al_init_font_addon();
	al_init_ttf_addon(); 
	al_draw_textf(font pointer, color, x, y, flag, message, replacement variables); // %i for int

//================================================================================
//Colors 
//================================================================================
	black (0,0,0) 
	white (255, 255, 255) 
	red (255, 0, 0)
	grey (100, 100, 100)

//================================================================================
// Bitmaps
//================================================================================
	ALLEGRO_BITMAP *image = NULL; 
	image = al_create_bitmap(width, height); 
	al_set_target_bitmap(image); // make image the current bitmap. 
						al_get_backbuffer(d); // to set back to backbuffer
	al_draw_bitmap(image, x, y, flag); // note that it draws from the top left corner of the bitmap. 
	al_destroy_bitmap(image); 
	image = al_load_bitmap("horse.gif"); 
	// (image, point of rotation of image, point of drawn, degree in rad, flag)
	al_draw_rotated_bitmap(image, rotationx, rotationy, x, y, rad, flags)  // draw a rotated bitmap
								// note point of rotationx and rotationy 
								// specifies the centre. 
		//EX:al_draw_rotated_bitmap(image, imageWidth/2, imageHeight/2 , width/2, height/2, (degree * 3.14159)/180, 0); 
	// (image, point of scaling, starting image width, starting image height, destination x, destination y, endingWidth, endingHeight, flag); 
	al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, x, y, imageWidth * scale, imageHeight * scale,0) ; // draw a scaled bitmap
		                         // 0, 0 means upper left point
	// (image, color, point of tinting, flags);              // 0.5 means half transparent 
		al_draw_tinted_bitmap(image, al_map_rgba(255, 0, 0, 0.5), x, y, 0 ); // it only draws a certain colour						 
								  
	al_convert_to_mask(color); // turns color transparent. 
	for (int i = 0; i< maxFrame; i++) // for animation. 
		al_convert_mask_to_alpha(image[i], color))

						// (image, starting x, starting y, width, height, dx, dy, flags) 
	al_draw_bitmap_region(image, curFrame * frameWidth, 0, frameWidth, frameHeight, x, y , 0); 
	al_save_bitmap("sprite_sheet_lion_running.bmp", outImage); // save a bunch of images into a spritesheet bitmap image

//================================================================================
// Image <allegro5\allegro_image.h> 
//================================================================================
	al_init_image_addon(); 
	imageWidth = al_get_bitmap_width(image); 
	imageHeight = al_get_bitmap_height(image); 

//================================================================================
// Primitives <allegro5\allegro_primitives.h> 
//================================================================================
	al_init_primitives_addon(); 
	al_draw_pixel(x, y, color); 
	al_draw_line(x1, y1, x2, y2, color, thickness); 
	al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness); 
	al_draw_filled_triange(x1, y1, x2, y2, x3, y3, color); 
	al_draw_circle(x, y, radius, color, thickness);
	al_draw_filled_circle(x, y, radius, color); 
	al_draw_ellipse(x, y, rx, ry, color, thickness); 
	al_draw_filled_ellipse(x, y, rx, ry, color);
	// not sure bout spline. 
	al_draw_spline(points, color, thickness); 
//================================================================================
// Sounds
//================================================================================
	#include <allegro5\allegro_audio.h> // for audio. 
	#include <allegro5\allegro_acodec.h> // audio codec (any audio files allowed)
	ALLEGRO_SAMPLE *sample = NULL; 
	al_install_audio();
	al_init_acodec_addon(); 
	al_reserve_samples(1); // number of voices
	sample = al_load_sample("song1.mp3");
	// (audio sound, loudness, pan(which speaker, left or right), speed, playmode, 
	al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL); // play sound forever
			// plays sound when you move. 
			if (sx !=x || sy != y) // if startingx or starting y not equal to current x or current y
				al_play_sample(sample2, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL); // play sound once. 
	al_destroy_sample(sample); 
	ALLEGRO_SAMPLE_INSTANCE *instance1 = NULL
	// Instances has to be attached to mixer in order to play
	instance1 = al_create_sample_instance(sample);
	al_attach_sample_instance_to_mixer(instance1, al_get_default_mixer()); 
	al_play_sample_instance(instance1); // plays sound once by default
	al_destroy_sample_instance(instance1);
	if(al_get_sample_instance_playing(instance1)); // if instance1 is playing
	al_set_sample_instance_playmode(instance3, ALLEGRO_PLAYMODE_LOOP); // for background music


	if(al_get_sample_instance_playing(instance3))
		al_draw_textf(font18, al_map_rgb(255,255,255), 5, height - 20, 0, "Instance 3 is playing: %.1f %", 
		al_get_sample_instance_position(instance3) / (float)al_get_sample_instance_length(instance3)* 100);
		// gets percentage of song playing, ((current position of song / total length of song) * 100)


//================================================================================
// Variables
//================================================================================
	ALLEGRO_DISPLAY *display = NULL; 
	ALLEGRO_FONT *font16 = NULL; 
	ALLEGRO_EVENT_QUEUE *event_queue = NULL; 
	ALLEGRO_EVENT ev; 
	ALLEGRO_TIMER *timer = NULL; 
	ALLEGRO_BITMAP *image = NULL; 
	ALLEGRO_SAMPLE *sample = NULL; 

//================================================================================
// Mappy
//================================================================================
MapFreeMem();
	// (offsets, leftcorner starting point, width, height) 
MapDrawBG(xOff,yOff, 0, 0, WIDTH, HEIGHT);

//================================================================================
// Functions
//================================================================================


//================================================================================
// ALGORITHMS 
//================================================================================
	bool done = false // game loop
	bool render = true // for event_queue (to only draw images last after everything) 

	while (!done) // game loop. 

Animations


Chasing Algorithm
		
		1.	// helper function to find angle between 1 and 2
			float AngleToTarget(int x1, int y1, int x2, int y2)
			{
				float deltaX = (x2 - x1);
				float deltaY = (y2 - y1);
				return atan2(deltaY, deltaX); .. return the angle
			}
				if(threshold < CheckDistance(badx, bady, cavex, cavey))
					ChangeState(state, RETREATING);
				else // if not, continue chasing. 
				{
					// move in an angle
					float angle = AngleToTarget(badx, bady, playerx, playery);
					bady += (2 * sin(angle));
					badx += (2 * cos(angle));
					if(threshold < CheckDistance(badx, bady, playerx, playery))
						ChangeState(state, RETREATING);
				}

Collision Detection

		1.	// Algorithm for bounding box collision  
			// if collision occurs
			// if ball 1 right is more right than object b's left
			if( ball1.x + ball1.bx > ball2.x - ball2.bx &&
				// and if ball 1 left more left than ball 2 right
				ball1.x - ball1.bx < ball2.x + ball2.bx &&
				// and if ball1 down is lower than ball 2 up
				ball1.y + ball1.by > ball2.y - ball2.by &&
				// and if ball1 up is higher than ball 2 down
				ball1.y - ball1.by < ball2.y + ball2.by)
			{
				collision = true;
			}
			else
				collision = false;

		2.	// Algorithm for Distance Collision Detection
			// Pythagoras Theorem
			// to figure out distance between 2 vectors 
			float distance = sqrt(pow(ball1.x - ball2.x, 2) + pow(ball1.y  - ball2.y, 2));
			// test if distance is too close
			if(distance < ball1.r + ball2.r)
				collision = true;
			else
				collision = false;
//*/