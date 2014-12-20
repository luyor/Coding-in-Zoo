#ifndef DESIGN_H
#define DESIGN_H

class Game;

class Design
{
public:
    Design();
    //NewEnemy is used to register new enemy in game engine, using game.EnemyRegister()
    void NewEnemy(Game& game,double backgrond_position);
    void Reset();//reset level
};

#endif // DESIGN_H
