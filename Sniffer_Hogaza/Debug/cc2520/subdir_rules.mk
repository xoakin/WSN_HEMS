################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
cc2520/cc2520.obj: ../cc2520/cc2520.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="cc2520/cc2520.pp" --obj_directory="cc2520" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

cc2520/hal_cc2520.obj: ../cc2520/hal_cc2520.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="cc2520/hal_cc2520.pp" --obj_directory="cc2520" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


