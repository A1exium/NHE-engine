/**
 * Здесь структура двусвязанного списка.
 */

#ifndef SGM_SRC_TOOLS_LIST_H_
#define SGM_SRC_TOOLS_LIST_H_

struct ListItem_s;
typedef struct ListItem_s ListItem;

/** двусвязный список
 */
typedef struct List_s List;

/**
 * Возвращает новый экземпляр списка
 */
extern ListItem *ListItem_new();

/**
 * ввозвращает первый элемент списка
 * @return Первый элемент списка как ListItem
 */
extern ListItem *List_first(List *list);

/**
 * Возвращает следущий элемент в списке
 */
extern ListItem *List_next(ListItem *item);

/**
 * Создает новый список и возвращает его
 */
extern List *List_new();

/**
 * Удаляет список и все объекты в нем
 */
extern void List_free(List *list);

/**
 * Добавляет ListItem в список
 */
extern void List_add_item(List *list, ListItem *item);

/**
 * Добавляет элемент в список
 */
extern void List_add(List *list, void *value);

/**
 * TODO
 * Удаляет элемент по значению из списка и возвращает его
 */
extern ListItem *List_remove(ListItem *item);

/**
 * TODO
 * Возвращает элемент по индексу \b index
 * @param list Список
 * @param index Индекс нужного элемента
 * @return Элемент под индексом \b index
 */
extern ListItem *List_get(List list, int index);

/**
 * TODO
 * Удаляет элемент под индексом \b index и возвращает его
 * @param list список
 * @param index индекс удаляемого элемента
 * @return Элемент под индексом \b index
 */
extern ListItem *List_pop(List list, int index);

/**
 * возвращает значений из элемента списка
 * @param item элемент списка
 * @return указатель на значение элемента списка
 */
extern void *ListItem_get(ListItem *item);

/**
 * Создает цикл перебора элементов в списке
 * @param Type Тип объекта в списке
 * @param var Переменная, ззначение которой = элемент списка
 * @param List Указатель на перебираемый список
 */
#define foreach(var, List) \
  for(ListItem *(var) = List_first(List); (var) != 0; (var) = List_next(var))

#endif //SGM_SRC_TOOLS_LIST_H_
