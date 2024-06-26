#pragma once

#include <QWidget>
#include "ui_verifypassword.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class VerifyPasswordClass; };
QT_END_NAMESPACE

class VerifyPassword : public QWidget
{
	Q_OBJECT

public:
	VerifyPassword(QWidget *parent = nullptr);
	~VerifyPassword();
	void closeEvent(QCloseEvent*);
signals:
	void fromVerifyPasswordSignalsIsTrue();
	void fromVerifyPasswordSignalsIsFalse();
	void ExitWin(); // 新建一个信号槽
private:
	Ui::VerifyPasswordClass *ui;
};
