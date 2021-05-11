################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
modem/modem.obj: ../modem/modem.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/bin/cl6x" -mv6740 -O3 --include_path="C:/ti/workspace_v7/demodulate" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="modem/modem.d_raw" --obj_directory="modem" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


