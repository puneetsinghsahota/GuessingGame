#include "QtGuiApplication2.h"
#include "vtkAutoInit.h"
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <QVTKOpenGLSimpleWidget.h>
#include <QVTKApplication.h>
#include <QPixMap>
#include <QGraphicsItem.h>
#include <QGraphicsProxyWidget.h>
#include <QGridLayout>


VTK_MODULE_INIT(vtkRenderingContextOpenGL2);
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);




QtGuiApplication2::QtGuiApplication2(QWidget *parent):QMainWindow(parent)
{
	ui.setupUi(this);

	ui.GoButton->connect(ui.GoButton,SIGNAL(clicked()), this , SLOT(handleButton()));
	ui.commentsLabel->setText("The system is Ready Now \n Go Onn Now !!! Guess It !");
	setWindowTitle("Guessing Game");
	srand(time(NULL));
	secret = rand() % 100 + 1;
	for (int i = 0; i < 10; i++)
	{
		guessArray[i] = 0;
	}
}
void QtGuiApplication2::plotGraph()
{


	vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

	vtkSmartPointer<vtkFloatArray> guessNumber = vtkSmartPointer<vtkFloatArray>::New();
	guessNumber->SetName("GuessNumber");

	table->AddColumn(guessNumber);

	vtkSmartPointer<vtkFloatArray> guessValue = vtkSmartPointer<vtkFloatArray>::New();
	guessValue->SetName("guessValue");
	table->AddColumn(guessValue);

	vtkSmartPointer<vtkFloatArray> diff = vtkSmartPointer<vtkFloatArray>::New();
	diff->SetName("diff");
	table->AddColumn(diff);

	table->SetNumberOfRows(10);

	for (int i = 0; i < 10; i++)
	{
		table->SetValue(i, 0, i+1);
		table->SetValue(i, 1, guessArray[i]);
		int distance = guessArray[i] - secret;
		if (distance < 0)
		{
			distance = distance * (-1);
		}
		if (guessArray[i] == 0)
		{
			distance = 0;
		}
		table->SetValue(i, 2, distance);
	}
	QVTKOpenGLSimpleWidget *widget = new QVTKOpenGLSimpleWidget();
	
	QGridLayout *gridLayout = new QGridLayout();
	
	ui.displayGroupBox->setLayout(gridLayout);
	gridLayout->addWidget(widget,0,0);

	vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
	view->SetRenderWindow(widget->GetRenderWindow());
	view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

	vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();

	vtkPlot *line = chart->AddPlot(vtkChart::LINE);

	line->SetInputData(table, 0, 1);
	line->SetColor(0, 255, 0, 255);
	line->SetWidth(1.0);

	line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(table, 0, 2);
	line->SetColor(255, 0, 0, 255);
	line->SetWidth(1.0);
	
	view->GetScene()->ClearItems();
	view->GetScene()->AddItem(chart);
	view->Render();
	
	


	showGraph(widget);
	for (int i = 0; i < 10; i++)
	{
		guessArray[i] = 0;
	}
	secret = rand() % 100 + 1;
	count = 0;

}
void QtGuiApplication2::showGraph(QWidget *widget)
{


}

void QtGuiApplication2::handleButton()
{
	QString commentVal = "";
	if (count <= 9)
	{
		count++;
		QString val = ui.guessedNumberTextBox->text();
		int guessedNumber = val.toInt();
		guessArray[count - 1] = guessedNumber;
		if (guessedNumber == secret)
		{
			QString imagePath = "D:\\testFolder\\correct.png";
			QImage *imageObject = new QImage();
			imageObject->load(imagePath);
			QPixmap image = QPixmap::fromImage(*imageObject);
			QGraphicsScene *scene = new QGraphicsScene(this);
			scene->addPixmap(image);
			ui.graphicsViewMore->setScene(scene);
			commentVal = "Wow ! You Cracked it in \n" + QString::number(count) + " guesses ! ";
			plotGraph();
		}
		else
		{
			int diff = guessedNumber - secret;
			int isLower = 0;
			if (diff < 0)
			{
				QString imagePath = "D:\\TestImages\\up.png";
				QImage *imageObject = new QImage();
				imageObject->load(imagePath);
				QPixmap image = QPixmap::fromImage(*imageObject);
				QGraphicsScene *scene = new QGraphicsScene(this);
				scene->addPixmap(image);
				ui.graphicsViewMore->setScene(scene);
				commentVal = "The SECRET is Greater than \n your current Guess";
				diff = diff * (-1);
			}
			else
			{
				QString imagePath = "D:\\TestImages\\down.png";
				QImage *imageObject = new QImage();
				imageObject->load(imagePath);
				QPixmap image = QPixmap::fromImage(*imageObject);
				QGraphicsScene *scene = new QGraphicsScene(this);
				scene->addPixmap(image);
				ui.graphicsViewMore->setScene(scene);
				commentVal = "The SECRET is Lower \n than your current Guess";
				isLower = 1;
			}
		}
	}
	else
	{
		commentVal = "Sorry You Lost :(";
		plotGraph();
	}
	ui.commentsLabel->setText(commentVal);
}

