#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{

}

void Plotter::pointEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,100)); // Brush cor amarela e sólida
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,0,0)); // Caneta cor vermelha
    pen.setWidth(2);

    painter.setBrush(brush); // Informa ao pintor qual o brush atual
    painter.setPen(pen); // Informa ao pintor qual a caneta atual

    painter.drawRect(0,0,width(), height()); // Desenha um retângulo abrangendo toda a extensão

    pen.setColor (QColor(0,0,255)); //Traçando o gráfico
    painter.setPen(pen);

}
