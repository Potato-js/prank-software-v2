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
		errorMessage = "Template executable not found at: " + templateExe;
		return false;
	}

	QDir outDir(outputDir);
	if (!outDir.exists() && !outDir.mkpath(".")) {
		errorMessage = "Failed to create output directory: " + outputDir;
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

	QString launcherFile = outDir.absoluteFilePath("launch_prank.bat");
	QFile file(launcherFile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
          errorMessage = "Failed to write configuration file: " + launcherFile;
		return false;
	}
	QTextStream out(&file);
	
    QString command = "prank.exe \"" + mediaFilePath + "\" " +
                          QString::number(minInterval) + " " +
                          QString::number(maxInterval);
    out << "@echo off\n";
    out << command << "\n";
    file.close();	

	qDebug() << "Executable generated successfully at:" << outputDir;
	return true;
}