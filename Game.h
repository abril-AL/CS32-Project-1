#ifndef G_HEADER
#define G_HEADER
int decodeDirection(char dir);
class Mesa;
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nGarks);
    ~Game();

    // Mutators
    void play();

private:
    Mesa* m_mesa;
};
#endif // !GAME_HEADER