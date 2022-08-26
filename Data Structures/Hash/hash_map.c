#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_HASH_SET_CAPACITY 1 << 10

typedef struct hash_map {
  int *keys;
  int *values;
  unsigned size;
  unsigned capacity;
} hash_map_t;

hash_map_t *init_hash_map();
unsigned add(hash_map_t *map, int value);
unsigned put(hash_map_t *map, long long hash, int value);
int contains(hash_map_t *map, int value);
int contains_hash(hash_map_t *map, long long hash);
void delete (hash_map_t *map, int value);
long long hash(int value);
unsigned retrieve_index_from_hash(long long hash, unsigned capacity);
void resize(hash_map_t *map);

int main() {
  hash_map_t *map = init_hash_map();

  for (int i = 0; i < 10; i++) {
    add(map, i + 1);
    printf("contains %d ? %d \n", i + 1, contains(map, i + 1));
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    delete (map, i + 1);
    printf("contains %d ? %d \n", i + 1, contains(map, i + 1));
  }
  printf("\n");

  return 0;
}

hash_map_t *init_hash_map() {
  hash_map_t *map = (hash_map_t *)malloc(sizeof(hash_map_t));
  map->capacity = DEFAULT_HASH_SET_CAPACITY;
  map->keys = (int *)calloc(map->capacity, sizeof(int));
  map->values = (int *)calloc(map->capacity, sizeof(int));
  map->size = 0;
  return map;
}

unsigned add(hash_map_t *map, int value) {
  return put(map, hash(value), value);
}

unsigned put(hash_map_t *map, long long hash, int value) {
  if (contains_hash(map, hash)) {
    if (map->keys[retrieve_index_from_hash(hash, map->capacity)] == value) {
      return 0;
    }
    // collision
    resize(map);
    return put(map, hash, value);
  }
  map->keys[retrieve_index_from_hash(hash, map->capacity)] = value;
  map->values[map->size++] = value;
  return 1;
}

int contains(hash_map_t *map, int value) {
  return map->keys[retrieve_index_from_hash(hash(value), map->capacity)] ==
                 value
             ? 1
             : 0;
}

int contains_hash(hash_map_t *map, long long hash) {
  return map->keys[retrieve_index_from_hash(hash, map->capacity)] ? 1 : 0;
}

void delete (hash_map_t *map, int value) {
  map->keys[retrieve_index_from_hash(hash(value), map->capacity)] = NULL;
}

// adler_32 hash
long long hash(int value) {
  const int MODADLER = 65521;
  char *str = &value;
  int a = 1, b = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    a = (a + str[i]) % MODADLER;
    b = (b + a) % MODADLER;
  }
  return (b << 16) | a;
}

unsigned retrieve_index_from_hash(long long hash, unsigned capacity) {
  return (capacity - 1) & (hash ^ (hash >> 12));
}

void resize(hash_map_t *map) {
  int *keys_resized = (int *)calloc((map->capacity <<= 1), sizeof(int *));
  for (int i = 0; i < map->size; i++) {
    keys_resized[retrieve_index_from_hash(hash(map->values[i]),
                                          map->capacity)] = map->values[i];
  }
  free(map->keys);
  map->keys = keys_resized;
  int *new_values = (int *)realloc(map->values, map->capacity * sizeof(int *));
  map->values = new_values;
}
