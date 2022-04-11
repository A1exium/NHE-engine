//
// Created by alexium on 25.03.2022.
//

#include "EventCallbackArgs.h"
#include <stdarg.h>
#include <stdlib.h>

const EventCallbackArgs NO_ARGS = {
    .length = 0,
    .storage = 0,
};

extern EventCallbackArgs EventCallbackArgs_pack(int argc, void *arg,...) {
  va_list _args;
  EventCallbackArgs args;
  args.length = argc;
  args.storage = calloc(argc, sizeof(void *));
  args.storage[0] = arg;
  if (argc > 1) {
    va_start(_args, arg);
    for (int i = 1; i < argc; i++) {
      void *tmp = va_arg(_args, void *);
      args.storage[i] = tmp;
    }
    va_end(_args);
  }
  return args;
}

extern void EventCallbackArgs_unpack(EventCallbackArgs _args, ...) {
  va_list _vars;
  if (_args.length > 0) {
    va_start(_vars, _args);
    for (int i = 0; i < _args.length; i++) {
      *va_arg(_vars, void **) = _args.storage[i];
    }
    va_end(_vars);
  }
}
