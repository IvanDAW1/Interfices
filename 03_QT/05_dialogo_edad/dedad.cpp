#include "dedad.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QString>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


    DEdad::DEdad(QWidget *parent , Qt::WindowFlags f): 
    QWidget(parent, f){


	QVBoxLayout * layout = new QVBoxLayout();
	QHBoxLayout * layoutDins = new QHBoxLayout();

	etiqSup = new QLabel("Edad: ");

	etiqInfo = new QLabel("No eres mayor de edad");

	spinBox = new QSpinBox();
	
 	spinBox->setRange(0, 130);
	

	layoutDins->addWidget(etiqSup);
	layoutDins->addWidget(spinBox);

	layout->addLayout(layoutDins);
	layout->addWidget(etiqInfo);


	this->setLayout(layout);

    }
