/***************************************************\
 * ESCP_internal.h
 *
 *  Created on: 2021
 *      Author: Wojciech Grzelinski
 *       Email: wojtekgrzela@gmail.com
 *      GitHub: https://github.com/wojtekgrzela/ESCP
 *
\***************************************************/
/***************************************************\
 *
 *  LICENSE: Attribution-NonCommercial 3.0 
 *           (CC BY-NC 3.0)
 *  More at: https://creativecommons.org/
 *  Copyright (c) 2021 wojtekgrzela
 *
\***************************************************/



/***************************************************\
 * INCLUDES
\***************************************************/

#include "../02_Srv/ESCP_user_cfg.h"

/***************************************************\
 * DEFINES
\***************************************************/

#ifndef uint8_t
#define uint8_t		UNSIGNED_8_BIT_TYPE
#endif

#ifndef uint16_t
#define uint16_t	UNSIGNED_16_BIT_TYPE
#endif

#ifndef uint32_t
#define uint32_t	UNSIGNED_32_BIT_TYPE
#endif

/***************************************************\
 * TYPEDEFS
\***************************************************/

typedef uint8_t ESCP_receiverAddress_T;
typedef uint8_t ESCP_senderAddress_T;

typedef uint8_t returnCode_T;
typedef uint8_t frameDataLength_T;

typedef union
{
	uint8_t ;
	struct request			/* Used when processing a request message */
	{
		uint8_t REQRES	:1;	/* Bit 0   - 1-Request, 0-Response */
		uint8_t CRC		:2;	/* Bit 1:2 - 00-no CRC, 01-CRC-8, 10-CRC-16, 11-CRC-32 */
		uint8_t 		:1;	/* Bit 3   - Reserved for future use */
		uint8_t CNT		:4;	/* Bit 4:7 - Values 0-15 indicates how many more frames are left to be sent */
	};
	struct responseACK		/* Used when processing a response with return code message */
	{
		uint8_t REQRES	:1;	/* Bit 0   - 1-Request, 0-Response */
		uint8_t DATARES	:1;	/* Bit 1   - 0-Response with return code, 1-Response with data */
		uint8_t 		:1;	/* Bit 2   - Reserved for future use */
		uint8_t CNT		:5;	/* Bit 3:7 - Values 0-31 indicates what minimal time delay should be between frames *10ms */
	};
	struct responseData		/* Used when processing a response with data message */
	{
		uint8_t REQRES	:1;	/* Bit 0   - 1-Request, 0-Response */
		uint8_t DATARES	:1;	/* Bit 1   - 0-Response with return code, 1-Response with data */
		uint8_t CRC		:2;	/* Bit 2:3 - 00-no CRC, 01-CRC-8, 10-CRC-16, 11-CRC-32 */
		uint8_t CNT		:4;	/* Bit 4:7 - Values 0-15 indicates how many more frames are left to be sent */
	};
}ESCP_mesageOptions_T;

typedef union
{
	returnCode_T returnCode;
	frameDataLength_T frameDataLength;
}ESCP_4thByte_T;

typedef union
{
	uint32_t CRC8		:8;  /* In case of a 8-bit CRC code */
	uint32_t CRC16		:16; /* In case of a 16-bit CRC code */
	uint32_t CRC32		:32; /* In case of a 32-bit CRC code */
}ESCP_CRC_T;

/***************************************************\
 * EXPORTED VARIABLES
\***************************************************/

/***************************************************\
 * LOCAL VARIABLES
\***************************************************/

/***************************************************\
 * FUNCTION PROTOTYPES
\***************************************************/





#ifndef SRC_ESCP_INTERNAL_H_
#define SRC_ESCP_INTERNAL_H_



#endif /* SRC_ESCP_INTERNAL_H_ */
