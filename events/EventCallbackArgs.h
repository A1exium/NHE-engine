//
// Created by alexium on 25.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENTCALLBACKARGS_H_
#define SGM_SRC_ENGINE_EVENTS_EVENTCALLBACKARGS_H_

typedef struct EventCallbackArgs_s {
  void **storage;
  int length;
} EventCallbackArgs;


extern const EventCallbackArgs NO_ARGS;

extern EventCallbackArgs EventCallbackArgs_pack(int argc, void *arg,...);

extern void EventCallbackArgs_unpack(EventCallbackArgs _args, ...);

#endif //SGM_SRC_ENGINE_EVENTS_EVENTCALLBACKARGS_H_
