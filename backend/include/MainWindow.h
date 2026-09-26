#pragma once

#include <QMainWindow>

class QLabel;
class QTableWidget;

class MainWindow final : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void loadSchedule();

    QTableWidget *scheduleTable_;
    QLabel *statusLabel_;
};
