
#include "NetworkRecorder.h"

const std::string OUTPUT_FILENAME="network_issues.log";
const std::vector<std::string> FILTERS={"timeout"};

NetworkRecorder::NetworkRecorder(const std::string& name)
:FileRecorderFilter(name,OUTPUT_FILENAME,FILTERS){

}
