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

	etiqInfo = new QLabel("Eres menor de edad");

	spinBox = new QSpinBox();
	
	boton = new QPushButton("Limpiar");
	
 	spinBox->setRange(0, 130);
	
    connect(spinBox, SIGNAL(valueChanged(int)),
        this, SLOT(slotIndicar(int)));
    
	layoutDins->addWidget(etiqSup);
	layoutDins->addWidget(spinBox);

	layout->addLayout(layoutDins);
	layout->addWidget(etiqInfo);
	layout->addWidget(boton);
        
    connect(boton, SIGNAL(clicked()),
			etiqInfo,SLOT(clear()));

    
	this->setLayout(layout);

}

void DEdad::slotIndicar(int e){

        if(e>=18)
            etiqInfo->setText("Eres mayor de edad");
        else
            etiqInfo->setText("Eres menor de edad");
            
            
            }
        

}



