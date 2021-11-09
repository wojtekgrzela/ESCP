## Messages flow in requests handling

### Standard message request frame:

| ***Request Frame*** | Receiver Address | Sender Address | Message Options | Data Length |  Data | CRC |
|:-------------------:|:----------------:|:--------------:|:---------------:|:-----------:|:-----:|:---:|
|    length (bytes)   |         1        |        1       |        1        |      1      | 1-256 | 0-4 |

The standard request frame can be between 5 and 264 bytes long. It can contain from 1 to maximum 256 bytes of data (request bytes, subservices, data etc.) and 0, 1, 2 or 4 bytes of CRC.

The Message Option byte controls different aspects of the communication:
 - **Bit 0** says if the frame carries a request or a response to a request.
 - **Bits 1:2** say what kind of CRC is used for the message. [More about the CRC.](docs/CRC.md)
 - **Bit 3** stays reserved for future use and expanding the protocol if needed.
 - **Bits 4:7** say how many frames are left to be send. This protocol allows the user to send more than 256 bytes in one request - the maximum value is 4096 bytes. It is achieved by sending frames one after another. If CNT[0:3]==0 then there is only one frame. If CNT>0 then more frames will follow. [More about the multiframe request.](docs/DUMMY.md)

| ***Message Options*** |  Bit Name |                                         Description                                        |
|:---------------------:|:---------:|:------------------------------------------------------------------------------------------:|
| Bit 0                 | REQ / RES |                                  1 - Request, 0 - Response                                 |
| Bit 1:2               | CRC[0:1]  |                      00 - no CRC, 01 - CRC-8 10, - CRC-16, 11 - CRC-32                     |
| Bit 3                 | RESERVED  |                                   Reserved for future use                                  |
| Bit 4:7               | CNT[0:3]  |  0-15: indicates how many more frames are left to be send (if 0 - there is only one frame) |


![One Frame Request Flow](/docs/images/One_Frame_Request.drawio.png)