#include "MainWindow.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "Course.h"
#include "Graph.h"
#include "Scheduler.h"
#include "TimeSlot.h"

namespace
{
QString dataFilePath(const QString &fileName)
{
    const QString projectPath = QDir::current().filePath("backend/data/" + fileName);
    if (QFileInfo::exists(projectPath))
    {
        return projectPath;
    }

    return QDir(QCoreApplication::applicationDirPath()).filePath("data/" + fileName);
}
} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scheduleTable_(new QTableWidget(this)), statusLabel_(new QLabel(this))
{
    setWindowTitle(tr("Xếp lịch học"));
    resize(920, 560);

    auto *content = new QWidget(this);
    auto *layout = new QVBoxLayout(content);

    auto *title = new QLabel(tr("Xếp lịch từ file dữ liệu"), content);
    title->setStyleSheet("font-size: 22px; font-weight: 600;");
    layout->addWidget(title);

    auto *description = new QLabel(
        tr("Đặt Course.txt và TimeSlot.txt trong backend/data, sau đó bấm nút để tạo lịch."),
        content);
    description->setWordWrap(true);
    layout->addWidget(description);

    auto *reloadButton = new QPushButton(tr("Tải dữ liệu và xếp lịch"), content);
    connect(reloadButton, &QPushButton::clicked, this, &MainWindow::loadSchedule);
    layout->addWidget(reloadButton);

    scheduleTable_->setColumnCount(6);
    scheduleTable_->setHorizontalHeaderLabels(
        {tr("Môn học"), tr("Số tiết/tuần"), tr("Thứ"), tr("Tiết"), tr("Bắt đầu"), tr("Kết thúc")});
    scheduleTable_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    scheduleTable_->setSelectionBehavior(QAbstractItemView::SelectRows);
    scheduleTable_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(scheduleTable_);

    statusLabel_->setWordWrap(true);
    layout->addWidget(statusLabel_);

    setCentralWidget(content);
    loadSchedule();
}

void MainWindow::loadSchedule()
{
    const QString coursesPath = dataFilePath("Course.txt");
    const QString timeSlotsPath = dataFilePath("TimeSlot.txt");

    if (!QFileInfo::exists(coursesPath) || !QFileInfo::exists(timeSlotsPath))
    {
        scheduleTable_->setRowCount(0);
        const QString message = tr("Không tìm thấy Course.txt hoặc TimeSlot.txt trong backend/data (hoặc data cạnh file .exe).");
        statusLabel_->setText(message);
        QMessageBox::warning(this, tr("Thiếu dữ liệu"), message);
        return;
    }

    Course courses[MAX_COURSE];
    TimeSlot timeSlots[MAX_TIMESLOT];
    int courseCount = 0;
    int timeSlotCount = 0;

    const QByteArray coursesPathBytes = QFile::encodeName(coursesPath);
    const QByteArray timeSlotsPathBytes = QFile::encodeName(timeSlotsPath);
    InputCourses(coursesPathBytes.constData(), courses, courseCount);
    InputTimeSlots(timeSlotsPathBytes.constData(), timeSlots, timeSlotCount);

    if (courseCount == 0 || timeSlotCount == 0)
    {
        scheduleTable_->setRowCount(0);
        statusLabel_->setText(tr("File dữ liệu không có dòng hợp lệ để xếp lịch."));
        return;
    }

    Graph graph;
    InitGraph(graph, courseCount);
    for (int firstCourse = 0; firstCourse < courseCount; ++firstCourse)
    {
        for (int secondCourse = firstCourse + 1; secondCourse < courseCount; ++secondCourse)
        {
            AddEdge(graph, firstCourse, secondCourse);
        }
    }

    int colors[MAX_COURSE];
    Schedule schedules[MAX_COURSE];
    ColoringGraph(graph, colors);
    CreateSchedule(courseCount, timeSlotCount, colors, schedules);

    scheduleTable_->setRowCount(courseCount);
    int unscheduledCount = 0;
    for (int row = 0; row < courseCount; ++row)
    {
        const int timeSlotIndex = schedules[row].timeSlotIndex;
        scheduleTable_->setItem(row, 0, new QTableWidgetItem(QString::fromLocal8Bit(courses[row].name)));
        scheduleTable_->setItem(row, 1, new QTableWidgetItem(QString::number(courses[row].periods)));

        if (timeSlotIndex < 0)
        {
            ++unscheduledCount;
            scheduleTable_->setItem(row, 2, new QTableWidgetItem(tr("Chưa xếp được")));
            for (int column = 3; column < 6; ++column)
            {
                scheduleTable_->setItem(row, column, new QTableWidgetItem("-"));
            }
            continue;
        }

        const TimeSlot &slot = timeSlots[timeSlotIndex];
        scheduleTable_->setItem(row, 2, new QTableWidgetItem(QString::fromLocal8Bit(slot.day)));
        scheduleTable_->setItem(row, 3, new QTableWidgetItem(QString::number(slot.period)));
        scheduleTable_->setItem(row, 4, new QTableWidgetItem(QString::fromLocal8Bit(slot.start)));
        scheduleTable_->setItem(row, 5, new QTableWidgetItem(QString::fromLocal8Bit(slot.end)));
    }

    QString status = tr("Đã đọc %1 môn học và %2 khung giờ. Dùng tô màu tham lam để xếp lịch.")
                         .arg(courseCount)
                         .arg(timeSlotCount);
    if (unscheduledCount > 0)
    {
        status += tr(" %1 môn chưa xếp được vì thiếu khung giờ.").arg(unscheduledCount);
    }
    statusLabel_->setText(status);
}
