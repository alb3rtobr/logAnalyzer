
#include "UnknownRecorder.h"

const std::string OUTPUT_FILENAME="unknown_issues.log";
const std::vector<std::string> FILTERS={"unexpected"};

UnknownRecorder::UnknownRecorder(const std::string& name)
:FileRecorderFilter(name,OUTPUT_FILENAME,FILTERS){

}
