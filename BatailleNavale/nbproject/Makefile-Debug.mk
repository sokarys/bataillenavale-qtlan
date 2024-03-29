#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++
CXX=g++
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Controller.o \
	${OBJECTDIR}/BateauCase.o \
	${OBJECTDIR}/InterfaceConsole.o \
	${OBJECTDIR}/Plateau.o \
	${OBJECTDIR}/Bateau.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/JoueurPlateau.o \
	${OBJECTDIR}/Historique.o \
	${OBJECTDIR}/Bonus.o \
	${OBJECTDIR}/BateauCaseBonus.o \
	${OBJECTDIR}/BonusManager.o \
	${OBJECTDIR}/BateauCasePleine.o \
	${OBJECTDIR}/ControlPlacementBonus.o \
	${OBJECTDIR}/Interface.o \
	${OBJECTDIR}/Partie.o \
	${OBJECTDIR}/Joueur.o \
	${OBJECTDIR}/PorteAvions.o \
	${OBJECTDIR}/BateauCaseVide.o \
	${OBJECTDIR}/ControlPlacementBateau.o \
	${OBJECTDIR}/Croiseur.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m32 -Wextra
CXXFLAGS=-m32 -Wextra

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bataillenavale.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bataillenavale.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bataillenavale ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Controller.o: Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Controller.o Controller.cpp

${OBJECTDIR}/BateauCase.o: BateauCase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BateauCase.o BateauCase.cpp

${OBJECTDIR}/InterfaceConsole.o: InterfaceConsole.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/InterfaceConsole.o InterfaceConsole.cpp

${OBJECTDIR}/Plateau.o: Plateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Plateau.o Plateau.cpp

${OBJECTDIR}/Bateau.o: Bateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bateau.o Bateau.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/JoueurPlateau.o: JoueurPlateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoueurPlateau.o JoueurPlateau.cpp

${OBJECTDIR}/Historique.o: Historique.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Historique.o Historique.cpp

${OBJECTDIR}/Bonus.o: Bonus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bonus.o Bonus.cpp

${OBJECTDIR}/BateauCaseBonus.o: BateauCaseBonus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BateauCaseBonus.o BateauCaseBonus.cpp

${OBJECTDIR}/BonusManager.o: BonusManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BonusManager.o BonusManager.cpp

${OBJECTDIR}/BateauCasePleine.o: BateauCasePleine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BateauCasePleine.o BateauCasePleine.cpp

${OBJECTDIR}/ControlPlacementBonus.o: ControlPlacementBonus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ControlPlacementBonus.o ControlPlacementBonus.cpp

${OBJECTDIR}/Interface.o: Interface.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Interface.o Interface.cpp

${OBJECTDIR}/Partie.o: Partie.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Partie.o Partie.cpp

${OBJECTDIR}/Joueur.o: Joueur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Joueur.o Joueur.cpp

${OBJECTDIR}/PorteAvions.o: PorteAvions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PorteAvions.o PorteAvions.cpp

${OBJECTDIR}/BateauCaseVide.o: BateauCaseVide.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BateauCaseVide.o BateauCaseVide.cpp

${OBJECTDIR}/ControlPlacementBateau.o: ControlPlacementBateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ControlPlacementBateau.o ControlPlacementBateau.cpp

${OBJECTDIR}/Croiseur.o: Croiseur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Croiseur.o Croiseur.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bataillenavale.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
