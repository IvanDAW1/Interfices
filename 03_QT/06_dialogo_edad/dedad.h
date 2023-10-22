#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

class DEdad : public QWidget {

Q_OBJECT

public:

DEdad(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	QLabel * etiqSup;
	QLabel * etiqInfo;
	QSpinBox * spinBox;
	QPushButton *boton;
	
	void crear (void);

    public slots:
    
        void slotIndicar(int edad);

};
