//
// Created by alexium on 19.03.2022.
//

#include "ListeningTable.h"
#include "PackedFunction.h"
#include "Event.h"
#include <stdlib.h>
#include "tools/List.h"

void ListeningTable_init() {
//  listeningTable = HashTable_new(EventKeyboard, HashTable_new());
//  listeningTable = calloc(sizeof(HashTable), EVENT_TYPE_COUNT);
//  listeningTable[EventKeyboard] = calloc(sizeof(HashTable), EVENT_TYPE_KEYBOARD_COUNT);
//  listeningTable[EventMouse] = calloc(sizeof(HashTable), EVENT_TYPE_MOUSE_COUNT);
//  listeningTable[EventLoop] = 0;
  listeningTable = HashTable_new();
  hashTable_insert(listeningTable, EventKeyboard, HashTable_new());
  hashTable_insert(listeningTable, EventMouse, HashTable_new());
  hashTable_insert(listeningTable, EventLoop, List_new());
  hashTable_insert(listeningTable, EventServerMessage, HashTable_new());
  hashTable_insert(listeningTable, EventCustom, HashTable_new());
}

void listeningTable_call(Event event) {
  List functions = 0;
  switch (event.type) {
    case EventMouse:
    case EventKeyboard:
      functions = hashTable_get(hashTable_get(listeningTable, EventKeyboard), event.payload.keyboard_event.key);
      break;
    case EventLoop:
      functions = hashTable_get(listeningTable, EventLoop);
      break;
    case EventCustom:
      functions = hashTable_get(
          hashTable_get(
              listeningTable,
              EventCustom
          ),
          event.payload.custom_event.custom_event_type
      );
      break;
    case EventServerMessage:
      functions = hashTable_get(
          hashTable_get(
              listeningTable,
              EventServerMessage
          ),
          event.payload.server_message_event.custom_event_type
      );
      break;
    default:
      break;
  }
  if (functions) {
    foreach(PackedFunction packed, packed, functions) {
      if (packed)
        packedFunction_call(event, packed);
    }
  }
}

PackedFunction function_pack(EventCallback f, EventCallbackArgs args) {
  PackedFunction packed = malloc(sizeof(struct PackedFunction_s));
  packed->f = f;
  packed->args = args;
  return packed;
}


extern void addEventListener(Event target, EventCallback func, EventCallbackArgs args) {
  switch (target.type) {
    case EventMouse:
    case EventKeyboard: {
      HashTable key_table = hashTable_get(listeningTable, target.type);
      List current_functions = hashTable_get(key_table, target.payload.keyboard_event.key);
      if (current_functions) {
        list_add(current_functions, function_pack(func, args));
      } else {
        List function_list = List_new();
        list_add(function_list, function_pack(func, args));
        hashTable_insert(key_table, target.payload.keyboard_event.key, function_list);
      }
      break;
    }
    case EventLoop: {
      List functions = hashTable_get(listeningTable, target.type);
      list_add(functions, function_pack(func, args));
      break;
    }
    case EventServerMessage: {
      HashTable types = hashTable_get(listeningTable, EventServerMessage);
      List functions = hashTable_get(types, target.payload.server_message_event.custom_event_type);
      if (functions) {
        list_add(functions, function_pack(func, args));
      } else {
        functions = List_new();
        list_add(functions, function_pack(func, args));
        hashTable_insert(types, target.payload.server_message_event.custom_event_type, functions);
      }
      break;
    }
    case EventCustom: {
      HashTable types = hashTable_get(listeningTable, EventServerMessage);
      List functions = hashTable_get(types, target.payload.custom_event.custom_event_type);
      if (functions) {
        list_add(functions, function_pack(func, args));
      } else {
        functions = List_new();
        list_add(functions, function_pack(func, args));
        hashTable_insert(types, target.payload.custom_event.custom_event_type, functions);
      }
      break;
    }
    default:
      break;
  }
}
