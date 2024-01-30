/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_H
#define UI_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plot
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *rangeFrom;
    QLabel *label_2;
    QLineEdit *rangeTo;
    QLabel *label_4;
    QLabel *labelCell;
    QPushButton *updatePlot;
    QSpacerItem *horizontalSpacer_2;
    QLabel *IncorrectRange;

    void setupUi(QWidget *Plot)
    {
        if (Plot->objectName().isEmpty())
            Plot->setObjectName(QString::fromUtf8("Plot"));
        Plot->resize(640, 480);
        Plot->setStyleSheet(QString::fromUtf8("MainWindow {\n"
"	border-radius:0;\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius:0;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color:rgb(245, 245, 245);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color:rgb(219, 229, 243);\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border-radius:0; \n"
"	border:1px solid grey; \n"
"}\n"
"\n"
"QLineEdit::disabled {\n"
"	background-color:transparent; 	\n"
"}"));
        horizontalLayoutWidget = new QWidget(Plot);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 641, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 30));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        rangeFrom = new QLineEdit(horizontalLayoutWidget);
        rangeFrom->setObjectName(QString::fromUtf8("rangeFrom"));
        rangeFrom->setMinimumSize(QSize(100, 0));
        rangeFrom->setMaximumSize(QSize(100, 20));
        rangeFrom->setFocusPolicy(Qt::ClickFocus);
        rangeFrom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(rangeFrom);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(20, 0));
        label_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(label_2);

        rangeTo = new QLineEdit(horizontalLayoutWidget);
        rangeTo->setObjectName(QString::fromUtf8("rangeTo"));
        rangeTo->setMinimumSize(QSize(100, 0));
        rangeTo->setMaximumSize(QSize(100, 20));
        rangeTo->setFocusPolicy(Qt::ClickFocus);
        rangeTo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(rangeTo);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(30, 0));
        label_4->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(label_4);

        labelCell = new QLabel(horizontalLayoutWidget);
        labelCell->setObjectName(QString::fromUtf8("labelCell"));
        labelCell->setMinimumSize(QSize(40, 0));
        labelCell->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(labelCell);

        updatePlot = new QPushButton(horizontalLayoutWidget);
        updatePlot->setObjectName(QString::fromUtf8("updatePlot"));
        updatePlot->setMinimumSize(QSize(70, 18));
        updatePlot->setMaximumSize(QSize(70, 18));
        QFont font;
        font.setPointSize(10);
        updatePlot->setFont(font);
        updatePlot->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1 solid black;\n"
"}"));

        horizontalLayout->addWidget(updatePlot);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        IncorrectRange = new QLabel(Plot);
        IncorrectRange->setObjectName(QString::fromUtf8("IncorrectRange"));
        IncorrectRange->setEnabled(true);
        IncorrectRange->setGeometry(QRect(170, 220, 271, 41));
        QFont font1;
        font1.setPointSize(18);
        IncorrectRange->setFont(font1);
        IncorrectRange->setAlignment(Qt::AlignCenter);

        retranslateUi(Plot);

        QMetaObject::connectSlotsByName(Plot);
    } // setupUi

    void retranslateUi(QWidget *Plot)
    {
        Plot->setWindowTitle(QCoreApplication::translate("Plot", "Plot", nullptr));
        label->setText(QCoreApplication::translate("Plot", "Range from:", nullptr));
        label_2->setText(QCoreApplication::translate("Plot", "to:", nullptr));
        label_4->setText(QCoreApplication::translate("Plot", "Cell: ", nullptr));
        labelCell->setText(QString());
        updatePlot->setText(QCoreApplication::translate("Plot", "Update", nullptr));
        IncorrectRange->setText(QCoreApplication::translate("Plot", "Incorrect range!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plot: public Ui_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_H