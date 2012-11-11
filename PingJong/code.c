#include <allegro.h>

#define AZUL 112,146,190
#define GREEN 50,255,50

void init();
void deinit();
void fMove_Bola();
void fAumenta_Velocidade();
void fInimigo();
void fTempo();

int x = 240;
int y = 440;
int inimigo_x = 240;
int inimigo_y = 40;
int bola_x = 200;
int bola_y = 200;
int vSentido1 = 2;
int vSentido2 = 1;
int vVelocidade_Bola = 1;
int vVelocidade = 2;
int vTempo = 0;

int main() 
{
	init();
    
    BITMAP *buffer = create_bitmap(640,480);
   
    install_int(fAumenta_Velocidade, 30000);
    install_int(fInimigo, 2);
    install_int(fTempo, 1000);
    
	while (!key[KEY_ESC]) {
          
          if ( bola_y > 410 || bola_y <= 2 || bola_x <= 2 || bola_x >= 638 || bola_y <= 50)
              fMove_Bola();                              
          
          clear_bitmap(buffer);
          
          if (key[KEY_RIGHT] && x <= 486 )
          {
              x += vVelocidade;
          }
          if (key[KEY_LEFT] && x >= 4 )
          {
              x -= vVelocidade;
          }
          
          circlefill (buffer, bola_x, bola_y, 6, makecol(255,255,255));
 
          rect(buffer, 1, 1, 639, 479, makecol(255,255,255));
          line(buffer, 0, 479, 640, 479, makecol(0,0,0));
          
          rectfill(buffer, x, y, x+150, y+10, makecol(AZUL));
          rectfill(buffer, inimigo_x, inimigo_y, inimigo_x+150, inimigo_y+10, makecol(GREEN));
	      
	      if ( vSentido1 == 2 )
	          bola_y -= vVelocidade_Bola;
          else 
          if ( vSentido1 == -1 )
              bola_y += vVelocidade_Bola;
              
          if ( vSentido2 == 1 )
              bola_x += vVelocidade_Bola;
          else
          if ( vSentido2 == 0 )
              bola_x -= vVelocidade_Bola;

          textprintf_ex(buffer, font, 10, 10, makecol(0, 0, 255), -1,"Tempo: %d segundos",vTempo);	      
	      draw_sprite(screen, buffer, 0, 0);
    }

	deinit();
	return 0;
}
END_OF_MAIN();

void init() 
{
	int res;
	
    allegro_init();
	
    set_color_depth(32);
	
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	
    if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit() 
{
	clear_keybuf();
}

void fMove_Bola()
{     
     if ( bola_x <= 2 && vSentido1 == 2 && vSentido2 == 0 )
     {
         vSentido2 = 1;
     }
     else
     if ( bola_x >= 638 && vSentido1 == 2 && vSentido2 == 1 )
     {
         vSentido2 = 0;
     }

     if ( bola_x <= 2 && vSentido1 == -1 && vSentido2 == 0 )
     {
         vSentido2 = 1;
     }
     else
     if ( bola_x >= 638 && vSentido1 == -1 && vSentido2 == 1 )
     {
         vSentido2 = 0;
     }
     
     if ( bola_y >= 440 && bola_x >= x && bola_x <= ( x+150 ) && vSentido1 == -1 )
     {
         vSentido1 = 2;
     }

     if ( bola_y <= 50 && bola_x >= inimigo_x && bola_x <= ( inimigo_x+150 ) && vSentido1 == 2 )
     {
         vSentido1 = -1;
     }
  
     if ( bola_y >= 480 )
     {
        allegro_message("Game Over!\nTempo : %d segundos\n\nVoce Perdeu!",vTempo);
        deinit();
        allegro_exit();
        exit(0);
     }
     else
     if ( bola_y <= 0)
     {
        allegro_message("Parabens!\nTempo : %d segundos\n\nVoce Venceu!",vTempo);
        deinit();
        allegro_exit();
        exit(0);
     }
}

void fAumenta_Velocidade()
{
     vVelocidade++;
     vVelocidade_Bola++;
}

void fInimigo()
{
    if ( bola_x > 320 && bola_x >= (inimigo_x+120) && inimigo_x <= 486 && vSentido2 == 1)
        inimigo_x += vVelocidade-1;
    else
    if ( bola_x > 320 && bola_x <= (inimigo_x+120) && vSentido2 == 0)
        inimigo_x -= vVelocidade-1;
    
    if ( bola_x < 320 && bola_x <= (inimigo_x+50) && inimigo_x >= 4 && vSentido2 == 0)
        inimigo_x -= vVelocidade-1;
    else
    if ( bola_x < 320 && bola_x >= (inimigo_x+50) && vSentido2 == 1)
        inimigo_x += vVelocidade-1;
}

void fTempo()
{
     vTempo += 1;
}
