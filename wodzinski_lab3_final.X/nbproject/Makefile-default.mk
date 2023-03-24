#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o.d ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o.d ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o.d ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o.d ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o

# Source Files
SOURCEFILES=/Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c  .generated_files/flags/default/56a1fd9ae6d6ee088b7d155d4d35d49cf10f5849 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c  .generated_files/flags/default/3b5aa62a9a0123138ad117c47dbd75267cc755f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c  .generated_files/flags/default/c4cddccffd8317d3e09705014a8bc0a9b07a79d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c  .generated_files/flags/default/70332e7b2d18b8dabd21c7a91f4f6e581c357351 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c  .generated_files/flags/default/b6fc975dd677c21bbf33f7379ec767058ab67641 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_util.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_util.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c  .generated_files/flags/default/1817a9f2e2426ae853f9e151924a46b38d08db31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_keypad.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_keypad.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c  .generated_files/flags/default/954d7c5ae059a960ea3981ba430fb6d356f755d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_main.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c  .generated_files/flags/default/c5b35f728542833b2f3ec6e1fad41d891f6a923a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_display.c  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_display.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s  .generated_files/flags/default/5db354515a758369e760df6352e9aad5d606a666 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o: /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s  .generated_files/flags/default/58e26759fc73a93b7a2d95b3a70a9b4ae6962636 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2067379334" 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab3_final.X/wodzinski_lab3_asmlib.s  -o ${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/2067379334/wodzinski_lab3_asmlib.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/wodzinski_lab3_final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
