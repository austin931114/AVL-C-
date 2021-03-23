ARGETS = Test_Binary_Search_Tree_Numbers AVL
CC = g++
CCFLAGS = -std=c++11 -g
AVL: main.cpp AVLInterface.h NodeInterface.h AVL.h AVL.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o AVL main.cpp AVL.cpp Node.cpp
Test_Binary_Search_Tree_Numbers: Test_Binary_Search_Tree_Numbers.cpp Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CC) $(CCFLAGS) -o Test_Binary_Search_Tree_Numbers Test_Binary_Search_Tree_Numbers.cpp