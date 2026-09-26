add_executable(OptimalSchedule
    src/main.cpp
    src/Course.cpp
    src/TimeSlot.cpp
    src/Graph.cpp
    src/Scheduler.cpp
)

target_include_directories(OptimalSchedule PRIVATE
    include
)