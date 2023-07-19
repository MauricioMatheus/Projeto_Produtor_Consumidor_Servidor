#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  public slots:

  void tcpConnect(); // Conexão com o servidor

  QString getHost(); // Usa o host fornecido pelo usuário, o utilizando na função tcpConnect

  void tcpDisconnect(); // Desconexão com o servidor

  void putData(); // Entrada de dados

  void stopData(); // Interrupção de dados

  void timerEvent(QTimerEvent *e); // Função utilizada para repetir o putData() tendo em vista a quantidade de milisegundos fornecidos pelo usuário

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int timer;
};

#endif // MAINWINDOW_H
