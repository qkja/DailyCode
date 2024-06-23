#pragma once

#include <QWidget>
#include "ui_WelcomeScreen.h"
#include <qtimer.h>
#include <iostream>
#include <qpushbutton.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreenClass; };
QT_END_NAMESPACE
/*
* ����һ������ui����Ļ�ӭ����,�ڳ���������������ʾ�������
* ˫��"��¯ȼ��"��ť�Ϳ��Խ�����ҳ��
*/
class WelcomeScreen : public QWidget
{
	Q_OBJECT

public:
	WelcomeScreen(QWidget* parent = nullptr);
	~WelcomeScreen();
	void init();
protected slots:
	void onButtonDoubleClicked();       // �����ť�����Ĳۺ���
	void resetClickCount();             // ���ü�����
signals:
	void fromWelToMianScreenSignals();  // ˫��֮��,��������ź�,ת��������
	void welcomeScreenCloseSignals();   // ���ڹر�ʱ,�����������
protected:
	void closeEvent(QCloseEvent*);      // ��д���ڹرյĺ���

private:
	Ui::WelcomeScreenClass* ui;
	QTimer* _doubleClickTimer;          // ��ʱ������
	volatile int _clickCount;           // ����ļ�����,volatile�ؼ���,��ȥ�ڴ���ȡֵ
};
