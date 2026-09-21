if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK is not set")
endif()

set(VITASDK "$ENV{VITASDK}")
include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Vita-MikuPan")
set(VITA_TITLEID "VMKP00001")
set(VITA_VERSION "01.00")

add_executable(MikuPan
    src/vita/main.cpp
)

target_compile_features(MikuPan PRIVATE cxx_std_20)
target_compile_definitions(MikuPan PRIVATE MIKUPAN_VITA=1)

target_include_directories(MikuPan PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/sdk"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_options(MikuPan PRIVATE
    -Wall
    -Wextra
    -Wno-psabi
)

target_link_libraries(MikuPan PRIVATE
    vitaGL
    mathneon
    vitaShaRK
    SceShaccCgExt
    taihen_stub
    SceShaccCg_stub
    SceKernelDmacMgr_stub
    SceGxm_stub
    SceDisplay_stub
    SceCtrl_stub
    SceAppMgr_stub
    SceCommonDialog_stub
    SceSysmodule_stub
    m
)

vita_create_self(MikuPan.self MikuPan UNSAFE)
vita_create_vpk(Vita-MikuPan.vpk ${VITA_TITLEID} MikuPan.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
)
