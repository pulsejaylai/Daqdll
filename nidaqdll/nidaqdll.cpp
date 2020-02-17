// nidaqdll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "NIDAQmx.h"


/*extern "C" __declspec(dllexport) UINT32 CreatTask(const char *taskName, TaskHandle taskHandle)
{
	int32 errcode;
	UINT32 handel;
	// TODO: Add extra initialization here
	errcode = DAQmxCreateTask(taskName, &taskHandle);
	handel = *(UINT32*)taskHandle;
	return handel;
}
*/
extern "C" __declspec(dllexport) UINT32 CreatTask()
{
	int32 errcode;
	UINT32 handel;
	TaskHandle taskHandle;
	// TODO: Add extra initialization here
	errcode = DAQmxCreateTask("", &taskHandle);
	handel = *(UINT32*)&taskHandle;
	return handel;
}

extern "C" __declspec(dllexport) int32 ConfigChann(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units)
{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxCreateAIVoltageChan(taskHandle, physicalChannel, nameToAssignToChannel, terminalConfig, minVal, maxVal, units, NULL);

	return errcode;
}

extern "C" __declspec(dllexport) int32 ConfigDOChann(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[])
{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxCreateDOChan(taskHandle, physicalChannel, nameToAssignToChannel, 1);

	return errcode;
}


extern "C" __declspec(dllexport) int32 ConfigSampleClk(TaskHandle taskHandle,  float64 rate, int32 activeEdge, int32 sampleMode, uInt64 sampsPerChanToAcquire)

{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxCfgSampClkTiming(taskHandle, "", rate, activeEdge, sampleMode, sampsPerChanToAcquire);

	return errcode;
}
extern "C" __declspec(dllexport) int32 StartTask(TaskHandle taskHandle)
{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxStartTask(taskHandle);

	return errcode;
}

extern "C" __declspec(dllexport) int32 ReadDCVol(TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, float64 readArray[],  int32 sampsPerChanRead)

{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxReadAnalogF64(taskHandle, numSampsPerChan, timeout, DAQmx_Val_GroupByChannel, readArray, 1000,&sampsPerChanRead,NULL);

	return errcode;
}

extern "C" __declspec(dllexport) int32 Writeport(TaskHandle taskHandle, int32 numSampsPerChan, bool32 autostart, float64 timeout, uInt32 data, int32 sampsPerChanWrite)

{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxWriteDigitalU32(taskHandle, numSampsPerChan, autostart, timeout, DAQmx_Val_GroupByChannel, &data, &sampsPerChanWrite, NULL);

	return errcode;
}



extern "C" __declspec(dllexport) int32 StopTask(TaskHandle taskHandle)
{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxStopTask(taskHandle);

	return errcode;
}
extern "C" __declspec(dllexport) int32 ClearTask(TaskHandle taskHandle)
{
	int32 errcode;

	// TODO: Add extra initialization here
	errcode = DAQmxClearTask(taskHandle);

	return errcode;
}
extern "C" __declspec(dllexport) char* GetErrInfo(int32 errorCode)
{
	char errorString[2048];
	char* errorString2;
	// TODO: Add extra initialization here
//	strcpy_s(errorString, 2048, "");
	DAQmxGetErrorString(errorCode, errorString,2048);
	errorString2 = errorString;
	return errorString2;
}