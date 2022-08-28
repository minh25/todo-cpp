add_executable(todo
    main.cpp
)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(todo PRIVATE unofficial::sqlite3::sqlite3)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(todo PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

find_package(SqliteOrm CONFIG REQUIRED)
target_link_libraries(todo PRIVATE sqlite_orm::sqlite_orm)