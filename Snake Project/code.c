/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   Angry Snake
 
   Game Project desenvolvido em C usando a biblioteca Allegro.
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/

// Declara��o das bibliotecas;
#include <allegro.h>
#include <string.h>
#include <time.h>

void fInicializa(); // Fun��o que inicializa as "fun��es" do Allegro;
void deinit(); // Fun��o que finaliza as "fun��es" do Allegro;

int main()
{
    fInicializa(); // Inicializa as fun��es do Allegro;
//  #################### - Declara��o de V�riaveis - #########################     
    int posicao_menu = 1, testa_laco = 0;
    int posicao_cabeca_x = 150, posicao_cabeca_y = 150;
    int posicao_comida_x, posicao_comida_y;
    int sentido=1; // Grava o sentido que a cobra esta indo, "UP=0, RIGHT=1, DOWN=2, LEFT=3";
    int sentido_antigo = sentido; // Salva o sentito antigo antes de ir para um novo;
    int velocidade = 0; // Velocidade do movimento da cobra;
    int tamanho = 30; // Tamanho da cobra;
    int distancia = 5;
    int tamanhocabeca = 5;
    int vAux=0;
    bool comida = true;
    int vPos = 0;
  
//  ###########################################################################
 
//  ################## - Cria e Carrega Bitmaps do Menu - #####################
    // Cria o buffer;
    BITMAP *buffer = create_bitmap(640,480);
    // Carrega o menu "New Game" e mostra na tela;
    //BITMAP *menu_new_game = load_bitmap("imgs\\menu\\menu_new_game.bmp", NULL);
    //draw_sprite(screen, menu_new_game, 0,0);
    //draw_sprite(buffer, menu_new_game, 0,0);
    // Carrega o menu "Help" e "Exit";
    //BITMAP *menu_help = load_bitmap("imgs\\menu\\menu_help.bmp", NULL);
    //BITMAP *menu_exit = load_bitmap("imgs\\menu\\menu_exit.bmp", NULL);
//  ########################################################################### 
  
    /*do { // Come�o da Tela de Menu;
 
        if (key[KEY_DOWN]) // Se for pressionado a seta para baixo;
        {
            clear_bitmap(buffer); // Limpa o buffer;
          
            if (posicao_menu == 3) // Se a posi��o do menu for 3, ou seja estiver na posi��o exit;
            {
                draw_sprite(buffer, menu_new_game, 0,0); // Coloca bitmap new game no buffer;
                posicao_menu = 1; // Vai para a posi��o 1, "New Game";
            }
              else if (posicao_menu == 2) // Se a posi��o do menu for 2, ou seja estiver na posi��o help;
            {
                draw_sprite(buffer, menu_exit, 0,0); // Coloca bitmap menu_exit no buffer;
                posicao_menu = 3; // Vai para a posi��o 3, "Exit";
            }
              else if (posicao_menu == 1) // Se a posi��o do menu for 1, ou seja estiver na posi��o New game;
            {
                draw_sprite(buffer, menu_help, 0,0); // Coloca bitmap menu_help no buffer;
                posicao_menu = 2; // Vai para a posi��o 2, "Help";
            }
        }
        if (key[KEY_UP]) // Se for pressionado a seta para cima;
        {
            clear_bitmap(buffer); // Limpa o buffer;
          
            if (posicao_menu == 3) // Se a posi��o do menu for 3, ou seja estiver na posi��o exit;
            {
                draw_sprite(buffer, menu_help, 0,0); // Coloca bitmap menu_help no buffer;
                posicao_menu = 2;  // Vai para a posi��o 2, "Help";
            }
              else if (posicao_menu == 2) // Se a posi��o do menu for 2, ou seja estiver na posi��o help;
            {
                draw_sprite(buffer, menu_new_game, 0,0); // Coloca bitmap new game no buffer;
                posicao_menu = 1; // Vai para a posi��o 1, "New Game";
            }
              else if (posicao_menu == 1) // Se a posi��o do menu for 1, ou seja estiver na posi��o New game;
            {
                draw_sprite(buffer, menu_exit, 0,0); // Coloca bitmap menu_exit no buffer;
                posicao_menu = 3; // Vai para a posi��o 3, "Exit";
            }
        }
        if(key[KEY_ENTER]) // Testa se o "enter" foi pressionado;
        { // Testa a posi��o que estava, quando o "enter" foi pressionado;
            if (posicao_menu == 1)
            { // Posi��o do bot�o "New Game";
                testa_laco = 1; // "testa_laco" recebe 1 para sair do la�o do menu e iniciar o jogo;
            }
            else if (posicao_menu == 2)
            { // Posi��o do bot�o "Help";
                allegro_message("Angry Snake\nVersao: 0.0.1.0\nDesenvolvido por: Kelvin S. e Mauro M.\n\nPara iniciar o jogo escolha a opcao New Game.");
            }
            else if (posicao_menu == 3)
            { // Posi��o do bot�o "Exit";
                 deinit(); // Chama a fun��o e finaliza o allegro;
                 return 0;
            }
        }
     
        draw_sprite(screen, buffer, 0,0); // Manda o bitmap buffer para a tela;
        rest(100); // Da um "sleep(100)";
      
    } while (testa_laco != 1); */// Quando for escolhida a op��o New Game termina o la�o;
//  #################### - Fim da Tela de Menu - ##############################

//  ################## - Cria e Carrega Bitmaps do Jogo - ##################### 
    // Cria a cabe�a da cobra;
    BITMAP *cabeca = create_bitmap(5,5); // Cria BITMAP com nome "cabeca";
    rectfill(cabeca, 0, 0, 5, 5, makecol(0,0,255)); // Cria retangulo no BITMAP criado acima;
  
    // Cria o rabo da cobra;
    BITMAP *rabo = create_bitmap(5,5); // Cria BITMAP com nome "rabo";
    rectfill(rabo, 0, 0, 5, 5, makecol(0,255,0)); // Cria retangulo no BITMAP criado acima;
 
    // Cria a comida;
    BITMAP *maca1 = create_bitmap(5, 5); // Cria BITMAP com nome "maca1";
    rectfill(maca1, 0, 0, 40, 40, makecol(255,255,0)); // Cria retangulo no BITMAP criado acima;

    // Cria o corpo da cobra e aloca dinamicamente do tamanho pr� definido; 
    BITMAP **corpo = (BITMAP **) malloc (sizeof (BITMAP *) * tamanho); // Cria o vetor de BITMAP;

    // Cria plano de fundo;
    BITMAP *fundo = create_bitmap(640, 480); // Cria BITMAP com nome "fundo";
    rectfill(fundo, 0, 0, 640, 480, makecol(125,125,0)); // Cria retangulo no BITMAP criado acima;
 
//  ###########################################################################
  
    for (vAux=0; vAux<=tamanho; vAux++ ) // Passa todas as posi��es do vetor de BITMAP;
    {
        corpo[vAux] = create_bitmap(5,5); // Cria um BITMAP para a posi��o do corpo que esta passando;
        rectfill(corpo[vAux], 0, 0, 5, 5, makecol(255,0,0)); // Cria um retangulo na posi��o do BITMAP criado acima;           
    }
//  ########## - Cria os Vetores de Posi��o da Cobra e Preenche - ############# 
    // Cria Vetor das posi��es
    int *posicao_x = (int*) malloc (sizeof (int *) * tamanho);
    int *posicao_y = (int*) malloc (sizeof (int *) * tamanho); 
 
    for ( vAux=tamanho-1; vAux>=0; vAux--) // Passa todo o vetor de tras para a frente;
    {    
        if (vAux != 0) // Se o valor que est� passando for diferente de zero;
        {
            posicao_x[vAux] = posicao_cabeca_x - ((vAux+1) * distancia);
            posicao_y[vAux] = posicao_cabeca_y;
        }
        else // Quando o valor que esta passando for = 0;
        {
            posicao_x[vAux] = posicao_cabeca_x + (distancia - velocidade);
            posicao_y[vAux] = posicao_cabeca_y + (distancia - velocidade);
        }              
    }    
    //  ###########################################################################
 
    //  #################### - Inicio do Jogo - ###################################
    while (!key[KEY_ESC]) { // O jogo funciona enquanto a tecla "Esc" n�o for pressionada;
      
        clear_bitmap(buffer); // Limpa o BITMAP "buffer";
        draw_sprite(buffer, fundo, 0, 0);
        
        //  ############# - Testa Quais Teclas est�o sendo Pressionadas - #############    
        if (key[KEY_RIGHT])
        { // Se seta para a direita for pressionada e sentido antigo for diferente de LEFT;
            if ( sentido_antigo != 3 )
            {
                sentido_antigo = sentido; // Salva sentido que est� passando em "sentido_antigo";
                sentido = 1; // Recebe o novo sentido "no caso para a direita";
            }
        }
        else
        if (key[KEY_UP])
        {
             // Sen�o Se seta para cima for pressionada e sentido antigo for diferente de DOWN;
            if ( sentido_antigo != 2 )
            {
                sentido_antigo = sentido; // Salva sentido que est� passando em "sentido_antigo";
                sentido = 0; // Recebe o novo sentido "no caso para cima";
            }
        }
        else
        if (key[KEY_LEFT])
        {
             // Sen�o Se seta para a esquerda for pressionada e sentido antigo for diferente de RIGHT;
            if ( sentido_antigo != 1 )
            {
                sentido_antigo = sentido; // Salva sentido que est� passando em "sentido_antigo";
                sentido = 3; // Recebe o novo sentido "no caso para a esquerda";
            }
        }
        else
        if (key[KEY_DOWN])
        {
            // Sen�o Se seta para baixo for pressionada e sentido antigo for diferente de UP;
            if ( sentido_antigo != 0 )
            {
                sentido_antigo = sentido; // Salva sentido que est� passando em "sentido_antigo";
                sentido = 2; // Recebe o novo sentido "no caso para baixo";
            }
        }
        //  ###########################################################################

        //  ################## - Testa se a Comida foi "Comida" - #####################    
        if ( comida == true )
        {
            posicao_comida_x = (rand() % 600)+10; // Randomiza a posi��o para a cria��o da comida no eixo X;
            posicao_comida_y = (rand() % 440)+10; // Randomiza a posi��o para a cria��o da comida no eixo Y;
            comida = false; // Diz ao programa que a Comida n�o foi "Comida" ainda;                
  
            tamanho = tamanho + 2;              
           
            corpo = (BITMAP **) malloc (sizeof (BITMAP *) * tamanho);
          
            // Cria Vetor das posi��es
            int *vetor_aux_x = (int*) malloc (sizeof (int *) * tamanho);
            int *vetor_aux_y = (int*) malloc (sizeof (int *) * tamanho);
           
            for ( vAux=0; vAux<tamanho; vAux++) // Passa todo o vetor de tras para a frente;
            {    
                 
                  if (vAux != tamanho-2)
                  {
                      vetor_aux_x[vAux] = posicao_x[vAux];        
                      vetor_aux_y[vAux] = posicao_y[vAux];        
                  }
                  else
                  {
                      vetor_aux_x[vAux] = posicao_x[vAux-1];        
                      vetor_aux_y[vAux] = posicao_y[vAux-1]; 
                  }
            }
           
            posicao_x = (int*) malloc (sizeof (int *) * tamanho);
            posicao_y = (int*) malloc (sizeof (int *) * tamanho); 
           
            for ( vAux=0; vAux<tamanho; vAux++) // Passa todo o vetor de tras para a frente;
            {   
                corpo[vAux] = create_bitmap(5,5); // Cria um BITMAP para a posi��o do corpo que esta passando;
                rectfill(corpo[vAux], 0, 0, 5, 5, makecol(255,0,0)); // Cria um retangulo na posi��o do BITMAP criado acima;           
               
                posicao_x[vAux] = vetor_aux_x[vAux];        
                posicao_y[vAux] = vetor_aux_y[vAux]; 
               
            } 
        }
     
        // Manda a imagem da comida "maca1" para o buffer;
        draw_sprite(buffer, maca1, posicao_comida_x, posicao_comida_y);
        //  ###########################################################################
      
        draw_sprite(buffer, rabo, posicao_x[tamanho-1], posicao_y[tamanho-1]);
          
        // Aqui vai passando a posi��o do corpo para a posi��o da frente;
        for (vAux=tamanho-1; vAux>=0; vAux--) // Percorre o vetor de tras para a frente;
        {         
            if (vAux != 0) // Se a posi��o que est� passando for diferente de 0;
            {
                posicao_x[vAux] = posicao_x[vAux-1]; // Posi��o X que est� passando recebe a pr�xima posi��o;
                posicao_y[vAux] = posicao_y[vAux-1]; // Posi��o Y que est� passando recebe a pr�xima posi��o;
            }
            else // Sen�o Se a posi��o que est� passando for 0;
            {
                posicao_x[vAux] = posicao_cabeca_x; // Posi��o_X[0] recebe a posi��o X da cabe�a;
                posicao_y[vAux] = posicao_cabeca_y; // Posi��o_Y[0] recebe a posi��o Y da cabe�a;
            }
            if  (posicao_cabeca_x == posicao_x[vAux-1] && posicao_cabeca_y == posicao_y[vAux-1]) // Aqui testa se a cabe�a da cobra bateu no corpo;
            {
                allegro_message("Game Over noob !");
                deinit();
                return 0;
            }           
            // Manda todas as posi��es do corpo para o buffer;
            draw_sprite(buffer, corpo[vAux], posicao_x[vAux], posicao_y[vAux]);
        }
      
        //  ########## - Testa Qual o Sentido que a Cobra esta se Mexendo - ###########          
        // $$$$$$$$$$$$$$$$$$$$$$ - Testa Sentido para Cima - $$$$$$$$$$$$$$$$$$$$$$$$$
        if ( sentido == 0 )
        {
             // Testa se o sentido � para cima (UP) e se a posi��o da cabe�a � maior que 0;        
            if ( posicao_cabeca_y >= 0 )
            {         
                // Troca a cabe�a de lugar
               posicao_cabeca_y = posicao_cabeca_y - velocidade - distancia;                  
               draw_sprite(buffer, cabeca, posicao_cabeca_x, posicao_cabeca_y); // Manda a cabeca para o buffer;
            }
            else
            if (posicao_cabeca_y < 0) // Sen�o Se a posi��o da cabe�a for menor que 0;
            {
                posicao_cabeca_y = 480; // A posi��o da cabe�a recebe 480;
            }
        }
        // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
      
        // $$$$$$$$$$$$$$$$$$$$ - Testa Sentido para a Direita - $$$$$$$$$$$$$$$$$$$$$
        else
        if ( sentido == 1 )
        { // Testa se o sentido � para a direita (RIGHT) e se a poicao da cabe�a � menor ou igual a 640;
            if ( posicao_cabeca_x <= 640 )
            {            
                posicao_cabeca_x = posicao_cabeca_x + velocidade + distancia;               
                draw_sprite(buffer, cabeca, posicao_cabeca_x, posicao_cabeca_y); // Manda a cabeca para o buffer;
            }
            else if (posicao_cabeca_x > 640) // Sen�o Se a posi��o da cabe�a for maior que 640;
            {
                posicao_cabeca_x = 0; // A posi��o da cabe�a recebe 0;
            }
        }
        // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      

        // $$$$$$$$$$$$$$$$$$$$$ - Testa Sentido para Baixo - $$$$$$$$$$$$$$$$$$$$$$$$
        else
        if ( sentido == 2 )
        {  // Testa se o sentido � para baixo (DOWN) e se a posi��o da cabe�a � menor ou igual a 480;
            if ( posicao_cabeca_y <= 480 )
            {
                posicao_cabeca_y = posicao_cabeca_y + velocidade + distancia;            
                draw_sprite(buffer, cabeca, posicao_cabeca_x, posicao_cabeca_y); // Manda a cabeca para o buffer;
            }
            else if ( posicao_cabeca_y > 480 )  // Sen�o Se a posi��o da cabe�a for maior que 480;
            {
                posicao_cabeca_y = 0; // A posi��o da cabe�a recebe 0;
            }
        }
        // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
      
        // $$$$$$$$$$$$$$$$$$$$ - Testa Sentido para a Esquerda - $$$$$$$$$$$$$$$$$$$$
        else
        if ( sentido == 3 )
        { // Testa se o sentido � para a esquerda (LEFT) e se a posi��o da cabe�a � maior ou igual a 0;
            if ( posicao_cabeca_x >= 0 )
            {
                posicao_cabeca_x = posicao_cabeca_x - velocidade - distancia;                                      
                draw_sprite(buffer, cabeca, posicao_cabeca_x, posicao_cabeca_y); // Manda a cabeca para o buffer;
            }
            else if ( posicao_cabeca_x < 0 ) // Sen�o Se a posi��o da cabe�a for menor que 0;
            {
                posicao_cabeca_x = 640; // A posi��o da cabe�a recebe 640;
            }
        }
        // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
        //  ###########################################################################

       //  ################### - Testa se a Cobra Comeu a Comida - ###################
       vAux = (tamanhocabeca*-1);     
       while (vAux <= tamanhocabeca && comida == false)
       {
           if ( posicao_cabeca_x == posicao_comida_x + vAux)
           {
              vPos = (tamanhocabeca*-1);
            
              while (vPos <= tamanhocabeca && comida == false)
              {
                  if ((posicao_cabeca_y) == posicao_comida_y + vPos)
                      comida = true;
              
                  vPos = vPos + 1;
              }
           }                 
        
           vAux = vAux + 1;
       }
       //  ###########################################################################
     
        draw_sprite(screen, buffer, 0,0); // Manda todo o "buffer" para a tela;
       
        rest(10);
     
    } // @@@@ - Fim do While do Jogo - @@@@
    //  ######################## - Fim do While do Jogo - #########################

    deinit(); // Chama a fun��o e finaliza o Allegro;
    return 0;
} // Fim do m�todo "main";
END_OF_MAIN(); // Finaliza o "main";

//  ############# - Fun��o que Inicializa fun��es do Allegro - ################
void fInicializa()
{
    allegro_init(); // Fun��o padr�o que inicializa fun��es do Allegro;
 
    set_color_depth(32);
 
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0); // Detecta o video e cria a janela do tamanho desejado;

    install_timer(); // Inicializa as funcionalidades do timer;
    install_keyboard(); // Inicializa as funcionalidades do teclado;
    install_mouse(); // Inicializa as funcionalidades do mouse;
}
//  ###########################################################################

//  ############## - Fun��o que Finaliza fun��es do Allegro - #################
void deinit()
{
    remove_timer();
    remove_keyboard();
    remove_mouse();
    allegro_exit();
}
//  ###########################################################################
