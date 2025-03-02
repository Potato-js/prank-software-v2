#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <qstring.h>

struct ConfigData {
	QString mediaFilePath;
	int minInterval;
	int maxInterval;
};

#endif // !CONFIGREADER_H
