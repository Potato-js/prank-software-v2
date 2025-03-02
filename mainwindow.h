#ifndef  MAINWINDOW_H
#define  MAINWINDOW_H

#include <qmainwindow.h>
#include <qdrag.h>
#include <qevent.h>
#include <qmimedata.h>
#include <qlabel.h>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

protected:
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;

private:
	QLabel* fileLabel;
	QPushButton* generateButton;
	QString mediaFilePath;
};

#endif // ! MAINWINDOW_H