#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "countint.hpp"
#include "BSTNode.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>


using namespace std;

static int countTime = 0;

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
    cout << "curr node = " << *curr << endl;
    cout <<"data of the node = "<<(*curr)->data<< "  priority of the node = " <<(*curr)->priority << endl;

    this->isize++;
    cout << "root = " << this->root << endl;

    // if(this->isize == 1)
    //   this->root = (*curr);

    cout << "isize = " <<this->isize << endl;


    //the root node?
    // if (!((*curr)->parent))
    // {
    //   cout << "doesn't have a parent" << endl;
    //   srand (time(0) + countTime);
    //   countTime++;
    // }
    // (*curr)->priority = rand();

    if ((*curr)->parent) {
    cout << "enter 1" <<endl;
    cout << "(*curr)->parent" << (*curr)->parent << endl;
    while ((*curr)->parent && (*curr)->priority > (*curr)->parent->priority) {
      cout << "enter 2" <<endl;

      if ((*curr)->parent->right == (*curr)) {
        //left rotation    
        cout << "left rotation" <<endl;   

          //if this is the node of a root's child
        if ((*curr)->parent == this->root) {
          cout << "enter 3" << endl;
          if (!((*curr)->left)) 
          {
            cout << "enter 4" << endl;

            (*curr)->left = (*curr)->parent;
            cout << "done 1" <<endl;
            cout << "(*curr)->left = "<<(*curr)->left << endl;
            cout << "(*curr)->parent = "<<(*curr)->parent << endl;

            cout << "*curr = " << *curr << endl;
            cout << "(*curr)->left->right = "<<(*curr)->left->right << endl;

            cout << "*curr = " << *curr << endl;
            cout << "done 2" <<endl;
            cout << (*curr)->parent << endl;


          }
          else
          {
            cout << "enter 4.5" << endl;

            (*curr)->parent->right = (*curr)->left;
            (*curr)->left = (*curr)->parent;
          }
          //re-establish all the connections back
          cout << (*curr)->parent->right << endl;
          (*curr)->parent = 0;
          cout << "done 3" <<endl;
          this->root = (*curr);
          cout << "done 4" <<endl;
          (*curr)->left->parent = (*curr);
          cout << "done 5" <<endl;
          (*curr)->left->right = 0;
          cout << "done 6" <<endl;
          cout << "*curr = " << *curr << endl;



        }

        else 
        {
          //leaf node
          cout << "enter 5" << endl;

          if (!((*curr)->left)) 
          {
            (*curr)->left = (*curr)->parent;
            (*curr)->left->right = 0;
          }
          //not a leaf node
          else
          {
            // (*curr)->parent->right = (*curr)->left;
            // (*curr)->left = (*curr)->parent;

            (*curr)->parent->right = (*curr)->left;
            (*curr)->left->parent = (*curr)->parent;
            (*curr)->left = (*curr)->parent;
          }
          (*curr)->parent = (*curr)->parent->parent;
          (*curr)->left->parent = (*curr);
          (*curr)->parent->right = (*curr);
        }
      }

      else 
      {
        //right rotation
        cout << "right rotation" <<endl;   

        if ((*curr)->parent == this->root) {
          if (!((*curr)->right)) 
          {
            (*curr)->right = (*curr)->parent;
            (*curr)->right->left = 0;
          }
          else
          {
            (*curr)->parent->left = (*curr)->right;
            (*curr)->right = (*curr)->parent;
          }
          (*curr)->parent = 0;
          this->root = (*curr);
          (*curr)->right->parent = (*curr);
        }

        else 
        {
          if (!((*curr)->right)) 
          {
            (*curr)->right = (*curr)->parent;
            (*curr)->right->left = 0;
          }
          else
          {
            (*curr)->parent->left = (*curr)->right;
            (*curr)->right = (*curr)->parent;
          }
          (*curr)->parent = (*curr)->parent->parent;
          (*curr)->right->parent = (*curr);
          (*curr)->parent->left = (*curr);
        }
      }
    }
  }


    cout << "right before return" << endl;
    return true;
  }

};
#endif // RST_HPP
