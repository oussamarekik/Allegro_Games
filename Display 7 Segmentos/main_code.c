/*
    Universidade Federal de Santa Maria
    Centro de Educação Superior Norte do Rio Grande do Sul
    Curso de Sistemas de Informação
    Disciplina: Circuitos Digitais
    
    Aluno: Kelvin Salton do Prado e Mauro André Murari
    
    Exemplo funcional de um Display de 7 segmentos.
    
    Obs.: Para compilar o código tem que ter instalado a biblioteca
    gráfica Allegro e compilar como projeto.
    
*/

#include <allegro.h>
#include <stdio.h>

// #### Define o RGB das cores ####
#define VERMELHO_ESCURO 20,0,0
#define VERMELHO 255,0,0
#define BRANCO 255,255,255
#define VERDE 0,128,0
#define PRETO 0,0,0
#define ROSA 200,1,200
// ################################

void init(int resolucao_x, int resolucao_y);
void deinit();

int main() 
{
//  ### Resolução da tela ###
    int resolucao_x = 320;
    int resolucao_y = 400;
//  #########################

//  ### Posições do Display ###
    bool a = false; 
    bool b = false; 
    bool c = false; 
    bool d = false; 
    bool e = false; 
    bool f = false; 
    bool g = false; 
//  ###########################  
  
	init(resolucao_x, resolucao_y); // Chama a função que inicializa o modo gráfico do Allegro;

    BITMAP *buffer = create_bitmap(resolucao_x,resolucao_y); // Cria uma área virtual;
    
    rectfill(buffer, 0, 0, resolucao_x, resolucao_y, makecol(BRANCO)); // Borda externa;
    rectfill(buffer, 3, 3, resolucao_x-4, resolucao_y-4, makecol(PRETO)); // Borda externa;
    rect(buffer, 84, 30, resolucao_x-96, resolucao_y-200, makecol(BRANCO)); // Borda interna;
    
//  ################### - Display - ##########################
    rectfill(buffer, 114, 50, 194, 56, makecol(VERMELHO_ESCURO)); // a;
    rectfill(buffer, 194, 56, 200, 106, makecol(VERMELHO_ESCURO)); // b;
    rectfill(buffer, 194, 112, 200, 168, makecol(VERMELHO_ESCURO)); // c;
    rectfill(buffer, 114, 168, 194, 174, makecol(VERMELHO_ESCURO)); // d;
    rectfill(buffer, 108, 112, 114, 168, makecol(VERMELHO_ESCURO)); // e;
    rectfill(buffer, 108, 56, 114, 106, makecol(VERMELHO_ESCURO)); // f;
    rectfill(buffer, 114, 106, 194, 112, makecol(VERMELHO_ESCURO)); // g;
//  ##########################################################

//  ################# - Cria os Botões - #####################
    rect(buffer, 84, 244, 102, 262, makecol(BRANCO));
    textout(buffer, font, "0", 90, 250, makecol(VERDE));
    
    rect(buffer, 114, 244, 132, 262, makecol(BRANCO));
    textout(buffer, font, "1", 120, 250, makecol(VERDE));
    
    rect(buffer, 144, 244, 162, 262, makecol(BRANCO));
    textout(buffer, font, "2", 150, 250, makecol(VERDE));
    
    rect(buffer, 174, 244, 192, 262, makecol(BRANCO));
    textout(buffer, font, "3", 180, 250, makecol(VERDE));
    
    rect(buffer, 204, 244, 222, 262, makecol(BRANCO));
    textout(buffer, font, "4", 210, 250, makecol(VERDE));
    
    rect(buffer, 84, 274, 102, 292, makecol(BRANCO));
    textout(buffer, font, "5", 90, 280, makecol(VERDE));
    
    rect(buffer, 114, 274, 132, 292, makecol(BRANCO));
    textout(buffer, font, "6", 120, 280, makecol(VERDE));
    
    rect(buffer, 144, 274, 162, 292, makecol(BRANCO));
    textout(buffer, font, "7", 150, 280, makecol(VERDE));
    
    rect(buffer, 174, 274, 192, 292, makecol(BRANCO));
    textout(buffer, font, "8", 180, 280, makecol(VERDE));
    
    rect(buffer, 204, 274, 222, 292, makecol(BRANCO));
    textout(buffer, font, "9", 210, 280, makecol(VERDE));
    
    rect(buffer, 84, 304, 102, 322, makecol(BRANCO));
    textout(buffer, font, "A", 90, 310, makecol(VERDE));
    
    rect(buffer, 114, 304, 132, 322, makecol(BRANCO));
    textout(buffer, font, "b", 120, 310, makecol(VERDE));
    
    rect(buffer, 144, 304, 162, 322, makecol(BRANCO));
    textout(buffer, font, "C", 150, 310, makecol(VERDE));
    
    rect(buffer, 174, 304, 192, 322, makecol(BRANCO));
    textout(buffer, font, "d", 180, 310, makecol(VERDE));
    
    rect(buffer, 204, 304, 222, 322, makecol(BRANCO));
    textout(buffer, font, "E", 210, 310, makecol(VERDE));
    
    rect(buffer, 84, 334, 102, 352, makecol(BRANCO));
    textout(buffer, font, "F", 90, 340, makecol(VERDE));
    
    rect(buffer, 114, 334, 132, 352, makecol(BRANCO));
    textout(buffer, font, "H", 120, 340, makecol(VERDE));
    
    rect(buffer, 144, 334, 162, 352, makecol(BRANCO));
    textout(buffer, font, "I", 150, 340, makecol(VERDE));
    
    rect(buffer, 174, 334, 192, 352, makecol(BRANCO));
    textout(buffer, font, "L", 180, 340, makecol(VERDE));
    
    rect(buffer, 204, 334, 222, 352, makecol(BRANCO));
    textout(buffer, font, "O", 210, 340, makecol(VERDE));
    
    rect(buffer, 84, 364, 102, 382, makecol(BRANCO));
    textout(buffer, font, "P", 90, 370, makecol(VERDE));
    
    rect(buffer, 114, 364, 132, 382, makecol(BRANCO));
    textout(buffer, font, "S", 120, 370, makecol(VERDE));
    
    rect(buffer, 144, 364, 162, 382, makecol(BRANCO));
    textout(buffer, font, "U", 150, 370, makecol(VERDE));
    
    rect(buffer, 174, 364, 222, 382, makecol(BRANCO));
    textout(buffer, font, "EXIT", 184, 370, makecol(VERDE));
//  ##########################################################
     
	while (!key[KEY_ESC]) // Enquanto for diferente de ESC executa o programa;
    {
		show_mouse(buffer); // Limpa buffer;
		
		textout(buffer,font,"Display de 7 Segmentos",66,14,makecol(ROSA));
		textout(buffer,font,"Clique no valor ou letra desejada",22,218,makecol(ROSA));
		
// ############## - Testa Posição Clicada e Mostra Valor Correspondente - ##################################		
        if (mouse_b & 1) // Testa se foi pressionado o botão esquerdo do mouse;
        {
              if ( mouse_x >= 86 && mouse_x <= 100 && mouse_y >= 246 && mouse_y <= 262 ) // Posição 0
              { 
                   a = true; 
                   b = true; 
                   c = true; 
                   d = true; 
                   e = true; 
                   f = true; 
                   g = false;
              }
              else 
              if ( mouse_x >= 116 && mouse_x <= 130 && mouse_y >= 246 && mouse_y <= 262 ) // Posição 1
              {
                   a = false; 
                   b = true; 
                   c = true; 
                   d = false; 
                   e = false; 
                   f = false; 
                   g = false;
              }
              else
              if ( mouse_x >= 146 && mouse_x <= 160 && mouse_y >= 246 && mouse_y <= 262 ) // Posição 2
              {
                   a = true; 
                   b = true; 
                   c = false; 
                   d = true; 
                   e = true; 
                   f = false; 
                   g = true;
              }
              else
              if ( mouse_x >= 176 && mouse_x <= 190 && mouse_y >= 246 && mouse_y <= 262 ) // Posição 3
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = false; 
                   f = false; 
                   g = true;
              }
              else
              if ( mouse_x >= 206 && mouse_x <= 220 && mouse_y >= 246 && mouse_y <= 262 ) // Posição 4
              {
                   a = false; 
                   b = true; 
                   c = true;
                   d = false; 
                   e = false; 
                   f = true; 
                   g = true;
              }     
              else
              if ( mouse_x >= 86 && mouse_x <= 100 && mouse_y >= 278 && mouse_y <= 292 ) // Posição 5
              {
                   a = true; 
                   b = false; 
                   c = true;
                   d = true; 
                   e = false; 
                   f = true; 
                   g = true;
              }
              else 
              if ( mouse_x >= 116 && mouse_x <= 130 && mouse_y >= 278 && mouse_y <= 292 ) // Posição 6
              {
                   a = true; 
                   b = false; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 146 && mouse_x <= 160 && mouse_y >= 278 && mouse_y <= 292 ) // Posição 7
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = false; 
                   e = false; 
                   f = true; 
                   g = false;
              }
              else
              if ( mouse_x >= 176 && mouse_x <= 190 && mouse_y >= 278 && mouse_y <= 292 ) // Posição 8
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 206 && mouse_x <= 220 && mouse_y >= 278 && mouse_y <= 292 ) // Posição 9
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = false; 
                   f = true; 
                   g = true;
              }   
              else
              if ( mouse_x >= 86 && mouse_x <= 100 && mouse_y >= 306 && mouse_y <= 320 ) // Posição A
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = false; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else 
              if ( mouse_x >= 116 && mouse_x <= 130 && mouse_y >= 306 && mouse_y <= 320 ) // Posição b
              {
                   a = false; 
                   b = false; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 146 && mouse_x <= 160 && mouse_y >= 306 && mouse_y <= 320 ) // Posição C
              {
                   a = true; 
                   b = false; 
                   c = false;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = false;
              }
              else
              if ( mouse_x >= 176 && mouse_x <= 190 && mouse_y >= 306 && mouse_y <= 320 ) // Posição d
              {
                   a = false; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = false; 
                   g = true;
              }
              else
              if ( mouse_x >= 206 && mouse_x <= 220 && mouse_y >= 306 && mouse_y <= 320 ) // Posição E
              {
                   a = true; 
                   b = false; 
                   c = false;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 86 && mouse_x <= 100 && mouse_y >= 336 && mouse_y <= 352 ) // Posição F
              {
                   a = true; 
                   b = false; 
                   c = false;
                   d = false; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else 
              if ( mouse_x >= 116 && mouse_x <= 130 && mouse_y >= 336 && mouse_y <= 352 ) // Posição H
              {
                   a = false; 
                   b = true; 
                   c = true;
                   d = false; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 146 && mouse_x <= 160 && mouse_y >= 336 && mouse_y <= 352 ) // Posição I
              {
                   a = false; 
                   b = true; 
                   c = true;
                   d = false; 
                   e = false; 
                   f = false; 
                   g = false;
              }
              else
              if ( mouse_x >= 176 && mouse_x <= 190 && mouse_y >= 336 && mouse_y <= 352 ) // Posição L
              {
                   a = false; 
                   b = false; 
                   c = false;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = false;
              }
              else
              if ( mouse_x >= 206 && mouse_x <= 220 && mouse_y >= 336 && mouse_y <= 352 ) // Posição O
              {
                   a = true; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = false;
              }   
              else
              if ( mouse_x >= 86 && mouse_x <= 100 && mouse_y >= 366 && mouse_y <= 381 ) // Posição P
              {
                   a = true; 
                   b = true; 
                   c = false;
                   d = false; 
                   e = true; 
                   f = true; 
                   g = true;
              }
              else 
              if ( mouse_x >= 116 && mouse_x <= 130 && mouse_y >= 366 && mouse_y <= 381 ) // Posição S
              {
                   a = true; 
                   b = false; 
                   c = true;
                   d = true; 
                   e = false; 
                   f = true; 
                   g = true;
              }
              else
              if ( mouse_x >= 146 && mouse_x <= 160 && mouse_y >= 366 && mouse_y <= 381 ) // Posição U
              {
                   a = false; 
                   b = true; 
                   c = true;
                   d = true; 
                   e = true; 
                   f = true; 
                   g = false;
              } 
              else
              if ( mouse_x >= 176 && mouse_x <= 222 && mouse_y >= 366 && mouse_y <= 381 ) // Posição Exit
              {
                  deinit();
                  return 0;
              }
              
              // @@@@@@@@@@@@@@@@@@@@ - Testa as Posições e Manda pro buffer - @@@@@@@@@@@@@@@@@@
              if ( a == true )
                  rectfill(buffer, 114, 50, 194, 56, makecol(VERMELHO)); // a;
              else
                  rectfill(buffer, 114, 50, 194, 56, makecol(VERMELHO_ESCURO)); // a;
                  
              if ( b == true )
                  rectfill(buffer, 194, 56, 200, 106, makecol(VERMELHO)); // b;
              else
                  rectfill(buffer, 194, 56, 200, 106, makecol(VERMELHO_ESCURO)); // b;
                  
              if ( c == true )
                  rectfill(buffer, 194, 112, 200, 168, makecol(VERMELHO)); // c;
              else
                  rectfill(buffer, 194, 112, 200, 168, makecol(VERMELHO_ESCURO)); // c;
                  
              if ( d == true )
                  rectfill(buffer, 114, 168, 194, 174, makecol(VERMELHO)); // d;
              else
                  rectfill(buffer, 114, 168, 194, 174, makecol(VERMELHO_ESCURO)); // d;
                  
              if ( e == true )
                  rectfill(buffer, 108, 112, 114, 168, makecol(VERMELHO)); // e;
              else
                  rectfill(buffer, 108, 112, 114, 168, makecol(VERMELHO_ESCURO)); // e;
                  
              if ( f == true )
                  rectfill(buffer, 108, 56, 114, 106, makecol(VERMELHO)); // f;
              else
                  rectfill(buffer, 108, 56, 114, 106, makecol(VERMELHO_ESCURO)); // f;
                  
              if ( g == true )
                  rectfill(buffer, 114, 106, 194, 112, makecol(VERMELHO)); // g;
              else
                  rectfill(buffer, 114, 106, 194, 112, makecol(VERMELHO_ESCURO)); // g;
              // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        } // Fim do if que testa o mouse clicado;
// #########################################################################################################
		
        draw_sprite (screen, buffer, 0, 0); // Mostra o buffer na tela;
        
	} // Fim do "while", laço principal;

	deinit();
	return 0;
}
END_OF_MAIN();


void init(int resolucao_x, int resolucao_y) // Inicializa os modos gráficos do allegro;
{    // Inicializa funções gráficas do allegro;
	allegro_init();
	set_color_depth(32); // Define 32 bits de cores;
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, resolucao_x, resolucao_y, 0, 0); // Detecta a placa de video e define o tamanho da tela;

	install_timer(); // Instala o timer;
	install_keyboard(); // Instala o teclado;
	install_mouse(); // Instala o mouse;
}

void deinit() 
{
	clear_keybuf(); // Limpa o buffer do teclado;
}
