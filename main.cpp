#include <QApplication>
#include <QQmlApplicationEngine>
#include "sudokugamer.h"
#include <QQmlContext>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    app.setWindowIcon(QIcon("://app_sudoku.ico"));

    QObject *root = engine.rootObjects()[0];
    SudokuGamer gamer(root);
    engine.rootContext()->setContextProperty("_sudoku_gamer", &gamer);

    return app.exec();
}
