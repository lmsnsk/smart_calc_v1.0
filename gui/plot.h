#ifndef PLOT_H
#define PLOT_H

#include <locale.h>
#include <stdio.h>

#include <QIcon>
#include <QPainter>
#include <QValidator>
#include <QWidget>

namespace Ui {
class Plot;
}

class Plot : public QWidget {
  Q_OBJECT

 protected:
  void paintEvent(QPaintEvent *event);

 public:
  explicit Plot(QWidget *parent = nullptr);
  ~Plot();

 public slots:
  void slot_plot(QString str);

private slots:
  void on_updatePlot_clicked();

private:
  QString check;
  double ran_x_l;
  double ran_x_r;
  char *input_plot_str;
  void axies_and_graph(QPainter *p, double center_x, double center_y, double *i,
                       double scale_x, double interval_grid_step, int step);
  Ui::Plot *ui;
};

#endif  // PLOT_H
