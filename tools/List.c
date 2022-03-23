//
// Created by alexium on 16.02.2022.
//

#include "List.h"
#include <stdlib.h>

struct ListItem_s {
  void *value;
  ListItem *next;
};

struct List_s {
  ListItem *head;
};

List *List_new() {
  List *list = (List *) malloc(sizeof(List));
  list->head = 0;
  return list;
}

void listItem_free(ListItem *list_item, void (*object_free_function)(void *)) {
  if (list_item->next) listItem_free(list_item->next, object_free_function);
  object_free_function(listItem_get(list_item));
  free(list_item);
}

void list_free(List *list, void (*object_free_function)(void *)) {
  if (list->head) listItem_free(list->head, object_free_function);
  free(list);
}

ListItem *ListItem_new(void *value) {
  ListItem *item = (ListItem *)malloc(sizeof(ListItem));
  item->value = value;
  item->next = 0;
  return item;
}

void list_add_item(List *list, ListItem *item) {
  if (list->head) {
    ListItem *insertion_item = list->head;
    while (insertion_item->next) {
      insertion_item = (ListItem *) insertion_item->next;
    }
    insertion_item->next = item;
  } else {
    list->head = item;
  }
}

void list_add(List *list, void *value) {
  list_add_item(list, ListItem_new(value));
}

ListItem *list_first(List *list) {
  return list->head;
}

ListItem *list_next(ListItem *item) {
  return item->next;
}

void *listItem_get(ListItem *item) {
  return item->value;
}
