//
// Created by alexium on 11.04.2022.
//

#include "HashTable.h"
#include <stdlib.h>

struct NodeItem_s {
  int key;
  void *value;
};

struct BinTreeNode_s {
  struct NodeItem_s item;
  struct BinTreeNode_s *left;
  struct BinTreeNode_s *right;
};

struct HashTable_s {
  struct BinTreeNode_s *root;
};

struct BinTreeNode_s *BinTreeNode_new(int key, void *value) {
  struct BinTreeNode_s *node = malloc(sizeof(struct BinTreeNode_s));
  node->left = 0;
  node->right = 0;
  node->item.key = key;
  node->item.value = value;
  return node;
}

void binTreeNode_insert(struct BinTreeNode_s *hash_table, int key, void *value) {
  if (key > hash_table->item.key) {
    if (hash_table->right)
      binTreeNode_insert(hash_table->right, key, value);
    else
      hash_table->right = BinTreeNode_new(key, value);
  } else if (key < hash_table->item.key) {
    if (hash_table->left)
      binTreeNode_insert(hash_table->left, key, value);
    else
      hash_table->left = BinTreeNode_new(key, value);
  } else {
    hash_table->item.value = value;
  }
//  struct BinTreeNode_s *node = hash_table;
//  while (1) {
//    if (key > node->item.key) {
//      if (node->right)
//        node = node->right;
//      else {
//        node->right = HashTable_new(key, value);
//        break;
//      }
//    } else if (key < node->item.key) {
//      if (node->left)
//        node = node->left;
//      else {
//        node->left = HashTable_new(key, node);
//        break;
//      }
//    } else {
//      return 1;
//    }
//  }
//  return 0;
}

void *binTreeNode_get(struct BinTreeNode_s *node, int key) {
  if (node) {
    if (key > node->item.key)
      return binTreeNode_get(node->right, key);
    else if (key < node->item.key)
      return binTreeNode_get(node->left, key);
    else
      return node->item.value;
  }
  return 0;
}

HashTable HashTable_new() {
  struct HashTable_s *table_s = malloc(sizeof(struct HashTable_s));
  table_s->root = 0;
  return table_s;
}

void hashTable_insert(HashTable hash_table, int key, void *value) {
  if (hash_table->root)
    binTreeNode_insert(hash_table->root, key, value);
  else
    hash_table->root = BinTreeNode_new(key, value);
}

void *hashTable_get(HashTable hash_table, int key) {
  if (hash_table->root)
    return binTreeNode_get(hash_table->root, key);
  return 0;
}
