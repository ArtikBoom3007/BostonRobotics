#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow() = default;

private slots:
	void calculateForward();
	void validateThetaInput(QTableWidgetItem *item);

private:
	void setupTable();
	QTableWidget *thetaTable;
	QLabel *resultLabel;
};
#endif // MAINWINDOW_H
