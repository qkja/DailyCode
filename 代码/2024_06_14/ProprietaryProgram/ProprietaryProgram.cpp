#include "ProprietaryProgram.h"
#include <iostream>
ProprietaryProgram::ProprietaryProgram(QWidget *parent, Configuration* configuration)
    : QMainWindow(parent)
    , ui(new Ui::ProprietaryProgramClass())
    , _attribute(nullptr)
    , _configuration(configuration)
{
    std::cout << "ProprietaryProgram()" << std::endl;
    ui->setupUi(this);
    connect(ui->pushButton_view_attribute, &QPushButton::clicked, this, &ProprietaryProgram::pushButtonViewAttributeClicked);
    
}

ProprietaryProgram::~ProprietaryProgram()
{
    std::cout << "~ProprietaryProgram()" << std::endl;
    delete ui;
}
void ProprietaryProgram::pushButtonViewAttributeClicked()
{
    auto iter = _configuration->_all_datas.begin();
    while (iter != _configuration->_all_datas.end())
    {
        if (iter->first.find("_user") != std::string::npos)
        {
            _attribute = new Attribute(nullptr, iter->first, _configuration);
            break;
        }
        ++iter;
    }
    _attribute->show();
}