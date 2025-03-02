#ifndef PRANKGENERATOR_H
#define PRANKGENERATOR_H
#include <qstring.h>

class PrankGenerator {
public:
    // Generates the executable file in the given output directory.
    // Parameters:
    //   mediaFilePath - the full path to the media file selected by the user
    //   minInterval   - minimum delay interval before the prank is executed
    //   maxInterval   - maximum delay interval before the prank is executed
    //   outputDir     - directory in which to save the generated .exe file and configuration file
    //   errorMessage  - returns an error message if generation fails
    // Returns 'true' on success, 'false' on failure.
    static bool generateExecutable(const QString& mediaFilePath, int minInterval, int maxInterval,
        const QString& outputDir, QString& errorMessage);
};

#endif // !PRANKGENERATOR_H
