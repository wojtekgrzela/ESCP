# ESCP
**ESCP - Embedded Systems Communication Protocol**

The aim of this project is to establish a functional, light, portable communication stack.
There are a few goals which are especially taken into consideration during development of this protocol:
 - **being light weight** - minimum resources required,
 - **configurability** - so unused features can be disabled
 - **portability and accessibility by every embedded system** - which means being used by the smallest microcontrollers with a few kB of memory up to big, multicore systems,
 - **extendability** - so can be used for various purposes and adjusted to specific needs,
 - **physical layer independence** - no matter what type of communication (I2C, SPI, CAN, UART, LIN etc.) you use.
 
Having some experience with different communication protocols and stack, the author tries his best to provide the greatest possible solution for embedded applications.


### Protocol capabilities:
 - Based on requests and answers
 - 255 addresses for different devices (255 - broadcast address)
 - user-configurable maximal length (from 256 up to 4096 bytes)
 - user-configurable requests and data formatting
 
 
### Protocol minimal requirements: //TODO
 - bytes of ROM
 - bytes of RAM




##[Messages flow in requests handling.](docs/REQUESTS.md)



### Standard message response frame when some data needs to be sent back:

| ***Response Frame*** | Receiver Address | Sender Address | Message Options | Data Length |  Data | CRC |
|:--------------------:|:----------------:|:--------------:|:---------------:|:-----------:|:-----:|:---:|
|    length (bytes)    |         1        |        1       |        1        |      1      | 1-256 | 0-4 |

The standard response frame can be between 5 and 264 bytes long. It can contain from 1 to maximum 256 bytes of data (response bytes, data etc.) and 0, 1, 2 or 4 bytes of CRC.

The frame looks very much the same as the request one. The difference in the Message Options byte:
 - **Bit 0** says if the frame carries a request or a response to a request.
 - **Bits 1** says if the response is with data or rather a response code. [More about the responses.](docs/DUMMY.md)
 - **Bit 2:3** say what kind of CRC is used for the message. [More about the CRC.](docs/CRC.md)
 - **Bits 4:7** say how many frames are left to be send. This protocol allows the user to send more than 256 bytes in one answer - the maximum value is 4096 bytes. It is achieved by sending frames one after another. If CNT[0:3]==0 then there is only one frame. If CNT>0 then more frames will follow. [More about the multiframe answers.](docs/DUMMY.md)

| ***Message Options*** |  Bit Name |                                        Description                                        |
|:---------------------:|:---------:|:-----------------------------------------------------------------------------------------:|
| Bit 0                 | REQ / ANS |                                  1 - Request 0 - Answer                                   |
| Bit 1                 | DATARES   |                   1 - Response with Data, 0 - Response with Return Code                   |
| Bit 2:3               | CRC[0:1]  |                     00 - no CRC, 01 - CRC-8, 10 - CRC-16, 11 - CRC-32                     |
| Bit 4:7               | CNT[0:3]  | 0-15: indicates how many more frames are left to be send (if 0 - there is only one frame) |




