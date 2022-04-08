/**
 * Здесь структура двусвязанного списка.
 */

#ifndef SGM_SRC_TOOLS_LIST_H_
#define SGM_SRC_TOOLS_LIST_H_

struct ListItem_s;
typedef struct ListItem_s *ListItem;

/** двусвязный список
 */
typedef struct List_s *List;

/**
 * Возвращает новый экземпляр списка
 */
extern ListItem ListItem_new();

/**
 * ввозвращает первый элемент списка
 * @return Первый элемент списка как ListItem
 */
extern ListItem list_first(List list);

/**
 * Возвращает следущий элемент в списке
 */
extern ListItem list_next(ListItem item);

/**
 * Создает новый список и возвращает его
 */
extern List List_new();

/**
 * Удаляет список. И все объекты в зависимости от параметров
 * @param list Удаляемый список
 * @param object_free_function Если не null, то применяется к каждому объекту
 */
extern void list_free(List list, void (*object_free_function)(void *));

/**
 * Добавляет ListItem в список
 */
extern void list_add_item(List list, ListItem item);

/**
 * Добавляет элемент в список
 */
extern void list_add(List list, void *value);

/**
 * TODO
 * Удаляет элемент по значению из списка и возвращает его
 */
extern ListItem list_remove(ListItem item);

/**
 * TODO
 * Возвращает элемент по индексу \b index
 * @param list Список
 * @param index Индекс нужного элемента
 * @return Элемент под индексом \b index
 */
extern ListItem list_get(List list, int index);

/**
 * TODO
 * Удаляет элемент под индексом \b index и возвращает его
 * @param list список
 * @param index индекс удаляемого элемента
 * @return Элемент под индексом \b index.
 */
extern ListItem list_pop(List list, int index);

/**
 * возвращает значений из элемента списка
 * @param item элемент списка
 * @return указатель на значение элемента списка
 */
extern void *listItem_get(ListItem item);

/**
 * Создает цикл перебора элементов в списке
 * @param Type Тип объекта в списке
 * @param var Переменная, ззначение которой = элемент списка
 * @param List Указатель на перебираемый список
 */
#define foreach(var_definition, var, List) \
  var_definition;                                     \
  for(ListItem (__ ##var) = list_first(List);((__ ##var) != 0) && ((var) = listItem_get(__ ##var)); (__ ##var) = list_next(__ ##var))

#endif //SGM_SRC_TOOLS_LIST_H_
