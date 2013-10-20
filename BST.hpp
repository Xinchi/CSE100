/**
 * Author: Xinchi Gu
 * PID: A53054946
 */
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    destroy(root);
    root = 0;
    return;
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  virtual bool insert(const Data& item) {
    BSTNode<Data>** curr = &root;
    BSTNode<Data>* parent = 0;

    while((*curr)!=0) {
      parent = *curr;
      if((*curr)->data == item)
      {
        return false;
      }
      else if(item<(*curr)->data)
        curr = &(*curr)->left;
      else
        curr = &(*curr)->right;
    }

    (*curr) = new BSTNode<Data>(item);
    (*curr)->parent = parent;

    isize++;

    return true;
  }



  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* curr = root;
    //the while loop terminates when the curr points to a null object
    while(curr!=0 && curr->data!=item)
    {
      if(item < curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }

    return typename BST<Data>::iterator(curr);

  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;

  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if(isize==0)
      return true;
    
      return false;

  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
    BSTNode<Data>* curr = root;

    if(curr!=0)
    {
      //go to the left most node recursively
      while(curr->left!=0)
      {
        curr = curr->left;
      }
    }
    return typename BST<Data>::iterator(curr);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */
  void inorder(BSTNode<Data>* n) const {
    if(n==0) return;
    inorder(n->left);
    std::cout << *n << std::endl;
    inorder(n->right);
  }

  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  // do a postorder traversal, deleting nodes
  static void deleteAll(BSTNode<Data>* n) {
    if (0 == n) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }

  static void destroy(BSTNode<Data>* TRoot){
    if(TRoot!=0)
    {
      destroy(TRoot->left);
      TRoot->left = 0;
      destroy(TRoot->right);
      TRoot->right = 0;
      TRoot->parent = 0;
      delete(TRoot);
    }
    return;
  }



 };


#endif //BST_HPP
