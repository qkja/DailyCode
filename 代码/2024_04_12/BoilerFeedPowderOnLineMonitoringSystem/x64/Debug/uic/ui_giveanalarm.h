/********************************************************************************
** Form generated from reading UI file 'giveanalarm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIVEANALARM_H
#define UI_GIVEANALARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GiveAnAlarmClass
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_25;
    QFrame *line;
    QSlider *upper_wind_speed;
    QFrame *line_2;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_27;
    QFrame *line_3;
    QSlider *limit_wind_speed;
    QFrame *line_4;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_31;
    QFrame *line_5;
    QSlider *upper_limit_of_pulverized_coal_concentration;
    QFrame *line_6;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_33;
    QFrame *line_7;
    QSlider *limit_limit_of_pulverized_coal_concentration;
    QFrame *line_8;
    QLabel *label_34;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_35;
    QFrame *line_9;
    QSlider *upper_temperature;
    QFrame *line_10;
    QLabel *label_36;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_37;
    QFrame *line_11;
    QSlider *limit_temperature;
    QFrame *line_12;
    QLabel *label_38;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_21;
    QPushButton *identify_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QWidget *GiveAnAlarmClass)
    {
        if (GiveAnAlarmClass->objectName().isEmpty())
            GiveAnAlarmClass->setObjectName(QString::fromUtf8("GiveAnAlarmClass"));
        GiveAnAlarmClass->resize(1275, 600);
        layoutWidget = new QWidget(GiveAnAlarmClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 30, 931, 511));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        verticalLayout->addWidget(label_1, 0, Qt::AlignRight);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignRight);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_2->addWidget(label_25, 0, Qt::AlignHCenter);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        upper_wind_speed = new QSlider(groupBox);
        upper_wind_speed->setObjectName(QString::fromUtf8("upper_wind_speed"));
        upper_wind_speed->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(upper_wind_speed, 0, Qt::AlignHCenter);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_2->addWidget(label_26, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_4->addWidget(label_27, 0, Qt::AlignHCenter);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        limit_wind_speed = new QSlider(groupBox);
        limit_wind_speed->setObjectName(QString::fromUtf8("limit_wind_speed"));
        limit_wind_speed->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(limit_wind_speed, 0, Qt::AlignHCenter);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_4->addWidget(label_28, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignLeft);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4, 0, Qt::AlignLeft);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_13->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_7->addWidget(label_5, 0, Qt::AlignRight);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_7->addWidget(label_6, 0, Qt::AlignRight);


        horizontalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        verticalLayout_8->addWidget(label_31, 0, Qt::AlignHCenter);

        line_5 = new QFrame(groupBox_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_5);

        upper_limit_of_pulverized_coal_concentration = new QSlider(groupBox_2);
        upper_limit_of_pulverized_coal_concentration->setObjectName(QString::fromUtf8("upper_limit_of_pulverized_coal_concentration"));
        upper_limit_of_pulverized_coal_concentration->setOrientation(Qt::Vertical);

        verticalLayout_8->addWidget(upper_limit_of_pulverized_coal_concentration, 0, Qt::AlignHCenter);

        line_6 = new QFrame(groupBox_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_6);

        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        verticalLayout_8->addWidget(label_32, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout_8);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        verticalLayout_9->addWidget(label_33, 0, Qt::AlignHCenter);

        line_7 = new QFrame(groupBox_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_7);

        limit_limit_of_pulverized_coal_concentration = new QSlider(groupBox_2);
        limit_limit_of_pulverized_coal_concentration->setObjectName(QString::fromUtf8("limit_limit_of_pulverized_coal_concentration"));
        limit_limit_of_pulverized_coal_concentration->setOrientation(Qt::Vertical);

        verticalLayout_9->addWidget(limit_limit_of_pulverized_coal_concentration, 0, Qt::AlignHCenter);

        line_8 = new QFrame(groupBox_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_8);

        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        verticalLayout_9->addWidget(label_34, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_14->addWidget(label_7, 0, Qt::AlignLeft);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_14->addWidget(label_8, 0, Qt::AlignLeft);


        horizontalLayout_6->addLayout(verticalLayout_14);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_13->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_15 = new QVBoxLayout(groupBox_3);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_17->addWidget(label_9, 0, Qt::AlignRight);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_17->addWidget(label_10, 0, Qt::AlignRight);


        horizontalLayout_11->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        verticalLayout_18->addWidget(label_35, 0, Qt::AlignHCenter);

        line_9 = new QFrame(groupBox_3);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_18->addWidget(line_9);

        upper_temperature = new QSlider(groupBox_3);
        upper_temperature->setObjectName(QString::fromUtf8("upper_temperature"));
        upper_temperature->setOrientation(Qt::Vertical);

        verticalLayout_18->addWidget(upper_temperature, 0, Qt::AlignHCenter);

        line_10 = new QFrame(groupBox_3);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_18->addWidget(line_10);

        label_36 = new QLabel(groupBox_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        verticalLayout_18->addWidget(label_36, 0, Qt::AlignHCenter);


        horizontalLayout_11->addLayout(verticalLayout_18);


        horizontalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        verticalLayout_19->addWidget(label_37, 0, Qt::AlignHCenter);

        line_11 = new QFrame(groupBox_3);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_19->addWidget(line_11);

        limit_temperature = new QSlider(groupBox_3);
        limit_temperature->setObjectName(QString::fromUtf8("limit_temperature"));
        limit_temperature->setOrientation(Qt::Vertical);

        verticalLayout_19->addWidget(limit_temperature, 0, Qt::AlignHCenter);

        line_12 = new QFrame(groupBox_3);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_19->addWidget(line_12);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        verticalLayout_19->addWidget(label_38, 0, Qt::AlignHCenter);


        horizontalLayout_12->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_20->addWidget(label_11, 0, Qt::AlignLeft);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_20->addWidget(label_12, 0, Qt::AlignLeft);


        horizontalLayout_12->addLayout(verticalLayout_20);


        horizontalLayout_10->addLayout(horizontalLayout_12);


        verticalLayout_15->addLayout(horizontalLayout_10);


        horizontalLayout_13->addWidget(groupBox_3);

        layoutWidget_2 = new QWidget(GiveAnAlarmClass);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(1130, 100, 95, 381));
        verticalLayout_21 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        identify_pushButton = new QPushButton(layoutWidget_2);
        identify_pushButton->setObjectName(QString::fromUtf8("identify_pushButton"));

        verticalLayout_21->addWidget(identify_pushButton);

        cancel_pushButton = new QPushButton(layoutWidget_2);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        verticalLayout_21->addWidget(cancel_pushButton);


        retranslateUi(GiveAnAlarmClass);

        QMetaObject::connectSlotsByName(GiveAnAlarmClass);
    } // setupUi

    void retranslateUi(QWidget *GiveAnAlarmClass)
    {
        GiveAnAlarmClass->setWindowTitle(QCoreApplication::translate("GiveAnAlarmClass", "GiveAnAlarm", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GiveAnAlarmClass", "\351\243\216\351\200\237", nullptr));
        label_1->setText(QCoreApplication::translate("GiveAnAlarmClass", "40", nullptr));
        label_2->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        label_25->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\212\351\231\220", nullptr));
        label_26->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_27->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\213\351\231\220", nullptr));
        label_28->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("GiveAnAlarmClass", "40", nullptr));
        label_4->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GiveAnAlarmClass", "\347\205\244\347\262\211\346\265\223\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("GiveAnAlarmClass", "1.6", nullptr));
        label_6->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        label_31->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\212\351\231\220", nullptr));
        label_32->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_33->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\213\351\231\220", nullptr));
        label_34->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("GiveAnAlarmClass", "1.6", nullptr));
        label_8->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("GiveAnAlarmClass", "\346\270\251\345\272\246", nullptr));
        label_9->setText(QCoreApplication::translate("GiveAnAlarmClass", "400", nullptr));
        label_10->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        label_35->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\212\351\231\220", nullptr));
        label_36->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_37->setText(QCoreApplication::translate("GiveAnAlarmClass", "\344\270\213\351\231\220", nullptr));
        label_38->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\275\223\345\211\215\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("GiveAnAlarmClass", "400", nullptr));
        label_12->setText(QCoreApplication::translate("GiveAnAlarmClass", "0", nullptr));
        identify_pushButton->setText(QCoreApplication::translate("GiveAnAlarmClass", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("GiveAnAlarmClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiveAnAlarmClass: public Ui_GiveAnAlarmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIVEANALARM_H
