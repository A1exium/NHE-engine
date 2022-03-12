//
// Created by alexium on 16.02.2022.
//

#include "List.h"
#include <stdlib.h>

struct ListItem_s {
  void *value;
  ListItem *prev;
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

void ListItem_free(ListItem *list_item) {
  if (list_item->next) ListItem_free(list_item->next);
  free(list_item);
}

void List_free(List *list) {
  if (list->head) ListItem_free(list->head);
  free(list);
}

ListItem *ListItem_new(void *value) {
  ListItem *item = (ListItem *)malloc(sizeof(ListItem));
  item->value = value;
  item->next = 0;
  item->prev = 0;
  return item;
}

void List_add_item(List *list, ListItem *item) {
  if (list->head) {
    ListItem *insertion_item = list->head;
    while (insertion_item->next) {
      insertion_item = (ListItem *) insertion_item->next;
    }
    item->prev = insertion_item;
    insertion_item->next = item;
  } else {
    list->head = item;
  }
}

void List_add(List *list, void *value) {
  List_add_item(list, ListItem_new(value));
}

ListItem *List_first(List *list) {
  return list->head;
}

ListItem *List_next(ListItem *item) {
  return item->next;
}

void *ListItem_get(ListItem *item) {
  return item->value;
}

