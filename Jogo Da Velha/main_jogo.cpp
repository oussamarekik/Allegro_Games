

#include <allegro.h>
#include <stdio.h> 
#include <time.h>

#define COR_TABULEIRO 255,255,0 // Amarelo
#define COR_X 0,255,255 // Azul
#define COR_BOLA 255,255,255 // Branco
#define COR_TESTE 255,0,0 // Vermelho

void inicializa();
void deinit();

int main() 
{
	inicializa();
	
    int x,y;
    int testa_bola_ganhou = 0;
    int testa_xis_ganhou = 0;
    int jogada=1;
    char ganhador[40];
    int tabuleiro[9] = {0,0,0,0,0,0,0,0,0};
    int teste_posicao[9] = {0,0,0,0,0,0,0,0,0};
    int random;
    
    BITMAP *buffer = create_bitmap(380, 360);
    

	while (!key[KEY_ESC]) 
    {
          clear_bitmap(buffer);
          show_mouse(buffer); // Carrega imagem do mouse no buffer;

// ####################### - Testa jogada do computador - ##############################
          if ( jogada % 2 != 0 )
          {
              srand ( time(NULL) );
              random = rand() % 8;
  
              if ( teste_posicao[random] == 1 )
              {
                  random = 9;
                  do
                  {
                      random--;
                  } while ( teste_posicao[random] == 1 );
              }
  
              tabuleiro[random] = 2;
              teste_posicao[random] = 1;
              jogada++;
          }

// #####################################################################################
          else
          if (mouse_b & 1) // Testa se foi pressionado o botão esquerdo do mouse;
          {
              x = mouse_x; // Passa para "X" a posição X do' mouse;
              y = mouse_y; // Passa para "Y" a posição Y do mouse;
              //sprintf(jogo,"%d %d",x,y);                        
              //textout(buffer,font,jogo,130,80,makecol(255,0,0));    
              
// ####################### - Testa posição Clicada - ####################################
              if ( x >= 124 && x <= 152 && y >= 142 && y <= 176 && teste_posicao[0] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[0] = 1;
                   }
                   teste_posicao[0] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else 
              if ( x >= 164 && x <= 196 && y >= 142 && y <= 176 && teste_posicao[1] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[1] = 1;
                   }
                   teste_posicao[1] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 204 && x <= 236 && y >= 142 && y <= 176 && teste_posicao[2] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[2] = 1;
                   }
                   teste_posicao[2] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 124 && x <= 152 && y >= 186 && y <= 216 && teste_posicao[3] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[3] = 1;
                   }
                   teste_posicao[3] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 164 && x <= 196 && y >= 186 && y <= 216 && teste_posicao[4] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[4] = 1;
                   }
                   teste_posicao[4] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 204 && x <= 236 && y >= 186 && y <= 216 && teste_posicao[5] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[5] = 1;
                   }
                   teste_posicao[5] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 124 && x <= 152 && y >= 224 && y <= 260 && teste_posicao[6] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[6] = 1;
                   }
                   teste_posicao[6] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 164 && x <= 196 && y >= 224 && y <= 260 && teste_posicao[7] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[7] = 1;
                   }
                   teste_posicao[7] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
              else
              if ( x >= 204 && x <= 236 && y >= 224 && y <= 260 && teste_posicao[8] == 0 )
              {
                   if ( jogada % 2 == 0 )
                   {
                       tabuleiro[8] = 1;
                   }
                   teste_posicao[8] = 1;
                   jogada++; // Muda a jogada para o outro jogador;
              }
// ####################################################################################### 

 // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           
          } // Fim do "if (mouse_b & 1)" "testa o click do mouse";
 // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
// ######### - Testa as posições marcadas no tabuleiro - #################
          if ( tabuleiro[0] == 1 )
          {
               circle(buffer, 138, 158, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[0] == 2 )
          {
               line(buffer, 130,142,150,170, makecol(COR_X));
               line(buffer, 130,170,150,142, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
          if ( tabuleiro[1] == 1 )
          {
               circle(buffer, 180, 158, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[1] == 2 )
          {
               line(buffer, 170,142,190,170, makecol(COR_X));
               line(buffer, 170,170,190,142, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[2] == 1 )
          {
               circle(buffer, 220, 158, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[2] == 2 )
          {
               line(buffer, 210,142,230,170, makecol(COR_X));
               line(buffer, 210,170,230,142, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[3] == 1 )
          {
               circle(buffer, 138, 200, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[3] == 2 )
          {
               line(buffer, 130,186,150,214, makecol(COR_X));
               line(buffer, 130,214,150,186, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         
          if ( tabuleiro[4] == 1 )
          {
               circle(buffer, 180, 200, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[4] == 2 )
          {
               line(buffer, 170,186,190,214, makecol(COR_X));
               line(buffer, 170,214,190,186, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[5] == 1 )
          {
               circle(buffer, 220, 200, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[5] == 2 )
          {
               line(buffer, 210,186,230,214, makecol(COR_X));
               line(buffer, 210,214,230,186, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[6] == 1 )
          {
               circle(buffer, 138, 242, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[6] == 2 )
          {
               line(buffer, 130,228,150,256, makecol(COR_X));
               line(buffer, 130,256,150,228, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[7] == 1 )
          {
               circle(buffer, 180, 242, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[7] == 2 )
          {
               line(buffer, 170,228,190,256, makecol(COR_X));
               line(buffer, 170,256,190,228, makecol(COR_X));
          }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          
          if ( tabuleiro[8] == 1 )
          {
               circle(buffer, 220, 242, 14, makecol(COR_BOLA));
          }
          else if ( tabuleiro[8] == 2 )
          {
               line(buffer, 210,228,230,256, makecol(COR_X));
               line(buffer, 210,256,230,228, makecol(COR_X));
          }
// #######################################################################   

// ################## - "Fim do jogo" - Testa quem Ganhou - ######################### 
          if ( jogada == 10 )
          {
// @@@@@@@@@@@@@@@@@@ - Testa a Primeira Linha - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
               if ( tabuleiro[0] == 1 && tabuleiro[1] == 1 && tabuleiro[2] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 110,156,250,156, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[0] == 2 && tabuleiro[1] == 2 && tabuleiro[2] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 110,156,250,156, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               } 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@ - Testa a Segunda Linha - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[3] == 1 && tabuleiro[4] == 1 && tabuleiro[5] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 110,200,250,200, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[3] == 2 && tabuleiro[4] == 2 && tabuleiro[5] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 110,200,250,200, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@ - Testa a Terceira Linha - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[6] == 1 && tabuleiro[7] == 1 && tabuleiro[8] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 110,242,250,242, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[6] == 2 && tabuleiro[7] == 2 && tabuleiro[8] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 110,242,250,242, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@ - Testa a Primeira Coluna - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[0] == 1 && tabuleiro[3] == 1 && tabuleiro[6] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 140,132,140,266, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[0] == 2 && tabuleiro[3] == 2 && tabuleiro[6] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 140,132,140,266, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@ - Testa a Segunda Coluna - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[1] == 1 && tabuleiro[4] == 1 && tabuleiro[7] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 180,132,180,266, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[1] == 2 && tabuleiro[4] == 2 && tabuleiro[7] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 180,132,180,266, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@ - Testa a Terceira Coluna - @@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[2] == 1 && tabuleiro[5] == 1 && tabuleiro[8] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 220,132,220,266, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[2] == 2 && tabuleiro[5] == 2 && tabuleiro[8] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 220,132,220,266, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ - Testa X1 = \ - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[0] == 1 && tabuleiro[4] == 1 && tabuleiro[8] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 120,132,240,266, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[0] == 2 && tabuleiro[4] == 2 && tabuleiro[8] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 120,132,240,266, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ - Testa X2 = / - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
               if ( tabuleiro[2] == 1 && tabuleiro[4] == 1 && tabuleiro[6] == 1 )
               {  // Testa se for todos bola;
                    line(buffer, 240,132,120,266, makecol(COR_TESTE));
                    testa_bola_ganhou++;
               }
               else
               if ( tabuleiro[2] == 2 && tabuleiro[4] == 2 && tabuleiro[6] == 2 )
               {  // Testa se for todos xis;
                    line(buffer, 240,132,120,266, makecol(COR_TESTE));
                    testa_xis_ganhou++;
               }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
              if ( testa_bola_ganhou > testa_xis_ganhou )
              {                      
                  rect (buffer, 110,84,260,102, makecol(128,128,128));
                  textout(buffer,font,"Jogador 1 Ganhou",120,90,makecol(255,0,0));  
              }
              else if ( testa_xis_ganhou > testa_bola_ganhou )
              {
                   rect (buffer, 110,84,262,102, makecol(128,128,128));
                   textout(buffer,font,"Computador Ganhou",120,90,makecol(255,0,0)); 
              }
              else if ( testa_bola_ganhou == testa_xis_ganhou )
              {
                   rect (buffer, 140,82,206,104, makecol(128,128,128));
                   textout(buffer,font,"Empate",150,90,makecol(255,0,0)); 
              }
          } // Fim do "if ( jogada == 10 )";   
// ############################################################################## 
   
          textout(buffer,font,"Jogo da Velha",130,50,makecol(255,0,0));
          line (buffer, 160,140,160,260, makecol(COR_TABULEIRO));
          line (buffer, 200,140,200,260, makecol(COR_TABULEIRO));
          line (buffer, 120,180,240,180, makecol(COR_TABULEIRO));          
          line (buffer, 120,220,240,220, makecol(COR_TABULEIRO));
          rect (buffer, 2,2,378,358, makecol(COR_TABULEIRO));
          rect (buffer, 120,40,244,68, makecol(COR_TESTE));
          rect (buffer, 100,120,260,280, makecol(COR_TABULEIRO));
          textout(buffer,font,"Press ESQ to close",110,320,makecol(255,0,0));
          
          
          draw_sprite (screen, buffer, 0, 0); // Carrega buffer na tela;
	}

	deinit();
	return 0;
}

END_OF_MAIN();

// #######################################################################

void inicializa() 
{
     
	allegro_init();

	set_color_depth(32);
	
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 380, 360, 0, 0);

	install_timer();
	install_keyboard();
	install_mouse();

}

// #######################################################################

void deinit() 
{
	clear_keybuf();
}
