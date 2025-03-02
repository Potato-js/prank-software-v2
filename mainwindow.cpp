#include "mainwindow.h"
#include <QApplication>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFontMetrics>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->setAcceptDrops(true);
    setWindowTitle("Jumpscare Software V1");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    fileLabel = new QLabel("Drag and drop a media file here", this);
    fileLabel->setAlignment(Qt::AlignCenter);
    fileLabel->setWordWrap(true);
    layout->addWidget(fileLabel);

    generateButton = new QPushButton("Generate .exe", this);
    layout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked, this, [this]() {
        if (mediaFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please drag and drop a media file first!");
        }
        else {
            QMessageBox::information(this, "Jumpscare Software", "Jumpscare software has been generated!");
        }
        });

    centralWidget->setLayout(layout);
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
        fileLabel->setText("File Selected: " + mediaFilePath);

        QFontMetrics metrics(fileLabel->font());
        int textWidth = metrics.horizontalAdvance(fileLabel->text());
        int labelWidth = std::min(textWidth + 20, this->width() - 40);
        fileLabel->setMinimumWidth(labelWidth);
    }
}