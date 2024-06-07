#include <QApplication>
#include <QGraphicsScene>
#include "Jugador.h"
#include "obstaculo.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear escena
    QGraphicsScene * scene = new QGraphicsScene();

    // Crear un elemento en la escena
    Jugador * jugador = new Jugador();
    /*Parametros:
     * 1 y 2: Ubicacion Esquina superior izquierda
     * 2 y 3: Ancho y alto
/*/
    jugador->setRect(0,0,100,100);

    // Añadir elementos en la escena
    scene->addItem(jugador);

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();

    // Agregar un view
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    // view->setFixedSize(1200,600);
    scene->setSceneRect(0,0,1200,600);

    jugador->setPos(scene->height()/2,scene->height() - jugador->rect().height());

    return a.exec();
}
