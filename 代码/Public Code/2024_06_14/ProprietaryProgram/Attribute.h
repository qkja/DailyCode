#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include "ui_Attribute.h"
#include <string>
#include <Configuration.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AttributeClass; };
QT_END_NAMESPACE

class Attribute : public QWidget
{
	Q_OBJECT

public:
	Attribute(QWidget *parent = nullptr, const std::string& name = std::string(), Configuration* configuration = nullptr);
	~Attribute();
signals:
	void attributeCloseSignals();
private:
	Ui::AttributeClass *ui;
	std::string _name;
	Configuration* _configuration;
};
