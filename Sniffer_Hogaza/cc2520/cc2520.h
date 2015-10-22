#ifndef CC2520_H_
#define CC2520_H_

#include <msp430f5435a.h>
#include <inttypes.h>

#include "hal_cc2520.h"

#define INCLUDE_PA

/* peripheral interface pin definitions */
#define CC2520_RESET_PIN		(1 << 1)
#define CC2520_VREG_EN_PIN		(1 << 7)
#define CC2520_INT_PIN			(1 << 0)

/* spi pin definitions */
#define CC2520_CS_PIN			(1 << 5)
#define CC2520_CLK_PIN			(1 << 6)
#define CC2520_SIMO_PIN			(1 << 6)
#define CC2520_MISO_PIN			(1 << 7)


/* A microsecond in msp430 cycles at 16MHz */
#define MSP430_USECOND			16
/* A milisecond in msp430 cycles at 16MHz */
#define MSP430_MSECOND			16000
/* Ring buffer length */
#define CC2520_BUF_LEN					512
/* Startup time values (in microseconds) */
#define CC2520_XOSC_MAX_STARTUP_TIME        300
#define CC2520_VREG_MAX_STARTUP_TIME        200
#define CC2520_SRXON_TO_RANDOM_READY_TIME   144

/***********************************************************************************
* CONSTANTS AND DEFINES
*/

// Application parameters
#define RF_CHANNEL              11      // 2.4 GHz RF channel

// BasicRF address definitions
#define PAN_ID                	0x1234

// Node's address
#define NODE_ADDR				0xbeef
// Packet and packet part lengths
#define PKT_LEN_MIC                         8
#define PKT_LEN_SEC                         PKT_LEN_UNSEC + PKT_LEN_MIC
#define PKT_LEN_AUTH                        8
#define PKT_LEN_ENCR                        24

// Packet overhead ((frame control field, sequence number, PAN ID,
// destination and source) + (footer))
// Note that the length byte itself is not included included in the packet length
#define CC2520_PACKET_OVERHEAD_SIZE       ((2 + 1 + 2 + 2 + 2) + (2))
#define CC2520_MAX_PAYLOAD_SIZE	        (127 - CC2520_PACKET_OVERHEAD_SIZE - \
    CC2520_AUX_HDR_LENGTH - CC2520_LEN_MIC)
#define CC2520_ACK_PACKET_SIZE	        5
#define CC2520_FOOTER_SIZE                2
#define CC2520_HDR_SIZE                   10

// The time it takes for the acknowledgment packet to be received after the
// data packet has been transmitted.
#define CC2520_ACK_DURATION		        (0.5 * 32 * 2 * ((4 + 1) + (1) + (2 + 1) + (2)))
#define CC2520_SYMBOL_DURATION	        (32 * 0.5)

// The length byte
#define CC2520_PLD_LEN_MASK               0x7F

// Frame control field
#define CC2520_FCF_NOACK                  0x8841
#define CC2520_FCF_ACK                    0x8861
#define CC2520_FCF_ACK_BM                 0x0020
#define CC2520_FCF_BM                     (~CC2520_FCF_ACK_BM)
#define CC2520_SEC_ENABLED_FCF_BM         0x0008

// Frame control field LSB
#define CC2520_FCF_NOACK_L                LO_UINT16(CC2520_FCF_NOACK)
#define CC2520_FCF_ACK_L                  LO_UINT16(CC2520_FCF_ACK)
#define CC2520_FCF_ACK_BM_L               LO_UINT16(CC2520_FCF_ACK_BM)
#define CC2520_FCF_BM_L                   LO_UINT16(CC2520_FCF_BM)
#define CC2520_SEC_ENABLED_FCF_BM_L       LO_UINT16(CC2520_SEC_ENABLED_FCF_BM)

// Auxiliary Security header
#define CC2520_AUX_HDR_LENGTH             5
#define CC2520_LEN_AUTH                   CC2520_PACKET_OVERHEAD_SIZE + \
    CC2520_AUX_HDR_LENGTH - CC2520_FOOTER_SIZE
#define CC2520_SECURITY_M                 2
#define CC2520_LEN_MIC                    8
#ifdef SECURITY_CCM
#undef CC2520_HDR_SIZE
#define CC2520_HDR_SIZE                   15
#endif

// Footer
#define CC2520_CRC_OK_BM                  0x80

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define MIN_CHANNEL 				        11    // 2405 MHz
#define MAX_CHANNEL                         26    // 2480 MHz
#define CHANNEL_SPACING                     5     // MHz

/* Type definitions */

typedef struct {
    uint8_t reg;
    uint8_t val;
} regVal_t;

typedef struct {
    uint16_t myAddr;
    uint16_t panId;
    uint8_t channel;
    uint8_t ackRequest;
    #ifdef SECURITY_CCM
    uint8_t* securityKey;
    uint8_t* securityNonce;
    #endif
} cc2520_cfg_t;

// The receive struct
typedef struct {
    uint8_t seqNumber;
    uint16_t srcAddr;
    uint16_t srcPanId;
    int8_t length;
    uint8_t* pPayload;
    uint8_t ackRequest;
    int8_t rssi;
    volatile uint8_t isReady;
    uint8_t status;
} cc2520_rxInfo_t;

// Tx state
typedef struct {
    uint8_t txSeqNumber;
    volatile uint8_t ackReceived;
    uint8_t receiveOn;
    uint32_t frameCounter;
} cc2520_rxState_t;

// Basic RF packet header (IEEE 802.15.4)
typedef struct {
    uint8_t   packetLength;
    uint8_t   fcf0;           // Frame control field LSB
    uint8_t   fcf1;           // Frame control field MSB
    uint8_t   seqNumber;
    uint16_t  panId;
    uint16_t  destAddr;
    uint16_t  srcAddr;
    #ifdef SECURITY_CCM
    uint8_t   securityControl;
    uint8_t  frameCounter[4];
    #endif
} cc2520_packetHdr_t;

/* External functions */

uint8_t cc2520_init();
uint8_t cc2520_packetSend(uint8_t len, uint8_t* packet); 
uint8_t cc2520_packetReceive(uint8_t maxlen, uint8_t* packet);

void cc2520_receiveOn(void);
void cc2520_receiveOff(void);
void cc2520_disableRxInterrupt(void);
void cc2520_enableRxInterrupt(void);

#endif /*CC2520_H_*/
