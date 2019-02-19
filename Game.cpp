#include "Game.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}




void Game::display(){
    cout<<endl<<endl;
    string s=" ";
    cout<<setw(15)<<right<<"Player 2";
    cout<<setw(5)<<s;
    for (int i=size-1; i>7;i--)
        cout<<setw(5)<<board[i]<<" ";
    cout<<endl<<setw(15)<<right<<"store 2";
    cout<<setw(5)<<right<<board[0]<<setw(40)<<board[7]<<setw(10)<<"store 1"<<endl;

    cout<<setw(20)<<s;
    for (int i=1; i<7;i++)
        cout<<setw(5)<<board[i]<<" ";
    cout<<setw(15)<<right<<"Player 1";
    cout<<endl<<endl;
}

bool Game::is_game_ends(){
    int count=0;
    int n,j;
    if (player==1){
       j=1;
       n=7;
    }else {
        j=8;
        n=size;
    }
    for (int i=j;i<n; i++){
        if(board[i]==0)
            count++;
    }
    if(count==6 )
        return true;
    return false;
}
int Game::who_wins(){
    int store1=board[7], store2=board[0];
    int winner=12;
    for(int i=1;i<7;i++) {
        store1+=board[i];
        board[i]=0;
        store2+=board[i+7];
        board[i+7]=0;
    }
    if (store1==store2)
        cout<<"Both Wins the game"<<endl;
    else if (store1>store2)
        winner=1;
    else
        winner=2;
    return winner;

}

void Game::start(){
    for (int i=0;i<size;i++){
        if (i==0 || i==7)
            board[i]=0;
        else
            board[i]=6;
    }
}

void Game::Adjust_pit_value(){
 if (player==2)
        pit=size-pit;

 }

int Game::get_stones(){

    return board[pit];
}

bool Game::opponent_store(){
    if ((player==1 && pit ==0) || (player==2 && pit==7))
        return true;
    return false;
}

void Game::validate_pit(){
   if (player==2) {
    while ( pit<=0 || pit>=7 ){
        cout<<"not a valid pit. Pick another pit (1-6):";
        cin>>pit;

    }
     Adjust_pit_value();
     while (get_stones()==0) {
        cout<<" No stones in the pit, pick another pit (1-6) :";
        cin>>pit;
     }
}
      	else if (player==1) {
		if (get_stones()==0) {
			pit++;

		}

}

}

void Game::player_turn(){
    if(player==1 && extra_move==false)
        player=2;
    else if(player==2 && extra_move==false)
        player=1;
}

void Game::capture_across(int pos) {

        if(player==1 && pos>0 && pos<7 && board[pos]==1) {
            board[7]+=1+board[size-pos];
            board[size-pos]=0;
            board[pos]=0;
            extra_move=true;
        }
        else if (player==2 && pos>7 && pos<size && board[pos]==1) {

            board[0]+=1+board[size-pos];
            board[size-pos]=0;
            board[pos]=0;
            extra_move=true;
        }
        else
            extra_move=false;
    }



void Game::make_move() {
   // validate_pit();
    Adjust_pit_value();
    int stones=get_stones();
    board[pit]=0;


    while(stones!=0){

        pit++;
        if ( pit == size)
            pit=0;
        //cout<<"pit value "<<pit<<endl;
        if (opponent_store())
            pit++;

        board[pit]+=1;
        if(stones==1)
            capture_across(pit);
        stones--;
            //display();
            //cout<<"stones "<<stones<<endl;


    }


}
