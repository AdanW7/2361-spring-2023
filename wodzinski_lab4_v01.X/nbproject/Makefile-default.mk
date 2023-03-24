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
FINAL_IMAGE=${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o.d ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o.d ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o

# Source Files
SOURCEFILES=/Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c  .generated_files/flags/default/eb952854728ca0827fbac16d735109a44dad748 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c  -o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c  .generated_files/flags/default/582f65f62325f38bd836d14f62183fbbfdd7dc30 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c  -o ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c  .generated_files/flags/default/dfa4f036fbb06c513ba2f24a31eb0e1a20e02121 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_main.c  -o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c  .generated_files/flags/default/90c2cf4d306c6acabb21c56e7695849467794a19 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinki_lab4_utility.c  -o ${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1903789192/wodzinki_lab4_utility.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s  .generated_files/flags/default/d3fe776dc6e99dc809b5ffac9c5736146bc19eaa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s  -o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o: /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s  .generated_files/flags/default/3e29c6e8a00d62cb9bc4b9c204a95b27bcf50ae6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1903789192" 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /Users/adan/MPLABXProjects/wodzinski_lab4_v01.X/wodzinski_lab4_asmlib.s  -o ${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1903789192/wodzinski_lab4_asmlib.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/wodzinski_lab4_v01.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
