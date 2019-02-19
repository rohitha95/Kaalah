#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();

        virtual ~Game();
        static const int size=14;
        int board[size];
        int player, pit;
        bool extra_move=false;




        void start();
        void display();
        void make_move();
        int get_stones();
        void validate_pit();
        void Adjust_pit_value();
        bool opponent_store();
        void player_turn();
        bool is_game_ends();
        int who_wins();
        void capture_across(int);
        //int computer_move(int [],int);

    protected:

    private:
};

#endif // GAME_H
