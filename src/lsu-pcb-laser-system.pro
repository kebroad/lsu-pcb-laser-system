#-------------------------------------------------
#
# Project created by QtCreator 2014-05-23T17:51:21
#
#-------------------------------------------------

QT       = core gui opengl serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32: {
    QT += winextras
    DEFINES += WINDOWS
    QMAKE_LFLAGS += "-Wl,--large-address-aware"
    QMAKE_CXXFLAGS_DEBUG += -g3 -pg
    QMAKE_LFLAGS_DEBUG += -pg -lgmon
}

unix:!macx {
    DEFINES += UNIX #GL_GLEXT_PROTOTYPES
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/libs\'"
}

contains(QT_CONFIG, opengles.) {
    warning("GL ES detected. VAO will be disabled.")
    DEFINES += GLES
    INSTALLS += target
    target.path = /home/pi
}

TARGET = "LSU PCB Laser System"
TEMPLATE = app
VERSION = 1.0.12
RC_ICONS += images/LSU_PCB_ICON.ico

DEFINES += sNan=\"65536\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

TRANSLATIONS += translations/candle_ru.ts translations/candle_es.ts translations/candle_fr.ts translations/candle_pt.ts

SOURCES += main.cpp\
        frmmain.cpp \
    frmsettings.cpp \
    frmabout.cpp \
    drawers/gcodedrawer.cpp \
    drawers/heightmapborderdrawer.cpp \
    drawers/heightmapgriddrawer.cpp \
    drawers/heightmapinterpolationdrawer.cpp \
    drawers/origindrawer.cpp \
    drawers/shaderdrawable.cpp \
    drawers/tooldrawer.cpp \
    drawers/selectiondrawer.cpp \
    parser/arcproperties.cpp \
    parser/gcodeparser.cpp \
    parser/gcodepreprocessorutils.cpp \
    parser/gcodeviewparse.cpp \
    parser/linesegment.cpp \
    parser/pointsegment.cpp \
    tables/gcodetablemodel.cpp \
    tables/heightmaptablemodel.cpp \
    widgets/colorpicker.cpp \
    widgets/combobox.cpp \
    widgets/groupbox.cpp \
    widgets/scrollarea.cpp \
    widgets/styledtoolbutton.cpp \
    widgets/widget.cpp \
    widgets/glwidget.cpp \
    boardlayout/boardview.cpp \
    boardlayout/boardlayoutwidget.cpp \
    boardlayout/boardselector.cpp \
    boardlayout/board.cpp \
    general/job.cpp \
    general/raster.cpp \
    dialogs/boardsize.cpp \
    startingwidget.cpp \
    dialogs/boardtype.cpp \
    general/layerselection.cpp

HEADERS  += frmmain.h \
    frmsettings.h \
    frmabout.h \
    drawers/gcodedrawer.h \
    drawers/heightmapborderdrawer.h \
    drawers/heightmapgriddrawer.h \
    drawers/heightmapinterpolationdrawer.h \
    drawers/origindrawer.h \
    drawers/shaderdrawable.h \
    drawers/tooldrawer.h \
    parser/arcproperties.h \
    parser/gcodeparser.h \
    parser/gcodepreprocessorutils.h \
    parser/gcodeviewparse.h \
    parser/linesegment.h \
    parser/pointsegment.h \
    tables/gcodetablemodel.h \
    tables/heightmaptablemodel.h \
    utils/interpolation.h \
    utils/util.h \
    widgets/colorpicker.h \
    widgets/combobox.h \
    widgets/groupbox.h \
    widgets/scrollarea.h \
    widgets/styledtoolbutton.h \
    widgets/widget.h \
    widgets/glwidget.h \
    drawers/selectiondrawer.h \
    boardlayout/boardview.h \
    boardlayout/boardlayoutwidget.h \
    boardlayout/boardselector.h \
    boardlayout/board.h \
    general/job.h \
    general/raster.h \
    dialogs/boardsize.h \
    startingwidget.h \
    dialogs/boardtype.h \
    general/layerselection.h

FORMS    += frmmain.ui \
    frmsettings.ui \
    frmabout.ui

DEFINES += _USE_MATH_DEFINES

RESOURCES += \
    shaders.qrc \
    images.qrc

CONFIG += c++11

DISTFILES +=