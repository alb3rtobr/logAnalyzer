#include "CriticalRecorder.h"

const std::string OUTPUT_FILENAME="critic_issues.log";
const std::vector<std::string> FILTERS={"coredump","aborted","panic"};

CriticalRecorder::CriticalRecorder(const std::string& name)
:FileRecorderFilter(name,OUTPUT_FILENAME,FILTERS){

}




