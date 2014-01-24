#ifndef CORE_UTILS_LOG_H
#define CORE_UTILS_LOG_H
#include "logging.h"

//�ڳ�������Ŀ¼�¼�����log �ļ���
void static initLog()
{
	google::InitGoogleLogging("");
	google::SetLogDestination(google::GLOG_INFO, "log/info.log");
	google::SetLogDestination(google::GLOG_ERROR, "log/error.log");
	google::SetLogDestination(google::GLOG_WARNING, "log/warning.log");
}

#endif