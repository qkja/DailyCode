#pragma once

#include <QWidget>
#include <iostream>
#include "ui_TangentialCircleDiagramOfPrimaryWind.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class TangentialCircleDiagramOfPrimaryWindClass; };
QT_END_NAMESPACE

class TangentialCircleDiagramOfPrimaryWind : public QWidget
{
	Q_OBJECT

public:
	TangentialCircleDiagramOfPrimaryWind(QWidget* parent = nullptr);
	~TangentialCircleDiagramOfPrimaryWind();
	void init();
signals:
	void tangentialCircleDiagramOfPrimaryWindCloseSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::TangentialCircleDiagramOfPrimaryWindClass* ui;
};
