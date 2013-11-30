#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Personaje.h"
#include <vector>
#include "Position.h"
#include "SDL/SDL_mixer.h"

const int SCREEN_WIDTH =960;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 20;

int scr_off_x = 0;
int scr_off_y = 0;
int lim_x1 = 2;
int lim_y1 = 2;
int lim_x2 = 12;
int lim_y2 = 7;
int turn = 0;
bool game_over = false;
SDL_Surface* river_horizontal_1;
SDL_Surface* river_vertical_1;
SDL_Surface* river_vertical_2;
SDL_Surface* river_side_left_1;
SDL_Surface* river_side_right_1;
SDL_Surface* river_side_down_1;
SDL_Surface* river_side_up_1;
SDL_Surface* river_side_NE_1;
SDL_Surface* river_side_SW_1;
SDL_Surface* river_side_NW_1;
SDL_Surface* river_side_NW_2;
SDL_Surface* river_side_SE_1;
SDL_Surface* river_side_SE_2;
SDL_Surface* plains_1;
SDL_Surface* plain_full_1;
SDL_Surface* plain_edge_down_1;
SDL_Surface* plain_light_down_1;
SDL_Surface* plain_light_left_1;
SDL_Surface* plain_light_right_1;
SDL_Surface* plain_light_NW_1;
SDL_Surface* plain_light_NE_1;
SDL_Surface* plain_light_SW_1;
SDL_Surface* plain_light_SE_1;
SDL_Surface* plain_light_up_1;
SDL_Surface* trees_1;
SDL_Surface* trees_2;
SDL_Surface* trees_3;
SDL_Surface* mountain_1;
SDL_Surface* mountain_2;
SDL_Surface* vert_bridge;
SDL_Surface* hor_bridge;
SDL_Surface* fort;
SDL_Surface* house;
SDL_Surface* game_end;
SDL_Surface* cursor_cube;

vector<Personaje*> Player1;
vector<Personaje*> Player2;

int cursor_x = 0;
int cursor_y = 0;

Mix_Chunk*cursor_move_sound;
Mix_Chunk*invalid_move_sound;
Mix_Chunk*select_sound;
Mix_Chunk*unselect_sound;
Mix_Chunk*move_complete_sound;
Mix_Chunk*next_turn_sound;


SDL_Surface *screen = NULL;

SDL_Event event;

TTF_Font *font = NULL;

SDL_Color textColor = { 179, 3, 3 };

class Timer
{
    private:
    int startTicks;

    int pausedTicks;

    bool paused;
    bool started;

    public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();

    bool is_started();
    bool is_paused();
};

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    return loadedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL )
    {
        return false;
    }

    if( TTF_Init() == -1 )
    {
        return false;
    }

    SDL_WM_SetCaption( "Power Emblem", NULL );

    return true;
}

bool load_files()
{
    font = TTF_OpenFont( "lazy.ttf", 72 );

    if( font == NULL )
    {
        return false;
    }
    cursor_move_sound = Mix_LoadWAV("Resources/Sounds/Cursor_Move.wav");
    invalid_move_sound = Mix_LoadWAV("Resources/Sounds/Invalid_Move.wav");
    select_sound = Mix_LoadWAV("Resources/Sounds/Unit_Select.wav");
    unselect_sound = Mix_LoadWAV("Resources/Sounds/Cancel_Move.wav");
    move_complete_sound = Mix_LoadWAV("Resources/Sounds/Select_Move.wav");
    next_turn_sound = Mix_LoadWAV("Resources/Sounds/Turn_Change.wav");

    river_horizontal_1 = load_image("Resources/Map_Tiles/River_Horizontal_1.png");
    river_vertical_1 = load_image("Resources/Map_Tiles/River_Vertical_1.png");
    river_vertical_2 = load_image("Resources/Map_Tiles/River_Vertical_2.png");
    river_side_left_1 = load_image("Resources/Map_Tiles/River_Side_Left_1.png");
    river_side_right_1 = load_image("Resources/Map_Tiles/River_Side_Right_1.png");
    river_side_down_1 = load_image("Resources/Map_Tiles/River_Side_Down_1.png");
    river_side_up_1 = load_image("Resources/Map_Tiles/River_Side_Up_1.png");
    river_side_NE_1 = load_image("Resources/Map_Tiles/River_Side_NE_1.png");
    river_side_SW_1 = load_image("Resources/Map_Tiles/River_Side_SW_1.png");
    river_side_NW_1 = load_image("Resources/Map_Tiles/River_Side_NW_1.png");
    river_side_NW_2 = load_image("Resources/Map_Tiles/River_Side_NW_2.png");
    river_side_SE_1 = load_image("Resources/Map_Tiles/River_Side_SE_1.png");
    river_side_SE_2 = load_image("Resources/Map_Tiles/River_Side_SE_2.png");
    plains_1 = load_image("Resources/Map_Tiles/Plains_1.png");
    plain_full_1 = load_image("Resources/Map_Tiles/Plain_Full_1.png");
    plain_edge_down_1 = load_image("Resources/Map_Tiles/Plain_Edge_Down_1.png");
    plain_light_down_1 = load_image("Resources/Map_Tiles/Plain_Light_Down_1.png");
    plain_light_left_1 = load_image("Resources/Map_Tiles/Plain_Light_Left_1.png");
    plain_light_right_1 = load_image("Resources/Map_Tiles/Plain_Light_Right_1.png");
    plain_light_NW_1 = load_image("Resources/Map_Tiles/Plain_Light_NW_1.png");
    plain_light_NE_1 = load_image("Resources/Map_Tiles/Plain_Light_NE_1.png");
    plain_light_SW_1 = load_image("Resources/Map_Tiles/Plain_Light_SW_1.png");
    plain_light_SE_1 = load_image("Resources/Map_Tiles/Plain_Light_SE_1.png");
    plain_light_up_1 = load_image("Resources/Map_Tiles/Plain_Light_Up_1.png");
    trees_1 = load_image("Resources/Map_Tiles/Forest_1.png");
    trees_2 = load_image("Resources/Map_Tiles/Forest_2.png");
    trees_3 = load_image("Resources/Map_Tiles/Forest_3.png");
    mountain_1 = load_image("Resources/Map_Tiles/Mountains_1.png");
    mountain_2 = load_image("Resources/Map_Tiles/Mountains_2.png");
    vert_bridge = load_image("Resources/Map_Tiles/Bridge_Vertical.png");
    hor_bridge = load_image("Resources/Map_Tiles/Bridge_Horizontal.png");
    fort = load_image("Resources/Map_Tiles/Fort_1.png");
    house = load_image("Resources/Map_Tiles/House_1.png");


    cursor_cube = load_image("Resources/Map_Tiles/Cursor_Block.png");

    Player1.push_back(new Personaje("Lord", 1, 0, 2));
    Player1.push_back(new Personaje("Lord", 1, 0, 5));
    Player1.push_back(new Personaje("Lord", 1, 0, 7));
    Player2.push_back(new Personaje("Knight", 1, 14, 8));
    Player2.push_back(new Personaje("Knight", 1, 14, 6));
    Player2.push_back(new Personaje("Knight", 1, 14, 4));
    return true;
}

void clean_up()
{

    TTF_CloseFont( font );

    TTF_Quit();

    SDL_Quit();
}

Timer::Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    started = true;

    paused = false;

    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    started = false;

    paused = false;
}

void Timer::pause()
{
    if( ( started == true ) && ( paused == false ) )
    {
        paused = true;

        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    if( paused == true )
    {
        paused = false;

        startTicks = SDL_GetTicks() - pausedTicks;

        pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
    if( started == true )
    {
        if( paused == true )
        {
            return pausedTicks;
        }
        else
        {
            return SDL_GetTicks() - startTicks;
        }
    }

    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}

int main( int argc, char* args[] )
{
    bool quit = false;
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    int frame = 0;

    bool cap = true;

    Timer fps;

    if( init() == false )
    {
        return 1;
    }

    if( load_files() == false )
    {
        return 1;
    }

    char tablero[14][18]={{'5', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', '4', 'w', '5', 'c', 'c', 'j', 'c', 'c', '4'},
                          {'6', ' ', 'j', 'j', ' ', ' ', 'j', ' ', ' ', 'g', 'e', '3', 'j', 'g', 'f', '6', ' ', 'g'},
                          {'6', 'g', 'z', 'm', '6', 'h', 'z', '6', ' ', 'g', 'o', 'i', 'u', '6', 'c', ' ', ' ', 'g'},
                          {'6', 'g', 'n', '5', 'g', 'x', '5', 'j', 'j', ' ', '4', 'o', 't', '6', ' ', ' ', ' ', 'g'},
                          {'6', ' ', 'c', ' ', ' ', 'c', 'g', 'l', 'k', '6', ' ', '4', 'w', '6', ' ', ' ', 'j', 'g'},
                          {'6', ' ', ' ', ' ', ' ', ' ', ' ', 'c', 'c', ' ', ' ', 'g', 'b', '6', ' ', 'g', 'f', '6'},
                          {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'j', ' ', ' ', 'g', 'e', '6', ' ', ' ', 'c', 'g'},
                          {'6', ' ', ' ', ' ', ' ', ' ', 'j', 'h', 'x', '3', ' ', 'g', 'w', '6', ' ', ' ', ' ', 'g'},
                          {'6', ' ', 'j', ' ', ' ', 'g', 'k', 'k', '2', 'm', '6', 'g', 'e', '3', 'j', ' ', ' ', 'g'},
                          {'6', 'g', 'f', '3', ' ', ' ', '4', 'l', '5', 'c', ' ', 'g', 'o', 'i', 'u', '3', 'j', 'h'},
                          {'6', ' ', '4', 'f', '6', ' ', ' ', 'c', 'j', 'j', ' ', ' ', '4', 'o', 'y', 'q', 'v', 'q'},
                          {'6', ' ', ' ', 'c', ' ', ' ', ' ', 'g', 'n', 'x', '6', ' ', 'g', 'l', '5', 'c', '4', '2'},
                          {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'c', 'c', ' ', ' ', 'j', 'c', ' ', 'j', 'h', 'k'},
                          {'3', 'j', 'j', 'j', 'j', 'j', 'j', 'j', 'j', 'j', 'j', 'h', 'z', '3', 'h', 'z', 'l', 'z'}};

    while( quit == false )
    {
        fps.start();
        if( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_KEYDOWN )
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
                        if((cursor_y>lim_y1) ||
                           (cursor_y <= lim_y1 &&cursor_y > 0 && lim_y1 <= 2))
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_y--;
                        }else if(cursor_y <= lim_y1 && lim_y1 > 2)
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_y--;
                            lim_y1--;
                            lim_y2--;
                            scr_off_y--;
                        }
                        break;
                    case SDLK_DOWN:
                        if((cursor_y < lim_y2) ||
                           (cursor_y >= lim_y2 &&
                            cursor_y < (sizeof(tablero)/sizeof(tablero[0]))-1 &&
                            lim_y2 >= (sizeof(tablero)/sizeof(tablero[0]))-3))
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_y++;
                        }else if(cursor_y >= lim_y2 && lim_y2 < (sizeof(tablero)/sizeof(tablero[0]))-3)
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_y++;
                            lim_y1++;
                            lim_y2++;
                            scr_off_y++;
                        }
                        break;
                    case SDLK_LEFT:
                        if((cursor_x>lim_x1) ||
                           (cursor_x <= lim_x1 &&cursor_x > 0 && lim_x1 <= 2))
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_x--;
                        }else if(cursor_x <= lim_x1 && lim_x1 > 2)
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_x--;
                            lim_x1--;
                            lim_x2--;
                            scr_off_x--;
                        }
                        break;
                    case SDLK_RIGHT:
                        if((cursor_x < lim_x2) ||
                           (cursor_x >= lim_x2 && cursor_x < sizeof(tablero[0])-1 && lim_x2 >= sizeof(tablero[0])-3))
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_x++;
                        }else if(cursor_x >= lim_x2 && lim_x2 < sizeof(tablero[0])-3)
                        {
                            Mix_PlayChannel( -1, cursor_move_sound, 0 );
                            cursor_x++;
                            lim_x1++;
                            lim_x2++;
                            scr_off_x++;
                        }
                        break;
                    case SDLK_z:
                        if(turn % 2 == 0)
                        {
                            for(int i = 0; i < Player1.size(); i++)
                            {
                                if((cursor_x == Player1[i]->Pos_x && cursor_y == Player1[i]->Pos_y) && Player1[i]->has_moved)
                                {
                                    Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                    break;
                                }
                                if((cursor_x == Player1[i]->Pos_x && cursor_y == Player1[i]->Pos_y) && !Player1[i]->moving)
                                {
                                    for(int e = 0; e < Player1.size(); e++)
                                    {
                                        if(Player1[e]->moving)
                                        {
                                            Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                            goto DATEND2;
                                        }
                                    }
                                    for(int e = 0; e < Player2.size(); e++)
                                    {
                                        if(Player2[e]->moving)
                                        {
                                            Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                            goto DATEND2;
                                        }

                                    }
                                    Player1[i]->moving = true;
                                    Mix_PlayChannel( -1, select_sound, 0 );
                                    DATEND2:;
                                }else if((cursor_x == Player1[i]->Pos_x && cursor_y == Player1[i]->Pos_y) && Player1[i]->moving)
                                {
                                    Mix_PlayChannel( -1, unselect_sound, 0 );
                                    Player1[i]->moving = false;
                                }else if((cursor_x != Player1[i]->Pos_x || cursor_y != Player1[i]->Pos_y) && Player1[i]->moving)
                                {
                                    for(int e = 0; e < Player1.size(); e++)
                                    {
                                        if(cursor_x == Player1[e]->Pos_x && cursor_y == Player1[e]->Pos_y)
                                            goto DATEND;
                                    }
                                    for(int e = 0; e < Player2.size(); e++)
                                    {
                                        if(cursor_x == Player2[e]->Pos_x && cursor_y == Player2[e]->Pos_y)
                                            goto DATEND;
                                    }

                                    Player1[i]->currently_moving = (Player1[i]->get_to_goal(tablero, Player1[i]->Pos_x, Player1[i]->Pos_y, Player1[i]->Pasos, cursor_x, cursor_y, Player2));
                                    if(Player1[i]->currently_moving)
                                    {
                                        Player1[i]->moving = false;
                                        Player1[i]->Positions = Player1[i]->getPositions(tablero, Player1[i]->Pos_x, Player1[i]->Pos_y, Player1[i]->Pasos, cursor_x, cursor_y, '0', Player2);
                                        Player1[i]->moving_x = Player1[i]->Pos_x*64;
                                        Player1[i]->moving_y = Player1[i]->Pos_y*64;
                                        Player1[i]->pos_vector = Player1[i]->Positions.size()-1;
                                        Mix_PlayChannel( -1, move_complete_sound, 0 );
                                    }else
                                    {
                                        Mix_PlayChannel( -1, invalid_move_sound, 0 );

                                    }

                                    DATEND:;
                                }
                            }
                        }else
                        {
                            for(int i = 0; i < Player2.size(); i++)
                            {
                                if((cursor_x == Player2[i]->Pos_x && cursor_y == Player2[i]->Pos_y) && Player2[i]->has_moved)
                                {
                                    Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                    break;
                                }
                                if((cursor_x == Player2[i]->Pos_x && cursor_y == Player2[i]->Pos_y) && !Player2[i]->moving)
                                {
                                    for(int e = 0; e < Player2.size(); e++)
                                    {
                                        if(Player2[e]->moving)
                                        {
                                            Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                            goto DATEND4;
                                        }
                                    }
                                    for(int e = 0; e < Player1.size(); e++)
                                    {
                                        if(Player1[e]->moving)
                                        {
                                            Mix_PlayChannel( -1, invalid_move_sound, 0 );
                                            goto DATEND4;
                                        }

                                    }
                                    Player2[i]->moving = true;
                                    Mix_PlayChannel( -1, select_sound, 0 );
                                    DATEND4:;
                                }else if((cursor_x == Player2[i]->Pos_x && cursor_y == Player2[i]->Pos_y) && Player2[i]->moving)
                                {
                                    Mix_PlayChannel( -1, unselect_sound, 0 );
                                    Player2[i]->moving = false;
                                }else if((cursor_x != Player2[i]->Pos_x || cursor_y != Player2[i]->Pos_y) && Player2[i]->moving)
                                {
                                    for(int e = 0; e < Player2.size(); e++)
                                    {
                                        if(cursor_x == Player2[e]->Pos_x && cursor_y == Player2[e]->Pos_y)
                                            goto DATEND3;
                                    }
                                    for(int e = 0; e < Player1.size(); e++)
                                    {
                                        if(cursor_x == Player1[e]->Pos_x && cursor_y == Player1[e]->Pos_y)
                                            goto DATEND3;
                                    }

                                    Player2[i]->currently_moving = (Player2[i]->get_to_goal(tablero, Player2[i]->Pos_x, Player2[i]->Pos_y, Player2[i]->Pasos, cursor_x, cursor_y, Player1));
                                    if(Player2[i]->currently_moving)
                                    {
                                        Player2[i]->moving = false;
                                        Player2[i]->Positions = Player2[i]->getPositions(tablero, Player2[i]->Pos_x, Player2[i]->Pos_y, Player2[i]->Pasos, cursor_x, cursor_y, '0', Player1);
                                        Player2[i]->moving_x = Player2[i]->Pos_x*64;
                                        Player2[i]->moving_y = Player2[i]->Pos_y*64;
                                        Player2[i]->pos_vector = Player2[i]->Positions.size()-1;
                                        Mix_PlayChannel( -1, move_complete_sound, 0 );
                                    }else
                                    {
                                        Mix_PlayChannel( -1, invalid_move_sound, 0 );

                                    }
                                    DATEND3:;
                                }
                            }
                        }
                        break;
                    case SDLK_x:
                        if(turn%2==0)
                        {
                            for(int i = 0; i < Player1.size(); i++)
                            {
                                if(Player1[i]->moving)
                                {
                                    Mix_PlayChannel( -1, unselect_sound, 0 );
                                    Player1[i]->moving = false;
                                    cursor_x = Player1[i]->Pos_x;
                                    cursor_y = Player1[i]->Pos_y;
                                }
                            }
                        }else
                        {
                            for(int i = 0; i < Player2.size(); i++)
                            {
                                if(Player2[i]->moving)
                                {
                                    Mix_PlayChannel( -1, unselect_sound, 0 );
                                    Player2[i]->moving = false;
                                    cursor_x = Player2[i]->Pos_x;
                                    cursor_y = Player2[i]->Pos_y;
                                }
                            }
                        }
                }
            }
            else if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        for(int yy = 0; yy <14; yy++)
        {
            for(int xx = 0; xx < 18; xx++)
            {
                if(((xx-scr_off_x)*64 >= 0 && (xx-scr_off_x)*64 <= 896) && (yy-scr_off_y)*64 >= 0 && (yy-scr_off_y)*64 <= 576)
                {
                    if(tablero[yy][xx]=='q')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_horizontal_1, screen);
                    if(tablero[yy][xx]=='w')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_vertical_1, screen);
                    if(tablero[yy][xx]=='e')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_vertical_2, screen);
                    if(tablero[yy][xx]=='r')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_left_1, screen);
                    if(tablero[yy][xx]=='t')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_right_1, screen);
                    if(tablero[yy][xx]=='y')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_down_1, screen);
                    if(tablero[yy][xx]=='u')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_up_1, screen);
                    if(tablero[yy][xx]=='i')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_NE_1, screen);
                    if(tablero[yy][xx]=='o')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_SW_1, screen);
                    if(tablero[yy][xx]=='p')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_NW_1, screen);
                    if(tablero[yy][xx]=='a')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_NW_2, screen);
                    if(tablero[yy][xx]=='s')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_SE_1, screen);
                    if(tablero[yy][xx]=='1')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, river_side_SE_2, screen);
                    if(tablero[yy][xx]=='k')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, trees_1, screen);
                    if(tablero[yy][xx]=='l')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, trees_2, screen);
                    if(tablero[yy][xx]=='z')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, trees_3, screen);
                    if(tablero[yy][xx]=='m')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, mountain_1, screen);
                    if(tablero[yy][xx]=='n')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, mountain_2, screen);
                    if(tablero[yy][xx]=='2')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plains_1, screen);
                    if(tablero[yy][xx]==' ')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_full_1, screen);
                    if(tablero[yy][xx]=='d')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_edge_down_1, screen);
                    if(tablero[yy][xx]=='c')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_down_1, screen);
                    if(tablero[yy][xx]=='g')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_left_1, screen);
                    if(tablero[yy][xx]=='6')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_right_1, screen);
                    if(tablero[yy][xx]=='h')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_NW_1, screen);
                    if(tablero[yy][xx]=='3')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_NE_1, screen);
                    if(tablero[yy][xx]=='4')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_SW_1, screen);
                    if(tablero[yy][xx]=='5')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_SE_1, screen);
                    if(tablero[yy][xx]=='j')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, plain_light_up_1, screen);
                    if(tablero[yy][xx]=='v')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, vert_bridge, screen);
                    if(tablero[yy][xx]=='b')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, hor_bridge, screen);
                    if(tablero[yy][xx]=='f')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, fort, screen);
                    if(tablero[yy][xx]=='x')
                        apply_surface((xx-scr_off_x)*64, (yy-scr_off_y)*64, house, screen);
                }
            }
        }
        for(int i = 0; i < Player1.size(); i++)
        {
            if(Player1[i]->moving)
            {
                Player1[i]->it_type = 2;
                Player1[i]->logic1(screen, tablero, Player1[i]->Pos_x, Player1[i]->Pos_y, Player1[i]->Pasos, '0', scr_off_x, scr_off_y, Player2);
                Player1[i]->logic2(screen, tablero, Player1[i]->Pos_x, Player1[i]->Pos_y, Player1[i]->Pasos, '0', scr_off_x, scr_off_y, Player2);
                Player1[i]->Positions.clear();
                Player1[i]->Positions = Player1[i]->getPositions(tablero, Player1[i]->Pos_x, Player1[i]->Pos_y, Player1[i]->Pasos, cursor_x, cursor_y, '0', Player2);
                Player1[i]->pos_vector = 0;
                Player1[i]->Draw_Arrow(Player1[i]->Positions, scr_off_x, scr_off_y, screen);
                Player1[i]->Visited_red.clear();
                Player1[i]->Visited_blue.clear();
            }
        }
        for(int i = 0; i < Player2.size(); i++)
        {
            if(Player2[i]->moving)
            {
                Player2[i]->it_type = 2;
                Player2[i]->logic1(screen, tablero, Player2[i]->Pos_x, Player2[i]->Pos_y, Player2[i]->Pasos, '0', scr_off_x, scr_off_y, Player1);
                Player2[i]->logic2(screen, tablero, Player2[i]->Pos_x, Player2[i]->Pos_y, Player2[i]->Pasos, '0', scr_off_x, scr_off_y, Player1);
                Player2[i]->Positions.clear();
                Player2[i]->Positions = Player2[i]->getPositions(tablero, Player2[i]->Pos_x, Player2[i]->Pos_y, Player2[i]->Pasos, cursor_x, cursor_y, '0', Player1);
                Player2[i]->pos_vector = 0;
                Player2[i]->Draw_Arrow(Player2[i]->Positions, scr_off_x, scr_off_y, screen);
                Player2[i]->Visited_red.clear();
                Player2[i]->Visited_blue.clear();
            }
        }
        for(int i = 0; i < Player1.size(); i++)
        {
            if(!Player1[i]->moving)
            {
                if(cursor_x == Player1[i]->Pos_x && cursor_y == Player1[i]->Pos_y)
                {
                    for(int i = 0; i < Player2.size(); i++)
                    {
                        if(Player2[i]->moving)
                        {
                            goto CONT;
                        }
                    }
                    for(int i = 0; i < Player1.size(); i++)
                    {
                        if(Player1[i]->moving)
                        {
                            goto CONT;
                        }
                    }
                    if(turn%2!=0)
                        goto CONT;
                    Player1[i]->it_type = 1;
                    CONT:;
                }else
                    Player1[i]->it_type = 0;
                if(Player1[i]->has_moved)
                    Player1[i]->it_type=6;

            }
            if(Player1[i]->currently_moving)
            {
                Player1[i]->get_to_goal2(Player1[i]->Positions,Player2, scr_off_x, scr_off_y, screen);
                goto AFTERDRAW;
            }
            Player1[i]->dibujar(screen, scr_off_x, scr_off_y);
            AFTERDRAW:;
        }
        for(int i = 0; i < Player2.size(); i++)
        {
            if(!Player2[i]->moving)
            {
                if((cursor_x == Player2[i]->Pos_x && cursor_y == Player2[i]->Pos_y) && !Player2[i]->moving)
                {
                    for(int i = 0; i < Player2.size(); i++)
                    {
                        if(Player2[i]->moving)
                        {
                            goto CONT2;
                        }
                    }
                    for(int i = 0; i < Player1.size(); i++)
                    {
                        if(Player1[i]->moving)
                        {
                            goto CONT2;
                        }
                    }
                    if(turn%2==0)
                        goto CONT2;
                    Player2[i]->it_type = 1;
                    CONT2:;
                }else
                    Player2[i]->it_type = 0;
                if(Player2[i]->has_moved)
                    Player2[i]->it_type=6;
            }
            if(Player2[i]->currently_moving)
            {
                Player2[i]->get_to_goal2(Player2[i]->Positions,Player1, scr_off_x, scr_off_y, screen);
                goto AFTERDRAW2;
            }
            Player2[i]->dibujar(screen, scr_off_x, scr_off_y);
            AFTERDRAW2:;
        }

        for(int i = 0; i < Player1.size(); i++)
        {
            if(Player1[i]->HP <= 0)
            {
                Player1.erase(Player1.begin() + i);
            }
        }
        for(int i = 0; i < Player2.size(); i++)
        {
            if(Player2[i]->HP <= 0)
            {
                Player2.erase(Player2.begin() + i);
            }
        }
        int move_tot = 0;
        if(turn %2 == 0)
        {
            for(int i = 0; i < Player1.size(); i++)
            {
                if(Player1[i]->has_moved)
                {
                    move_tot++;
                }
                if(move_tot==Player1.size())
                {
                    for(int o = 0; o < Player1.size(); o++)
                    {
                        Player1[o]->has_moved = false;
                    }
                    turn++;
                    Mix_PlayChannel( -1, next_turn_sound, 0 );
                }
            }
        }else
        {
            for(int i = 0; i < Player2.size(); i++)
            {
                if(Player2[i]->has_moved)
                {
                    move_tot++;
                }
                if(move_tot==Player2.size())
                {
                    for(int o = 0; o < Player2.size(); o++)
                    {
                        Player2[o]->has_moved = false;
                    }
                    turn++;
                    Mix_PlayChannel( -1, next_turn_sound, 0 );
                }
            }
        }
        apply_surface((cursor_x-scr_off_x)*64, (cursor_y-scr_off_y)*64, cursor_cube, screen);
        if(game_over)
        {
            string ganado;
            if(Player1.size() == 0)
            {
                ganado = "Player 2 has won!";
            }else
            {
                ganado = "Player 1 has won!";
            }
            game_end = TTF_RenderText_Solid(font, ganado.c_str(), textColor);
            int iteracion_final = 0;
            while(quit == false)
            {
                if( SDL_PollEvent( &event ) )
                {

                }
                apply_surface((960/2)-150, (640/2)-20, game_end, screen);
                if( SDL_Flip( screen ) == -1 )
                {
                    return 1;
                }
                iteracion_final++;
                if(iteracion_final > 2000)
                    quit = true;
            }
        }
        if(Player1.size() == 0 || Player2.size() == 0)
        {
            game_over = true;
        }
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        frame++;

        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
    clean_up();

    return 0;
}
