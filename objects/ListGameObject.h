///
/// Здесь двусвязный список (List из tools), но для работы с GameObject *, а не с void *
///

#ifndef SGM_SRC_GAME_LISTGAMEOBJECT_H_
#define SGM_SRC_GAME_LISTGAMEOBJECT_H_

#include "../tools/List.h"
#include "GameObject.h"

typedef List *ListGameObject;

/**
 * Создает новый объект типа \b List и возвращает его
 * @return Указатель на созданный \b List
 */
ListGameObject ListGameObject_new();

/**
 * TODO
 * Отчищает память списка. \n
 * Отчищает память всех его элементов, если их нет в area???
 * @param list Удаляемый список
 */
extern void ListGameObject_free(ListGameObject list);

/**
 * Добавляет GameObject * в список
 * @param list Список, в который нужно добавить объект
 * @param game_object Добавляемый объект
 */
extern void ListGameObject_add(ListGameObject list, GameObject *game_object);

/**
 * TODO
 * Удаляет элемент из коллекции и возвращает его
 * @param list Коллекция, из которой нужно удалить объект
 * @param game_object Удаляемый объект
 * @return Удаляемый объект?????
 */
extern GameObject *ListGameObject_remove(ListGameObject list, GameObject *game_object);

#endif //SGM_SRC_GAME_LISTGAMEOBJECT_H_
