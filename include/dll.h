#pragma once

#if defined(__linux) || defined(__linux__) || defined(linux)
#define API_EXPORT extern "C" __attribute__((visibility("default")))
#define API_IMPORT extern "C" __attribute__((visibility("hidden")))
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#define API_EXPORT extern "C" __declspec(dllexport)
#define API_IMPORT extern "C" __declspec(dllimport)
#else
#define API_EXPORT
#define API_IMPORT
#endif

#ifdef LIB_IMPORT
#define API_METHOD API_IMPORT
#else
#define API_METHOD API_EXPORT
#endif

#ifndef CALL_CONV
#if defined(__linux) || defined(__linux__) || defined(linux)
#define CALL_CONV
#else
#define CALL_CONV _cdecl
#endif
#endif

#include "api_types.h"

API_EXPORT uint32_t CALL_CONV
RG_GetVersion();

/// <summary>
/// ��������� ������������� ���������� ���������� ����������.
/// </summary>
API_EXPORT uint32_t CALL_CONV
RG_InitializeLib();

/// <summary>
/// ��������� ������ ���������� ���������� ����������.
/// </summary>
/// <returns></returns>
API_METHOD uint32_t  CALL_CONV
RG_Uninitialize();

/// <summary>
/// ��������� � ���������� ����� ���������� ������ �� ���������� �����������.
/// </summary>
/// <param name="handle">���������� �������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_CloseResource(void* handle);

/// <summary>
/// ��������� ����� ��������� ����� �����������.
/// </summary>
/// <param name="pEndPointListHandle">��������� �� ����������, � �������� ����� ������� ���������� ������ ��������� ����� �����������.</param>
/// <param name="pCount">����� ����� �������� �����.</param>
/// <param name="pCount">��������� �� ����������, �� �������� ����� ��������� ����������� ��������� � ������ �����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_FindEndPoints(void** pEndPointListHandle, uint8_t enpointTypeMask, uint32_t* pCount);

/// <summary>
/// ��������� �� ������ �����������, ����������� � ������� ������� RG_GetEndpointList, ���������� � ����� ����������� �� ���������� �������.
/// </summary>
/// <param name="endPointListHandle">���������� ������ ����� �����������, ���������� ����� RG_GetEndpointList.</param>
/// <param name="listIndex">������ � ������.</param>
/// <param name="pEndpointInfo">��������� �� ��������� ���������� � ����� �����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_GetFoundEndPointInfo(void* endPointListHandle, uint32_t listIndex, PRG_ENDPOINT_INFO pEndpointInfo);

/// <summary>
/// ��������� ����� ��������� �� ���� ��������� ������ �����������.
/// </summary>
/// <param name="pDevicesListHandle">��������� �� ����������, � �������� ����� ������� ���������� ������ ��������� ���������.</param>
/// <param name="pCount">��������� �� ����������, �� �������� ����� ��������� ����������� ��������� � ������ �����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_FindDevices(void** pDevicesListHandle, uint8_t endpointTypeMask, uint32_t* pCount);

/// <summary>
/// ��������� �� ������ �����������, ����������� � ������� ������� RG_GetDevicesList, ���������� �� ���������� �� �������.
/// </summary>
/// <param name="deviceListHandle">���������� ������ ��������� ���������, ���������� ����� RG_GetDevicesList.</param>
/// <param name="listIndex">������ � ������.</param>
/// <param name="pEndpointInfo">��������� �� ��������� ���������� � ����� �����������.</param>
/// <param name="pDeviceInfoExt">��������� �� ��������� ����������� ���������� �� ����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_GetFoundDeviceInfo(void* deviceListHandle, uint32_t ListIndex, PRG_ENDPOINT_INFO pEndpointInfo, PRG_DEVICE_INFO_EXT pDeviceInfoExt);

/// <summary>
/// ������������� ����������.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_InitDevice(PRG_ENDPOINT pEndPoint, uint8_t address);

/// <summary>
/// ���������� ��������� ����������. ����������� ��������� �������������.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_CloseDevice(PRG_ENDPOINT pEndPoint, uint8_t address);

/// <summary>
/// ������ ���������� �� ����������. ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pDeviceInfo">��������� �� ��������� ���������� �� ����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_GetInfo(PRG_ENDPOINT pEndPoint, uint8_t address, PRG_DEVICE_INFO_SHORT pDeviceInfo);

/// <summary>
/// ������ ����������� ���������� �� ����������.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pDeviceInfo">��������� �� ��������� ����������� ���������� �� ����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_GetInfoExt(PRG_ENDPOINT pEndPoint, uint8_t address, PRG_DEVICE_INFO_EXT pDeviceInfo);

/// <summary>
/// ������ ��� ���������� ���� ����������� ����. ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="mCardsFamilyMask">����� ����� ����������� ����, �������� E_RG_CARD_FAMILY_CODE.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_SetCardsMask(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t mCardsFamilyMask);

/// <summary>
/// ������� ��� ������� �� ������ ����������. ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_ClearProfiles(PRG_ENDPOINT pEndPoint, uint8_t address);

/// <summary>
/// ���������� ������� � ������ ����������. ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="mProfileNum">����� �������, ��� ������� �� ����� ������� � ������ ����������.</param>
/// <param name="mBlockNum">����� ����� �����.</param>
/// <param name="pCardAuthParams">��������� �� ��������� ���������� ����������� �����.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_WriteProfile(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t profileNum, uint8_t blockNum, PRG_CARD_AUTH_PARAMS pCardAuthParams);

/// <summary>
/// ���������� ���������� � ������ ����������. ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="mCodogrammNum">����� ����������, ��� ������� ��� ����� �������� � ������ ����������.</param>
/// <param name="pCodogramm">��������� �� ��������� �������������� ����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_WriteCodogramm(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t codogrammNum, PRG_CODOGRAMM pCodogramm);

/// <summary>
/// ��������� ���������� ��������� �� ��������� ������� ��������� �� ��������� ������ ����������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ���������� ������ ���� �������� � ������ ���������� ������� RG_WriteCodogramm
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="priority">��������� ����������.</param>
/// <param name="sChannelNum">����� ���������� ��� ��������� ������.</param>
/// <param name="rChannelNum">����� ���������� ��� �������� ������.</param>
/// <param name="gChannelNum">����� ���������� ��� �������� ������.</param>
/// <param name="bChannelNum">����� ���������� ��� ������ ������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_StartCodogramm(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t priority, uint8_t sChannelNum, uint8_t rChannelNum, uint8_t gChannelNum, uint8_t bChannelNum);

/// <summary>
/// ���������� ������ � ���� ������ ����� �� ���������� ������ �������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ������� ������ ���� �������������� ������� � ������ ���������� ������� RG_WriteProfile.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pMemory">��������� �� ��������� ������ ����� ������. ������ ������� ����������� � pMemory->profile_block.</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_WriteBlock(PRG_ENDPOINT pEndPoint, uint8_t address, PRG_CARD_MEMORY pMemory);

/// <summary>
/// ���������� ������ � ��������� ���� ������ ����� ��������� ��������� ��������� �����������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pMemory">��������� �� ��������� ������ ����� ������. ����� ����� ����������� � pMemory->profile_block.</param>
/// <param name="pCardAuthParams">��������� �� ��������� ���������� ����������� �����.</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_WriteBlockDirect(PRG_ENDPOINT pEndPoint, uint8_t address, PRG_CARD_MEMORY pMemory, PRG_CARD_AUTH_PARAMS pCardAuthParams);

/// <summary>
/// ��������� ������ �� ����������� ����� ������ ����� ��������� ��������� ��������� �����������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pMemory">��������� �� ��������� ������ ����� ������. ����� ����� ����������� � pMemory->profile_block.</param>
/// <param name="pCardAuthParams">��������� �� ��������� ���������� ����������� �����.</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_ReadBlockDirect(PRG_ENDPOINT pEndPoint, uint8_t address, PRG_CARD_MEMORY pMemory, PRG_CARD_AUTH_PARAMS pCardAuthParams);

/// <summary>
/// ��������� ������ �� ����������� ����� ������ ����� ��������� ��������� ��������� �����������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pStatusType">��������� �� ����������, �� �������� ����� �������� ������� �������� ������.</param>
/// <param name="pPinStates">��������� �� ����������, �� �������� ����� �������� ����� �������� ��������� ������/�������.</param>
/// <param name="pCardInfo">��������� �� ��������� ���������� � �����, ����������� � ����������� �� �������� �������.</param>
/// <param name="pMemory">��������� �� ��������� ������, ��������� �� ����� ������ ����� ��� �������� ����������� �� �������. ����� ������� ����������� � pMemory->profile_block.</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_GetStatus(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t* pStatusType, uint8_t* pPinStates, PRG_CARD_INFO pCardInfo, PRG_CARD_MEMORY pMemory);

/// <summary>
/// ��������� ������ �� ����������� ����� ������ ����� ��������� ��������� ��������� �����������.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pStatusType">��������� �� ����������, �� �������� ����� �������� ������� �������� ������.</param>
/// <param name="pUidBuffer">��������� �� ���� ������, ��� �������� UID.</param>
/// <param name="uidBufferSize">������ ����� ������ �� ��������� pUidBuffer.</param>
/// <param name="pUidSize">��������� �� ����������, � ������ ����� ������� ������ UID �����.</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_GetCard(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t* pStatusType, uint8_t* pUidBuffer, int32_t uidBufferSize, int32_t*
           pUidSize);


/// <summary>
/// �������� �� ������� ���������� �������� �����.
/// </summary>
/// <param name="pDeviceEventsQueue">��������� �� ����������, � �������� ����� ������� ���������� ������� ������� ���������� ��� ������� ��������.</param>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="eventsMask">����� ����� ������� ����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_Subscribe(void** pDeviceEventsQueue, PRG_ENDPOINT pEndPoint, uint8_t address, uint32_t eventsMask, void* systeEventHandle);

/// <summary>
/// ��������� ������� �� ������� ������� ���������� ��� ������� ����������� ������ ������� ��� ������ �������.
/// </summary>
/// <param name="deviceEventsQueue">���������� ������� ������� ����������.</param>
/// <param name="pEventType">��������� �� ����������, � ������� ����� ������� ��� ������������ �������.</param>
/// <param name="pEventMem">��������� �� ��������� �� ������� ������, �� �������� ����� ������ ����� �������� ���������� �������.</param>
/// <param name="pollWaitTimeoutMs">����� �������� ��� ���������� ����� ������� � �������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_PollEvents(void* deviceEventsQueue, uint32_t* pEventType, void** pEventMem, uint32_t pollWaitTimeoutMs);

/// <summary>
/// ��������� ���������� �� ������ ������
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_IsolateDevice(PRG_ENDPOINT pEndPoint, uint8_t address);

/// <summary>
/// ������� �������� � ����������
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns>��� ������</returns>
API_METHOD uint32_t CALL_CONV
RG_ResetIsolation(PRG_ENDPOINT pEndPoint, uint8_t address);

/// <summary>
/// ������ ��������� ������������ ������/����� �� ��� ������ �� ��������� �����.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="outputNum">����� ������.</param>
/// <param name="state">����� ���������. ���� ������� <c>true</c> ����� ����� ���������� � ��������, ����� - � �����.</param>
/// <param name="timeSec">����� ������������ � ��������, 0 = ���������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_SetControlOutputState(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint8_t outputNum, bool state, uint8_t timeSec);

/// <summary>
/// ���������� ���� �� �����, ����������� ��� ������������ ����� �� ������ ������ � ������ (��������, ��� ������������ �� SL1 � SL3) � ������ ��������
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ��� ������� �������� �������� �� �������, ��������� ����� RG_IsolateDevice().
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_ResetField(PRG_ENDPOINT pEndPoint, uint8_t mAddress);

/// <summary>
/// ��������� ���� ������� ���� � ����, ��������� ������������ � ����� �����.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ��� ������� �������� �������� �� �������, ��������� ����� RG_IsolateDevice().
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pSak">��������� �� ���������� ��� ������ ���� SAK (Select Acknowledge)</param>
/// <param name="pAtqa">��������� �� ���������� ��� ������ ���� ���� ����� Mifare.</param>
/// <param name="pUidBuf">��������� �� ���� ������ ��� ���������� UID ��������� �����.</param>
/// <param name="uidBufSize">������ ����� ������ �� ��������� pUidBufSize.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_Iso_Ras(PRG_ENDPOINT pEndPoint, uint8_t address, uint16_t* pSak, uint16_t* pAtqa, uint8_t* pUidBuf, int32_t uidBufSize);

/// <summary>
/// ��������� ������� �������� �� ����� �� ISO 14443-4
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ��� ������� �������� �������� �� �������, ��������� ����� RG_IsolateDevice().
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pAtsBuf">��������� �� ���� ������ ��� ������ UID ��������� �����.</param>
/// <param name="atsBufSize">������ ����� ������ �� ��������� pAtsBuf</param>
/// <param name="pAtsSize">��������� �� ����������, ��� ������ ���������� ����, ����������� � pAtsBuf.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_Iso_Rats(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t* pAtsBuf, int32_t atsBufSize, int32_t* pAtsSize);

/// <summary>
/// ��������� ������������ �������� ������ �� ��������� ISO14443-4.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ��� ������� �������� �������� �� �������, ��������� ����� RG_IsolateDevice().
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pReqBuf">��������� �� ���� ������, � ������� �������� ������������ ������.</param>
/// <param name="reqBufSize">������ ����� ������ �� ��������� pDataBuf.</param>
/// <param name="pRespBuf">��������� �� ���� ������, � ������� ����� �������� ����� �� ���������� ���������.</param>
/// <param name="respBufSize">������ ����� ������ �� ��������� respBufSize.</param>
/// <param name="pRespSize">��������� �� ����������, ��� ������ ���������� ����, ����������� � pRespBuf.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_Iso_Exchange(PRG_ENDPOINT pEndPoint, uint8_t address, const uint8_t* pReqBuf, int32_t reqBufSize, uint8_t* pRespBuf, int32_t
                respBufSize, int32_t* pRespSize);

/// <summary>
/// ����������� ������� ����� Mifare.
/// ��������� ��������������� ������������� ���������� ������� RG_InitDevice.
/// ��� ������� �������� �������� �� �������, ��������� ����� RG_IsolateDevice().
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="blockNum">����� ����� �������, � ������� ������������ �����������.</param>
/// <param name="pKeyBuf">��������� �� ���� ������ � ������� ����� �����������.</param>
/// <param name="keyBufSize">������ ����� ������/������ �� ��������� pKeyBuf (����������� ���������� ������ ����� - 16 ����).</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_Iso_Auth(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint16_t blockNum, const uint8_t* pKeyBuf, int32_t keyBufSize);

/// <summary>
/// ��������� ����������� ������� ����� Mifare Classic
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="blockNum">����� ����� �������, � ������� ������������ �����������.</param>
/// <param name="keyType">��� ������������� ����� ����������� (A/B).</param>
/// <param name="pKeyBuf">��������� �� ���� ������, ����������, ��� �������, 6 ���� ������� ����� �����������.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_MF_AuthorizeClassic(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint8_t blockNum, uint8_t keyType, uint8_t* pKeyBuf);

/// <summary>
/// ��������� ������ ������ �� ����� ������ ����� Mifare Classic/Plus
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="flags">����� ������������ ��� �����, � ������� ������������ ������.</param>
/// <param name="blockNum">����� ����� �����.</param>
/// <param name="pDataBuf">��������� �� ���� ������, � ������� ����� �������� ������ ��������� �� ����� ������ �����.</param>
/// <param name="dataBufSize">������ ����� ������ �� ��������� pDataBuf.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_MF_ReadBlock(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint8_t blockNum, uint8_t flags, uint8_t* pDataBuf, int32_t dataBufSize);

/// <summary>
/// ��������� ������ ������ � ���� ������ ����� Mifare Classic/Plus
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="mAddress">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="flags">����� ������������ ��� �����, � ������ ������� ������������ ������ (Classic/Plus).</param>
/// <param name="blockNum">����� ����� �����.</param>
/// <param name="pDataBuf">��������� �� ���� ������ ���������� ������, ������� ���������� �������� � ���� ������ �����.</param>
/// <param name="dataBufSize">������ ����� ������ �� ��������� pDataBuf.</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_MF_WriteBlock(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint8_t blockNum, uint8_t flags, uint8_t* pDataBuf, int32_t dataBufSize);

/// <summary>
/// ��������� �������� PIN-���� ������ ����������
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pin">PIN-���</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_UnlockSettigns(PRG_ENDPOINT pEndPoint, uint8_t address, uint16_t pin);

/// <summary>
/// ��������� �������� PIN-���� ������ ����������
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="pin">PIN-���</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_CommitSettings(PRG_ENDPOINT pEndPoint, uint8_t address, uint16_t pin);

/// <summary>
/// ��������� ������ ����� ����������
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="blockType">��� ����� ����������, �������� E_RG_SETTINGS_BLOCK_TYPE</param>
/// <param name="blockNum">����� �����/�������</param>
/// <param name="block32Buf">��������� �� ������� ������, ���� ����� ����������� ������ ������ ����� �� ������ ����������</param>
/// <param name="block32BufSize">������ ����� ������ �� ��������� pBlockData</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_ReadSettingsBlock(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t blockType, uint16_t blockNum, uint8_t* block32Buf, int32_t
                     block32BufSize);

/// <summary>
/// ��������� ������ ����� ����������
/// </summary>
/// <param name="pEndPoint">��������� �� ��������� ���������� �����������.</param>
/// <param name="address">����� ���������� (0...3, � ����������� �� ���� �����������).</param>
/// <param name="blockType">��� ����� ����������, �������� E_RG_SETTINGS_BLOCK_TYPE</param>
/// <param name="blockNum">����� �����/�������</param>
/// <param name="block32Buf">��������� �� ������� ������ � ������� ����� ����������, ������� ��������� ��������, �� ����� 32 ����.</param>
/// <param name="block32BufSize">������ ����� ������ �� ��������� pBlockData</param>
/// <returns></returns>
API_METHOD uint32_t CALL_CONV
RG_WriteSettingsBlock(PRG_ENDPOINT pEndPoint, uint8_t address, uint8_t blockType, uint16_t blockNum, uint8_t* block32Buf, int32_t
                      block32BufSize);



API_METHOD uint32_t CALL_CONV
RG_UpdateFirmware(PRG_ENDPOINT pEndPoint, uint8_t mAddress, const char* fwFilePath, void (*firmwarecb)(uint8_t mode, uint16_t currentBlock, uint16_t totalBlocks, uint32_t error));

API_METHOD uint32_t CALL_CONV
RG_FP_EnrollAndStoreRam(PRG_ENDPOINT pEndPoint, uint8_t mAddress);

API_METHOD uint32_t CALL_CONV
RG_FP_ReadEnroll(PRG_ENDPOINT pEndPoint, uint8_t mAddress, uint8_t* enrollBuffer, int32_t enrollBufferSize);

API_METHOD uint32_t CALL_CONV
RG_FP_ReadEnrollToFile(PRG_ENDPOINT pEndPoint, uint8_t mAddress, const char* enrollFilePath);
