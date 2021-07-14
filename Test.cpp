#include "doctest.h"
#include "sources/BinaryTree.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace ariel;
using namespace std;

TEST_CASE("BT - Int"){

  BinaryTree<int> tree_int;

  CHECK_NOTHROW(tree_int.add_root(1));
  
  CHECK_NOTHROW(tree_int.add_root(2));

  CHECK_NOTHROW(tree_int.add_root(3));

  CHECK_NOTHROW(tree_int.add_left(1, 2));

  CHECK_NOTHROW(tree_int.add_left(1, 9));

  CHECK_NOTHROW(tree_int.add_left(9, 4));

  CHECK_NOTHROW(tree_int.add_right(9, 5));      

  CHECK_NOTHROW(tree_int.add_right(1, 3));

  CHECK_NOTHROW(cout << tree_int << endl);

  int preOrder[] = {1, 2, 4, 5, 3};

  int inOrder[] = {4, 2, 5, 1, 3};

  int postOrder[] = {4, 5, 2, 3, 1};

  int i = 0;
  for (auto it = tree_int.begin_preorder(); it != tree_int.end_preorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_int.begin_inorder(); it != tree_int.end_inorder(); ++it){
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_int.begin_postorder(); it != tree_int.end_postorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}

TEST_CASE("BT - Chars"){

  BinaryTree<char> tree_chars;

  CHECK_NOTHROW(tree_chars.add_root('1'));

  CHECK_NOTHROW(tree_chars.add_root('2'));

  CHECK_NOTHROW(tree_chars.add_root('3'));

  CHECK_NOTHROW(tree_chars.add_left('1', '9'));

  CHECK_NOTHROW(tree_chars.add_left('9', '4'));

  CHECK_NOTHROW(tree_chars.add_left('1', '2')); 

  CHECK_NOTHROW(tree_chars.add_right('9', '5')); 

  CHECK_NOTHROW(tree_chars.add_right('1', '3'));
  
  CHECK_NOTHROW(cout << tree_chars << endl;);

  char preOrder[] = {'1', '2', '4', '5', '3'};

  char inOrder[] = {'4', '2', '5', '1', '3'};

  char postOrder[] = {'4', '5', '2', '3', '1'};

  int i = 0;
  for (auto it = tree_chars.begin_preorder(); it != tree_chars.end_preorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_chars.begin_inorder(); it != tree_chars.end_inorder(); ++it){
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_chars.begin_postorder(); it != tree_chars.end_postorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}

TEST_CASE("BT - String"){

  BinaryTree<string> tree_strings;

  CHECK_NOTHROW(tree_strings.add_root("1"));

  CHECK_NOTHROW(tree_strings.add_root("2"));

  CHECK_NOTHROW(tree_strings.add_root("3"));

  CHECK_NOTHROW(tree_strings.add_left("1", "2")); 

  CHECK_NOTHROW(tree_strings.add_left("1", "9"));

  CHECK_NOTHROW(tree_strings.add_left("9", "4"));

  CHECK_NOTHROW(tree_strings.add_right("9", "5"));

  CHECK_NOTHROW(tree_strings.add_right("1", "3"));

  CHECK_NOTHROW(cout << tree_strings << endl;);

  string preOrder[] = {"1", "2", "4", "5", "3"};
  
  string inOrder[] = {"4", "2", "5", "1", "3"};
  
  string postOrder[] = {"4", "5", "2", "3", "1"};

  int i = 0;
  for (auto it = tree_strings.begin_preorder(); it != tree_strings.end_preorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_strings.begin_inorder(); it != tree_strings.end_inorder(); ++it){
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }
  i = 0;
  for (auto it = tree_strings.begin_postorder(); it != tree_strings.end_postorder(); ++it){
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}
