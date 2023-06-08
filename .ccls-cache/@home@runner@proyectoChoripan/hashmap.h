//
//  HashMap.h
//  TablaHashLab
//
//

#ifndef HashMap_h
#define HashMap_h


typedef struct HashMap HashMap;

typedef struct hashPair {
     char * key;
     void * value;
} hashPair;

HashMap * createMap(long capacity);

void insertMap(HashMap * table, char * key, void * value);

void eraseMap(HashMap * table, char * key);

hashPair * searchMap(HashMap * table, char * key);

hashPair * firstMap(HashMap * table);

hashPair * nextMap(HashMap * table);

void enlarge(HashMap * map);

#endif /* HashMap_h */
