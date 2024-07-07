#pragma once

#include <QWidget>
#include "ui_BackrestCanal.h"
#include <iostream>
#include "Configure.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class BackrestCanalClass; };
QT_END_NAMESPACE

class BackrestCanal : public QWidget
{
	Q_OBJECT

public:
	BackrestCanal(QWidget* parent = nullptr, Configure* configure = nullptr);
	~BackrestCanal();
	void init();
private:
	void setReadOnly(bool); // lable �ؼ��Ƿ���Ա��޸�
signals:
	void fromBackrestCanalToMainScreenSignals();
	void backrestCanalCloseSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::BackrestCanalClass* ui;
	Configure* _configure;
};
