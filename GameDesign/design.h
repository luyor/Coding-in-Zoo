#ifndef DESIGN_H
#define DESIGN_H
#define N_ENEMY 1000
class Game;

class Design
{
public:
    Design();
    //NewEnemy is used to register new enemy in game engine, using game.EnemyRegister()
    //background_position started with 0
    void NewEnemy(Game& game, double backgrond_position);
    void Reset();//reset level
private:
    int Current
    struct MeetingPoint{
        int EmemyType;
        double OccurPosition;
    };
    struct MeetingPoint EnemyLists[N_ENEMY];
};

void Design::NewEnemy(Game &game, double backgrond_position)
{

}

#endif // DESIGN_H
