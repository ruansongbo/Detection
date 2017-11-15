#include <QComboBox>

class MyQComboBox : public QComboBox
{
	Q_OBJECT
public:
	MyQComboBox(QWidget* parent = nullptr) :QComboBox(parent){}
	virtual ~MyQComboBox() = default;
	virtual void hidePopup() override{
		emit menuHidden();
		QComboBox::hidePopup();
	}
	virtual void showPopup() override{
		emit menuPopped();
		QComboBox::showPopup();
	}
signals:
	void menuPopped();
	void menuHidden();
};
