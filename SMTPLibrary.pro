#DEFINES += isApplication

contains(DEFINES, isApplication){
    message( "Application" )
    #add openssll libray
    unix:!macx: LIBS += -L$$PWD/libs/openssl/linux64/lib/ -ltls
    unix:!macx: PRE_TARGETDEPS += $$PWD/libs/openssl/linux64/lib/libtls.a
    INCLUDEPATH += $$PWD/libs/openssl/linux64/include
    DEPENDPATH += $$PWD/libs/openssl/linux64/include

    ####App
    TEMPLATE = app
    CONFIG += console
    CONFIG -= app_bundle
    CONFIG -= qt
    TARGET = SMTPLibrary.run

} else {
    message( "Library" )
    ####Library
    TEMPLATE = lib
    CONFIG -= qt
    DEFINES += libSMTP
    TARGET = libSMTP
    CONFIG += staticlib
}

#includs source
INCLUDEPATH += $$PWD/./src
DEPENDPATH += $$PWD/./src


CONFIG(release, debug|release) {
    LIBS += -pthread -static --static
    message( "release static mod" )
} else  {
    message( "debug mod" )
}

DESTDIR=../bin
OBJECTS_DIR=../objs
MOC_DIR=../moc

SOURCES += \
	main.cpp \
	src/clsSMTPClient.cpp \
	src/smtp.c

HEADERS += \
    src/clsSMTPClient.h \
    src/smtp.h

#for Install library#
target.path = /usr/lib/
INSTALLS += target

headers.files += $$HEADERS
headers.path = /usr/include/SMTPLibrary
INSTALLS += headers

