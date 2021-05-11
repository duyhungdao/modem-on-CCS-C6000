################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ISRs_talkthrough.obj: ../ISRs_talkthrough.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/bin/cl6x" -mv6740 -O3 --include_path="C:/ti/workspace_v7/modulate" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="ISRs_talkthrough.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LCDK_Support_DSP.obj: ../LCDK_Support_DSP.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/bin/cl6x" -mv6740 -O3 --include_path="C:/ti/workspace_v7/modulate" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="LCDK_Support_DSP.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main_talkthrough.obj: ../main_talkthrough.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/bin/cl6x" -mv6740 -O3 --include_path="C:/ti/workspace_v7/modulate" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="main_talkthrough.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

vectors_EDMA.obj: ../vectors_EDMA.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/bin/cl6x" -mv6740 -O3 --include_path="C:/ti/workspace_v7/modulate" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c6000_8.3.7/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="vectors_EDMA.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


