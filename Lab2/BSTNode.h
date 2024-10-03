// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 05/14/2024 modification by Prof Sipantzi
// This is the file to include for access to the complete binary node
// template implementation

#include "book.h"
#include "BinNode.h"

#pragma once

// Simple binary tree node implementation
template <class Key, class E>
class BSTNode : public BinNode<E> {
private:
  Key k;                  // The node's key
  E it;                   // The node's value
  BSTNode* lc;            // Pointer to left child
  BSTNode* rc;            // Pointer to right child

  // Bit field instead of boolean
  unsigned int isThreadedLeft : 1;
  unsigned int isThreadedRight : 1;

public:
  // Two constructors -- with and without initial values
  BSTNode() { lc = rc = NULL; isThreadedLeft = 0; isThreadedRight = 0; }
  BSTNode(Key K, E e, BSTNode* l =NULL, BSTNode* r =NULL, bool leftThread = false, bool rightThread = false)
  {
      k = K; it = e; lc = l; rc = r;
      isThreadedLeft = leftThread ? 1 : 0;
      isThreadedRight = rightThread ? 1 : 0;
  }
  ~BSTNode() {}             // Destructor

  // Functions to set and return the value and key
  E& element() { return it; }
  void setElement(const E& e) { it = e; }
  Key& key() { return k; }
  void setKey(const Key& K) { k = K; }

  // Functions to set and return the children
  inline BSTNode* left() const { return lc; }
  void setLeft(BinNode<E>* b, bool isThread = false)
  {
      lc = (BSTNode*)b;
      isThreadedLeft = isThread ? 1 : 0;
  }

  inline BSTNode* right() const { return rc; }
  void setRight(BinNode<E>* b, bool isThread = false)
  {
      rc = (BSTNode*)b;
      isThreadedRight = isThread ? 1 : 0;
  }

  // Return true if it is a leaf, false otherwise
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};
