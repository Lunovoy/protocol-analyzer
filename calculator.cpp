#include "calculator.h"

double first_number;
bool is_user_typing_second_number = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    main_widget = new QWidget;
    setCentralWidget(main_widget);

    setMinimumSize(400, 600);
    setMaximumSize(400, 600);
    move(700, 100);
    setWindowTitle("Calculator");

    const QSize button_size = QSize(90, 90);
    //
    pushbutton_plus_minus = new QPushButton("+/-");
    pushbutton_plus_minus->setFixedSize(button_size);

    pushbutton_clear = new QPushButton("C");
    pushbutton_clear->setFixedSize(button_size);

    pushbutton_digit_0 = new QPushButton("0");
    pushbutton_digit_0->setFixedSize(button_size);

    pushbutton_digit_1 = new QPushButton("1");
    pushbutton_digit_1->setFixedSize(button_size);

    pushbutton_digit_2 = new QPushButton("2");
    pushbutton_digit_2->setFixedSize(button_size);

    pushbutton_digit_3 = new QPushButton("3");
    pushbutton_digit_3->setFixedSize(button_size);

    pushbutton_digit_4 = new QPushButton("4");
    pushbutton_digit_4->setFixedSize(button_size);

    pushbutton_digit_5 = new QPushButton("5");
    pushbutton_digit_5->setFixedSize(button_size);

    pushbutton_digit_6 = new QPushButton("6");
    pushbutton_digit_6->setFixedSize(button_size);

    pushbutton_digit_7 = new QPushButton("7");
    pushbutton_digit_7->setFixedSize(button_size);

    pushbutton_digit_8 = new QPushButton("8");
    pushbutton_digit_8->setFixedSize(button_size);

    pushbutton_digit_9 = new QPushButton("9");
    pushbutton_digit_9->setFixedSize(button_size);
    //
    pushbutton_divide = new QPushButton("/");
    pushbutton_divide->setFixedSize(button_size);
    pushbutton_divide->setCheckable(true);

    pushbutton_multiply = new QPushButton("X");
    pushbutton_multiply->setFixedSize(button_size);
    pushbutton_multiply->setCheckable(true);

    pushbutton_sum = new QPushButton("+");
    pushbutton_sum->setFixedSize(button_size);
    pushbutton_sum->setCheckable(true);

    pushbutton_minus = new QPushButton("-");
    pushbutton_minus->setFixedSize(button_size);
    pushbutton_minus->setCheckable(true);

    pushbutton_point = new QPushButton(".");
    pushbutton_point->setFixedSize(button_size);
    pushbutton_point->setCheckable(true);
    pushbutton_point->setChecked(false);

    pushbutton_equals = new QPushButton("=");
    pushbutton_equals->setFixedSize(button_size);

    lineedit_screen = new QLineEdit();
    lineedit_screen->setFixedSize(380, 70);
    lineedit_screen->setAlignment(Qt::AlignmentFlag::AlignRight);
    lineedit_screen->setReadOnly(true);
    lineedit_screen->setText("0");
    //

    vbox_layout = new QVBoxLayout();

    grid_layout = new QGridLayout();
    grid_layout->setSpacing(2);

    grid_layout->addWidget(pushbutton_clear, 0, 1);
    grid_layout->addWidget(pushbutton_plus_minus, 0, 2);
    grid_layout->addWidget(pushbutton_digit_7, 1, 1);
    grid_layout->addWidget(pushbutton_digit_8, 1, 2);
    grid_layout->addWidget(pushbutton_digit_9, 1, 3);
    grid_layout->addWidget(pushbutton_digit_4, 2, 1);
    grid_layout->addWidget(pushbutton_digit_5, 2, 2);
    grid_layout->addWidget(pushbutton_digit_6, 2, 3);
    grid_layout->addWidget(pushbutton_digit_1, 3, 1);
    grid_layout->addWidget(pushbutton_digit_2, 3, 2);
    grid_layout->addWidget(pushbutton_digit_3, 3, 3);
    grid_layout->addWidget(pushbutton_digit_0, 4, 1);
    grid_layout->addWidget(pushbutton_point, 4, 2);

    grid_layout->addWidget(pushbutton_equals, 4, 3);
    grid_layout->addWidget(pushbutton_divide, 1, 4);
    grid_layout->addWidget(pushbutton_multiply, 2, 4);
    grid_layout->addWidget(pushbutton_minus, 3, 4);
    grid_layout->addWidget(pushbutton_sum, 4, 4);

    vbox_layout->addWidget(lineedit_screen);
    vbox_layout->addLayout(grid_layout);

    main_widget->setLayout(vbox_layout);

    connect(pushbutton_digit_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(pushbutton_digit_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    //
    connect(pushbutton_point, SIGNAL(released()), this, SLOT(point_pressed()));
    //
    connect(pushbutton_divide, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(pushbutton_multiply, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(pushbutton_sum, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(pushbutton_minus, SIGNAL(released()), this, SLOT(operation_pressed()));
    //
    connect(pushbutton_equals, SIGNAL(released()), this, SLOT(equals_pressed()));
    connect(pushbutton_clear, SIGNAL(released()), this, SLOT(clear_pressed()));

    connect(pushbutton_plus_minus, SIGNAL(released()), this, SLOT(plus_minus_pressed()));


}

void Calculator::digit_pressed() {

    QPushButton *button = (QPushButton*)sender();
    double number{};
    QString num_str{};

    if ((pushbutton_divide->isChecked() || pushbutton_multiply->isChecked() ||
            pushbutton_sum->isChecked() || pushbutton_minus->isChecked()) && (!is_user_typing_second_number)) {
         number = button->text().toDouble();
         is_user_typing_second_number = true;
         num_str = QString::number(number, 'g', 15);
    }
    else {
        if (lineedit_screen->text().contains(".") && button->text() == "0") {
            num_str = (lineedit_screen->text() + button->text());
        }
        else {
            number = (lineedit_screen->text() + button->text()).toDouble();
            num_str = QString::number(number, 'g', 15);
        }

    }

    lineedit_screen->setText(num_str);
}

void Calculator::point_pressed() {
    if (lineedit_screen->text().contains(".")) {
        lineedit_screen->setText(lineedit_screen->text());
    }
    else {
        lineedit_screen->setText(lineedit_screen->text() + ".");
    }
}
void Calculator::plus_minus_pressed() {
    double number{};
    QString num_str{};

    number = lineedit_screen->text().toDouble() * -1;

    num_str = QString::number(number, 'g', 15);
    lineedit_screen->setText(num_str);

}

void Calculator::clear_pressed() {
    lineedit_screen->setText("0");
    pushbutton_sum->setChecked(false);
    pushbutton_minus->setChecked(false);
    pushbutton_multiply->setChecked(false);
    pushbutton_divide->setChecked(false);

    is_user_typing_second_number = false;
}

void Calculator::operation_pressed() {

    QPushButton *button = (QPushButton*)sender();

    first_number = lineedit_screen->text().toDouble();

    button->setChecked(true);
}

void Calculator::equals_pressed() {

    double final_number, second_number{};
    QString num_str{};

    second_number = lineedit_screen->text().toDouble();

    if (pushbutton_divide->isChecked()) {
        final_number = first_number / second_number;
        num_str = QString::number(final_number, 'g', 15);
        lineedit_screen->setText(num_str);
        pushbutton_divide->setChecked(false);
    }
    else if (pushbutton_multiply->isChecked()) {
        final_number = first_number * second_number;
        num_str = QString::number(final_number, 'g', 15);
        lineedit_screen->setText(num_str);
        pushbutton_multiply->setChecked(false);
    }
    else if (pushbutton_sum->isChecked()) {
        final_number = first_number + second_number;
        num_str = QString::number(final_number, 'g', 15);
        lineedit_screen->setText(num_str);
        pushbutton_sum->setChecked(false);
    }
    else if (pushbutton_minus->isChecked()) {
        final_number = first_number - second_number;
        num_str = QString::number(final_number, 'g', 15);
        lineedit_screen->setText(num_str);
        pushbutton_minus->setChecked(false);
    }

    is_user_typing_second_number = false;
}

Calculator::~Calculator()
{
}

