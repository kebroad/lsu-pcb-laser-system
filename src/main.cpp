// This file is a part of "Candle" application.
// Copyright 2015-2016 Hayrullin Denis Ravilevich

#include <QApplication>
#include <QDebug>
#include <QGLWidget>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QStyleFactory>
#include <QFontDatabase>
#include <QMessageBox>

#include "parser/gcodepreprocessorutils.h"
#include "parser/gcodeparser.h"
#include "parser/gcodeviewparse.h"

#include "frmmain.h"
#include "general/job.h"
#include "general/raster.h"
#include "general/loadingwidget.h"

#include <startingwidget.h>


int main(int argc, char *argv[])
{
#ifdef UNIX
    bool styleOverrided = false;
    for (int i = 0; i < argc; i++) if (QString(argv[i]).toUpper() == "-STYLE")
    {
        styleOverrided = true;
        break;
    }
#endif

    QApplication a(argc, argv);
#ifdef GLES
    QFontDatabase::addApplicationFont(":/fonts/Ubuntu-R.ttf");
#endif

    QGLFormat glf = QGLFormat::defaultFormat();
    glf.setSampleBuffers(true);
    glf.setSamples(8);

    QGLFormat::setDefaultFormat(glf);
    QString loc = QLocale().name().left(2);
    QString translationsFolder = qApp->applicationDirPath() + "/translations/";
    QString translationFileName = translationsFolder + qApp->applicationDisplayName() + "_" + loc + ".qm";

    qDebug() << "locale:" << loc;

    if(QFile::exists(translationFileName))
    {
        QTranslator* translator = new QTranslator();
        if (translator->load(translationFileName)) a.installTranslator(translator); else delete translator;
    }

    QString baseTranslationFileName = translationsFolder + "qt_" + loc + ".qm";

    if(QFile::exists(translationFileName))
    {
        QTranslator* baseTranslator = new QTranslator();

        if (baseTranslator->load(baseTranslationFileName))
        {
            a.installTranslator(baseTranslator);
        }
        else
        {
            delete baseTranslator;
        }
    }

    a.setApplicationVersion(APP_VERSION);

#ifdef UNIX
    if (!styleOverrided) foreach (QString str, QStyleFactory::keys())
    {
        qDebug() << "style" << str;
        if (str.contains("GTK+")) {
            a.setStyle(QStyleFactory::create(str));
            break;
        }
    }
#endif

#ifdef GLES
    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette palette;
    palette.setColor(QPalette::Highlight, QColor(204, 204, 254));
    palette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
    a.setPalette(palette);

    a.setStyleSheet("QWidget {font-family: \"Ubuntu\";}\
                    QMenuBar {background-color: #303030; padding-top: 2px; padding-bottom: 2px;}\
                    QMenuBar::item {spacing: 3px; padding: 2px 8px; background: transparent; color: white;}\
                    QMenuBar::item:pressed {border: 1px solid #505050; border-bottom: 1px; border-top-left-radius: 3px; border-top-right-radius: 3px; background: #404040; color: white;}\
                    QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white;}\
                    QDialog {border: 1px solid palette(mid);}");
#endif

    a.setStyleSheet(a.styleSheet() + "QWidget {font-size: 8pt}");

    Job * j = new Job;
    StartingWidget sw(NULL, j);
    int isacc = sw.exec();

    Raster r(j, 0.0508, CONSTANT_LASER_POWER_MODE, j->power, j->speed);

    LoadingWidget * load = new LoadingWidget;
    load->show();
    switch(j->job_type)
    {
    case TOP:
        j->top_gcode_data = r.hybridRoute(j->top);
        break;
    case TOP_SOL:
       j->top_gcode_data = r.isolateRoute(j->top);
       j->sol_top_gcode_data = r.isolateRoute(j->sol_top);

        break;
    case TOP_BOT:
        j->top_gcode_data = r.isolateRoute(j->top);
        j->bot_gcode_data = r.isolateRoute(j->bot);

        break;
    case TOP_BOT_SOL:
        j->top_gcode_data = r.hybridRoute(j->top);
        j->sol_top_gcode_data = r.hybridRoute(j->sol_top);
        j->bot_gcode_data = r.hybridRoute(j->bot);
        j->sol_bot_gcode_data = r.hybridRoute(j->sol_bot);

        break;
    }
    load->hide();
    frmMain* w = new frmMain(NULL,j);
        w->hide();
    if(isacc == QDialog::Accepted){

        w->show();
    }

    return a.exec();
}
