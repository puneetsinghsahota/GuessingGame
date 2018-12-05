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
#include <QtWidgets/QApplication>
#include <QtWidgets/qwidget.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2);
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	

	QtGuiApplication2 mainWindow;


	mainWindow.show();

	return a.exec();
}
