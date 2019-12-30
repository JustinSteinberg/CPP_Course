//BinarySearchTree.cpp
//Author: Justin Steinberg
//Comp15 HW3
//Date: March 1st, 2019
//Implementation of Binary Search Tree
//////////////////////////////////////

/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>

#include "BinarySearchTree.h"

using namespace std;

//Constructor
BinarySearchTree::BinarySearchTree()
{
        root = NULL;
}

//Destructor
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = NULL;   // not really necessary, since the tree is going 
                       // away, but might want to guard against someone
                       // using a pointer after deleting
}

//Input: Pointer to a struct node
//Returns: Nothing
//Does: Deletes nodes in the Tree recursively using post order
// traversal.  
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == NULL){
            return;
        }
       
        post_order_delete(node->left);
        post_order_delete(node->right);
        delete node;
        node = NULL;
        
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator= (const BinarySearchTree &source)
{
       
        if(&source != this){
            if(root != NULL){
                post_order_delete(root);
            } 
            if(source.root == NULL){
                root = NULL;
            }
            else{
                root = pre_order_copy(source.root);
            }
        }
        return *this;
        
}

//Input: A pointer to a struct node
//Returns: A pointer to a struct node
//Does: Copies details from old Node to new Node,
//copies the entire structure
Node *BinarySearchTree::pre_order_copy(Node *node) const
{

        if(node == NULL){
            return NULL;
        } 

        else
        {
            Node *new_node = new Node();
            new_node->data = node->data;
            new_node->count = node->count;
            new_node->left = pre_order_copy(node->left);
            new_node->right = pre_order_copy(node->right);
            return new_node;
        } 

}

//Input: None
//Returns: An integer 
//Does: Invokes the find_min(node) private function
//to return the smallest value (aka key)
int BinarySearchTree::find_min() const
{
        if (root == NULL){
                return INT_MIN;
        }
        return find_min(root)->data;
}

//Input: A pointer to a struct node  
//Returns: Returns a pointer to a struct node
//Does: Recurses through the tree until the node with the 
//smallest value is found
Node *BinarySearchTree::find_min(Node *node) const
{
        if(node->left != NULL){
       	    node = find_min(node->left);
        }
        return node;
}

//Input: None
//Returns: An integer
//Does: Invokes the private find_max(node) function
//if root is not null to return the max value
int BinarySearchTree::find_max() const
{
        if(root == NULL){
            return INT_MAX;
        }
        return find_max(root)->data;
}

//Input: A pointer to a node struct
//Returns: A pointer to a node struct
//Does: Recurses through the tree to find the node 
//with the largest value
Node *BinarySearchTree::find_max(Node *node) const
{
        if(node->right != NULL){
       	    node = find_max(node->right);
        }
        return node;

}

//Input: A integer value
//Returns: A boolean 
//Does: Invokes the private function contains(node, value),
//returns true if the private function is true
bool BinarySearchTree::contains(int value) const
{
        if(root == NULL){
            return false;
        }
        return contains(root, value); 
}

//Input: A pointer to a node struct, an integer value
//Returns: A boolean
//Does: Recurses through the tree to find the max value
bool BinarySearchTree::contains(Node *node, int value) const
{
        bool found = false;
        if(node != NULL && !found){
            if(node->data == value){
                found = true;
            }
            else{
                if(node->data > value){
                    found = contains(node->left,value);
                } 
                else{
                    found = contains(node->right,value);
                }
            }
        }
        return found;
}

//Input: An Integer value
//Returns: nothing
//Does: Invokes that private insert function 
void BinarySearchTree::insert(int value)
{
        insert(root, NULL, value);
}

//Input: A pointer to a struct node, a pointer to a struct node (parent),
//an interger value
//Returns: Nothing
//Does: Recursively goes through tree to find appropriate place to
//insert a node, or increment count if the value is already in the tree 
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{

        if(node == NULL){
             Node *new_node = new Node();
             new_node->left = NULL;
             new_node->right = NULL;
             new_node->data = value;

            if(root == NULL){
                new_node->count = 1;
                root = new_node;
            }
            else{
                new_node->count = 1;
                node = new_node;
            }
  
            if(parent != NULL){

                if(parent->data > value){
                    parent->left = new_node;
                }
                else if(parent->data < value){
                    parent->right = new_node;
                }
            }
        }
        
        else{
            if(node != NULL){
                parent = node; 
                if(node->data == value){
                    node->count = node->count + 1; 
                }
                else{
                    if(node->data > value){
                        insert(node->left, parent, value);
                    }
                    else{
                        insert(node->right, parent, value);
                    }
                }
            }

        }

}

//Input: Integer Value
//Returns: Boolean return type
//Does: Invokes the private remove function
bool BinarySearchTree::remove(int value)
{
        return remove(root, NULL, value);
}

//Input: A pointer to a struct node, pointer to struct node (parent),
//and a integer value
//Returns: A boolean value
//Does: Recursively goes through the tree to find the appropriate
//nodes to remove, checking all possible senarios (uses smallest
//in right subtree)
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if(node == NULL){
            return false;
        }
        else if(value < node->data){
            parent = node;
            return remove(node->left,parent,value);
        }
        else if(value > node->data){
            parent = node;
            return remove(node->right,parent,value);
        }
        else{
            if(node->count > 1){     //Mutiple instances of the value//
                node->count = node->count -1;
            }
            else if(node->left == NULL && node->right == NULL) //no children//
            {
                delete node;
                node = NULL;
                return true;
            }
            else if(node->left == NULL){  //1 child//
                Node * temp = node;
                node = node->right;
                if(parent->data > node->data){
                    parent->left = node;
                }
                else{
                    parent->right = node;
                }
                delete temp;
                return true;
            }
            else if(node->right == NULL){
                Node * temp = node;
                node = node->left;
                 if(parent->data > node->data){
   	       	       	parent->left = node;
       	       	}
       	       	else{
       	       	    parent->right = node;
       	       	}

                delete temp;
                return true;
            }
            else{   //2 children//
                Node * temp = node->right;
                node->data = temp->data;
                return remove(node->right,parent,node->data); 
            }

        }

    return false;
    
}
//Input: Nothing
//Returns: An integer value
//Does: Invokes the private tree height function starting at root
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

//Input: A pointer to a struct node
//Returns: An integer value
//Does: Recursively determines the height of a tree
int BinarySearchTree::tree_height(Node *node) const
{
        if(root == NULL){
           return -1;
        }
        if(node == NULL){
            return 0;
        }
        else{
            int height_L = tree_height(node->left);
            int height_R = tree_height(node->right);
            if(height_L > height_R){
                return (height_L + 1);
            }
            else{
                return (height_R + 1);
            }
       }
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

//Input: A pointer to a struct node
//Returns: An integer value
//Does: Recursively calculates the number of nodes in the Tree
int BinarySearchTree::node_count(Node *node) const
{
    if(node == NULL){
        return 0;
    }
    else{
        return node_count(node->left) + node_count(node->right) + 1;
    }
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

//Input: A pointer to a struct node
//Returns: An integer value
//Does: Recursively calculates the total "count" value
//of all the nodes
int BinarySearchTree::count_total(Node *node) const
{
        if(node == NULL){
            return 0;
        }
        return (node->data + count_total(node->left) + count_total(node->right));
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node, Node *child) const
{
        if (node == NULL) return NULL;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}
