#include "Personaje.h"

Personaje::Personaje(string Clase, int Equipo, int Pos_x, int Pos_y)
{
    this->Clase = Clase;
    this->Equipo = Equipo;
    this->Pos_x = Pos_x;
    this->Pos_y = Pos_y;
    this->is_crit = false;
    this->moving = false;
    this->anim_back = 0;
    this->iteracion = 0;
    this->it_type = 0;
    this->tiempo = 0;
    this->movement_it = 0;
    this->pos_vector = 0;
    this->HP_Font = TTF_OpenFont( "lazy.ttf", 15 );
    this->moving_x = this->Pos_x * 64;
    this->moving_y = this->Pos_y * 64;
    this->currently_moving = false;
    this->has_moved = false;
    this->hit_sound = Mix_LoadWAV("Resources/Sounds/Hit_Normal.wav");
    this->crit_sound = Mix_LoadWAV("Resources/Sounds/Hit_Crit.wav");
    this->kill_sound = Mix_LoadWAV("Resources/Sounds/Kill_Normal.wav");
    this->crit_kill_sound = Mix_LoadWAV("Resources/Sounds/Kill_Crit.wav");
    this->no_dmg_sound = Mix_LoadWAV("Resources/Sounds/No_Dmg.wav");
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Start_Left.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Start_Down.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Start_Right.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Start_Up.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Mid_Vert.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Mid_Hor.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Corner_DL.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Corner_DR.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Corner_UL.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_Corner_UR.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_End_Left.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_End_Down.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_End_Right.png"));
    this->arrow.push_back(IMG_Load("Resources/MoveSprite/Arrow_End_Up.png"));
    this->arrow.push_back(IMG_Load(""));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A1.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A2.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A3.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A4.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A5.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A6.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A7.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A8.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A9.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A10.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A11.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A12.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A13.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A14.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A15.png"));
    this->attacker.push_back(IMG_Load("Resources/MoveSprite/A16.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M1.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M2.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M3.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M4.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M5.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M6.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M7.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M8.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M9.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M10.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M11.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M12.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M13.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M14.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M15.png"));
    this->movement.push_back(IMG_Load("Resources/MoveSprite/M16.png"));
    if(this->Clase == "Lord")
    {
        this->Def=28;
        this->Atk=19;
        this->HP=1;
        this->Crit=17;
        this->Pasos = 5;
        if(this->Equipo == 1)
        {
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L1.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L2.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L3.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L4.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L5.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L6.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L7.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L8.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L9.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L10.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L11.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L12.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L13.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L14.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L15.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L16.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L17.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L18.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L19.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L20.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L21.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L22.png"));
        }else
        {
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L1_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L2_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L3_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L4_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L5_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L6_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L7_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L8_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L9_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L10_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L11_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L12_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L13_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L14_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L15_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L16_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L17_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L18_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L19_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L20_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L21_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L22_.png"));
        }
        this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L23.png"));
        this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L24.png"));
        this->anim.push_back(IMG_Load("Resources/Characters/Great_Lord/L25.png"));
    }else if(this->Clase == "Assassin")
    {
        this->Def=15;
        this->Atk=18;
        this->HP=35;
        this->Crit=35;
        this->Pasos = 6;
    }else if(this->Clase == "Warrior")
    {
        this->Def=22;
        this->Atk=18;
        this->HP=48;
        this->Crit=18;
        this->Pasos = 5;
    }else if(this->Clase == "Berserker")
    {
        this->Def=22;
        this->Atk=17;
        this->HP=50;
        this->Crit=25;
        this->Pasos = 5;
    }else if(this->Clase == "Druid")
    {
        this->Def=15;
        this->Atk=20;
        this->HP=44;
        this->Crit=22;
        this->Pasos = 4;
    }else if(this->Clase == "Knight")
    {
        this->Def=23;
        this->Atk=17;
        this->HP=1;
        this->Crit=16;
        this->Pasos = 7;
        if(this->Equipo == 1)
        {
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K1.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K2.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K3.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K4.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K5.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K6.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K7.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K8.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K9.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K10.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K11.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K12.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K13.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K14.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K15.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K16.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K17.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K18.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K19.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K20.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K21.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K22.png"));
        }else
        {
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K1_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K2_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K3_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K4_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K5_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K6_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K7_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K8_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K9_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K10_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K11_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K12_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K13_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K14_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K15_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K16_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K17_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K18_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K19_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K20_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K21_.png"));
            this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K22_.png"));
        }
        this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K23.png"));
        this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K24.png"));
        this->anim.push_back(IMG_Load("Resources/Characters/Knight_Lord/K25.png"));
    }else if(this->Clase == "Captain")
    {
        this->Def=28;
        this->Atk=16;
        this->HP=45;
        this->Crit=14;
        this->Pasos = 3;
    }else if(this->Clase == "Sage")
    {
        this->Def=20;
        this->Atk=15;
        this->HP=48;
        this->Crit=18;
        this->Pasos = 5;
    }else if(this->Clase == "Paladin")
    {
        this->Def=23;
        this->Atk=17;
        this->HP=47;
        this->Crit=17;
        this->Pasos = 7;
    }else if(this->Clase == "General")
    {
        this->Def=30;
        this->Atk=18;
        this->HP=55;
        this->Crit=15;
        this->Pasos = 3;
    }
}

Personaje::~Personaje()
{
    //dtor
}
void Personaje::attack(Personaje* pers)
{
    int temp_atk;
    if((this->Atk - (pers->Def/2)) <= 0)
    {
        Mix_PlayChannel( -1, no_dmg_sound, 0 );
        is_crit = false;
        return;
    }
    if(is_crit)
    {
        temp_atk= this->Atk * 2;
    }else
    {
        temp_atk = this->Atk;
    }

    int dmg = temp_atk - (pers->Def/2);
    pers->HP -= dmg;
    if(pers->HP > 0)
    {
        if(is_crit)
        {
            Mix_PlayChannel( -1, crit_sound, 0 );
        }else
        {
            Mix_PlayChannel( -1, hit_sound, 0 );
        }
    }else
    {
        if(is_crit)
        {
            Mix_PlayChannel( -1, crit_kill_sound, 0 );
        }else
        {
            Mix_PlayChannel( -1, kill_sound, 0 );
        }
    }
}

void Personaje::pre_attack()
{
    int n = rand()%100;
    if(n <= this->Crit)
    {
        this->is_crit = true;
    }
}

void Personaje::dibujar(SDL_Surface*screen, int offset_x, int offset_y)
{
    SDL_Rect offset;

    offset.x=(this->Pos_x - offset_x)*64;
    offset.y=(this->Pos_y - offset_y)*64;
    if(it_type == 0)
    {
        if(tiempo >= 2 && iteracion == 1)
        {
            if(!anim_back)
                iteracion++;
            else
            {
                iteracion--;
                anim_back = false;
            }
            tiempo = 0;
        }else if(tiempo >= 7 && iteracion == 0)
        {
            iteracion++;
            tiempo = 0;
        }else if(tiempo >= 7 && iteracion == 2)
        {
            iteracion--;
            tiempo = 0;
            anim_back = true;
        }else if(iteracion > 2)
        {
            iteracion = 0;
            tiempo = 0;
        }
    }else if(it_type == 1)
    {
        if(iteracion < 3 || iteracion > 5)
        {
            iteracion = 3;
            tiempo = 0;
        }
        if(tiempo >= 2 && iteracion == 4)
        {
            if(!anim_back)
                iteracion++;
            else
            {
                iteracion--;
                anim_back = false;
            }
            tiempo = 0;
        }else if(tiempo >= 5 && iteracion == 3)
        {
            iteracion++;
            tiempo = 0;
        }else if(tiempo >= 5 && iteracion >= 5)
        {
            iteracion--;
            tiempo = 0;
            anim_back = true;
        }
    }else if(it_type == 2)
    {

        if(tiempo>=2)
        {
            iteracion++;
            tiempo = 0;
        }
        if(iteracion < 6 || iteracion > 9)
        {
            iteracion = 6;
            tiempo = 0;
        }
    }else if(it_type == 6)
    {
        if(tiempo >= 2 && iteracion == 23)
        {
            if(!anim_back)
                iteracion++;
            else
            {
                iteracion--;
                anim_back = false;
            }
            tiempo = 0;
        }else if(tiempo >= 7 && iteracion ==22)
        {
            iteracion++;
            tiempo = 0;
        }else if(tiempo >= 7 && iteracion == 24)
        {
            iteracion--;
            tiempo = 0;
            anim_back = true;
        }else if(iteracion < 22)
        {
            iteracion = 22;
            tiempo = 0;
        }
    }
    tiempo++;
    SDL_BlitSurface(this->anim[iteracion], NULL, screen, &offset);
    stringstream ss;
    ss <<"HP: "<<this->HP;
    this->HP_Message = TTF_RenderText_Solid(HP_Font, ss.str().c_str(), HP_Font_Color);
    SDL_BlitSurface(this->HP_Message, NULL, screen, &offset);
    movement_it++;
    if(movement_it > 15)
    {
        movement_it = 0;
    }
}

void Personaje::logic1(SDL_Surface* screen, char table[14][18], int x_actual, int y_actual, int pasoss, char direction, int off_x, int off_y, vector<Personaje*> opponent)
{
    SDL_Rect offset;
    offset.x=(x_actual-off_x)*64;
    offset.y=(y_actual-off_y)*64;
    if(pasoss<0)
    {
        return;
    }
    if(x_actual>=18
       ||y_actual>=14
       ||x_actual<0
       ||y_actual<0)
        return;
    //Mountains
    if(table[y_actual][x_actual] == 'm' || table[y_actual][x_actual] == 'n')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            return;
        else
            pasoss -= 5;
    }
    //Mountains
    if(table[y_actual][x_actual] == 'q' || table[y_actual][x_actual] == 'w' || table[y_actual][x_actual] == 'e' ||
       table[y_actual][x_actual] == 'r' || table[y_actual][x_actual] == 't' || table[y_actual][x_actual] == 'y' ||
       table[y_actual][x_actual] == 'u' || table[y_actual][x_actual] == 'i' || table[y_actual][x_actual] == 'o' ||
       table[y_actual][x_actual] == 'p' || table[y_actual][x_actual] == 'a' || table[y_actual][x_actual] == 's' ||
       table[y_actual][x_actual] == '1')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            return;
        else
            pasoss -= 3;
    }
    //House/Fort/Forest
    if(table[y_actual][x_actual] == 'x' || table[y_actual][x_actual] == 'f' ||
       table[y_actual][x_actual] == 'k' || table[y_actual][x_actual] == 'l' ||
       table[y_actual][x_actual] == 'z')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            pasoss-=2;
        else
            pasoss --;
    }
    for(int i = 0; i < opponent.size(); i++)
    {
        if(opponent[i]->Pos_x == x_actual && opponent[i]->Pos_y == y_actual)
            return;
    }
    if(table[y_actual][x_actual] == ' ' || table[y_actual][x_actual] == '2' || table[y_actual][x_actual] == '3' ||
       table[y_actual][x_actual] == '4' || table[y_actual][x_actual] == '5' || table[y_actual][x_actual] == '6' ||
       table[y_actual][x_actual] == 'd' || table[y_actual][x_actual] == 'c' || table[y_actual][x_actual] == 'g' ||
       table[y_actual][x_actual] == 'g' || table[y_actual][x_actual] == 'j' || table[y_actual][x_actual] == 'x' ||
       table[y_actual][x_actual] == 'f' || table[y_actual][x_actual] == 'k' || table[y_actual][x_actual] == 'l' ||
       table[y_actual][x_actual] == 'z' || table[y_actual][x_actual] == 'v' || table[y_actual][x_actual] == 'b' ||
       table[y_actual][x_actual] == 'h')
    {
        for(int i = 0; i < Visited_blue.size(); i++)
        {
            if(Visited_blue[i]->pos_x == x_actual && Visited_blue[i]->pos_y == y_actual)
                goto AFTERWARDS;
        }
        SDL_BlitSurface(this->movement[movement_it], NULL, screen, &offset);
        Visited_blue.push_back(new Position(x_actual, y_actual));
        AFTERWARDS:;
    }

    pasoss--;
    if(direction != 'r')
        logic1(screen, table, x_actual+1, y_actual, pasoss, 'l', off_x, off_y, opponent);
    if(direction != 'l')
        logic1(screen, table, x_actual-1, y_actual, pasoss, 'r', off_x, off_y, opponent);
    if(direction != 'u')
        logic1(screen, table, x_actual, y_actual+1, pasoss, 'd', off_x, off_y, opponent);
    if(direction != 'd')
        logic1(screen, table, x_actual, y_actual-1, pasoss, 'u', off_x, off_y, opponent);
}

void Personaje::logic2(SDL_Surface* screen, char table[14][18], int x_actual, int y_actual, int pasoss, char direction, int off_x, int off_y, vector<Personaje*> opponent)
{
    SDL_Rect offset;
    offset.x=(x_actual-off_x)*64;
    offset.y=(y_actual-off_y)*64;
    if(pasoss<0)
    {
        for(int i = 0; i < Visited_red.size(); i++)
        {
            if(Visited_red[i]->pos_x == x_actual && Visited_red[i]->pos_y == y_actual)
                return;
        }
        for(int i = 0; i < Visited_blue.size(); i++)
        {
            if(Visited_blue[i]->pos_x == x_actual && Visited_blue[i]->pos_y == y_actual)
                return;
        }
        SDL_BlitSurface(this->attacker[movement_it], NULL, screen, &offset);
        Visited_red.push_back(new Position(x_actual, y_actual));
        return;
    }
    if(x_actual>=18
       ||y_actual>=14
       ||x_actual<0
       ||y_actual<0)
        return;
    if(table[y_actual][x_actual] == 'm' || table[y_actual][x_actual] == 'n')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
        {
            for(int i = 0; i < Visited_red.size(); i++)
            {
                if(Visited_red[i]->pos_x == x_actual && Visited_red[i]->pos_y == y_actual)
                    return;
            }
            for(int i = 0; i < Visited_blue.size(); i++)
            {
                if(Visited_blue[i]->pos_x == x_actual && Visited_blue[i]->pos_y == y_actual)
                    return;
            }
            SDL_BlitSurface(this->attacker[movement_it], NULL, screen, &offset);
            Visited_red.push_back(new Position(x_actual, y_actual));
            return;
        }
        else
            pasoss -= 5;
    }
    //Rivers
    if(table[y_actual][x_actual] == 'q' || table[y_actual][x_actual] == 'w' || table[y_actual][x_actual] == 'e' ||
       table[y_actual][x_actual] == 'r' || table[y_actual][x_actual] == 't' || table[y_actual][x_actual] == 'y' ||
       table[y_actual][x_actual] == 'u' || table[y_actual][x_actual] == 'i' || table[y_actual][x_actual] == 'o' ||
       table[y_actual][x_actual] == 'p' || table[y_actual][x_actual] == 'a' || table[y_actual][x_actual] == 's' ||
       table[y_actual][x_actual] == '1')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
        {
            for(int i = 0; i < Visited_red.size(); i++)
            {
                if(Visited_red[i]->pos_x == x_actual && Visited_red[i]->pos_y == y_actual)
                    return;
            }
            for(int i = 0; i < Visited_blue.size(); i++)
            {
                if(Visited_blue[i]->pos_x == x_actual && Visited_blue[i]->pos_y == y_actual)
                    return;
            }
            SDL_BlitSurface(this->attacker[movement_it], NULL, screen, &offset);
            Visited_red.push_back(new Position(x_actual, y_actual));
            return;
        }
        else
            pasoss -= 3;
    }
    //House/Fort/Forest
    if(table[y_actual][x_actual] == 'x' || table[y_actual][x_actual] == 'f' ||
       table[y_actual][x_actual] == 'k' || table[y_actual][x_actual] == 'l' ||
       table[y_actual][x_actual] == 'z')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            pasoss-=2;
        else
            pasoss --;
    }
    for(int i = 0; i < opponent.size(); i++)
    {
        if(opponent[i]->Pos_x == x_actual && opponent[i]->Pos_y == y_actual)
        {
            for(int i = 0; i < Visited_red.size(); i++)
            {
                if(Visited_red[i]->pos_x == x_actual && Visited_red[i]->pos_y == y_actual)
                    return;
            }
            for(int i = 0; i < Visited_blue.size(); i++)
            {
                if(Visited_blue[i]->pos_x == x_actual && Visited_blue[i]->pos_y == y_actual)
                    return;
            }
            SDL_BlitSurface(this->attacker[movement_it], NULL, screen, &offset);
            Visited_red.push_back(new Position(x_actual, y_actual));
            return;
        }
    }
    pasoss--;
    if(direction != 'r')
        logic2(screen, table, x_actual+1, y_actual, pasoss, 'l', off_x, off_y, opponent);
    if(direction != 'l')
        logic2(screen, table, x_actual-1, y_actual, pasoss, 'r', off_x, off_y, opponent);
    if(direction != 'u')
        logic2(screen, table, x_actual, y_actual+1, pasoss, 'd', off_x, off_y, opponent);
    if(direction != 'd')
        logic2(screen, table, x_actual, y_actual-1, pasoss, 'u', off_x, off_y, opponent);
}

bool Personaje::get_to_goal(char tablero[14][18], int x_actual, int y_actual, int pasoss, int x_goal, int y_goal, vector<Personaje*> opponent)
{
    if(pasoss<0)
        return false;
    if(x_actual>=18
       ||y_actual>=14
       ||x_actual<0
       ||y_actual<0)
        return false;
    //Mountains
    if(tablero[y_actual][x_actual] == 'm' || tablero[y_actual][x_actual] == 'n')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            return false;
        else
            pasoss -= 5;
    }
    //Rivers
    if(tablero[y_actual][x_actual] == 'q' || tablero[y_actual][x_actual] == 'w' || tablero[y_actual][x_actual] == 'e' ||
       tablero[y_actual][x_actual] == 'r' || tablero[y_actual][x_actual] == 't' || tablero[y_actual][x_actual] == 'y' ||
       tablero[y_actual][x_actual] == 'u' || tablero[y_actual][x_actual] == 'i' || tablero[y_actual][x_actual] == 'o' ||
       tablero[y_actual][x_actual] == 'p' || tablero[y_actual][x_actual] == 'a' || tablero[y_actual][x_actual] == 's' ||
       tablero[y_actual][x_actual] == '1')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            return false;
        else
            pasoss -= 3;
    }
    //House/Fort/Forest
    if(tablero[y_actual][x_actual] == 'x' || tablero[y_actual][x_actual] == 'f' ||
       tablero[y_actual][x_actual] == 'k' || tablero[y_actual][x_actual] == 'l' ||
       tablero[y_actual][x_actual] == 'z')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            pasoss-=2;
        else
            pasoss --;
    }
    for(int i = 0; i < opponent.size(); i++)
    {
        if(opponent[i]->Pos_x == x_actual && opponent[i]->Pos_y == y_actual)
            return false;
    }
    if(y_actual == y_goal && x_actual == x_goal)
        return true;
    pasoss--;
    return get_to_goal(tablero, x_actual+1, y_actual, pasoss, x_goal, y_goal, opponent)
            ||get_to_goal(tablero, x_actual-1, y_actual, pasoss, x_goal, y_goal, opponent)
            ||get_to_goal(tablero, x_actual, y_actual+1, pasoss, x_goal, y_goal, opponent)
            ||get_to_goal(tablero, x_actual, y_actual-1, pasoss, x_goal, y_goal, opponent);
}

void Personaje::get_to_goal2(vector<Position*> posses,vector<Personaje*>opponent, int offset_x, int offset_y, SDL_Surface* screen)
{
    SDL_Rect offset;
    if(pos_vector >= 0)
    {
        if((posses[pos_vector]->pos_x*64) > (this->moving_x))
        {
            this->moving_x+=8;
            it_type = 3;
        }
        if((posses[pos_vector]->pos_x*64) < (this->moving_x))
        {
            this->moving_x-=8;
            it_type = 4;
        }
        if((posses[pos_vector]->pos_y*64) > (this->moving_y))
        {
            this->moving_y+=8;
            it_type = 2;
        }
        if((posses[pos_vector]->pos_y*64) < (this->moving_y))
        {
            this->moving_y-=8;
            it_type = 5;
        }
        if(((posses[pos_vector]->pos_y*64) == (this->moving_y))&&((posses[pos_vector]->pos_x*64) == (this->moving_x)))
        {
            this->Pos_x = this->moving_x/64;
            this->Pos_y = this->moving_y/64;
            pos_vector--;
        }
    }else
    {
        pos_vector = 0;
        pre_attack();
        for(int i = 0; i < opponent.size(); i++)
        {
            if((opponent[i]->Pos_x == posses[pos_vector]->pos_x+1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x-1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x && opponent[i]->Pos_y == posses[pos_vector]->pos_y+1) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x && opponent[i]->Pos_y == posses[pos_vector]->pos_y-1) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x-1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y-1) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x-1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y+1) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x+1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y-1) ||
               (opponent[i]->Pos_x == posses[pos_vector]->pos_x+1 && opponent[i]->Pos_y == posses[pos_vector]->pos_y+1))
            {
                attack(opponent[i]);
            }
        }
        currently_moving = false;
        moving = false;
        has_moved = true;
        is_crit = false;
    }
    offset.x = moving_x - (offset_x*64);
    offset.y = moving_y - (offset_y*64);
    if(it_type == 2)
    {

        if(tiempo>=2)
        {
            iteracion++;
            tiempo = 0;
        }
        if(iteracion < 6 || iteracion > 9)
        {
            iteracion = 6;
            tiempo = 0;
        }
    }else if(it_type == 3)
    {

        if(tiempo>=2)
        {
            iteracion++;
            tiempo = 0;
        }
        if(iteracion < 10 || iteracion > 13)
        {
            iteracion = 10;
            tiempo = 0;
        }
    }else if(it_type == 4)
    {

        if(tiempo>=2)
        {
            iteracion++;
            tiempo = 0;
        }
        if(iteracion < 14 || iteracion > 17)
        {
            iteracion = 14;
            tiempo = 0;
        }
    }else if(it_type == 5)
    {

        if(tiempo>=2)
        {
            iteracion++;
            tiempo = 0;
        }
        if(iteracion < 18 || iteracion > 21)
        {
            iteracion = 18;
            tiempo = 0;
        }
    }
    tiempo++;
    SDL_BlitSurface(this->anim[iteracion], NULL, screen, &offset);
}

void Personaje::Draw_Arrow(vector<Position*> posses, int offset_x, int offset_y, SDL_Surface*screen)
{
    SDL_Rect offset;
    int arrow_sprite = 14;
    if(posses[0] == NULL || posses.size() <= 1)
    {
        return;
    }

    while(pos_vector < Positions.size())
    {
        if(pos_vector == Positions.size()-1)
        {
            if(posses[pos_vector]->pos_x > posses[pos_vector-1]->pos_x)
            {
                arrow_sprite = 0;
            }
            else if(posses[pos_vector]->pos_x < posses[pos_vector-1]->pos_x)
            {
                arrow_sprite = 2;
            }
            else if(posses[pos_vector]->pos_y < posses[pos_vector-1]->pos_y)
            {
                arrow_sprite = 1;
            }
            else if(posses[pos_vector]->pos_y > posses[pos_vector-1]->pos_y)
            {
                arrow_sprite = 3;
            }
        }
        if(pos_vector == 0)
        {
            if(posses[pos_vector]->pos_x < posses[pos_vector+1]->pos_x)
            {
                arrow_sprite = 10;
            }
            else if(posses[pos_vector]->pos_x > posses[pos_vector+1]->pos_x)
            {
                arrow_sprite = 12;
            }
            else if(posses[pos_vector]->pos_y > posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 11;
            }
            else if(posses[pos_vector]->pos_y < posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 13;
            }
        }

        if(pos_vector > 0 && pos_vector < posses.size()-1)
        {
            if(posses[pos_vector]->pos_x < posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 5;
            }
            else if(posses[pos_vector]->pos_x > posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 5;
            }
            else if(posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y < posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 4;
            }
            else if(posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y > posses[pos_vector+1]->pos_y)
            {
                arrow_sprite = 4;
            }
            if((posses[pos_vector]->pos_x > posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x == posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y < posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 6;
            }else if((posses[pos_vector]->pos_x > posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x == posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y > posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 8;
            }else if((posses[pos_vector]->pos_x < posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x == posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y < posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 7;
            }else if((posses[pos_vector]->pos_x < posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x == posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y > posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 9;
            } else if((posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y < posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x > posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 6;
            }else if((posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y > posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x > posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 8;
            }else if((posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y < posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x < posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 7;
            }else if((posses[pos_vector]->pos_x == posses[pos_vector+1]->pos_x && posses[pos_vector]->pos_y > posses[pos_vector+1]->pos_y) &&
               (posses[pos_vector]->pos_x < posses[pos_vector-1]->pos_x && posses[pos_vector]->pos_y == posses[pos_vector-1]->pos_y))
            {
                arrow_sprite = 9;
            }
        }
        offset.x = (posses[pos_vector]->pos_x - offset_x)*64;
        offset.y = (posses[pos_vector]->pos_y - offset_y)*64;
        SDL_BlitSurface(this->arrow[arrow_sprite], NULL, screen, &offset);
        pos_vector++;
    }
}
vector<Position*> Personaje::getPositions(char tablero[14][18], int x_actual, int y_actual, int pasoss, int x_goal, int y_goal, char direction, vector<Personaje*> opponent)
{
    vector<Position*> posses;
    if(pasoss<0)
    {
        posses.push_back(NULL);
        return posses;
    }
    if(x_actual>=18
       ||y_actual>=14
       ||x_actual<0
       ||y_actual<0)
       {
           posses.push_back(NULL);
            return posses;
       }
    //Mountains
    if(tablero[y_actual][x_actual] == 'm' || tablero[y_actual][x_actual] == 'n')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
        {
            posses.push_back(NULL);
            return posses;
        }
        else
            pasoss -= 5;
    }
    //Mountains
    if(tablero[y_actual][x_actual] == 'q' || tablero[y_actual][x_actual] == 'w' || tablero[y_actual][x_actual] == 'e' ||
       tablero[y_actual][x_actual] == 'r' || tablero[y_actual][x_actual] == 't' || tablero[y_actual][x_actual] == 'y' ||
       tablero[y_actual][x_actual] == 'u' || tablero[y_actual][x_actual] == 'i' || tablero[y_actual][x_actual] == 'o' ||
       tablero[y_actual][x_actual] == 'p' || tablero[y_actual][x_actual] == 'a' || tablero[y_actual][x_actual] == 's' ||
       tablero[y_actual][x_actual] == '1')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
        {
            posses.push_back(NULL);
            return posses;
        }
        else
            pasoss -= 3;
    }
    //House/Fort/Forest
    if(tablero[y_actual][x_actual] == 'x' || tablero[y_actual][x_actual] == 'f' ||
       tablero[y_actual][x_actual] == 'k' || tablero[y_actual][x_actual] == 'l' ||
       tablero[y_actual][x_actual] == 'z')
    {
        if(this->Clase == "Lord" || this->Clase == "Knight" || this->Clase == "General" || this->Clase == "Captain")
            pasoss-=2;
        else
            pasoss --;
    }
    for(int i = 0; i < opponent.size(); i++)
    {
        if(opponent[i]->Pos_x == x_actual && opponent[i]->Pos_y == y_actual)
        {
            posses.push_back(NULL);
            return posses;
        }
    }
    if(y_actual == y_goal && x_actual == x_goal)
    {
        posses.push_back(new Position(x_actual, y_actual));
        return posses;
    }
    pasoss-=1;
    vector<Position*> p1;
    vector<Position*> p2;
    vector<Position*> p3;
    vector<Position*> p4;
    if(direction != 'r')
        p1 = getPositions(tablero, x_actual+1, y_actual, pasoss, x_goal, y_goal, 'l', opponent);
    else
        p1.push_back(NULL);
    if(direction != 'l')
        p2 = getPositions(tablero, x_actual-1, y_actual, pasoss, x_goal, y_goal, 'r', opponent);
    else
        p2.push_back(NULL);
    if(direction != 'u')
        p3 = getPositions(tablero, x_actual, y_actual-1, pasoss, x_goal, y_goal, 'd', opponent);
    else
        p3.push_back(NULL);
    if(direction != 'd')
        p4 = getPositions(tablero, x_actual, y_actual+1, pasoss, x_goal, y_goal, 'u', opponent);
    else
        p4.push_back(NULL);

    int x1 = 0;
    int x2 = 0;
    vector<vector<Position*> > vecs;
    if(p1[0] != NULL)
    {
        vecs.push_back(p1);
        x2++;
    }
    if(p2[0] != NULL)
    {
        vecs.push_back(p2);
        x2++;
    }
    if(p3[0] != NULL)
    {
        vecs.push_back(p3);
        x2++;
    }
    if(p4[0] != NULL)
    {
        vecs.push_back(p4);
        x2++;
    }
    if(x2 > 1)
    {
        for(int i = 0; i < x2; i++)
        {
            if(vecs[x1].size() < vecs[i].size())
            {

            }else
            {
                x1 = (i);
            }
        }
    }
    if(x2 == 0)
    {
        posses.push_back(NULL);
    }else
    {
        posses = vecs[x1];
        posses.push_back(new Position(x_actual, y_actual));
    }

    return posses;
}
