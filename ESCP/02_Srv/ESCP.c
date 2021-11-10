/***************************************************\
 * ESCP.c
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

#include "../02_Srv/ESCP.h"

#include "../02_Srv/ESCP_internal.h"
#include "../02_Srv/ESCP_user_cfg.h"

/***************************************************\
 * DEFINES
\***************************************************/

#define MAX_FRAME_DATA_SIZE		((uint8_t)(256u))



/***************************************************\
 * TYPEDEFS
\***************************************************/

typedef struct
{
	ESCP_receiverAddress_T  		receiverAddress;
	ESCP_senderAddress_T 			senderAddress;
	ESCP_mesageOptions_T 			messageOptions;
	ESCP_byte4th_T 					byte4th;
	uint8_t[MAX_FRAME_DATA_SIZE]	data;
	ESCP_CRC_T						CRC;
}ESCP_frame_T;

/***************************************************\
 * EXPORTED VARIABLES
\***************************************************/

/***************************************************\
 * LOCAL VARIABLES
\***************************************************/

static ESCP_frame_T ESCPframe = 0;

/***************************************************\
 * FUNCTION PROTOTYPES
\***************************************************/



/***************************************************\
\***************************************************/



void ESCP_main(void)
{

}





















