#include "mainwindow.h"
#include "prankgenerator.h"

#include <qapplication.h>
#include <qdrag.h>
#include <qevent.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qdir.h>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->setAcceptDrops(true);
    setWindowTitle("Jumpscare Software V1");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // title
	QLabel* titleLabel = new QLabel("Jumpscare Software V1", this);
	titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setStyleSheet("font-weight: bold; font-size: 16pt;");
	mainLayout->addWidget(titleLabel);

	// drag and drop area
    fileLabel = new QLabel("Drag and drop a media file here", this);
    fileLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("border: 1px dashed gray; padding: 20px;");
    mainLayout->addWidget(fileLabel);

	// browse button
	browseButton = new QPushButton("[ Browse... ]", this);
	mainLayout->addWidget(browseButton);
    connect(browseButton, &QPushButton::clicked, this, &MainWindow::browseForMedia);

	// interval inputs
	QLabel* intervalLabel = new QLabel("Interval (in minutes) between jumpscares:", this);
	mainLayout->addWidget(intervalLabel);

    QHBoxLayout* intervalLayout = new QHBoxLayout();
    QLabel* minLabel = new QLabel("Min:", this);
    minIntervalEdit = new QLineEdit(this);
    minIntervalEdit->setPlaceholderText("5");
    QLabel* maxLabel = new QLabel("Max:", this);
    maxIntervalEdit = new QLineEdit(this);
    maxIntervalEdit->setPlaceholderText("30");
    intervalLayout->addWidget(minLabel);
    intervalLayout->addWidget(minIntervalEdit);
    intervalLayout->addWidget(new QLabel("-", this)); // Dash separator
    intervalLayout->addWidget(maxLabel);
    intervalLayout->addWidget(maxIntervalEdit);
    mainLayout->addLayout(intervalLayout);

    generateButton = new QPushButton("Generate .exe", this);
    mainLayout->addWidget(generateButton);
	connect(browseButton, &QPushButton::clicked, this, &MainWindow::generatePrank);

	outputLabel = new QLabel("Output: ", this);
	outputLabel->setAlignment(Qt::AlignCenter);
	mainLayout->addWidget(outputLabel);
}

MainWindow::~MainWindow() {}

void MainWindow::dragEnterEvent(QDragEnterEvent* event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent* event) {
	QList<QUrl> droppedFiles = event->mimeData()->urls();
    if (!droppedFiles.isEmpty()) {
		mediaFilePath = droppedFiles.first().toLocalFile();
		fileLabel->setText(QDir::toNativeSeparators(mediaFilePath));
    }
}

void MainWindow::browseForMedia() {
	QString selectedFile = QFileDialog::getOpenFileName(this, "Select Media File");
    if (!selectedFile.isEmpty()) {
		mediaFilePath = selectedFile;
		fileLabel->setText("File Selected: " + mediaFilePath);
	}
}

void MainWindow::generatePrank() {
    if (mediaFilePath.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please drag and drop a media file first!");
        return;
    }

	int minInterval = minIntervalEdit->text().isEmpty() ? 5 : minIntervalEdit->text().toInt();
	int maxInterval = maxIntervalEdit->text().isEmpty() ? 30 : maxIntervalEdit->text().toInt();

	if (minInterval <= 0 || maxInterval <= 0 || minInterval > maxInterval) {
		QMessageBox::warning(this, "Invalid Interval", "Please enter valid interval values!");
		return;
	}

	QString outputDir = QFileDialog::getExistingDirectory(this, "Select Output Directory");
	if (outputDir.isEmpty()) {
		QMessageBox::warning(this, "No Output Directory", "Please select an output directory!");
		return;
	}

	QString errorMessage;
    if (PrankGenerator::generateExecutable(mediaFilePath, minInterval, maxInterval, outputDir, errorMessage)) {
		outputLabel->setText("Output: prank.exe generated!");
    } else {
		QMessageBox::critical(this, "Generation Failed", errorMessage);
    }
}