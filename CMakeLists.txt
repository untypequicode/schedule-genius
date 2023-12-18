cmake_minimum_required(VERSION 3.22)
project(Schedule_Genius)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(Schedule_Genius src/main.cpp
    # Headers
        ## Lib
            src/lib/generateur_csv.h
            src/lib/fichier.h
            src/lib/import.h
            src/lib/generation_groupes.h

            ### Tab_dyn
                src/lib/tab_dyn/tab_dyn.h

            ### Dict_dyn
                src/lib/dict_dyn/dict_dyn.h

            ### Character
                src/lib/character/eleves.h
                src/lib/character/matieres.h
                src/lib/character/profs.h
                src/lib/character/salles.h
                src/lib/character/matieres_temp.h
                src/lib/character/groupes.h

            ### Database
                src/lib/database/database.h

    # Sources
        ## Lib
            src/lib/generateur_csv.cpp
            src/lib/fichier.cpp
            src/lib/import.cpp

            ### Tab_dyn
                src/lib/tab_dyn/tab_dyn.cpp
                src/lib/tab_dyn/tab_dyn_char.cpp
                src/lib/tab_dyn/tab_dyn_string.cpp
                src/lib/tab_dyn/tab_dyn_double.cpp
                src/lib/tab_dyn/tab_dyn_int_unsigned.cpp
                src/lib/tab_dyn/tab_dyn_int.cpp
                src/lib/tab_dyn/tab_dyn_float.cpp
                src/lib/tab_dyn/tab_dyn_matieres.cpp
                src/lib/tab_dyn/tab_dyn_eleves.cpp
                src/lib/tab_dyn/tab_dyn_groupes.cpp
                src/lib/tab_dyn/tab_dyn_profs.cpp
                src/lib/tab_dyn/tab_dyn_salles.cpp

            ### Dict_dyn
                src/lib/dict_dyn/dict_dyn.cpp
                src/lib/dict_dyn/dict_dyn_char_double.cpp
                src/lib/dict_dyn/dict_dyn_char_int.cpp
                src/lib/dict_dyn/dict_dyn_int_unsigned_string.cpp
                src/lib/dict_dyn/dict_dyn_int_unsigned_eleves.cpp

            ### Character
                src/lib/character/eleves.cpp
                src/lib/character/matieres.cpp
                src/lib/character/profs.cpp
                src/lib/character/salles.cpp
                src/lib/character/matieres_temp.cpp
                src/lib/character/groupes.cpp

            ### Database
                src/lib/database/database.cpp

            ## Generation
                src/lib/generation_groupes.cpp
)
