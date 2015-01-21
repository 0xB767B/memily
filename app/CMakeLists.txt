include_directories(../inc)

#find_library(MemilyLibrary memily)

set(AppSources 
    ./Main.cpp
   )

set(STM32_LINKER_SCRIPT ../ldscripts/stm32f103rb.ld)
add_executable(memilyapp ${AppSources})
#target_link_libraries(memilyapp ${MemilyLibrary})
target_link_libraries(memilyapp memily)
#STM32_SET_TARGET_PROPERTIES(fOoBaR)