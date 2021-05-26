#pragma once
#include <string>
#include <iostream>

//Use map to rows.
namespace ariel {

    template <typename T> class BinaryTree {

        struct Node {
            T val;
            Node* right;
            Node* left;
            Node(T node): val(node), right(nullptr), left(nullptr){}
        };

        Node* root;

        class Iterator{

            Node* pointer;
            public:
                //Iterator construct
                Iterator(Node* N = nullptr) : pointer(N){}
                //Create * ability. (read info of pointer)
                T& operator*()const {return pointer->val;}
                //pointer.
                T* operator -> ()const{return &(pointer->val);}
                //Overload  ++ from right.
                Iterator& operator ++(){

                    return *this;
                    }
                //Overload ++ from left.
                Iterator operator ++(int){return *this;}
                //Overload ==
                bool operator == (Iterator const& rhs)const{return false;}
                //Overload !=
                bool operator != (Iterator const& rhs)const{return false;}

            

        };
        public :
            
            BinaryTree& add_root(T root){

                return *this;
            }
            BinaryTree& add_left(T right, T left){

                return *this;
            }
            BinaryTree& add_right(T right, T left){

                return *this;
            }
            Iterator begin(){ return Iterator(root);}
            Iterator end(){return Iterator(nullptr);}
            Iterator begin_preorder(){return Iterator(root);}
            Iterator end_preorder(){return Iterator(nullptr);}
            Iterator begin_inorder(){return Iterator(root);}
            Iterator end_inorder(){return Iterator(nullptr);}
            Iterator begin_postorder(){return Iterator(root);}
            Iterator end_postorder(){return Iterator(nullptr);}

            friend std::ostream& operator<<(std::ostream& out, const BinaryTree<T> &bt){
                out<<"hello\n";
                return out;
            }

    };

};