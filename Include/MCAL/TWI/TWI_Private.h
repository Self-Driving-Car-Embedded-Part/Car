/*
 * TWI_Private.h
 *
 * Created: 4/14/2023 4:00:21 PM
 *  Author: Dell
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


#define TWCR_TWEN 2
#define TWCR_TWST0 4
#define TWCR_TWSTA 5
#define TWCR_TWEA 6
#define TWCR_TWINT 7

#define TWSR_TWPS0 0
#define TWSR_TWPS1 1

#define TWDR_TWDR0 0

#define TWAR	*((volatile u8*)0x22)
#define TWBR	*((volatile u8*)0x20)
#define TWCR	*((volatile u8*)0x56)
#define TWDR	*((volatile u8*)0x23)
#define TWSR	*((volatile u8*)0x21)


#define START_ACK 0x08
#define REP_START_ACK 0x10
#define SLAVE_ADD_AND_WR_ACK 0x18
#define SLAVE_ADD_AND_RD_ACK 0x40
#define MASTER_WR_BYTE_ACK 0x28
#define MASTER_RD_BYTE_WITH_ACK 0x50
#define MASTER_RD_BYTE_WITH_NACK 0x58 
#define SLAVE_ADD_RCVD_RD_REQ 0xA8
#define SLAVE_ADD_RCVD_WR_REQ 0x60
#define SLAVE_DATA_RECEIVED	0x80
#define SLAVE_BYTE_TRANSMITTED 0xbb

#define STATUS_BIT_MASK 0xF8
#endif /* TWI_PRIVATE_H_ */