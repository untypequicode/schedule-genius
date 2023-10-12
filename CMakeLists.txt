cmake_minimum_required(VERSION 3.26)
project(Schedule_Genius)

set(CMAKE_CXX_STANDARD 23)

add_executable(Schedule_Genius src/main.cpp
        src/lib/character/eleves.cpp
        src/lib/character/eleves.h
        src/lib/fichier.cpp
        src/lib/fichier.h
        src/lib/generateur_csv.cpp
        src/lib/generateur_csv.h
        src/lib/generation_groupes.cpp
        src/lib/generation_groupes.h
        src/lib/import.cpp
        src/lib/import.h
        src/lib/dict_dyn/dict_dyn.cpp
        src/lib/dict_dyn/dict_dyn.h
        src/lib/tab_dyn/tab_dyn.cpp
        src/lib/tab_dyn/tab_dyn.h
        src/lib/tab_dyn/tab_dyn_char.cpp
        src/lib/tab_dyn/tab_dyn_eleve.cpp
        src/lib/tab_dyn/tab_dyn_int.cpp
        src/lib/tab_dyn/tab_dyn_string.cpp
        src/lib/character/matieres.cpp
        src/lib/character/matieres.h
        src/lib/database/database.cpp
        src/lib/database/database.h
        src/lib/character/prof.cpp
        src/lib/character/prof.h
)
