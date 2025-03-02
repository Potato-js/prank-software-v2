#ifndef  MAINWINDOW_H
#define  MAINWINDOW_H

#include <qmainwindow.h>
#include <qdrag.h>
#include <qevent.h>
#include <qmimedata.h>
#include <qlabel.h>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow() override;

protected:
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;

private slots:
	void browseForMedia();
	void generatePrank();

private:
	QString mediaFilePath;
	QLabel *fileLabel;
	QPushButton *browseButton;
	QLineEdit *minIntervalEdit;
	QLineEdit *maxIntervalEdit;
	QPushButton *generateButton;
	QLabel* outputLabel;
};

#endif // ! MAINWINDOW_H