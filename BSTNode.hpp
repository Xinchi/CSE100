/**
 * Author: Xinchi Gu
 * PID: A53054946
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
#include "countint.hpp"

template<typename Data>
class BSTNode {

public:
  int priority;


public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    if(right!=0)
      return right->leftMostNode();
    else if(parent==0)
      return 0;
    else if(this == parent->left)
      return parent;
    else
      return parent->ancestorSuccessor();
  }

private:

  /** Return the left most node of the binary subtree, or itself if it doesn't have a child.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   **RETURNS:  the pointer to the BSTNode that is the left most of the subtree.
  */
  BSTNode<Data>* leftMostNode() {
    if(left != 0)
      return(left->leftMostNode());
    else 
      return this;
  }

  /** Return the inorder parental successor of the BSTNode in a BST, or 0 if none.
   ** PRECONDITON:  this BSTNode is a node in a BST.
   ** POSTCONDITION: the BST is unchanged.
   ** RETURNS  the pointer to the BSTNode that is the ancestor successor of the node, or 0 if there is none.
  */
  BSTNode<Data>* ancestorSuccessor() {
    if(parent == 0)
      return 0;
    else if(this == parent->right)
      return parent->ancestorSuccessor();
    else
      return parent;
  }
}; 



/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}


#endif // BSTNODE_HPP
