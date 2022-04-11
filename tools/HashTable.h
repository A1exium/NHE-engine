//
// Created by alexium on 11.04.2022.
//

#ifndef SGM_SRC_ENGINE_TOOLS_HASHTABLE_H_
#define SGM_SRC_ENGINE_TOOLS_HASHTABLE_H_

typedef struct HashTable_s *HashTable;

HashTable HashTable_new();

void hashTable_insert(HashTable hash_table, int key, void *value);

void *hashTable_get(HashTable hash_table, int key);

#endif //SGM_SRC_ENGINE_TOOLS_HASHTABLE_H_
