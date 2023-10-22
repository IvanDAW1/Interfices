#include <QApplication>
#include <QLabel>
#include <unistd.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	
	QWidget *window = new QWidget;
	window->setWindowTitle("Ejercico 03");
	
	QPushButton * boton = new QPushButton("Limpiar");
	QLineEdit * entrada = new QLineEdit();
	QLabel * letrero = new QLabel();
	
	QVBoxLayout *layout = new QVBoxLayout();
	
	layout->addWidget(entrada);
	layout->addWidget(boton);			
	layout->addWidget(letrero);	
	
	window->setLayout(layout);
	
	window->show();
	
	QObject::connect(entrada, SIGNAL(textChanged(QString)),
			letrero,SLOT( setText(QString)));
			
	QObject::connect(boton,SIGNAL (clicked()),
			letrero, SLOT(clear()));
			
	QObject::connect(boton,SIGNAL (clicked()),
			entrada,SLOT (clear()));	


	return app.exec(); //Arrancamos el monstruo
}
