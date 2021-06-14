#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод шифрования
std::string encrypt(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 1) % 26];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

//Метод дешифрования
std::string decrypt(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 1) % 26];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

//Зашифровать
void MainWindow::on_pushButton_clicked()
{
    QString text = this->ui->lineEdit->text();
    //Конвертируем текст из QString в String
    std::string convText = text.toStdString();
    //Шифруем конвертируемый текст
    std::string encryptText = encrypt(convText);
    //Конвертируем зашифрованный текст обратно в QString
    QString qstr = QString::fromStdString(encryptText);
    this->ui->lineEdit_2->setText(qstr);
}

//Расшифровать
void MainWindow::on_pushButton_2_clicked()
{
    QString text = this->ui->lineEdit->text();
    //Конвертируем текст из QString в String
    std::string convText = text.toStdString();
    //Дешифруем конвертируемый текст
    std::string encryptText = decrypt(convText);
    //Конвертируем дешифрованный текст обратно в QString
    QString qstr = QString::fromStdString(encryptText);
    this->ui->lineEdit_2->setText(qstr);
}

//Отчистить
void MainWindow::on_pushButton_3_clicked()
{
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
}

