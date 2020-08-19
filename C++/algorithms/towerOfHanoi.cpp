#include <iostream>
#include <vector>

class Game
{
public:
    Game(int fields, int n_cubes)
    {
        _fields = fields;
        _n_cubes = n_cubes;
        for (int i = 0; i < _fields; i++)
        {
            std::vector<int> stack;
            board.push_back(stack);
        }
        for (int i = _n_cubes; i > 0; i--)
        {
            board[0].push_back(i);
        }
    }
    friend std::ostream &operator<<(std::ostream &os, Game &game)
    {
        for (int i = 0; i < game._fields; i++)
        {
            std::cout << "Stack[" << (i + 1) << "] ";
            for (const int &item : game.board[i])
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
        return os;
    }
    void solve()
    {
        
    }

private:
    int _fields;
    int _n_cubes;
    std::vector<std::vector<int>> board;
    bool is_inverted(std::vector<int> stack)
    {
        int j = _n_cubes;
        for (int i = 0; i < _n_cubes; i++)
        {
            if (stack[i] != j)
            {
                return false;
            }
            j--;
        }
        return true;
    }
};

int main()
{
    Game newGame(3, 4);
    std::cout << newGame;
    return 0;
}