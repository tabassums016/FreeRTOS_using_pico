# cmake_minimum_required(VERSION 3.13)

# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)

# # Initialise pico_sdk from installed location
# # (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "/home/tabassum/pico/pico-sdk")

# # Pull in Raspberry Pi Pico SDK (must be before project)
# include(pico_sdk_import.cmake)

# project(rp2040-freertos-projects C CXX ASM)

# # Initialise the Raspberry Pi Pico SDK
# pico_sdk_init()

# # Add executable. Default name is the project name, version 0.1

# # add_executable(FreeRTOStest FreeRTOStest.c )

# # pico_set_program_name(rp2040-freertos-projects "FreeRTOStest")
# # pico_set_program_version(rp2040-freertos-projects "0.1")

# pico_enable_stdio_uart(rp2040-freertos-projects 1)
# pico_enable_stdio_usb(rp2040-freertos-projects 0)

# # Add the standard library to the build
# # target_link_libraries(rp2040-freertos-projects pico_stdlib)

# # Add any user requested libraries
# # target_link_libraries(FreeRTOStest
# #         hardware_pio
# #         )

# pico_add_extra_outputs(rp2040-freertos-projects) 
 
 
 
 
 
 
 
 
 
cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

      include(pico_sdk_import.cmake)

      project(Pico-FreeRTOS)

      add_executable(blink
       main.c
        )

      pico_sdk_init()
   
      add_subdirectory(freertos)
      
     


      target_link_libraries(blink pico_stdlib freertos)
      pico_enable_stdio_uart(blink 0)
      pico_enable_stdio_usb(blink 1)

      pico_add_extra_outputs(blink)
