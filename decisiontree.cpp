#include "decisiontree.h"


#define NUM_MOVES 4;
#define DEPTH 3;

DecisionTree::DecisionTree()
{
    std::cout << "Invalid (empty) call to DecisionTree(params)." << std::endl;
}






int DecisionTree::evaluate(Scene currScene)
{
    //considering 1v1 only atm
    int num_moves = NUM_MOVES;
    if (currScene.isEnd) return INT_MAX;

    int temp_score = 0;

    int max_dmg = 0;

    for ( int i = 0; i < num_moves; i ++){
        int temp_dmg = currScene.currMon.calcDamage(currScene.ocurrMon, i);
        if (temp_dmg > max_dmg)
            max_dmg = temp_dmg;
    }

    int omax_dmg = 0;

    for ( int i = 0; i < num_moves; i ++){
        int otemp_dmg = currScene.ocurrMon.calcDamage(currScene.currMon, i);
        if (otemp_dmg > omax_dmg)
            omax_dmg = otemp_dmg;
    }

    int max_turn_ko = ( currScene.ocurrMon.stats_.curr_hp / max_dmg );
    int omax_turn_ko = ( currScene.currMon.stats_.curr_hp / omax_dmg );

    temp_score += (max_turn_ko - omax_turn_ko); //calculate turn advantage


    if ( currScene.ocurrMon.status.name() == "Sleep" )
        temp_score += 1;
    if ( currScene.currMon.status.name() == "Sleep" )
        temp_score -= 1;

    return temp_score;

}



int DecisionTree::negamax(Node node, int depth, int alpha, int beta, int side)
{
    int num_moves = NUM_MOVES;

    if (depth == 0 || node.scene().isEnd)
        return evaluate(node.scene()) * side;



    for (int i = 0; i < num_moves; i ++)
        node.children.push_back(Node(genMove(node.scene(),i,side)));


    for (int i = 0; i < num_moves; i ++){
        int val = -negamax(node.children[i], depth - 1,-beta, -alpha, -side);
        node.score = std::max ( val, node.score );
        alpha = std::max ( alpha, val );
        if (alpha >= beta)
            break;
    }

    return node.score;
}

Scene DecisionTree::genMove(Scene currScene, int move, int side)
{

    //Scene newScene = currScene;
    return currScene.potentialUpdate(move, side);
}

DecisionTree::DecisionTree(Node rootNode)
{
   root = rootNode;
   Scene rootScene = root.scene();
   int min = INT_MIN;
   int max = INT_MAX;
   int depth = DEPTH;
   negamax( root , depth, min, max, 1  );
   int numMoves = NUM_MOVES;

   Node currBestMove = root.children[0];
   for (int i = 1; i < numMoves; i++ ){
       if (root.children[i].score > currBestMove.score)
           currBestMove = root.children[i];
   }

   bestMove = currBestMove;
}



DecisionTree::Node::Node(Scene currScene)
{
    scene_ = currScene;
    score = INT_MIN;
}

Scene DecisionTree::Node::scene() const
{
    return scene_;
}


DecisionTree::Node::Node()
{

}
