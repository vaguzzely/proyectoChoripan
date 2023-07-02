#ifndef TREEMAP_h
#define TREEMAP_h

typedef struct TreeMap TreeMap;

typedef struct PairTree {
     void * key;
     void * value;
} PairTree;

TreeMap * createTreeMap(int (*lower_than_int) (void* key1, void* key2));

void insertTreeMap(TreeMap * tree, void* key, void * value);

void eraseTreeMap(TreeMap * tree, void* key);

PairTree * searchTreeMap(TreeMap * tree, void* key);

PairTree * upperBound(TreeMap * tree, void* key);

PairTree * firstTreeMap(TreeMap * tree);

PairTree * nextTreeMap(TreeMap * tree);

int sizeTreeMap(TreeMap* arbol);
#endif /* TREEMAP_h */
