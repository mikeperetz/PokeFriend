#ifndef DECISIONTREE_H
#define DECISIONTREE_H

#include <cstdint>
#include <vector>
#include "scene.h"
#include <limits>
#include <iostream>


class DecisionTree
{
public:

    struct Node{
    public:

        Node(Scene currScene);

        int score;
        //int side; //1 if player, -1 if opp
        std::vector< Node > children;
        Node();

        //int alpha;
        //int beta;


       // Scene currScene;

        Scene scene() const;



    private:
        Scene scene_;

        // std::vector < Scores > child_scores;

    };


    Node root;

    Node bestMove;


    int evaluate(Scene  currScene);
    int negamax(Node node, int depth, int alpha, int beta, int side);
    void buildTree(Scene rootScene, int depth);
    Scene genMove(Scene currScene, int move, int side);

    DecisionTree(Node rootNode);

    DecisionTree();
};

#endif // DECISIONTREE_H
