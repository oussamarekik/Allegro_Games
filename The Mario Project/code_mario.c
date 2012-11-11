/*
    The Mario Project
*/
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

// ############ - Declaração das Funções - ##################
void init(int resolucao_x, int resolucao_y);
void deinit();
void fCarrega_Sprites_Mapa();
void fCarrega_Mapa();
void fMostra_Mapa();
void fGravidade();
int fColisao();
void fPulo();
void fNova_Fase();
// ##########################################################

// ############ - Declaração das Variáveis - ################
int vFase = 1; // Guarda a fase que está;
int vQuantidade_Fases = 5;
int vTile = 32; // Define o tamanho dos tiles;
float vPos_x = 0;
float vPos_y = 0;
float vGravidade = 2;//32;
int vSentido = 1; // Para a esquerda 0 para a direita 1;
int vContador_Pulo = 0;
bool vPulo = false;
bool vSprite = true;
float vVelocidade = 0.5;
float vContador_Movimento = 0;
bool vGravidade_fail = true;

char vMatriz_Mapa[15][20]; // Matriz que desenha o mapa;
char *vFases[] = {"Fases/fase1.txt","Fases/fase2.txt","Fases/fase3.txt","Fases/fase4.txt","Fases/fase5.txt"}; // Guarda o endereço dos arquivos das fases;
char vLe_Char; // Variável auxiliar para a leitura dos arquivos de texto;

BITMAP *bTile; // Bitmap do tile;
BITMAP *bMapa; // Bitmap do mapa;
BITMAP *bTexturas[20]; // Vetor de bitmap das texturas;
BITMAP *bChar; // Bitmap do personagem;
BITMAP *bMario[3];
// ##########################################################

int main()
{
    int vResolucao_x = 640;
    int vResolucao_y = 480;

    init(vResolucao_x, vResolucao_y);

    BITMAP *buffer = create_bitmap(vResolucao_x, vResolucao_y);
    
    bTile = load_bitmap("Tiles/tile.bmp", NULL);
    bChar = load_bitmap("Tiles/mario.bmp", NULL);
    bMapa = create_bitmap(vResolucao_x, vResolucao_y);
    
// ############# - Carrega imagens do mario - ############
    bMario[0] = create_bitmap(vTile,vTile);
    bMario[1] = create_bitmap(vTile,vTile);
    bMario[2] = create_bitmap(vTile,vTile);
    blit(bChar, bMario[0],  0, 0, 0, 0, vTile, vTile);
    blit(bChar, bMario[1],  33, 0, 0, 0, vTile, vTile);
    blit(bChar, bMario[2],  66, 0, 0, 0, vTile, vTile);
// #######################################################

    install_int(fGravidade,5);
    
    fCarrega_Sprites_Mapa();
    fCarrega_Mapa();
    fMostra_Mapa();

    draw_sprite(screen, bMapa, 0, 0 );

	while (!key[KEY_ESC]) {

        clear_bitmap(buffer);

	    if (key[KEY_LEFT])
		{
            if ( vSprite == true )
                vSprite = false;
            else
                vSprite = true;
               
            vSentido = 0;

            if ( vContador_Movimento == 0 )
            {
                if ( fColisao() == 0 )
                {
                    vPos_x -= vVelocidade;
                    vContador_Movimento = 32;
                }
            }
            else
            {
                vPos_x -= vVelocidade;
                vContador_Movimento -= vVelocidade;
            }
                        
        }
	    if (key[KEY_RIGHT])
		{
            if ( vSprite == true )
                vSprite = false;
            else
                vSprite = true;
                
            vSentido = 1;

            if ( vContador_Movimento == 32 )
            {
                if ( fColisao() == 0 )
                {
                    vPos_x += vVelocidade;
                    vContador_Movimento = 0;
                }
            }
            else
            {
                vPos_x += vVelocidade;
                vContador_Movimento += vVelocidade;
            }
            
        }
	    if (key[KEY_ENTER] && vPulo == false)
		{
            fNova_Fase();
        }
	    if (key[KEY_SPACE] && vPulo == false && vGravidade_fail == true )
		{
            vPulo = true;
            install_int(fPulo,6);
        }
        
        draw_sprite(buffer, bMapa, 0, 0 );
        
        if ( vSentido == 1 && vPulo == true )
            draw_sprite(buffer, bMario[2], vPos_x, vPos_y );
        else
        if ( vSentido == 0 && vPulo == true )
            rotate_sprite_v_flip(buffer, bMario[2], vPos_x, vPos_y, itofix(128));
        else
        if ( vSentido == 1 && vSprite == true )
            draw_sprite(buffer, bMario[0], vPos_x, vPos_y );
        else
        if ( vSentido == 1 && vSprite == false )
            draw_sprite(buffer, bMario[1], vPos_x, vPos_y );
        else 
        if ( vSentido == 0 && vSprite == true )
            rotate_sprite_v_flip(buffer, bMario[0], vPos_x, vPos_y, itofix(128));
        else 
        if ( vSentido == 0 && vSprite == false )
            rotate_sprite_v_flip(buffer, bMario[1], vPos_x, vPos_y, itofix(128));
        
        textprintf_ex(buffer, font, 50, 40,makecol(0, 0, 255), -1,"Pontuacao: %f",vContador_Movimento);    
       
        draw_sprite(screen, buffer, 0, 0 );
        
        if ( !key[KEY_RIGHT] && !key[KEY_LEFT] && vSprite == false )
            vSprite = true;
    }

	deinit();
	return 0;
}
END_OF_MAIN();

void init(int resolucao_x, int resolucao_y)
{
	allegro_init();

	set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, resolucao_x, resolucao_y, 0, 0);

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit()
{
	clear_keybuf();
}

void fCarrega_Sprites_Mapa() // Função que separa o sprite;
{
    int vAux;

    for (vAux=0; vAux<20; vAux++) // Aloca todo o vetor de BITMAP;
    {
        bTexturas[vAux] = create_bitmap(vTile,vTile);
    }

    blit(bTile, bTexturas[0],  0, 0, 0, 0, vTile, vTile); // Cano Verde "BOCA";
    blit(bTile, bTexturas[1],  0, 32, 0, 0, vTile, vTile); // Cano Verde;
    blit(bTile, bTexturas[2],  0, 64, 0, 0, vTile, vTile); // Cano Roxo "BOCA";
    blit(bTile, bTexturas[3],  0, 96, 0, 0, vTile, vTile); // Cano Roxo;
    
    blit(bTile, bTexturas[4],  32, 0, 0, 0, vTile, vTile); // Chão com borda esquerda em cima;
    blit(bTile, bTexturas[5],  32, 32, 0, 0, vTile, vTile); // Chão com borda esquerda em baixo;
    blit(bTile, bTexturas[6],  32, 64, 0, 0, vTile, vTile); // Chão com borda esquerda em cima e em baixo;
    blit(bTile, bTexturas[7],  32, 96, 0, 0, vTile, vTile); // Chão com borda esquerda;
    
    blit(bTile, bTexturas[8],  64, 0, 0, 0, vTile, vTile); // Chão com borda meio em cima;
    blit(bTile, bTexturas[9],  64, 32, 0, 0, vTile, vTile); // Chão com borda meio em baixo;
    blit(bTile, bTexturas[10],  64, 64, 0, 0, vTile, vTile); // Chão com borda meio em cima e em baixo;
    blit(bTile, bTexturas[11],  64, 96, 0, 0, vTile, vTile); // Chão com borda Direita;

    blit(bTile, bTexturas[12],  96, 0, 0, 0, vTile, vTile); // Chão com borda direita em cima;
    blit(bTile, bTexturas[13],  96, 32, 0, 0, vTile, vTile); // Chão com borda direita em baixo;
    blit(bTile, bTexturas[14],  96, 64, 0, 0, vTile, vTile); // Chão com borda direita em cima e em baixo;
    blit(bTile, bTexturas[15],  96, 96, 0, 0, vTile, vTile); // Agua com ondas;
    
    blit(bTile, bTexturas[16],  128, 0, 0, 0, vTile, vTile); // Chão normal sem borda;
    
    blit(bTile, bTexturas[17],  128, 0, 0, 0, vTile, vTile); // Chão normal sem borda;
    blit(bTile, bTexturas[18],  128, 0, 0, 0, vTile, vTile); // Chão normal sem borda;
    blit(bTile, bTexturas[19],  128, 0, 0, 0, vTile, vTile); // Chão normal sem borda;
    
}

void fCarrega_Mapa()
{
    FILE *fFase = fopen(vFases[vFase], "r"); // Carrega o arquivo de texto da fase em questão;
    
    int x=0;
    int y=0;

    while((vLe_Char = getc(fFase) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( y < 20 ) // Enquanto estivar na linha;
        {
            vMatriz_Mapa[x][y] = vLe_Char; // Carrega a matriz com os caracteres que representam as imagens;
            y++;
        }
        else // senao passa para a proxima linha;
        {
            x++;
            y=0;
        }
    }
}

void fMostra_Mapa() // Função que "cria" o mapa;
{
    int x,y;
    
    rectfill(bMapa, 0,0 ,640, 480, makecol(220,250,250)); // Carrega o fundo do mapa;
    
    for (x=0; x<15; x++)
    {
        for (y=0; y<20 ;y++)
        {
            if ( vMatriz_Mapa[x][y] == '#' )
            {
                draw_sprite(bMapa, bTexturas[0], y*32, x*32 );
                vPos_y = (x * 32) - 32;
                vPos_x = y * 32;
            }
            else if ( vMatriz_Mapa[x][y] == '*' )
                draw_sprite(bMapa, bTexturas[1], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '$' )
                draw_sprite(bMapa, bTexturas[2], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '!' )
                draw_sprite(bMapa, bTexturas[3], y*32, x*32 );
                
            else if ( vMatriz_Mapa[x][y] == '0' )
                draw_sprite(bMapa, bTexturas[4], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '1' )
                draw_sprite(bMapa, bTexturas[5], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '2' )
                draw_sprite(bMapa, bTexturas[6], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '3' )
                draw_sprite(bMapa, bTexturas[7], y*32, x*32 );
                
            else if ( vMatriz_Mapa[x][y] == '4' )
                draw_sprite(bMapa, bTexturas[8], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '5' )
                draw_sprite(bMapa, bTexturas[9], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '6' )
                draw_sprite(bMapa, bTexturas[10], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '7' )
                draw_sprite(bMapa, bTexturas[11], y*32, x*32 );

            else if ( vMatriz_Mapa[x][y] == '8' )
                draw_sprite(bMapa, bTexturas[12], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '9' )
                draw_sprite(bMapa, bTexturas[13], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '+' )
                draw_sprite(bMapa, bTexturas[14], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '~' )
                draw_sprite(bMapa, bTexturas[15], y*32, x*32 );

            else if ( vMatriz_Mapa[x][y] == '=' )
                draw_sprite(bMapa, bTexturas[16], y*32, x*32 );
                
            else if ( vMatriz_Mapa[x][y] == '=' )
                draw_sprite(bMapa, bTexturas[17], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '=' )
                draw_sprite(bMapa, bTexturas[18], y*32, x*32 );
            else if ( vMatriz_Mapa[x][y] == '=' )
                draw_sprite(bMapa, bTexturas[19], y*32, x*32 );
        }
    }
}

void fGravidade()
{   
     int vSentido_Antigo = vSentido;
     vSentido = -1;
     
     if ( vPulo == false )
     if ( fColisao() == 0 )
     if ( vPos_y < 448 )
     {
        vPos_y += vGravidade; 
        vGravidade_fail = false;
     }
     
     if ( fColisao() == 1 )
        vGravidade_fail = true;
     
     vSentido = vSentido_Antigo;
}

int fColisao()
{
    int aux_x = (vPos_x - vContador_Movimento) / 32;
    int aux_y = vPos_y / 32;
    
    if ( vSentido == 1 )
        aux_x += 1;
    else 
    if ( vSentido == 0 )
        aux_x -= 1;
    else
    if ( vSentido == -1 )
        aux_y += 1;
    else
    if ( vSentido == 2 )
        aux_y -= 1;

    if ( vMatriz_Mapa[aux_y][aux_x] != ':' )
        return 1;  
    if ( vPos_y <= 0 && key[KEY_SPACE] )
        return 1;
    if ( vPos_x <= 0 && key[KEY_LEFT] )
        return 1;
    if ( vPos_x >= 596  && key[KEY_RIGHT] )
        return 1;
    
    return 0;
}

void fPulo()
{
     int vSentido_Antigo = vSentido;
     vSentido = 2;

     if ( fColisao() == 0 && vContador_Pulo < 32 )
     {
          vPos_y -= vGravidade;
          vContador_Pulo += 1;
     }
     else
     {
         vGravidade_fail = false;
         vPulo = false;
         vContador_Pulo = 0;
         remove_int(fPulo);
     }
     
     vSentido = vSentido_Antigo;
}

void fNova_Fase()
{
    int aux_y = vPos_y / 32;
    int aux_x = vPos_x / 32;

    if ( vFase < vQuantidade_Fases-1 )
        if ( vMatriz_Mapa[aux_y+1][aux_x] == '$' )
        {
            vFase++;
            clear_bitmap(bMapa);
            fCarrega_Sprites_Mapa();
            fCarrega_Mapa();
            fMostra_Mapa();
        } 
}
