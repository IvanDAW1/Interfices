#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>

class DTransferencia : public QWidget {

Q_OBJECT

public:

DTransferencia(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	QLabel * etiqDest;
	QLabel * etiqCant;
	QLabel * etqCom;
	
	QPushButton * botonAceptar;
	QPushButton * botonCancelar;
	
	QLineEdit * cuenta;
	QLineEdit * destino;
	
	void crear (void);
	
	public slots:
    
        void calcularComision(int cantidad);


};
