#pragma once

#include <QMainWindow>
#include "ui_rodtypewindpowderdiagram.h"
#include <iostream>
#include "mythread.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class RodTypeWindPowderDiagramClass;
};
QT_END_NAMESPACE

class RodTypeWindPowderDiagram : public QMainWindow
{
	Q_OBJECT

public:
	RodTypeWindPowderDiagram(QWidget *parent = nullptr, MyThread* mythread = nullptr);
	~RodTypeWindPowderDiagram();

private:
	Ui::RodTypeWindPowderDiagramClass *ui;
	MyThread* _mythread;  // 线程的指针,为了得到计算的结果
};
