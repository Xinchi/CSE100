#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "countint.hpp"
#include "BSTNode.hpp"
#include <stdlib.h>
#include <iostream>

#include <cstdlib>


using namespace std;


template <typename Data>
class RST : public BST<Data> {

public:

 virtual bool insert(const Data& item) {
    // TODO: implement this function!
    BSTNode<Data>** curr =&this->root;
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
    (*curr)->priority = rand();

    this->isize++;
    BSTNode<Data> *c = *curr;





    if ((c)->parent) {

    while ((c)->parent && (c)->priority > (c)->parent->priority) {

      if ((c)->parent->right == (c)) {
        //left rotation

          //if this is the node of a root's child
        if ((c)->parent == this->root) {

            (c)->parent->right = (c)->left;
            if(c->left!=0)
              c->left->parent = c->parent;
            (c)->left = (c)->parent;
            (c)->parent = 0;

            (c)->left->parent = (c);
           this->root = (c);          
        }

        else 
        {

          (c)->parent->right = (c)->left;
          if(c->left!=0)
            (c)->left->parent = (c)->parent;
          (c)->left = (c)->parent;

          (c)->parent = (c)->left->parent;
          (c)->left->parent = (c);


          if((c)->parent->left == (c)->left)
            (c)->parent->left = (c);
          else  
            (c)->parent->right = (c);
        }
      }

      else 
      {
        if ((c)->parent == this->root) {
          (c)->parent->left = (c)->right;
          if(c->right!=0)
            c->right->parent = c->parent;

          (c)->right = (c)->parent;
          (c)->parent = 0;

          (c)->right->parent = (c);
          this->root = (c);    
        }

        else 
        {

          (c)->parent->left = (c)->right;
          if(c->right!=0)
            (c)->right->parent = (c)->parent;
          (c)->right = (c)->parent;

          (c)->parent = (c)->right->parent;
          (c)->right->parent = (c);


          if((c)->parent->right == (c)->right)
            (c)->parent->right = (c);
          else  
            (c)->parent->left = (c);
        }


      }
    }
  }


    return true;
  }

};
#endif // RST_HPP
