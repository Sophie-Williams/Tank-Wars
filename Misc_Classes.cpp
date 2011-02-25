#include <iostream>
#include "Misc_Classes.h"

using namespace std;

Direction::Direction()
{
     // By default goes up
     this->get_from_integer (0);
}

void Direction::print ()
{
     cout << "Direction : " << xdir << " " << ydir << endl;
}

void Direction::get_from_integer (int inp)
{
     switch (inp){
     case 0:
          this->xdir = -1;
          this->ydir = 0;
          break;
     case 1:
          this->xdir = 1;
          this->ydir = 0;
          break;
     case 2:
          this->xdir = 0;
          this->ydir = 1;
          break;
     case 3:
          this->xdir = 0;
          this->ydir = -1;
          break;
     }
     
}

Move::Move() 
{
     this->shoot = false;
}

void Move::interpret_move (int user_move)
{
     if (user_move / 4 == 1)
          this->shoot = true;
     else
          this->shoot = false;
     this->dirn.get_from_integer (user_move % 4);
}

void Move::print() 
{
     cout << "Shoot " << boolalpha << shoot << endl;
     this->dirn.print();
}

Position::Position ()
{
     x = y = 0;
}

Position::Position (int x, int y)
{
     this->x = x;
     this->y = y;
}

void Position::go_in_direction (Direction d)
{
     x += d.xdir;
     y += d.ydir;
}

bool Position::operator== (Position p)
{
     return ((this->x == p.x) && (this->y == p.y));
}

void Position::print ()
{
     cout << "Position : " << x << " " << y << endl;
}

Position Position::operator = (Position pos)
{
     this->x = pos.x;
     this->y = pos.y;
     return *this;
}

Move Move::operator = (Move mov)
{
     this->shoot = mov.shoot;
     this->dirn = mov.dirn;
     return *this;
}

Direction Direction::operator = (Direction dir)
{
     this->xdir = dir.xdir;
     this->ydir = dir.ydir;
     return *this;
}
