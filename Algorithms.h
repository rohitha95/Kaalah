ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include<string>
#include "Game.h"
#include<vector>

using namespace std;


class algorithms
{
    public:
        struct result{
            int value;
            int path;
        };
	vector<result> arrayList;
	int currDepth=0;
	int no_of_nodes=0;

        static const int cut_off_depth=1;
        result r;
       // Game list[6];

        algorithms();
        virtual ~algorithms();
        vector<Game> move_generator(int [], int);
        bool deep_enough(int[],int);
        int static_evaluation_function(int[],int);
        result minimaxAB(int[],int,int,int,int);
        result minimaxAB1(int[],int,int,int,int);
	int opposite(int);
	int initialize(int [],int);
	int alphaBetaSearch(Game);
	int getActionBoard(int);
	int minVal(Game,int,int);
	int maxVal(Game, int,int);
	int evaluation_function21(int[],int);
	int evaluation_function2(Game,int);
	bool deep_enoughS(int );
	int node_count();
	void node_count1(int);


    protected:
    private:
};

#endif // ALGORITHMS_H
