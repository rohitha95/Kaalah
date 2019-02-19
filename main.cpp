//Driver function

#include <iostream>
#include "Game.h"
#include "algorithms.h"
#include <chrono>
#include <cstdlib>
#include<ctime>

using namespace std;
using namespace std::chrono;
int nodes=0;
int computer_move(Game g) {
    algorithms a;
    int v=a.alphaBetaSearch(g);
    nodes+=a.node_count();
	//return a.initialize(arr,player_no);
	return v;

}
int computer_move1(Game g) {
    algorithms a;
    int v=a.initialize(g.board,g.player);
    nodes+=a.node_count();


	return v;
	//return a.alphaBetaSearch(g);

}




int main()
{
    int gs, pit;

    cout<<"***********Welcome to  Mancala Game!***********"<<endl<<endl;
    Game g;
    g.start();
    g.display();
    int user, comp;

    cout<<endl<<endl;
    cout<<"First line is Player 2, Second line is Player 1"<<endl;
    cout<<"*********MENU********"<<endl;
    cout<<"1. MINMAX VS MINMAX"<<endl;
    cout<<"2. alpha beta vs alpha beta"<<endl;
    cout<<"3. minmax vs alpha beta"<<endl;
    int ch;
    cout<<"Which option want to start first (input 1 or 2) :";
    cin>>ch;
    g.player=1;
    int rounds=0;
    if (ch==1){
            auto start = high_resolution_clock::now();
         while(rounds<50) {
        if (g.is_game_ends()){
            cout<<" Player "<<g.player<<" don't have any legal moves"<<endl;
            cout<<" collecting stones to the stores......."<<endl;
            cout<<" Player "<<g.who_wins()<<" wins the game!"<<endl;
            break;
        }
        if (g.player==1) {
            //cout<<" Turn for player "<<g.player<<endl;
           // cout<<" pick the pit number (1-6) :";
           // cin>>g.pit;
           cout<<" Turn for player 1 "<<endl;
            g.pit=computer_move1(g);
            cout<<" player 1 choses pit "<<g.pit<<endl;
        }else {
            cout<<" Turn for player 2 "<<endl;
            g.pit=computer_move1(g);
            cout<<" player 2 choses pit "<<g.pit<<endl;
        }
        g.make_move();
        g.display();
        g.player_turn();
        rounds++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Total Node Count:"<<nodes<<endl;
    cout<<"Length of the game path"<< 2 * rounds<<endl;
    nodes=0;


    }

    if (ch==2){
        auto start = high_resolution_clock::now();
         while(rounds<50) {
        if (g.is_game_ends()){
            cout<<" Player "<<g.player<<" don't have any legal moves"<<endl;
            cout<<" collecting stones to the stores......."<<endl;
            cout<<" Player "<<g.who_wins()<<" wins the game!"<<endl;
            break;
        }
        if (g.player==1) {
            //cout<<" Turn for player "<<g.player<<endl;
           // cout<<" pick the pit number (1-6) :";
           // cin>>g.pit;
           cout<<" Turn for player 1 "<<endl;
            g.pit=computer_move(g);
            cout<<" player 1 choses pit "<<g.pit<<endl;
        }else {
            cout<<" Turn for player 2 "<<endl;
            g.pit=computer_move(g);
            cout<<" player 2 choses pit "<<g.pit<<endl;
        }
        g.make_move();
        g.display();
        g.player_turn();
        rounds++;
    }
        auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Total Node Count:"<<nodes<<endl;
    cout<<"Length of the game path"<< 2 * rounds<<endl;
    nodes=0;

        rounds=0;
    }


    if (ch==3){
            auto start = high_resolution_clock::now();
         while(rounds<50) {
        if (g.is_game_ends()){
            cout<<" Player "<<g.player<<" don't have any legal moves"<<endl;
            cout<<" collecting stones to the stores......."<<endl;
            cout<<" Player "<<g.who_wins()<<" wins the game!"<<endl;
            break;
        }
        if (g.player==1) {
            //cout<<" Turn for player "<<g.player<<endl;
           // cout<<" pick the pit number (1-6) :";
           // cin>>g.pit;
           cout<<" Turn for player 1 "<<endl;
            g.pit=computer_move1(g);
            cout<<" player 1 choses pit "<<g.pit<<endl;
        }else {
            cout<<" Turn for player 2 "<<endl;
            g.pit=computer_move(g);
            cout<<" player 2 choses pit "<<g.pit<<endl;
        }
        g.make_move();
        g.display();
        g.player_turn();
        rounds++;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout<<"Total Node Count:"<<nodes<<endl;
    cout<<"Length of the game path"<< 2 * rounds<<endl;
    nodes=0;
    }

  /*  while(1) {
        if (g.is_game_ends()){
            cout<<" Player "<<g.player<<" don't have any legal moves"<<endl;
            cout<<" collecting stones to the stores......."<<endl;
            cout<<" Player "<<g.who_wins()<<" wins the game!"<<endl;
            break;
        }
        if (g.player==user) {
            cout<<" Turn for player "<<g.player<<endl;
            cout<<" pick the pit number (1-6) :";
            cin>>g.pit;
        }else {
            cout<<" Turn for computer "<<endl;
            g.pit=computer_move(g);
            cout<<" Computer choses pit "<<g.pit<<endl;
        }
        g.make_move();
        g.display();
        g.player_turn();
    }*/
