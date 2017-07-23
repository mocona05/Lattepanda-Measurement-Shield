// MESSAGE TRANSMIT_CAN_DATA PACKING

#define MAVLINK_MSG_ID_TRANSMIT_CAN_DATA 208

MAVPACKED(
typedef struct __mavlink_transmit_can_data_t {
 uint32_t CAN_ID; /*<  CAN ID*/
 uint8_t CAN_Data[8]; /*<  CAN DATA*/
 uint8_t CAN_RTR; /*<  CAN Request*/
}) mavlink_transmit_can_data_t;

#define MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN 13
#define MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN 13
#define MAVLINK_MSG_ID_208_LEN 13
#define MAVLINK_MSG_ID_208_MIN_LEN 13

#define MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC 204
#define MAVLINK_MSG_ID_208_CRC 204

#define MAVLINK_MSG_TRANSMIT_CAN_DATA_FIELD_CAN_DATA_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRANSMIT_CAN_DATA { \
	208, \
	"TRANSMIT_CAN_DATA", \
	3, \
	{  { "CAN_ID", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_transmit_can_data_t, CAN_ID) }, \
         { "CAN_Data", NULL, MAVLINK_TYPE_UINT8_T, 8, 4, offsetof(mavlink_transmit_can_data_t, CAN_Data) }, \
         { "CAN_RTR", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_transmit_can_data_t, CAN_RTR) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRANSMIT_CAN_DATA { \
	"TRANSMIT_CAN_DATA", \
	3, \
	{  { "CAN_ID", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_transmit_can_data_t, CAN_ID) }, \
         { "CAN_Data", NULL, MAVLINK_TYPE_UINT8_T, 8, 4, offsetof(mavlink_transmit_can_data_t, CAN_Data) }, \
         { "CAN_RTR", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_transmit_can_data_t, CAN_RTR) }, \
         } \
}
#endif

/**
 * @brief Pack a transmit_can_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param CAN_ID  CAN ID
 * @param CAN_Data  CAN DATA
 * @param CAN_RTR  CAN Request
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_transmit_can_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t CAN_ID, const uint8_t *CAN_Data, uint8_t CAN_RTR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN];
	_mav_put_uint32_t(buf, 0, CAN_ID);
	_mav_put_uint8_t(buf, 12, CAN_RTR);
	_mav_put_uint8_t_array(buf, 4, CAN_Data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN);
#else
	mavlink_transmit_can_data_t packet;
	packet.CAN_ID = CAN_ID;
	packet.CAN_RTR = CAN_RTR;
	mav_array_memcpy(packet.CAN_Data, CAN_Data, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TRANSMIT_CAN_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
}

/**
 * @brief Pack a transmit_can_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param CAN_ID  CAN ID
 * @param CAN_Data  CAN DATA
 * @param CAN_RTR  CAN Request
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_transmit_can_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t CAN_ID,const uint8_t *CAN_Data,uint8_t CAN_RTR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN];
	_mav_put_uint32_t(buf, 0, CAN_ID);
	_mav_put_uint8_t(buf, 12, CAN_RTR);
	_mav_put_uint8_t_array(buf, 4, CAN_Data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN);
#else
	mavlink_transmit_can_data_t packet;
	packet.CAN_ID = CAN_ID;
	packet.CAN_RTR = CAN_RTR;
	mav_array_memcpy(packet.CAN_Data, CAN_Data, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TRANSMIT_CAN_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
}

/**
 * @brief Encode a transmit_can_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param transmit_can_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_transmit_can_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_transmit_can_data_t* transmit_can_data)
{
	return mavlink_msg_transmit_can_data_pack(system_id, component_id, msg, transmit_can_data->CAN_ID, transmit_can_data->CAN_Data, transmit_can_data->CAN_RTR);
}

/**
 * @brief Encode a transmit_can_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param transmit_can_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_transmit_can_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_transmit_can_data_t* transmit_can_data)
{
	return mavlink_msg_transmit_can_data_pack_chan(system_id, component_id, chan, msg, transmit_can_data->CAN_ID, transmit_can_data->CAN_Data, transmit_can_data->CAN_RTR);
}

/**
 * @brief Send a transmit_can_data message
 * @param chan MAVLink channel to send the message
 *
 * @param CAN_ID  CAN ID
 * @param CAN_Data  CAN DATA
 * @param CAN_RTR  CAN Request
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_transmit_can_data_send(mavlink_channel_t chan, uint32_t CAN_ID, const uint8_t *CAN_Data, uint8_t CAN_RTR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN];
	_mav_put_uint32_t(buf, 0, CAN_ID);
	_mav_put_uint8_t(buf, 12, CAN_RTR);
	_mav_put_uint8_t_array(buf, 4, CAN_Data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA, buf, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
#else
	mavlink_transmit_can_data_t packet;
	packet.CAN_ID = CAN_ID;
	packet.CAN_RTR = CAN_RTR;
	mav_array_memcpy(packet.CAN_Data, CAN_Data, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA, (const char *)&packet, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
#endif
}

/**
 * @brief Send a transmit_can_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_transmit_can_data_send_struct(mavlink_channel_t chan, const mavlink_transmit_can_data_t* transmit_can_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_transmit_can_data_send(chan, transmit_can_data->CAN_ID, transmit_can_data->CAN_Data, transmit_can_data->CAN_RTR);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA, (const char *)transmit_can_data, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_transmit_can_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t CAN_ID, const uint8_t *CAN_Data, uint8_t CAN_RTR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, CAN_ID);
	_mav_put_uint8_t(buf, 12, CAN_RTR);
	_mav_put_uint8_t_array(buf, 4, CAN_Data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA, buf, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
#else
	mavlink_transmit_can_data_t *packet = (mavlink_transmit_can_data_t *)msgbuf;
	packet->CAN_ID = CAN_ID;
	packet->CAN_RTR = CAN_RTR;
	mav_array_memcpy(packet->CAN_Data, CAN_Data, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA, (const char *)packet, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_MIN_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE TRANSMIT_CAN_DATA UNPACKING


/**
 * @brief Get field CAN_ID from transmit_can_data message
 *
 * @return  CAN ID
 */
static inline uint32_t mavlink_msg_transmit_can_data_get_CAN_ID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field CAN_Data from transmit_can_data message
 *
 * @return  CAN DATA
 */
static inline uint16_t mavlink_msg_transmit_can_data_get_CAN_Data(const mavlink_message_t* msg, uint8_t *CAN_Data)
{
	return _MAV_RETURN_uint8_t_array(msg, CAN_Data, 8,  4);
}

/**
 * @brief Get field CAN_RTR from transmit_can_data message
 *
 * @return  CAN Request
 */
static inline uint8_t mavlink_msg_transmit_can_data_get_CAN_RTR(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a transmit_can_data message into a struct
 *
 * @param msg The message to decode
 * @param transmit_can_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_transmit_can_data_decode(const mavlink_message_t* msg, mavlink_transmit_can_data_t* transmit_can_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	transmit_can_data->CAN_ID = mavlink_msg_transmit_can_data_get_CAN_ID(msg);
	mavlink_msg_transmit_can_data_get_CAN_Data(msg, transmit_can_data->CAN_Data);
	transmit_can_data->CAN_RTR = mavlink_msg_transmit_can_data_get_CAN_RTR(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN? msg->len : MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN;
        memset(transmit_can_data, 0, MAVLINK_MSG_ID_TRANSMIT_CAN_DATA_LEN);
	memcpy(transmit_can_data, _MAV_PAYLOAD(msg), len);
#endif
}
