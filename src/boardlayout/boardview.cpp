#include "boardview.h"

BoardView1::BoardView1(Job* j, QWidget *parent) : QWidget(parent)
{
    layers = new QTabWidget(this);
    top_view = new QGraphicsView;
    top_scene = new QGraphicsScene;
    job = j;


    QPen pen(Qt::darkMagenta, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    top_scene->setSceneRect(j->origin.x(), j->origin.y(),j->border_width, j->border_height);
    //top_scene->addRect(this->job->border->toRect());
    top_scene->addRect(this->job->border->toRect(), pen, Qt::NoBrush);
    top_view->setScene(top_scene);
    top_view->fitInView(top_view->sceneRect(), Qt::KeepAspectRatio);

    layers->addTab(top_view, tr("Top Copper"));
    layers->adjustSize();

}

void BoardView1::addBoard(Board1* board){
    top_scene->addItem(board);
}

void BoardView1::removeBoard(Board1 *board){
    top_scene->removeItem(board);
}

QImage BoardView1::publishLayout(){
    this->top_scene->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(top_scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    top_scene->render(&painter);
    return image;
}

/**********************************************************/

BoardView2::BoardView2(Job* j, QWidget * parent) : QWidget(parent){
    job =j;
    layers = new QTabWidget(this);

    top_view = new QGraphicsView;
    sol_top_view = new QGraphicsView;

    top_scene = new QGraphicsScene;
    sol_top_scene = new QGraphicsScene;

    QPen pen(Qt::darkMagenta, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    top_scene->setSceneRect(job->origin.x(), job->origin.y(),job->border_width, job->border_height );
    top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    top_view->setScene(top_scene);
    top_view->fitInView(top_view->sceneRect(), Qt::KeepAspectRatio);

    sol_top_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    sol_top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    sol_top_view->setScene(sol_top_scene);
    sol_top_view->fitInView(sol_top_view->sceneRect(), Qt::KeepAspectRatio);

    layers->addTab(top_view, tr("Top Copper"));
    layers->addTab(sol_top_view, tr("Top Solder Mask"));
}

void BoardView2::addBoard(Board2* board){
    top_scene->addItem(board);
    sol_top_scene->addItem(board->sol_top);
}

void BoardView2::removeBoard(Board2 *board){
    top_scene->removeItem(board);
    sol_top_scene->removeItem(board->sol_top);
}

QImage BoardView2::publishLayoutTop(){
    this->top_scene->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(top_scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    top_scene->render(&painter);
    return image;
}

QImage BoardView2::publishLayoutSolTop(){
    this->sol_top_scene->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->sol_top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(sol_top_scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    sol_top_scene->render(&painter);
    return image;
}
/**********************************************************/

BoardView3::BoardView3(Job* j, QWidget * parent) : QWidget(parent){
    job = j;
    layers = new QTabWidget(this);

    top_view = new QGraphicsView;
    bot_view = new QGraphicsView;

    top_scene = new QGraphicsScene;
    bot_scene = new QGraphicsScene;


    QPen pen(Qt::darkMagenta, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    top_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    top_view->setScene(top_scene);
    top_view->fitInView(top_view->sceneRect(), Qt::KeepAspectRatio);

    bot_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    bot_view->scale(-1,1);
    bot_view->setScene(bot_scene);
    bot_view->fitInView(bot_view->sceneRect(), Qt::KeepAspectRatio);


    layers->addTab(top_view, tr("Top Copper"));
    layers->addTab(bot_view, tr("Bottom Copper"));
}

void BoardView3::addBoard(Board3* board){
    top_scene->addItem(board);
    bot_scene->addItem(board->bot);
}

void BoardView3::removeBoard(Board3 *board){
    top_scene->removeItem(board);
    bot_scene->removeItem(board->bot);
}

QImage BoardView3::publishLayoutTop(){
    this->top_view->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(top_view->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    top_scene->render(&painter);
    return image;
}

QImage BoardView3::publishLayoutBot(){
    this->bot_view->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(bot_view->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    bot_view->render(&painter);
    return image;
}


BoardView4::BoardView4(Job * j, QWidget * parent) : QWidget(parent){
    job = j;
    layers = new QTabWidget(this);

    top_view = new QGraphicsView;
    bot_view = new QGraphicsView;
    sol_top_view = new QGraphicsView;
    sol_bot_view = new QGraphicsView;

    top_scene = new QGraphicsScene;
    bot_scene = new QGraphicsScene;
    sol_top_scene = new QGraphicsScene;
    sol_bot_scene = new QGraphicsScene;


    QPen pen(Qt::darkMagenta, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    top_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width,job->border_height );
    top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    top_view->setScene(top_scene);
    top_view->fitInView(top_view->sceneRect(), Qt::KeepAspectRatio);

    bot_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    bot_view->setScene(bot_scene);
    bot_view->fitInView(bot_view->sceneRect(), Qt::KeepAspectRatio);

    sol_top_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    sol_top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    sol_top_view->setScene(sol_top_scene);
    sol_top_view->fitInView(sol_top_view->sceneRect(), Qt::KeepAspectRatio);

    sol_bot_scene->setSceneRect(this->job->origin.x(), this->job->origin.y(),job->border_width, job->border_height );
    sol_bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    sol_bot_view->setScene(sol_bot_scene);
    sol_bot_view->fitInView(sol_bot_view->sceneRect(), Qt::KeepAspectRatio);




    top_view->setScene(top_scene);
    bot_view->setScene(bot_scene);
    sol_top_view->setScene(sol_top_scene);
    sol_bot_view->setScene(sol_bot_scene);

    bot_view->scale(-1,1);
    sol_bot_view->scale(-1,1);

    layers->addTab(top_view, tr("Top Copper"));
    layers->addTab(bot_view, tr("Bottom Copper"));
    layers->addTab(sol_top_view, tr("Top Solder Mask"));
    layers->addTab(sol_bot_view, tr("Bottom Solder Mask"));
}

void BoardView4::addBoard(Board4* board){
    top_scene->addItem(board);
    bot_scene->addItem(board->bot);
    sol_top_scene->addItem(board->sol_top);
    sol_bot_scene->addItem(board->sol_bot);
}

void BoardView4::removeBoard(Board4 *board){
    top_scene->removeItem(board);
    bot_scene->removeItem(board->bot);
    sol_top_scene->removeItem(board->sol_top);
    sol_bot_scene->removeItem(board->sol_bot);
}

QImage BoardView4::publishLayoutTop(){
    this->top_view->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(top_view->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    top_view->render(&painter);
    return image;
}

QImage BoardView4::publishLayoutBot(){
    this->bot_view->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(bot_view->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    bot_view->render(&painter);
    return image;
}

QImage BoardView4::publishLayoutSolTop(){
    this->sol_top_scene->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->sol_top_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(sol_top_scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    sol_top_scene->render(&painter);
    return image;
}

QImage BoardView4::publishLayoutSolBot(){
    this->sol_bot_view->setSceneRect(job->border->toRect());
    QPen pen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    this->sol_bot_scene->addRect(job->border->toRect(), pen, Qt::NoBrush);
    QImage image(sol_bot_view->sceneRect().size().toSize(), QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    sol_bot_view->render(&painter);
    return image;
}
