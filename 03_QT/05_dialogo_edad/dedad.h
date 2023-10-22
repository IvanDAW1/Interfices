#include <QWidget>
#include <QLabel>
#include <QSpinBox>


class DEdad : public QWidget {

public:

DEdad(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	QLabel * etiqSup;
	QLabel * etiqInfo;
	QSpinBox * spinBox;
	
	void crear (void);

	
};
