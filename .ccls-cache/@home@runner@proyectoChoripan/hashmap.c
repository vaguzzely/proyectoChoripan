#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    hashPair ** buckets;
    long size; //cantidad de datos/hashpairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

hashPair * createhashPair( char * key,  void * value) {
    hashPair * new = (hashPair *)malloc(sizeof(hashPair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equalHash(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap *map, char *key, void *value) {
    long codigo = hash(key, map->capacity);
    int count = 0;

    if (map->size > (map->capacity * 0.7))
    {
      enlarge(map); //se agranda la capacidad del mapa si es que está llena hasta el 70%
    }
    while (map->buckets[codigo] != NULL && count < map->capacity) {
      
        if (is_equalHash(map->buckets[codigo]->key, key)) {
            return;
        }
        codigo = (codigo + 1) % map->capacity; 
        count++;
    }
    if (count == map->capacity) {
        return;
    }

    map->buckets[codigo] = createhashPair(key, value);
    map->current = codigo; 
    map->size++; 
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)
    hashPair ** old_buckets = map->buckets; 
    int old_capacity = map->capacity; 

    map->capacity *= 2;
    map->buckets = (hashPair **) calloc(map->capacity, sizeof(hashPair *));

    
    map->size = 0;

    
    for (int i = 0; i < old_capacity; i++) {
        if (old_buckets[i] != NULL && old_buckets[i]->key != NULL) {
            insertMap(map, old_buckets[i]->key, old_buckets[i]->value);
        }
    }

    free(old_buckets);

}


HashMap * createMap(long capacity) {

  HashMap *mapa = (HashMap*)malloc(sizeof(HashMap));
  mapa->buckets = (hashPair**)malloc(capacity * sizeof(hashPair**));
  mapa->size = 0;
  mapa->capacity = capacity;
  mapa->current = -1;
  return mapa;
}

void eraseMap(HashMap * map,  char * key) {    
    hashPair *dato=searchMap(map,key);
  if(dato!=NULL)
  {
    dato->key=NULL;
    map->size--;
  }

}

hashPair * searchMap(HashMap * map, char * key) {
    long codigo = hash(key, map->capacity);
    int i = 0;
    while (i < map->capacity) {
        if (map->buckets[codigo] == NULL) {
            break;
        }
        if (is_equalHash(map->buckets[codigo]->key, key)) {
            map->current = codigo;
            return map->buckets[codigo];
      }
        codigo = (codigo + 1) % map->capacity; 
        i++;
    }
    return NULL; 
}

hashPair * firstMap(HashMap * map) {
    map->current = 0;
  
    while (map->current < map->capacity) {
        if (map->buckets[map->current] != NULL && map->buckets[map->current]->key != NULL) {
            map->current++;
            return (map->buckets[map->current-1]);
        }
        map->current++;
    }
    return NULL;
}

hashPair * nextMap(HashMap * map) {
 
    while (map->current < map->capacity) {
        if (map->buckets[map->current] != NULL && map->buckets[map->current]->key != NULL) {
          map->current++;
return map->buckets[(map->current)-1];
        }
        map->current++;
    }
    return NULL;
    
}
