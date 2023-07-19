#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

class Plotter : public QWidget
{
    Q_OBJECT

private:
    std::vector<double> times;
    std::vector<double> data;
    float time;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void pointEvent(QPaintEvent *event);
signals:

};

#endif // PLOTTER_H
