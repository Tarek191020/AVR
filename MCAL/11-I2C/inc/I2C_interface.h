/*
 * I2C_interface.h
 *
 * Created: 3/23/2024 12:59:09 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_





/*************** APIS PROTOTYPES ***************/

//Master APIS
void I2C_voidInitMaster                   (u8 copy_u8MasterAddress);
void I2C_voidSendStartCondition           (void);
void I2C_voidSendRepeatedStartCondition   (void);
void I2C_voidSendStopCondition            (void);
void I2C_voidSendSlaveAddWithWrite        (u8  copy_u8SlaveAdd);
void I2C_voidSendSlaveAddWithRead         (u8  copy_u8SlaveAdd);
void I2C_voidTransmitMasterDataByte       (u8  copy_u8TxData);
void I2C_voidReceiveMasterDataByteWithAck (u8* copy_pu8RxData);
void I2C_voidReceiveMasterDataByteWithNack(u8* copy_pu8RxData);

//Slave APIS
void I2C_voidInitSlave                    (u8 copy_u8SlaveAddress);
void I2C_voidTransmitSlaveDataByte        (u8  copy_u8TxData);
void I2C_voidReceiveSlaveDataByteWithAck  (u8* copy_pu8RxData);
void I2C_voidReceiveSlaveDataByteWithNack (u8* copy_pu8RxData);


#endif /* I2C_INTERFACE_H_ */