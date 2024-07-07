#pragma once

#include <QWidget>
#include "ui_backrestcanal.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class BackrestCanalClass; };
QT_END_NAMESPACE

class BackrestCanal : public QWidget
{
	Q_OBJECT

public:
	BackrestCanal(QWidget *parent = nullptr);
	~BackrestCanal();
signals:
	void fromBackrestCanalToMainScreenSignals();
private:
	Ui::BackrestCanalClass *ui;
};
