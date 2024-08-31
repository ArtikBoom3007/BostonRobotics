#include "kinematics.h"
#include "mainwindow.h"
#include "parameters.h"

#include <Eigen/Dense>
#include <QHeaderView>
#include <QMessageBox>
#include <QPushButton>
#include <QScreen>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent)
{
	QWidget *centralWidget = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout(centralWidget);

	thetaTable = new QTableWidget(6, 4, this);
	thetaTable->setHorizontalHeaderLabels({"Theta (deg)", "a(m)", "d(m)", "alpha(rad)"});
	thetaTable->verticalHeader()->setVisible(true);
	layout->addWidget(thetaTable);
	
	setupTable();
	
	QPushButton *calcButton = new QPushButton("Calculate", this);
	layout->addWidget(calcButton);
	
	resultLabel = new QLabel("Result: ", this);
	layout->addWidget(resultLabel);
	
	setCentralWidget(centralWidget);
	
	adjustSize();
	
	connect(calcButton, &QPushButton::clicked, this, &MainWindow::calculateForward);
	connect(thetaTable, &QTableWidget::itemChanged, this, &MainWindow::validateThetaInput);
}

void MainWindow::setupTable()
{
	thetaTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	thetaTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	thetaTable->setMinimumHeight(214);
	thetaTable->setMinimumWidth(417);
	thetaTable->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	for (int i = 0; i < 6; ++i) {
		thetaTable->setItem(i, 1, new QTableWidgetItem(QString::number(param::a[i])));
		thetaTable->setItem(i, 2, new QTableWidgetItem(QString::number(param::d[i])));
		thetaTable->setItem(i, 3, new QTableWidgetItem(QString::number(param::alpha[i])));
		
		for (int j = 1; j <= 3; ++j) {
			thetaTable->item(i, j)->setFlags(thetaTable->item(i, j)->flags() & ~Qt::ItemIsEditable);
		}
	}
}

void MainWindow::calculateForward() {
	for (int i = 0; i < 6; ++i) {
		param::theta[i] = thetaTable->item(i, 0) ? thetaTable->item(i, 0)->text().toDouble() : 0.0;
	}
	
	Eigen::Vector3d result = Kinematics::instance().forwardTransform();
	resultLabel->setText(QString("Result: x = %1, y = %2, z = %3")
							.arg(result.x())
							.arg(result.y())
							.arg(result.z()));
}

void MainWindow::validateThetaInput(QTableWidgetItem *item) {
	if (item->column() == 0) {
		bool ok;
		item->text().toDouble(&ok);
		
		if (!ok) {
			QMessageBox::warning(this, "Invalid Input", "Please enter a valid number for Theta.");
			item->setText("0"); 
		}
	}
}

