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
void listGameObject_free(ListGameObject list) {
  list_free(list);
}

// Добавляет GameObject * в список
void listGameObject_add(ListGameObject list, GameObject *game_object) {
  list_add(list, game_object);
};
