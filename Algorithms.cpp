#include "algorithms.h"
#include<vector>
#include "Game.h"
#include<iostream>

using namespace std;

algorithms::algorithms()
{
    //ctor
}

algorithms::~algorithms()
{
    //dtor
}

vector<Game> algorithms::move_generator(int arr[], int player_no) {
    Game computer[6];
    vector<Game> list;
   // cout<<"test"<<endl;

    int k;
    int store[6];
    if (player_no==1){
        k=1;
       // i=0;
    }else if(player_no==2){
        k=13;
       // i=;
    }
   int i=0;

    while ( i<6 ){
            for (int j=0;j<14;j++)
                computer[i].board[j]=arr[j];
            computer[i].player=player_no;
            computer[i].pit=i+1;
	   // cout<<"test for player"<<player_no<<endl;
            if(computer[i].board[k]==0){
                store[i]=-100;
            }else{
                computer[i].make_move();
	/*	do {
			computer[i].make_move();
			computer[i].player_turn();
			cout<<"player::: "<<computer[i].player<<endl;
		}while(computer[i].player==player_no);*/
                store[i]=computer[i].board[7]-computer[i].board[0];
		computer[i].pit=i+1;
	//	cout<<"i value: "<<i<<endl<<endl;
		//computer[i].display();
                list.push_back(computer[i]);

            }
            //cout<<" Evaluated value at pit "<<i+1<<" : "<<store[i]<<endl;
	  i++;
	if (player_no==2)
		k--;
	else
		k++;
    }
    //cout<<"tested"<<endl;
    return list;


}

int algorithms::initialize(int b[],int p) {
	result r;

        r=minimaxAB(b,0,p,100,-100);



	return r.path;
}
// Evaluation function 1
int algorithms::static_evaluation_function(int arr[], int player) {
    int value;
    if (player==1)
        value=arr[7]-arr[0];
    else if (player==2)
        value=arr[0]-arr[7];
    return value;


}

// Evaluation function2

int algorithms::evaluation_function2(Game g,int player){


    int val;
    if (player==1)
        val=(g.board[0]+2)/g.board[7];
    if (player==2)
        val=(g.board[7]+2)/g.board[0];

    //cout<<val<<endl;
    return val;


}

int algorithms::evaluation_function21(int g[],int player){
    int val;
    if (player==1)
        val=g[0]+2/g[7]+2;
    if (player==2)
        val=g[7]+2/g[0]+2;

    //cout<<val<<endl;
    return val;


}
bool algorithms::deep_enough(int arr[], int depth) {
    if (depth>=cut_off_depth)
        return true;
    return false;
}
int algorithms::opposite(int player) {
	if(player==1)
		return 2;
	return 1;

}
void algorithms::node_count1(int n){
    this->no_of_nodes+=n;
    //cout<<"node: "<<node_count()<<endl;
}
int algorithms::node_count(){
 //cout<<"no of nodes_count "<<this->no_of_nodes<<endl;
int val=no_of_nodes;
//cout<<"node val "<<val<<endl;
return val;
}

algorithms::result algorithms::minimaxAB(int b[],int depth, int player, int use_thresh, int pass_thresh){
	result r,res_succ;
	int new_value,val,bp;
    if (deep_enough(b,depth)){

            r.value=static_evaluation_function(b, player);
            r.path=0;
	    //cout<<" deep enough"<<endl;
            return r;
    }
    else {
        vector<Game> successors=move_generator(b,player);
        if (successors.empty()){
            r.value=static_evaluation_function(b, player);
            r.path=0;
            return r;
        }else {
            //no_of_nodes+=successors.size();
            node_count1(successors.size());
           // cout<<"no of nodes"<<no_of_nodes<<endl;
		for (int i=0; i<successors.size(); i++) {

			 res_succ=minimaxAB(successors[i].board, depth+1, opposite(player), 0-pass_thresh, 0-use_thresh);
			 val=res_succ.value;
			 new_value=0-val;

		//	res_succ.path=successors[i].pit;
			if (new_value > pass_thresh) {
				pass_thresh=new_value;
				bp=successors[i].pit;
			}
			if (pass_thresh>=use_thresh) {

				r.value=pass_thresh;
				r.path=successors[i].pit;
			}
		}
	}
	}
	r.value=pass_thresh;
	r.path=bp;
	return r;

    }


algorithms::result algorithms::minimaxAB1(int b[],int depth, int player, int use_thresh, int pass_thresh){
	result r,res_succ;
	int new_value,val,bp;
    if (deep_enough(b,depth)){

            r.value=static_evaluation_function(b, player);
            r.path=0;
	    //cout<<" deep enough"<<endl;
            return r;
    }
    else {
        vector<Game> successors=move_generator(b,player);
        if (successors.empty()){
            r.value=evaluation_function21(b, player);
            r.path=0;
            return r;
        }else {
            //no_of_nodes+=successors.size();
            node_count1(successors.size());
           // cout<<"no of nodes"<<no_of_nodes<<endl;
		for (int i=0; i<successors.size(); i++) {

			 res_succ=minimaxAB(successors[i].board, depth+1, opposite(player), 0-pass_thresh, 0-use_thresh);
			 val=res_succ.value;
			 new_value=0-val;

		//	res_succ.path=successors[i].pit;
			if (new_value > pass_thresh) {
				pass_thresh=new_value;
				bp=successors[i].pit;
			}
			if (pass_thresh>=use_thresh) {

				r.value=pass_thresh;
				r.path=successors[i].pit;
			}
		}
	}
	}
	r.value=pass_thresh;
	r.path=bp;
	return r;

    }


bool algorithms::deep_enoughS(int d) {
	if (d>=2)
		return true;
	return false;
}
int algorithms::maxVal(Game g, int alpha, int beta) {
	if (deep_enoughS( currDepth))
	{
		//return evaluation_function2(g,g.player);
		return static_evaluation_function(g.board,g.player);
	}
	int v=-1000;
	vector<Game> succ=move_generator(g.board,g.player);
	if (succ.size()==0){

		return -1;
	}else {
		currDepth++;
		 no_of_nodes+=succ.size();
		for (int i=0; i<succ.size(); i++) {
		//	if (depth==1)
		//	{
				int min_val=minVal(succ[i],alpha,beta);
				if (v<min_val)
					v=min_val;
				result r;
				r.value=v;
				r.path=succ[i].pit;

				arrayList.push_back(r);

				if (v<=alpha)
					return v;
				if (beta > v)
					beta=v;
				else{
					if (v<minVal(succ[i],alpha,beta))
						v=minVal(succ[i],alpha,beta);
					if (v>= beta)
						return v;
					if (alpha<v)
						alpha=v;
				}
		//	}
		}

	}
	return v;
}


/* returning min turn best value,
 * alpha is the best already explored value to root for max
 * beta is best already explored value to root for min*/

int algorithms::minVal(Game g, int alpha, int beta) {
	if (deep_enoughS(currDepth)) {
	//	if (depth==1){
			g.player=opposite(g.player);
			result r;
			//r.value=evaluation_function2(g,g.player);
			r.value=static_evaluation_function(g.board,g.player);
			r.path=g.pit;
			arrayList.push_back(r);
	//	}
		//change evaluation function here
		return evaluation_function2(g,g.player);

	}

	int v=1000;
	vector<Game> succ=move_generator(g.board,g.player);
    no_of_nodes+=succ.size();
	if (succ.size()==0)
		return -1;
	else {
		currDepth++;
		for (int i=0;i<succ.size();i++) {
			if (v>maxVal(succ[i],alpha,beta))
				v=maxVal(succ[i],alpha,beta);
			if (v<=alpha)
				return v;
			if (beta > v)
				beta=v;

		}

	}
	return v;
}

//Function to back up the best value at each node and update the board state
int algorithms::getActionBoard(int v) {
	if (v==-1)
		cout<<" integer -1 is returned"<<endl;
	if (arrayList.size()==0)
		cout<<"Array list is blank"<<endl;
	for (int i=0; i<arrayList.size();i++) {
		if (arrayList[i].value==v)
			return arrayList[i].path;

	}
	result max=arrayList[0];
	int maxV=arrayList[0].value;
	for (int i=0; i<arrayList.size();i++) {
		result track;
		track.value=arrayList[i].value;
		track.path=arrayList[i].path;
		if (track.value>maxV){
			max.value=arrayList[i].value;
			max.path=arrayList[i].path;
		}
	}
	return max.path;
}

int algorithms::alphaBetaSearch(Game g) {
	int player=g.player;
	int val=maxVal(g, -1000, 1000);
	currDepth=0;
	int p=getActionBoard(val);
//	arrayList.clear();
	return p;
}



