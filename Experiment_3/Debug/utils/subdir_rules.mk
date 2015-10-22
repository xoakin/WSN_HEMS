################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utils/sense_utils.obj: ../utils/sense_utils.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g -O0 --define=__MSP430F5435__ --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Experiment_3/utils" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --silicon_errata=CPU22 --silicon_errata=CPU21 --silicon_errata=CPU15 --silicon_errata=CPU23 --silicon_errata=CPU18 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="utils/sense_utils.pp" --obj_directory="utils" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


