#pragma once
#include <string>
#include <iostream>
#include <queue>

//Use map to rows.
namespace ariel {

    template <typename T> class BinaryTree {

        //Use enum to define order
        enum order
        {
            PREORDER,
            INORDER,
            POSTORDER
        };


        struct Node {
            T val;
            Node* right;
            Node* left;
            Node(T node): val(node), right(nullptr), left(nullptr){}
        };

        Node* root;

        class Iterator{

            Node* pointer;
            order o;
            std::queue<Node *> node_queue;

            //put all nodes in queue inorder
            void inorder(Node* root){
                if(root !=nullptr){
                    inorder(root->left);
                    node_queue.push(root);
                    inorder(root->right);
                }
            }
            //put all nodes in queue in postorder
            void postorder(Node* root){
                if(root !=nullptr){
                    postorder(root->left);
                    postorder(root->right);
                    node_queue.push(root);
                }
            }
            //put all nodes in queue in preorder
            void preorder(Node* root){
                if(root !=nullptr){
                    node_queue.push(root);
                    preorder(root->left);
                    preorder(root->right);
                }
            }
            public:
                //Iterator construct
                Iterator(Node* N = nullptr) : pointer(N){}
                //Iterator constructor with order included.
                Iterator(Node* N, order order){
                    pointer = N;
                    o = order;
                    switch(o) {

                        case INORDER:
                            inorder(pointer);
                            node_queue.push(nullptr);
                            pointer = node_queue.front();
                            node_queue.pop();

                        case POSTORDER:
                            postorder(pointer);
                            node_queue.push(nullptr);
                            pointer = node_queue.front();
                            node_queue.pop();

                        case PREORDER:
                            preorder(pointer);
                            node_queue.push(nullptr);
                            pointer = node_queue.front();
                            node_queue.pop();

                    }
                }
                //Create * ability. (read info of pointer)
                T& operator*()const {return pointer->val;}
                //pointer.
                T* operator -> ()const{return &(pointer->val);}
                //Overload  ++ from right.   
                Iterator& operator ++(){
                    
                    return *this;
                    }
                //Overload ++ from left.
                Iterator operator ++(int){
                    if(!node_queue.empty()){
                        pointer = node_queue.front();
                        node_queue.pop();
                    }

                    return *this;
                    }
                //Overload ==
                bool operator == (Iterator const& rhs)const{//return (pointer == rhs.pointer)
                return false;}
                //Overload !=
                bool operator != (Iterator const& rhs)const{//return !(pointer == rhs.pointer)
                return false;}

            

        };
        //find a node with said value
        Node* search(Node *n ,T val){
            //base cases
            if( n ->val == val){
                return n;
            }

            if (n == nullptr) {
                return n;
            } 
            //search right side, if not found search left side.       
            Node *node = search(n->right, val);
            if(node == nullptr) {
                return search(n->left, val);
            }
            return node;
                
    }
        public :
            //Constructor
            BinaryTree(){
                root = nullptr;
            }
            //Destructor
            ~BinaryTree(){
                del_tree(root);
            }
            //del all the tree
            void del_tree(Node* &root){
                if(root != nullptr){
                    del_tree(root->right);
                    del_tree(root->left);
                    delete root;
                    root = nullptr;
                }
            }
            //Shallow Copy
            BinaryTree(BinaryTree &other){
                if (root != nullptr && other.root != nullptr){
                    root = new Node(*other.root);
                }
            }

            BinaryTree& add_root(T other_root){
                if(root != nullptr){
                    root->val = other_root;
                }
                else {
                    root = new Node{other_root};
                }

                return *this;
            }
            BinaryTree& add_left(T father, T new_v){
                Node* node = search(root, father);
                //if node doesn't have a left child, create a the child with the given value.
                if ( node != nullptr){
                    if(node->left == nullptr)
                        node->left = new Node{new_v};
                    else //Else it had a left child already, just change the value
                        node->left->val = new_v;
                }
                else {
                   // throw {"Cannot add value to a none existent node"}
                }
                

                return *this;
            }
            BinaryTree& add_right(T father, T new_v){
                Node* node = search(root, father);
                //if node doesn't have a right child, create a the child with the given value.
                if ( node != nullptr){
                    if(node->right == nullptr)
                        node->right = new Node{new_v};
                    else //Else it had a right child already, just change the value
                        node->right->val = new_v;
                }
                else {
                    //throw {"Cannot add value to a none existent node"}
                }
                return *this;
            }
            Iterator begin(){ return Iterator{root, INORDER};}
            Iterator end(){return Iterator(nullptr);}
            Iterator begin_preorder(){return Iterator{root, PREORDER};}
            Iterator end_preorder(){return Iterator(nullptr);}
            Iterator begin_inorder(){return Iterator{root, INORDER};}
            Iterator end_inorder(){return Iterator(nullptr);}
            Iterator begin_postorder(){return Iterator{root, POSTORDER};}
            Iterator end_postorder(){return Iterator(nullptr);}

            friend std::ostream& operator<<(std::ostream& out, const BinaryTree<T> &bt){
                out<<"hello\n";
                return out;
            }

    };

};