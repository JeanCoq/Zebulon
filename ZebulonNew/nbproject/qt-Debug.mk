#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/Zebulon
# Generated by qmake (2.01a) (Qt 4.7.2) on: mer. mars 7 15:17:17 2012
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -Inbproject -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = ClassPeriod.cpp \
		Group.cpp \
		Controller.cpp \
		TutorialClassroom.C \
		Student.cpp \
		main.cpp \
		Module.cpp \
		MagistralClass.cpp \
		Gui/QTimeSlot.cpp \
		PracticalClass.cpp \
		Classroom.cpp \
		sqlite/lib/sqlite3.c \
		LectureHall.C \
		Gui/QSchedule.cpp \
		TimeSlot.cpp \
		Schedule.cpp \
		TutorialClass.cpp \
		Date.cpp \
		Gui/WindowEditTimeSlot.cpp \
		PracticalClassroom.cpp \
		sqlite/Database.cpp \
		Gui/mainwindow.cpp moc_QSchedule.cpp \
		moc_mainwindow.cpp \
		moc_WindowEditTimeSlot.cpp \
		moc_QTimeSlot.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/ClassPeriod.o \
		build/Debug/GNU-Linux-x86/Group.o \
		build/Debug/GNU-Linux-x86/Controller.o \
		build/Debug/GNU-Linux-x86/TutorialClassroom.o \
		build/Debug/GNU-Linux-x86/Student.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/Module.o \
		build/Debug/GNU-Linux-x86/MagistralClass.o \
		build/Debug/GNU-Linux-x86/QTimeSlot.o \
		build/Debug/GNU-Linux-x86/PracticalClass.o \
		build/Debug/GNU-Linux-x86/Classroom.o \
		build/Debug/GNU-Linux-x86/sqlite3.o \
		build/Debug/GNU-Linux-x86/LectureHall.o \
		build/Debug/GNU-Linux-x86/QSchedule.o \
		build/Debug/GNU-Linux-x86/TimeSlot.o \
		build/Debug/GNU-Linux-x86/Schedule.o \
		build/Debug/GNU-Linux-x86/TutorialClass.o \
		build/Debug/GNU-Linux-x86/Date.o \
		build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o \
		build/Debug/GNU-Linux-x86/PracticalClassroom.o \
		build/Debug/GNU-Linux-x86/Database.o \
		build/Debug/GNU-Linux-x86/mainwindow.o \
		build/Debug/GNU-Linux-x86/moc_QSchedule.o \
		build/Debug/GNU-Linux-x86/moc_mainwindow.o \
		build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o \
		build/Debug/GNU-Linux-x86/moc_QTimeSlot.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = Zebulon
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/Zebulon

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_WindowEditTimeSlot.h ui_mainwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0 || $(MKDIR) nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents TutorialClassroom.h Gui/QSchedule.h Classroom.h TimeSlot.h Date.h PracticalClass.h Group.h PracticalClassroom.h sqlite/Database.h sqlite/lib/sqlite3.h Gui/mainwindow.h Student.h Gui/WindowEditTimeSlot.h TutorialClass.h LectureHall.h Schedule.h ClassPeriod.h MagistralClass.h Gui/QTimeSlot.h sqlite/lib/sqlite3ext.h Module.h Controller.h nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents ClassPeriod.cpp Group.cpp Controller.cpp TutorialClassroom.C Student.cpp main.cpp Module.cpp MagistralClass.cpp Gui/QTimeSlot.cpp PracticalClass.cpp Classroom.cpp sqlite/lib/sqlite3.c LectureHall.C Gui/QSchedule.cpp TimeSlot.cpp Schedule.cpp TutorialClass.cpp Date.cpp Gui/WindowEditTimeSlot.cpp PracticalClassroom.cpp sqlite/Database.cpp Gui/mainwindow.cpp nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents Gui/WindowEditTimeSlot.ui Gui/mainwindow.ui nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && (cd `dirname nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0` && $(TAR) Zebulon1.0.0.tar Zebulon1.0.0 && $(COMPRESS) Zebulon1.0.0.tar) && $(MOVE) `dirname nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0`/Zebulon1.0.0.tar.gz . && $(DEL_FILE) -r nbproject/build/Debug/GNU-Linux-x86/Zebulon1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_QSchedule.cpp moc_mainwindow.cpp moc_WindowEditTimeSlot.cpp moc_QTimeSlot.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_QSchedule.cpp moc_mainwindow.cpp moc_WindowEditTimeSlot.cpp moc_QTimeSlot.cpp
moc_QSchedule.cpp: Gui/QTimeSlot.h \
		Gui/QSchedule.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/QSchedule.h -o moc_QSchedule.cpp

moc_mainwindow.cpp: Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		ui_WindowEditTimeSlot.h \
		Controller.h \
		Student.h \
		PracticalClass.h \
		ClassPeriod.h \
		Group.h \
		TutorialClass.h \
		MagistralClass.h \
		Schedule.h \
		TimeSlot.h \
		Date.h \
		Classroom.h \
		Module.h \
		sqlite/Database.h \
		sqlite/lib/sqlite3.h \
		Gui/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/mainwindow.h -o moc_mainwindow.cpp

moc_WindowEditTimeSlot.cpp: ui_WindowEditTimeSlot.h \
		Gui/WindowEditTimeSlot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/WindowEditTimeSlot.h -o moc_WindowEditTimeSlot.cpp

moc_QTimeSlot.cpp: Gui/QTimeSlot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/QTimeSlot.h -o moc_QTimeSlot.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_WindowEditTimeSlot.h ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_WindowEditTimeSlot.h ui_mainwindow.h
ui_WindowEditTimeSlot.h: Gui/WindowEditTimeSlot.ui
	/usr/bin/uic-qt4 Gui/WindowEditTimeSlot.ui -o ui_WindowEditTimeSlot.h

ui_mainwindow.h: Gui/mainwindow.ui
	/usr/bin/uic-qt4 Gui/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/ClassPeriod.o: ClassPeriod.cpp ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ClassPeriod.o ClassPeriod.cpp

build/Debug/GNU-Linux-x86/Group.o: Group.cpp Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Group.o Group.cpp

build/Debug/GNU-Linux-x86/Controller.o: Controller.cpp Controller.h \
		Student.h \
		PracticalClass.h \
		ClassPeriod.h \
		Group.h \
		TutorialClass.h \
		MagistralClass.h \
		Schedule.h \
		TimeSlot.h \
		Date.h \
		Classroom.h \
		Module.h \
		sqlite/Database.h \
		sqlite/lib/sqlite3.h \
		LectureHall.h \
		PracticalClassroom.h \
		TutorialClassroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Controller.o Controller.cpp

build/Debug/GNU-Linux-x86/TutorialClassroom.o: TutorialClassroom.C TutorialClassroom.h \
		Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TutorialClassroom.o TutorialClassroom.C

build/Debug/GNU-Linux-x86/Student.o: Student.cpp Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Student.o Student.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		ui_WindowEditTimeSlot.h \
		Controller.h \
		Student.h \
		PracticalClass.h \
		ClassPeriod.h \
		Group.h \
		TutorialClass.h \
		MagistralClass.h \
		Schedule.h \
		TimeSlot.h \
		Date.h \
		Classroom.h \
		Module.h \
		sqlite/Database.h \
		sqlite/lib/sqlite3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/Module.o: Module.cpp Module.h \
		ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Module.o Module.cpp

build/Debug/GNU-Linux-x86/MagistralClass.o: MagistralClass.cpp MagistralClass.h \
		ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/MagistralClass.o MagistralClass.cpp

build/Debug/GNU-Linux-x86/QTimeSlot.o: Gui/QTimeSlot.cpp Gui/QTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/QTimeSlot.o Gui/QTimeSlot.cpp

build/Debug/GNU-Linux-x86/PracticalClass.o: PracticalClass.cpp PracticalClass.h \
		ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/PracticalClass.o PracticalClass.cpp

build/Debug/GNU-Linux-x86/Classroom.o: Classroom.cpp Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Classroom.o Classroom.cpp

build/Debug/GNU-Linux-x86/sqlite3.o: sqlite/lib/sqlite3.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/sqlite3.o sqlite/lib/sqlite3.c

build/Debug/GNU-Linux-x86/LectureHall.o: LectureHall.C LectureHall.h \
		Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/LectureHall.o LectureHall.C

build/Debug/GNU-Linux-x86/QSchedule.o: Gui/QSchedule.cpp Gui/QSchedule.h \
		Gui/QTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/QSchedule.o Gui/QSchedule.cpp

build/Debug/GNU-Linux-x86/TimeSlot.o: TimeSlot.cpp TimeSlot.h \
		Date.h \
		Classroom.h \
		ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TimeSlot.o TimeSlot.cpp

build/Debug/GNU-Linux-x86/Schedule.o: Schedule.cpp Schedule.h \
		TimeSlot.h \
		Date.h \
		Classroom.h \
		ClassPeriod.h \
		Group.h \
		Student.h \
		Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Schedule.o Schedule.cpp

build/Debug/GNU-Linux-x86/TutorialClass.o: TutorialClass.cpp TutorialClass.h \
		ClassPeriod.h \
		Group.h \
		Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TutorialClass.o TutorialClass.cpp

build/Debug/GNU-Linux-x86/Date.o: Date.cpp Date.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Date.o Date.cpp

build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o: Gui/WindowEditTimeSlot.cpp Gui/WindowEditTimeSlot.h \
		ui_WindowEditTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o Gui/WindowEditTimeSlot.cpp

build/Debug/GNU-Linux-x86/PracticalClassroom.o: PracticalClassroom.cpp PracticalClassroom.h \
		Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/PracticalClassroom.o PracticalClassroom.cpp

build/Debug/GNU-Linux-x86/Database.o: sqlite/Database.cpp sqlite/Database.h \
		sqlite/lib/sqlite3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Database.o sqlite/Database.cpp

build/Debug/GNU-Linux-x86/mainwindow.o: Gui/mainwindow.cpp Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		ui_WindowEditTimeSlot.h \
		Controller.h \
		Student.h \
		PracticalClass.h \
		ClassPeriod.h \
		Group.h \
		TutorialClass.h \
		MagistralClass.h \
		Schedule.h \
		TimeSlot.h \
		Date.h \
		Classroom.h \
		Module.h \
		sqlite/Database.h \
		sqlite/lib/sqlite3.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/mainwindow.o Gui/mainwindow.cpp

build/Debug/GNU-Linux-x86/moc_QSchedule.o: moc_QSchedule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_QSchedule.o moc_QSchedule.cpp

build/Debug/GNU-Linux-x86/moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_mainwindow.o moc_mainwindow.cpp

build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o: moc_WindowEditTimeSlot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o moc_WindowEditTimeSlot.cpp

build/Debug/GNU-Linux-x86/moc_QTimeSlot.o: moc_QTimeSlot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_QTimeSlot.o moc_QTimeSlot.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

