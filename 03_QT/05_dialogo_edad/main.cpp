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
#include "dedad.h"

  int main(int argc, char *argv[])
  {
    	QApplication app(argc, argv);
    	
    	
    	DEdad * dEdad = new DEdad();
    	
    	dEdad->show();
    	
    	
  	    return app.exec();
  }
  
