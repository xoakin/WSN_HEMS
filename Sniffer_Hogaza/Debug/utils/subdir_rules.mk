################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utils/buttons.obj: ../utils/buttons.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="utils/buttons.pp" --obj_directory="utils" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

utils/leds.obj: ../utils/leds.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="utils/leds.pp" --obj_directory="utils" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

utils/msp430_arch.obj: ../utils/msp430_arch.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="utils/msp430_arch.pp" --obj_directory="utils" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

utils/sense_utils.obj: ../utils/sense_utils.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Sniffer_Hogaza" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="utils/sense_utils.pp" --obj_directory="utils" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


