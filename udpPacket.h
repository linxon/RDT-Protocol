/**
 * This file describes the functions used for operating on the UDP packets
 *
 * @author Jeffrey Bromen
 * @author Raymond Fleming
 * @date 3/8/2017
 * @info Systems and Networks II
 * @info Project 2
 *
 */

#ifndef _UDP_PACKET_H
#define _UDP_PACKET_H

#include <math.h>

#include "definitions.h"

/**
 * Calculates the number of segments required to send a given message.
 *
 * @param message - the message that will be segmented
 *
 * @return the number of segments needed to send the message
 */
int numberOfSegments(const char *message);

/**
 * Checks to see if the corrupt flag of a packet is set.
 *
 * @param packet - the received packet
 *
 * @return 1 if corrupt, 0 if not corrupt
 */
int isCorrupt(const char *packet);

/**
 * Extracts the sequence number of a packet.
 *
 * @param packet - the received packet
 *
 * @return the sequence number of the packet
 */
int sequenceNumber(const char *packet);

/**
 * Extracts the source IP address of a packet
 *
 * @param buffer - buffer where IP address will be stored
 * @param packet - the received packet
 */
void getSourceIP(char *buffer, const char *packet);

/**
 * Extracts the source port of a packet
 *
 * @param packet - the received packet
 *
 * @return the port number
 */
int getSourcePort(const char *packet);

/**
 * Extracts the destination IP address of a packet
 *
 * @param buffer - buffer where IP address will be stored
 * @param packet - the received packet
 */
void getDestinationIP(char *buffer, const char *packet);

/**
 * Extracts the destination port of a packet
 *
 * @param packet - the received packet
 *
 * @return the port number
 */
int getDestinationPort(const char *packet);

/**
 * Extracts the segment from a packet
 *
 * @param buffer - buffer where the segment will be stored
 * @param packet - the received packet
 */
void getSegment(char *buffer, const char *packet);

/**
 * Extracts the segment header from a packet
 *
 * @param packet - the received packet
 *
 * @return the byte containing the segment header
 */
char getSegmentHeader(const char *packet);

/**
 * Extracts the segment content from a packet
 *
 * @param buffer - buffer where the segment content will be stored
 * @param packet - the received packet
 */
void getSegmentContent(char *buffer, const char *packet);

/**
 * Formats a segment to be sent in a packet
 *
 * @param buffer      - buffer where the segment will be stored
 * @param sequenceNum - sequence number of the created segment
 * @param content     - content that will be wrapped in segment
 */
void makeSegment(char *buffer, const int sequenceNum, const char *content);

/**
 * Formats a packet to be sent across the network
 *
 * @param buffer   - buffer where the packet will be stored
 * @param srcIP    - source IP address
 * @param srcPort  - source port number
 * @param destIP   - destination IP address
 * @param destPort - destination port number
 * @param segment  - segment that will be wrapped in packet
 */
void makePacket(char *buffer, const char *srcIP, const int srcPort, const char *destIP, const int destPort, const char *segment);

/**
 * Sets the corrupt flag of a packet
 *
 * @param packet - packet to be corrupted
 */
void corruptPacket(char *packet);

#endif // _UDP_PACKET_H