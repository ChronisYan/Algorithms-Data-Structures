#include <iostream>
#include <vector>

class Game
{
public:
    Game(int n_cubes)
    {
        FIELDS = 3;
        n_moves = 0;
        _n_cubes = n_cubes;
        for (int i = 0; i < FIELDS; i++)
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
        for (int i = 0; i < game.FIELDS; i++)
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
        move(0, _n_cubes - 1, board[0], board[2], board[1]);
    }

    int n_moves;

private:
    int _n_cubes;
    int FIELDS;
    std::vector<std::vector<int>> board;
    void move(unsigned start, unsigned end, std::vector<int> &source, std::vector<int> &target, std::vector<int> &spare)
    {
        n_moves++;

        if (start == end)
        {
            target.push_back(source.back());
            source.pop_back();
        }
        else
        {
            move(start + 1, end, source, spare, target);
            move(start, start, source, target, spare);
            move(start + 1, end, spare, target, source);
        }
    }
};

int main()
{
    Game newGame(2);
    std::cout << newGame;
    std::cout << "---Solution---" << std::endl;
    newGame.solve();
    std::cout << newGame;
    std::cout << "Number of moves: " << newGame.n_moves << std::endl;
    return 0;
}