#include <QGraphicsView>
#include <QTimer>
#include <QAction>
#include <QMenubar>
#include <QApplication>
#include <QMessageBox>

#include "constants.h"
#include "gamecontroller.h"
#include "mainwindow.h"

#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(*scene, this))
{
    setCentralWidget(view);
    setFixedSize(800, 800);

    setWindowIcon(QIcon(":/images/snake_ico"));

    createActions();
    createMenus();

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::createActions()
{
    newGameAction = new QAction(tr("&New Game"), this);
    newGameAction->setShortcut(QKeySequence::New);
    newGameAction->setStatusTip(tr("Start a new game"));
    connect(newGameAction, &QAction::triggered, this, &MainWindow::newGame);

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the game"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    pauseAction = new QAction(tr("&Pause"), this);
    pauseAction->setStatusTip(tr("Pause..."));
    connect(pauseAction, &QAction::triggered, game, &GameController::pause);

    resumeAction = new QAction(tr("&Resume"), this);
    resumeAction->setStatusTip(tr("Resume..."));
    connect(resumeAction, &QAction::triggered, game, &GameController::resume);

    gameHelpAction = new QAction(tr("Game &Help"), this);
    gameHelpAction->setShortcut(tr("ctrl+H"));
    gameHelpAction->setStatusTip(tr("Help on this game"));
    connect(gameHelpAction, &QAction::triggered, this, &MainWindow::gameHelp);

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's about box"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::about);

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, &QAction::triggered, qApp, QApplication::aboutQt);
}

void MainWindow::createMenus()
{
    QMenu *options = menuBar()->addMenu(tr("&Options"));
    options->addAction(newGameAction);
    options->addSeparator();
    options->addAction(pauseAction);
    options->addAction(resumeAction);
    options->addSeparator();
    options->addAction(exitAction);

    QMenu *help = menuBar()->addMenu(tr("&Help"));
    help->addAction(gameHelpAction);
    help->addAction(aboutAction);
    help->addAction(aboutQtAction);
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));
}

void MainWindow::newGame()
{
    QTimer::singleShot(0, game, SLOT(gameOver()));
}

void MainWindow::about()
{

}

void MainWindow::gameHelp()
{

}


