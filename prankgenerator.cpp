#include "prankgenerator.h"
#include <qfile.h>
#include <qdir.h>
#include <qcoreapplication.h>
#include <qtextstream.h>
#include <qdebug.h>

bool PrankGenerator::generateExecutable(const QString& mediaFilePath, int minInterval, int maxInterval, const QString& outputDir, QString& errorMessage) {
	QString appDir = QCoreApplication::applicationDirPath();
	QString templateExe = appDir + "/prank_template.exe";
	if (!QFile::exists(templateExe)) {
		errorMessage = "Template executable not found!";
		return false;
	}

	QDir outDir(outputDir);
	if (!outDir.exists() && !outDir.mkpath(".")) {
		errorMessage = "Output directory does not exist!";
		return false;
	}

	QString outputExe = outDir.absoluteFilePath("prank.exe");
	if (QFile::exists(outputExe)) {
		QFile::remove(outputExe);
	}
	if (!QFile::copy(templateExe, outputExe)) {
		errorMessage = "Failed to copy template executable to: " + outputExe;
		return false;
	}

	QString configFile = outDir.absoluteFilePath("config.txt");
	QFile file(configFile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		errorMessage = "Failed to write configuration file: " + configFile;
		return false;
	}
	QTextStream out(&file);
	out << mediaFilePath << "\n" << minInterval << "\n" << maxInterval << "\n";
	file.close();

	qDebug() << "Executable generated successfully at:" << outputExe;
	return true;
}