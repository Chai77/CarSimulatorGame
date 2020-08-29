################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/models/Model.cpp \
../src/models/TextureMesh.cpp 

OBJS += \
./src/models/Model.o \
./src/models/TextureMesh.o 

CPP_DEPS += \
./src/models/Model.d \
./src/models/TextureMesh.d 


# Each subdirectory must supply rules for building sources it contributes
src/models/%.o: ../src/models/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLEW/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/SOIL/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLFW/include" -I"/home/chaitanya/Documents/Projects/CarSimulatorGame/Dependencies/GLM/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


