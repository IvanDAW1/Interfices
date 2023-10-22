#include "dtransferencia.h"
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
#include <QLineEdit>

    DTransferencia::DTransferencia(QWidget *parent , Qt::WindowFlags f): 
    QWidget(parent, f){

    QHBoxLayout * todo = new QHBoxLayout();
	QVBoxLayout * izquierda = new QVBoxLayout();
	QVBoxLayout * derecha = new QVBoxLayout();
	
	QHBoxLayout * lDestino = new QHBoxLayout();
	QHBoxLayout * lCantidad = new QHBoxLayout();

	etiqDest = new QLabel("Cuenta destino: ");
	etiqCant = new QLabel("Cantidad");
	etqCom = new QLabel("Comision de 0 euros");
	
	cuenta = new QLineEdit();
	destino = new QLineEdit();
	
	botonAceptar = new QPushButton("Aceptar");
	botonCancelar = new QPushButton("Cancelar");
	
	todo->addLayout(izquierda);
	todo->addLayout(derecha);
	
	izquierda->addLayout(lDestino);
	izquierda->addLayout(lCantidad);
	izquierda->addWidget(etqCom);
	
	lDestino->addWidget(etiqDest);
	lDestino->addWidget(destino);
	   
	lCantidad->addWidget(etiqCant);
	lCantidad->addWidget(cuenta);

	derecha->addWidget(botonAceptar);
	derecha->addWidget(botonCancelar);
	
	
	connect(destino, SIGNAL(valueChanged(QString)),
        this, SLOT(slotIndicar(int)));
	
    
	this->setLayout(todo);
	
	
void DTransferencia::calcularComision(int e){

     int comision = e *0.05;
      
	 etqCom->setText("Comisión de " << comision << " euros");
	
}


