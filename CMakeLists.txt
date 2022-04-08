cmake_minimum_required(VERSION 3.17)
project(NHE C)

set(CMAKE_C_STANDARD 11)

add_library(NHE-base STATIC#SHARED
        tools/List.c tools/List.h
        tools/2DArray.c tools/2DArray.h
        tools/serializer.c tools/serializer.h

        geometry/Position.c geometry/Position.h
        geometry/mod.h geometry/mod_pub.h

        objects/Area.c objects/Area.h
        objects/GameObject.c objects/GameObject.h
        objects/mod.h
        objects/mod_pub.h objects/mod_pub.c
        renders/2D/base/Screen.c
        renders/2D/base/TextureStorage.c
        renders/2D/base/View.c
#        renders/2D/base/Texture.h
        renders/2D/mod.h

        events/Event.h
        events/event_loop.c events/event_loop.h
        events/EventPool.c events/EventPool.h
        events/ListeningTable.c events/ListeningTable.h
        events/event_provider.h
        events/EventCallbackArgs.c events/EventCallbackArgs.h
        events/EventCallback.c events/EventCallback.h
        events/PackedFunction.c events/PackedFunction.h
        events/mod.h events/mod_pub.h
        events/mod_init.h events/mod_init.c

		network/client/event_provider.c
		network/client/client_init.c network/client/client_init.h
		tools/SizedArray.c tools/SizedArray.h
		events/Event.c network/server/server_init.c
		network/server/server_init.h network/server/server.c
		network/server/server.h network/client/client.h
        network/mod_pub.h network/mod_pub.c)

#add_library(NHE-term STATIC)
#target_link_libraries(NGE-term NHE-base)

target_include_directories(NHE-base PUBLIC tools)
# TODO: Remove const from engine
target_include_directories(NHE-base PRIVATE ../globals)

target_include_directories(NHE-base PRIVATE .)

set_target_properties(NHE-base PROPERTIES PUBLIC_HEADER engine.h)

# Build with terminal graphics
if (RENDER STREQUAL "sdl")
	add_subdirectory(./renders/2D/sdl)
	target_link_libraries(NHE-base SDL-graphics)
else()
	add_subdirectory(./renders/2D/terminal)
	target_link_libraries(NHE-base Term-graphics)
endif()

