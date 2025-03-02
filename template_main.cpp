#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <cstdlib>

int create(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QString mediaFilePath;
    int minInterval = 5;
    int maxInterval = 30;

    if (argc >= 4) {
        mediaFilePath = argv[1];
        minInterval = std::atoi(argv[2]);
        maxInterval = std::atoi(argv[3]);
    } else {
        qDebug() << "No command-line configuration provided. Using default values.";
    }

    int range = maxInterval - minInterval + 1;
    int delayMinutes = minInterval + rand() % range;
    int delayMs = delayMinutes * 60 * 1000;

    qDebug() << "Media file:" << mediaFilePath;
    qDebug() << "Waiting for" << delayMinutes << "minute(s) before running jumpscare.";

    QTimer::singleShot(delayMs, [&]() {
        qDebug() << "Jumpscare activated! Displaying media:" << mediaFilePath;
        // TODO: do full-screen scare
        app.quit();
        });

    //MainWindow w;
    //w.resize(400, 200);
    //w.show();
    return app.exec();
}