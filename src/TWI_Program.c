/*
 * TWI_Program.c
 *
 * Created: 4/14/2023 4:02:56 PM
 *  Author: Dell
 */ 

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_Private.h"
#include "../Include/MCAL/TWI/TWI_Cfg.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"

void MTWI_voidInitMaster(u8 Copy_u8Address)
{
	SET_BIT(TWCR,TWCR_TWEA);
	
	TWBR = 2;
	
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	
	if(Copy_u8Address == 0){}
	else{
		TWAR = (Copy_u8Address<<1);
	}
	SET_BIT(TWCR,TWCR_TWEN);
}


void MTWI_voidInitSlave(u8 Copy_u8Address)
{
	TWAR = Copy_u8Address<<1;
	SET_BIT(TWCR,TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus_t MTWI_ErrorStatusSendStartConditionWithACK()
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	
	TWCR |= (1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN);
	
	while(! GET_BIT(TWCR,TWCR_TWINT));
	
	if((TWSR & STATUS_BIT_MASK) != START_ACK)
	{
		local_ErrorStatus = StartConditonError;
	}
	return local_ErrorStatus;
}


TWI_ErrorStatus_t MTWI_ErrorStatusSendRepeatedStartConditionWithACK()
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(! GET_BIT(TWCR,TWCR_TWINT));
	
	if((TWSR & STATUS_BIT_MASK) != REP_START_ACK)
	{
		local_ErrorStatus  = RepeatedStartError;
	}
	return local_ErrorStatus;
}

TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,TWDR_TWDR0);
	
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(! GET_BIT(TWCR,TWCR_TWINT));
	if((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		local_ErrorStatus = SlaveAddressWithWriteError;
	}
	return local_ErrorStatus;
}


TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	TWDR = Copy_u8SlaveAddress << 1;
	SET_BIT(TWDR,TWDR_TWDR0);
	
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(! GET_BIT(TWCR,TWCR_TWINT));
	if((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		local_ErrorStatus = SlaveAddressWithReadError;
	}
	return local_ErrorStatus;
}

TWI_ErrorStatus_t MTWI_ErrorStatusMsterWriteDataByteWithACK(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	TWDR = Copy_u8DataByte;
	SET_BIT(TWCR,TWCR_TWINT);
	while(!GET_BIT(TWCR,TWCR_TWINT));
	if((TWSR & STATUS_BIT_MASK) != MASTER_WR_BYTE_ACK)
		local_ErrorStatus = MasterWriteByteWithACKError;
	return local_ErrorStatus;
}

TWI_ErrorStatus_t MTWI_ErrorStatusMsterReadDataByteWithACK(u8* Copy_pu8ReceivedByte)
{
	TWI_ErrorStatus_t local_ErrorStatus = NoError;
	SET_BIT(TWCR,TWCR_TWINT);
	while(!GET_BIT(TWCR,TWCR_TWINT));
	if ((TWSR & STATUS_BIT_MASK) != MASTER_RD_BYTE_WITH_ACK)
	{
		local_ErrorStatus = MasterReadByteWithACKError;
	}
	else
	{
		*Copy_pu8ReceivedByte = TWDR;
	}
	return local_ErrorStatus;
}


void MTWI_voidSendStopCondition()
{
	SET_BIT(TWCR,TWCR_TWST0);
	SET_BIT(TWCR,TWCR_TWINT);
}