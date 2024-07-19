#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QtWidgets/QMainWindow>
#include "ui_ProprietaryProgram.h"
#include <qpushbutton.h>
#include "Attribute.h"
#include "Configuration.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProprietaryProgramClass; };
QT_END_NAMESPACE

class ProprietaryProgram : public QMainWindow
{
    Q_OBJECT

public:
    ProprietaryProgram(QWidget *parent = nullptr, Configuration* configuration = nullptr);
    ~ProprietaryProgram();
private slots:
    void pushButtonViewAttributeClicked();// 这是查看属性的按钮
private:
    Ui::ProprietaryProgramClass *ui;
    Attribute* _attribute; // 属性
    Configuration* _configuration;   // 配置文件
};
