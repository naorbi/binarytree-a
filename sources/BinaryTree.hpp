#pragma once
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>

namespace ariel{
    template <class T>

    class BinaryTree{
        struct Node{
            Node* left = nullptr;
            Node* right = nullptr;
            T value; 
            Node(T d) : value(d), left(nullptr), right(nullptr) {}
        };

        Node *root;

        class PostOrderIterator{

        private:
            Node* current_node;

        public:

            T& operator*() const{return current_node->value;}

            T* operator->() const{return &(current_node->value);}

            bool operator==(const PostOrderIterator& iter) const{return current_node == iter.current_node;}

            bool operator!=(const PostOrderIterator& iter) const{return current_node != iter.current_node;}

            PostOrderIterator(Node* ptr = nullptr): current_node(ptr){}

            PostOrderIterator& operator++(){return *this;}

            const PostOrderIterator operator++(int){
                PostOrderIterator temp = *this;
                return temp;
            }            
        }; 

    public:
        BinaryTree<T>(){root = nullptr;}

        BinaryTree<T> add_root(const T &value){return *this;}

        BinaryTree<T> add_left(const T &value, const T &left){return *this;}

        BinaryTree<T> add_right(const T &value, const T &right){return *this;}

        PostOrderIterator begin_preorder(){return PostOrderIterator{root};}

        PostOrderIterator begin_inorder(){return PostOrderIterator{root};}

        PostOrderIterator begin_postorder(){return PostOrderIterator{root};}

        PostOrderIterator begin(){return PostOrderIterator{root};}

        PostOrderIterator end_preorder(){return PostOrderIterator{root};}

        PostOrderIterator end_inorder(){return PostOrderIterator{root};}        

        PostOrderIterator end_postorder(){return PostOrderIterator{root};}

        PostOrderIterator end(){return PostOrderIterator{root};}

        friend std::ostream &operator<<(std::ostream& out, const BinaryTree<T>& binary_tree){
            out << "\n       ROOT     \n      /    \\     \n  LEFT     RIGHT\n  /  \\      /  \\  \n...  ...  ...  ...\n";
            return out;
        }
    }; 
} 
