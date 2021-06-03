/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "sources/BinaryTree.hpp"
#include <string>
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("CHECK TREE") {             




//////////////////////////////////////////////////////////////////String tree
BinaryTree<string> tree_of_strings;
CHECK_NOTHROW(tree_of_strings.add_root("1"));     
CHECK_NOTHROW(tree_of_strings.add_left("1", "9"));      // Now 9 is the left child of 1
CHECK_NOTHROW(tree_of_strings.add_left("9", "4"));      // Now 4 is the left child of 9
CHECK_NOTHROW(tree_of_strings.add_right("9", "5"));     // Now 5 is the right child of 9
CHECK_NOTHROW(tree_of_strings.add_right("1", "3"));    // Now 3 is the right child of 1
CHECK_NOTHROW(tree_of_strings.add_left("1", "2"));     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

//Change root
tree_of_strings.add_root("7");
CHECK(*(tree_of_strings.begin()) == "7");

std::string tree_str;
std::string tree_preorder="12453" ;
std::string tree_posteorder="45231" ;
std::string tree_inorder="42513" ;

for(auto n:tree_of_strings){
    tree_str+= n ;
}
//Check normal for each.
CHECK( tree_str == "42513" );
tree_str = "" ;
//Check preorder
for (auto it = tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
        CHECK_NOTHROW(tree_str += (*it));
}
CHECK( tree_preorder == tree_str );
tree_str = "" ;
//Check postorder
for (auto it = tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
        CHECK_NOTHROW(tree_str += (*it));
}
CHECK( tree_preorder == tree_str );
tree_str = "" ;
//Check inorder
for (auto it = tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
        CHECK_NOTHROW(tree_str += (*it));
}
CHECK( tree_preorder == tree_str );


///////////////////////////////////////////////////////////////////Int tree
BinaryTree<int> tree_of_ints;
CHECK_NOTHROW(tree_of_ints.add_root(1));
CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
CHECK_NOTHROW(tree_of_ints.add_left(9, 4)); 
CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
     
//add to none existent node
CHECK_THROWS(tree_of_ints.add_left(6, 2));

//Change root
tree_of_ints.add_root(6);
CHECK(*(tree_of_strings.begin()) == 6);

//Check adding to a tree without a root.
BinaryTree<int> tree_of_ints_no_root;
CHECK_THROWS(tree_of_ints_no_root.add_left(1, 2));
CHECK_THROWS(tree_of_ints_no_root.add_right(1, 3));

//TEST All orders.
std::string tree_int;

for(auto n:tree_of_ints){
    tree_int+= to_string(n) ;
}
//Check normal for each.
CHECK( tree_int == "42513" );
tree_int = "" ;
//Check preorder
for (auto it = tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        CHECK_NOTHROW(tree_int += std::to_string(*it));
}
CHECK( tree_preorder == tree_int );
tree_int = "" ;
//Check postorder
for (auto it = tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        CHECK_NOTHROW(tree_int += to_string(*it));
}
CHECK( tree_posteorder == tree_int );
tree_int = "" ;
//Check inorder
for (auto it = tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        CHECK_NOTHROW(tree_int += to_string(*it));
}
CHECK( tree_inorder == tree_int );




}

