#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFile>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>

class Calculator : public QMainWindow
{
    Q_OBJECT
private slots:
    void digit_pressed();
    void operation_pressed();
    void equals_pressed();
    void point_pressed();
    void clear_pressed();
    void plus_minus_pressed();

private:
    QWidget *main_widget;
    //

    QPushButton *pushbutton_digit_0;
    QPushButton *pushbutton_digit_1;
    QPushButton *pushbutton_digit_2;
    QPushButton *pushbutton_digit_3;
    QPushButton *pushbutton_digit_4;
    QPushButton *pushbutton_digit_5;
    QPushButton *pushbutton_digit_6;
    QPushButton *pushbutton_digit_7;
    QPushButton *pushbutton_digit_8;
    QPushButton *pushbutton_digit_9;
    //
    QPushButton *pushbutton_plus_minus;
    QPushButton *pushbutton_point;
    QPushButton *pushbutton_equals;
    QPushButton *pushbutton_divide;
    QPushButton *pushbutton_multiply;
    QPushButton *pushbutton_sum;
    QPushButton *pushbutton_minus;
    QPushButton *pushbutton_clear;

    QLineEdit *lineedit_screen;

    //
    QVBoxLayout *vbox_layout;
    QGridLayout *grid_layout;

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
};
#endif // CALCULATOR_H
