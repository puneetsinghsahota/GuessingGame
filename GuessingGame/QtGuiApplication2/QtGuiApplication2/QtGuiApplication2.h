#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_QtGuiApplication2.h"

class QtGuiApplication2 : public QMainWindow
{
	Q_OBJECT;
public:
		int secret = 0;
		int count = 0;
		int minGuess = 100;
		int guessArray[10];
		QtGuiApplication2(QWidget *parent = Q_NULLPTR);
		void plotGraph();
		void showGraph(QWidget *widget);
		
	
public slots:
	
		void handleButton();
		
private:

		Ui::QtGuiApplication2Class ui;
};
