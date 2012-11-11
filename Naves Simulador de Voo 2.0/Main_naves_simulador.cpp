
#include <allegro.h>
#include <stdio.h>   
     
void fInicializa(int resolucao_x, int resolucao_y); // Inicializa as funções da biblioteca Allegro;
void fClear_buf(); // Limpa o buf do teclado;
     
int main() 
{
//  ##################### - Variaveis - ###########################

    int x = 10, y = 330; // Posicao inicial da nave mae;
    int ini_x = 10, ini_y = 6; // Posicao inicial da nave inimiga;
    int resolucao_x = 900, resolucao_y = 400;
    int velocidade_nave_mae = 4;
    int velocidade_nave_inimigo = 2;
    int velocidade_do_tiro_nave_mae = 4;
    int y_tiro, x_tiro;
    int testa_tiro_nave_mae = 0;
    int teste_movimento = 0;
    int vida_do_inimigo = 10;
    int vida_da_nave_mae = 10;
    int aux_tiro = 0;
    int x_tiro_inimigo, y_tiro_inimigo;
    int velocidade_do_tiro_nave_inimigo = 2;
    int testa_tiro_nave_inimigo = 0;
    int acertou_nave_mae = 0;
    int acertou_nave_inimiga = 0;
    int pause=1;
    char nome_do_jogo[40];
    char enemy_life[40];
    char my_life[40];     
    
//  #################################################################  
   
    fInicializa(resolucao_x,resolucao_y);
    
    sprintf(nome_do_jogo,"Naves: Simulador de Voo 2.0");                        
    textout(screen,font,nome_do_jogo,resolucao_y+250,20,makecol(255,0,0));

    sprintf(enemy_life,"Enemy's life: %d",vida_do_inimigo);                        
    textout(screen,font,enemy_life,resolucao_y+250,60,makecol(255,0,0));
    
    sprintf(my_life,"My Life: %d",vida_da_nave_mae);                        
    textout(screen,font,my_life,resolucao_y+250,320,makecol(255,0,0));
    
    BITMAP *nave_mae; 
    nave_mae = load_bitmap("imgs\\nave_mae.bmp", NULL);
    draw_sprite(screen, nave_mae, x,y);
    
    BITMAP *nave_inimiga; 
    nave_inimiga = load_bitmap("imgs\\nave_inimiga.bmp", NULL);
    draw_sprite(screen, nave_inimiga, ini_x, ini_y);
    
    BITMAP *tiro;
    tiro = load_bitmap("imgs\\tiro.bmp", NULL);
    
    BITMAP *tiro_inimigo;
    tiro_inimigo = load_bitmap("imgs\\tiro_inimigo.bmp", NULL);
    
    BITMAP *buffer = create_bitmap(resolucao_x,resolucao_y);
    
    BITMAP *borda;
    borda = load_bitmap("imgs\\borda.bmp", NULL);
    draw_sprite(screen, borda, resolucao_x-290, 2);
    
    while (!key[KEY_ESC] && vida_do_inimigo > 0 && vida_da_nave_mae > 0) 
    {
        clear_bitmap(buffer);
        
// ################# - Pause - ###################### 
        if(key[KEY_P])
        {
            readkey();
        }
// ##################################################
        
        textout(buffer,font,nome_do_jogo,resolucao_y+250,20,makecol(255,0,0));
        sprintf(enemy_life,"Enemy's life: %d",vida_do_inimigo);
        textout(buffer,font,enemy_life,resolucao_y+250,60,makecol(255,0,0));
        sprintf(my_life,"My Life: %d",vida_da_nave_mae);                        
        textout(buffer,font,my_life,resolucao_y+250,320,makecol(255,0,0));

// ######### - Movimentos da Nave Mãe - ############ 
        if(key[KEY_RIGHT] && x <= resolucao_x-334 )
        {
            x = x + velocidade_nave_mae;
        }
        else if(key[KEY_LEFT] && x >= 5 )
        {
            x = x - velocidade_nave_mae;
        }
// ########################################################
  
// ############## - Tiro da Nave Mãe - ####################           
        if (key[KEY_SPACE])
        {   
            x_tiro = x+20;
            y_tiro = y-10;
            testa_tiro_nave_mae = 1;
        }
        if ( testa_tiro_nave_mae == 1 )
        {                  
            y_tiro = y_tiro - velocidade_do_tiro_nave_mae;
            draw_sprite(buffer, tiro, x_tiro, y_tiro);
            if ( y_tiro <= -10 )
            {
                if ( acertou_nave_inimiga == 1 )
                {
                    vida_do_inimigo--;
                }
                testa_tiro_nave_mae = 0;
                acertou_nave_inimiga = 0;
            }
        }
// ########################################################

// ########## - Testa se atingiu o Inimigo - ##############
        if ( y_tiro <= 20 && y_tiro >= 0 )
        {
             if ( x_tiro >= ini_x && x_tiro <= ini_x+20)
                acertou_nave_inimiga = 1; 
        }
// ########################################################

// #########- Movimento da Nave Inimiga - #################              
        if ( ini_x <= resolucao_x-334 && teste_movimento == 0 )
        {           
            ini_x = ini_x + velocidade_nave_inimigo;
            draw_sprite(buffer, nave_inimiga, ini_x, ini_y);
            if ( ini_x >= resolucao_x-334 )
                teste_movimento = 1;
        }
        else if ( ini_x >= 5 && teste_movimento == 1 )
        {           
            ini_x = ini_x - velocidade_nave_inimigo;
            draw_sprite(buffer, nave_inimiga, ini_x, ini_y);
            if ( ini_x <= 5 )
                teste_movimento = 0;
        }
// ########################################################

// ############### - Tiro do Inimigo - ####################  
        if ( aux_tiro % 200 == 0 )
        {
            x_tiro_inimigo = ini_x+8;
            y_tiro_inimigo = ini_y+50;
            testa_tiro_nave_inimigo = 1;
        }
        if ( testa_tiro_nave_inimigo == 1 )
        {                   
                y_tiro_inimigo = y_tiro_inimigo + velocidade_do_tiro_nave_inimigo;
                draw_sprite(buffer, tiro_inimigo, x_tiro_inimigo, y_tiro_inimigo);
                if ( y_tiro_inimigo >= 400 )
                {
                    if ( acertou_nave_mae == 1 )
                    {
                        vida_da_nave_mae--;
                    }
                    testa_tiro_nave_inimigo = 0;
                    acertou_nave_mae = 0;
                }
        }
        aux_tiro++;

// ########################################################

// ########## - Testa se atingiu a Nave Mãe - #############
        if ( y_tiro_inimigo <= 400 && y_tiro_inimigo >= 380 )
        {
             if ( x_tiro_inimigo >= x && x_tiro_inimigo <= x+20)
                acertou_nave_mae=1; 
        }
// ########################################################

// # - Carrega as imagens no buffer depois carrega o buffer na tela - #     
        draw_sprite(buffer, nave_mae, x,y);
        draw_sprite(buffer, nave_inimiga, ini_x, ini_y);
        draw_sprite(buffer, borda, resolucao_x-290,2);
        textout_ex(buffer,font," Instrucoes ",resolucao_y+330,150,makecol(255,0,0), -1);
        textout_ex(buffer,font," SpaceBar = Tiro ",resolucao_y+330,170,makecol(255,0,0), -1);
        textout_ex(buffer,font," P = pause ",resolucao_y+330,180,makecol(255,0,0), -1);
        textout_ex(buffer,font," Movimentacao=Setas ",resolucao_y+330,190,makecol(255,0,0), -1);
        rect(buffer, 0,0, resolucao_x-1,resolucao_y-1, makecol(0,128,0 ) ); 
        draw_sprite(screen, buffer, 0, 0);
// ######################################################## 
    } // Fim do "while (!key[KEY_ESC])";
        
    clear_bitmap(buffer);
    
    if (  vida_da_nave_mae > 0 && vida_do_inimigo <= 0 )
    {
        textout(buffer,font,"Parabens Voce Venceu !",resolucao_x/3+80, resolucao_y/3-40,makecol(255,255,0));
        textout(buffer,font,"Pressione qualquer tecla para finalizar!",resolucao_x/3, resolucao_y/3,makecol(255,255,0));
        readkey();    
        readkey(); 
    }
    else if (  vida_do_inimigo > 0 && vida_da_nave_mae <= 0 )
    {
        textout(buffer,font,"Game Over !",resolucao_x/3+100, resolucao_y/3-40,makecol(255,255,0));
        textout(buffer,font,"Pressione qualquer tecla para finalizar!",resolucao_x/3, resolucao_y/3,makecol(255,255,0));
        readkey();
        readkey();
    }
    else
    {
        textout(buffer,font,"Pressione qualquer tecla para finalizar!",resolucao_x/3, resolucao_y/3,makecol(255,255,0));    
    }
    
    draw_sprite(screen, buffer, 0, 0);
    
    rest(1000);
    readkey(); 
    readkey();
    
    fClear_buf();
    return 0;
}
END_OF_MAIN()
     
void fInicializa(int resolucao_x, int resolucao_y) 
{
    allegro_init(); // Inicializa a allegro;
    
    set_color_depth(32); // bits de cores;
    
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, resolucao_x, resolucao_y, 0, 0); 
    // Configura a placa de video e a resolução da tela;
     
    install_timer(); // Instala o timer;
    install_keyboard(); // Instala o teclado;
    install_mouse(); // Instala o mouse;
}
     
void fClear_buf()
{
    clear_keybuf(); // Limpa buf do teclado;
}
