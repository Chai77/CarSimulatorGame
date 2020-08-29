################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/renderEngine/DisplayManager.cpp \
../src/renderEngine/Renderer.cpp 

OBJS += \
./src/renderEngine/DisplayManager.o \
./src/renderEngine/Renderer.o 

CPP_DEPS += \
./src/renderEngine/DisplayManager.d \
./src/renderEngine/Renderer.d 


# Each subdirectory must supply rules for building sources it contributes
src/renderEngine/%.o: ../src/renderEngine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLEW/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/SOIL/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLFW/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLM/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


