#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "SDL/SDL_mixer.h"
#include "Position.h"

using namespace std;


class Personaje
{
    public:
        Personaje(string Clase, int Equipo, int Pos_x, int Pos_y);
        string Clase;
        int Equipo, HP, Atk, Def, Pasos, Pos_x, Pos_y, Crit, iteracion, tiempo, it_type, movement_it, pos_vector, moving_x, moving_y;
        TTF_Font *HP_Font;
        SDL_Surface*HP_Message;
        SDL_Color HP_Font_Color = {0, 0, 0, 0};
        bool is_crit, anim_back, moving, currently_moving, has_moved;
        vector<Position*> Visited_red, Visited_blue;
        vector<SDL_Surface*> anim;
        vector<SDL_Surface*> movement;
        vector<SDL_Surface*> attacker;
        vector<SDL_Surface*> arrow;
        vector<Position*> Positions;
        Mix_Chunk* hit_sound, *crit_sound, *kill_sound, *crit_kill_sound, *no_dmg_sound;
        void attack(Personaje* pers);
        void dibujar(SDL_Surface* screen, int offset_x, int offset_y);
        void logic1(SDL_Surface* screen, char table[14][18], int x_actual, int y_actual, int pasos, char direction, int off_x, int off_y, vector<Personaje*> opponent);
        void logic2(SDL_Surface* screen, char table[14][18], int x_actual, int y_actual, int pasos, char direction, int off_x, int off_y, vector<Personaje*> opponent);
        bool get_to_goal(char tablero[14][18], int x_actual, int y_actual, int pasos, int x_goal, int y_goal, vector<Personaje*> opponent);
        void get_to_goal2(vector<Position*> posses,vector<Personaje*>opponent, int offset_x, int offset_y, SDL_Surface* screen);
        vector<Position*> getPositions(char tablero[14][18], int x_actual, int y_actual, int pasos, int x_goal, int y_goal, char direction, vector<Personaje*> opponent);
        void Draw_Arrow(vector<Position*> posses, int offset_x, int offset_y, SDL_Surface*screen);
        virtual ~Personaje();
    protected:
    private:
        void pre_attack();
};

#endif // PERSONAJE_H
