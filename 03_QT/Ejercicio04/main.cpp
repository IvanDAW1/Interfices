#include <QApplication>
#include <QLabel>
#include <unistd.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QSpinBox>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	
	QWidget *window = new QWidget;
	window->setWindowTitle("Ejercico 04");
	
	
	QSpinBox *spinBox = new QSpinBox;
	QSlider *slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);
	
	
	QObject::connect(spinBox, SIGNAL(valueChanged(int)),
	slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)),
	spinBox, SLOT(setValue(int)));
	spinBox->setValue(35);
	
	QPushButton * oct = new QPushButton("Oct");
	QPushButton * dec = new QPushButton("Dec");
	QPushButton * boton = new QPushButton("Limpiar");
	QLineEdit * entrada = new QLineEdit();
	QLabel * letrero = new QLabel();
	
	QVBoxLayout *todo = new QVBoxLayout();
	
	QHBoxLayout *sup = new QHBoxLayout();
	QVBoxLayout *supIzq = new QVBoxLayout();
	QHBoxLayout *SupDer = new QHBoxLayout();
	
	QHBoxLayout *inf = new QHBoxLayout();
	
	supIzq->addWidget(entrada);
	supIzq->addWidget(boton);			
	supIzq->addWidget(letrero);
	
	SupDer->addWidget(spinBox);
	SupDer->addWidget(slider);

	inf->addWidget(oct);
	inf->addWidget(dec);		
	
	
	window->setLayout(todo);
	todo->addLayout(sup);
	sup->addLayout(supIzq);
	sup->addLayout(SupDer);
	todo->addLayout(inf);
	
	window->show();
	
	QObject::connect(entrada, SIGNAL(textChanged(QString)),
			letrero,SLOT( setText(QString)));
			
	QObject::connect(boton,SIGNAL (clicked()),
			letrero, SLOT(clear()));
			
	QObject::connect(boton,SIGNAL (clicked()),
			entrada,SLOT (clear()));	


	return app.exec(); //Arrancamos el monstruo
}
