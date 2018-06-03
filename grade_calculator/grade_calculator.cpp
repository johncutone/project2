#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <string>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::calculateGrade() {

    if (!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) {
        return;
    }

    double h1 = ui->hw1sl->value();
    double h2 = ui->hw2sl->value();
    double h3 = ui->hw3sl->value();
    double h4 = ui->hw4sl->value();
    double h5 = ui->hw5sl->value();
    double h6 = ui->hw6sl->value();
    double h7 = ui->hw7sl->value();
    double h8 = ui->hw8sl->value();
    double m1 = ui->m1sl->value();
    double m2 = ui->m2sl->value();
    double fin = ui->fsl->value();

    double htotal = (h1+h2+h3+h4+h5+h6+h7+h8)/8;
    double maxm = m1;
    if (m1< m2)
        maxm = m2;

    double grade = 0;

    if (ui->radioButton->isChecked()) {
        grade = .25*htotal + .2*m1 + .2*m2 + .35*fin;
    }
    else if (m1 > m2){
        grade = .25*htotal + .3*m1 + .44*fin;
    }
    else {
        grade = .25*htotal + .3*m2 + .44*fin;
    }
    ui->label_12->setText(QString::number(double(grade)));
}

void grade_calculator::on_pushButton_clicked()
{
    calculateGrade();
}
