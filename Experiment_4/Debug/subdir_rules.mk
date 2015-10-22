################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
cc2520ll.obj: ../cc2520ll.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g -O0 --define=__MSP430F5435__ --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Experiment_4/utils" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --silicon_errata=CPU22 --silicon_errata=CPU21 --silicon_errata=CPU15 --silicon_errata=CPU23 --silicon_errata=CPU18 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="cc2520ll.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

experiment_4.obj: ../experiment_4.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g -O0 --define=__MSP430F5435__ --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Experiment_4/utils" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --silicon_errata=CPU22 --silicon_errata=CPU21 --silicon_errata=CPU15 --silicon_errata=CPU23 --silicon_errata=CPU18 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="experiment_4.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

hal_cc2520.obj: ../hal_cc2520.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g -O0 --define=__MSP430F5435__ --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Experiment_4/utils" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --silicon_errata=CPU22 --silicon_errata=CPU21 --silicon_errata=CPU15 --silicon_errata=CPU23 --silicon_errata=CPU18 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="hal_cc2520.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

msp430_arch.obj: ../msp430_arch.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g -O0 --define=__MSP430F5435__ --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/msp430/include" --include_path="C:/Users/Joaquin/Documents/CodeComposer/Experiment_4/utils" --include_path="C:/Program Files (x86)/Texas Instruments/time_limited/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --silicon_errata=CPU22 --silicon_errata=CPU21 --silicon_errata=CPU15 --silicon_errata=CPU23 --silicon_errata=CPU18 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="msp430_arch.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


