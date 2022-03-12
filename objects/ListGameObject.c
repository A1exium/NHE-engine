//
// Здесь Список (List из tools), но для работы с GameObject *, а не void *
//

#include "ListGameObject.h"

// Создает новый объект типа List и возвращает его
ListGameObject ListGameObject_new() {
  return List_new();
}

// Отчищает память объекта
// ЗАГЛУШКА
// TODO: сделать по описанию в ListGameObject.h
void ListGameObject_free(ListGameObject list) {
  List_free(list);
}

// Добавляет GameObject * в список
void ListGameObject_add(ListGameObject list, GameObject *game_object) {
  List_add(list, game_object);
};
