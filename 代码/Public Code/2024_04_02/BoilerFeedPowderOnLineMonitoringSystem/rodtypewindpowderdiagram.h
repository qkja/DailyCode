#pragma once

#include <QMainWindow>
#include "ui_rodtypewindpowderdiagram.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RodTypeWindPowderDiagramClass; };
QT_END_NAMESPACE

class RodTypeWindPowderDiagram : public QMainWindow
{
	Q_OBJECT

public:
	RodTypeWindPowderDiagram(QWidget *parent = nullptr);
	~RodTypeWindPowderDiagram();

private:
	Ui::RodTypeWindPowderDiagramClass *ui;
};
