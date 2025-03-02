#include "configreader.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qdebug.h>

bool readConfig(const QString& configPath, ConfigData& data) { 
	QFile file(configPath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
          qDebug() << "Could not open file: " << configPath;
          return false;
  }

  QTextStream in(&file);
  data.mediaFilePath = in.readLine().trimmed();
  data.minInterval = in.readLine().trimmed().toInt();
  data.maxInterval = in.readLine().trimmed().toInt();
  file.close();

  if (data.mediaFilePath.isEmpty() || data.minInterval <= 0 || data.maxInterval <= 0 || data.minInterval > data.maxInterval) {
    qDebug() << "Invalid configuration data";
    return false;
  }
  return true;
}