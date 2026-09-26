add_executable(OptimalSchedule
    src/main.cpp
    src/MainWindow.cpp
    src/Course.cpp
    src/TimeSlot.cpp
    src/Graph.cpp
    src/Scheduler.cpp
)

target_include_directories(OptimalSchedule PRIVATE
    include
)

target_link_libraries(OptimalSchedule PRIVATE Qt6::Widgets)

if(MSVC)
    target_compile_options(OptimalSchedule PRIVATE /W4 /permissive-)
endif()

add_custom_command(TARGET OptimalSchedule POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:OptimalSchedule>/data"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/data"
        "$<TARGET_FILE_DIR:OptimalSchedule>/data"
)

if(WIN32)
    get_filename_component(QT_ROOT_DIR "${Qt6_DIR}/../../.." ABSOLUTE)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt
        HINTS "${QT_ROOT_DIR}/bin"
        REQUIRED
        NO_DEFAULT_PATH
    )

    add_custom_command(TARGET OptimalSchedule POST_BUILD
        COMMAND "${WINDEPLOYQT_EXECUTABLE}" --no-translations --no-compiler-runtime
            "$<TARGET_FILE:OptimalSchedule>"
    )
endif()
