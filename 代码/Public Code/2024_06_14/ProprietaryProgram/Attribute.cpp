#include "Attribute.h"
#include <iostream>
Attribute::Attribute(QWidget *parent, const std::string& name, Configuration* configuration)
	: QWidget(parent)
	, ui(new Ui::AttributeClass())
	,_name(name)
	,_configuration(configuration)
{
	std::cout << "Attribute()" << std::endl;

	ui->setupUi(this);
	// ���ñ����,��Դ�����ͷ�
	this->setAttribute(Qt::WA_DeleteOnClose);


	ui->label->setText(_name.c_str());
}

Attribute::~Attribute()
{
	std::cout << "~Attribute()" << std::endl;
	delete ui;
}
