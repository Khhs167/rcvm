#ifndef _RCVM_LIST_H
#define _RCVM_LIST_H

#include "stdint.h"
#include "stdlib.h"
#include "rcvm_callbacks.h"


#define LIST(type__) rcvm_list_##type__##_t
#define LIST_GET(list__, index__) (list->values[index__])
#define LIST_SET(list__, index__, value__) (list->values[index__] = value__)

#define __list_func(type__, name__) rcvm_list_##type__##_##name__##_
#define __def_list_func(type__, name__, ...) __list_func(type__, name__) (__VA_ARGS__)

#define RCVM_DEF_LIST_T(type__) \
    typedef struct { uint64_t size; type__* values; } LIST(type__);                         \
    LIST(type__)* __def_list_func(type__, create, uint32_t size);                            \
    void __def_list_func(type__, destroy, LIST(type__)* list);                               \
    void __def_list_func(type__, push, LIST(type__)* list, type__ value);                    \
    type__ __def_list_func(type__, pop, LIST(type__)* list);                                 \
    void __def_list_func(type__, set, LIST(type__)* list, uint64_t index, type__ value);     \
    type__ __def_list_func(type__, get, LIST(type__)* list, uint64_t index);                 \

#define RCVM_IMPLEMENT_LIST_T(type__) \
    LIST(type__)* __def_list_func(type__, create, uint32_t size) {                           \
        LIST(type__)* list = malloc(sizeof( LIST(type__) ));                                \
        list->size = size;                                                                  \
        list->values = malloc(size * sizeof( type__ ));                                     \
        return list;                                                                        \
    }                                                                                       \
    static void __def_list_func(type__, resize, LIST(type__)* list, uint64_t size) {        \
        type__* old = list->values;                                                         \
        type__* new = malloc(size * sizeof( type__ ));                                      \
        int old_size = list->size;                                                          \
        for(int i = 0; i < size; i++) {                                                     \
            if(i < old_size) new[i] = old[i];                                               \
        }                                                                                   \
        list->size = size;                                                                  \
        list->values = new;                                                                 \
        free(old);                                                                          \
    }                                                                                       \
    void __def_list_func(type__, destroy, LIST(type__)* list) {                             \
        free(list->values);                                                                 \
        free(list);                                                                         \
    }                                                                                       \
    void __def_list_func(type__, push, LIST(type__)* list, type__ value) {                  \
        __list_func(type__, resize)(list, list->size + 1);                                  \
        list->values[list->size - 1] = value;                                               \
    }                                                                                       \
    type__ __def_list_func(type__, pop, LIST(type__)* list) {                               \
        type__ value = list->values[list->size - 1];                                        \
        __list_func(type__, resize)(list, list->size + 1);                                  \
        return value;                                                                       \
    }                                                                                       \

RCVM_DEF_LIST_T(int)

#endif