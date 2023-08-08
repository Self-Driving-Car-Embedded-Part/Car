/*
 * TWI_Interface.h
 *
 * Created: 4/14/2023 4:00:39 PM
 *  Author: Dell
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum 
{
	NoError,
	StartConditonError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteWithACKError,
	MasterReadByteWithACKError
}TWI_ErrorStatus_t;

void MTWI_voidInitMaster(u8 Copy_u8Address);
void MTWI_voidInitSlave(u8 Copy_u8Address);
TWI_ErrorStatus_t MTWI_ErrorStatusSendStartConditionWithACK();
TWI_ErrorStatus_t MTWI_ErrorStatusSendRepeatedStartConditionWithACK();
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t MTWI_ErrorStatusMsterWriteDataByteWithACK(u8 Copy_u8DataByte);
TWI_ErrorStatus_t MTWI_ErrorStatusMsterReadDataByteWithACK(u8* Copy_pu8ReceivedByte);
void MTWI_voidSendStopCondition();
#endif /* TWI_INTERFACE_H_ */