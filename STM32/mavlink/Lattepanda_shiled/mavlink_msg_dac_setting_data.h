// MESSAGE DAC_SETTING_DATA PACKING

#define MAVLINK_MSG_ID_DAC_SETTING_DATA 202

MAVPACKED(
typedef struct __mavlink_dac_setting_data_t {
 uint16_t DAC_ch1; /*<  12bit DAC [mV]*/
 uint16_t DAC_ch2; /*<  12bit DAC [mV]*/
}) mavlink_dac_setting_data_t;

#define MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN 4
#define MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN 4
#define MAVLINK_MSG_ID_202_LEN 4
#define MAVLINK_MSG_ID_202_MIN_LEN 4

#define MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC 244
#define MAVLINK_MSG_ID_202_CRC 244



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DAC_SETTING_DATA { \
	202, \
	"DAC_SETTING_DATA", \
	2, \
	{  { "DAC_ch1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_dac_setting_data_t, DAC_ch1) }, \
         { "DAC_ch2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_dac_setting_data_t, DAC_ch2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DAC_SETTING_DATA { \
	"DAC_SETTING_DATA", \
	2, \
	{  { "DAC_ch1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_dac_setting_data_t, DAC_ch1) }, \
         { "DAC_ch2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_dac_setting_data_t, DAC_ch2) }, \
         } \
}
#endif

/**
 * @brief Pack a dac_setting_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param DAC_ch1  12bit DAC [mV]
 * @param DAC_ch2  12bit DAC [mV]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dac_setting_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t DAC_ch1, uint16_t DAC_ch2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN];
	_mav_put_uint16_t(buf, 0, DAC_ch1);
	_mav_put_uint16_t(buf, 2, DAC_ch2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN);
#else
	mavlink_dac_setting_data_t packet;
	packet.DAC_ch1 = DAC_ch1;
	packet.DAC_ch2 = DAC_ch2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DAC_SETTING_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
}

/**
 * @brief Pack a dac_setting_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param DAC_ch1  12bit DAC [mV]
 * @param DAC_ch2  12bit DAC [mV]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dac_setting_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t DAC_ch1,uint16_t DAC_ch2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN];
	_mav_put_uint16_t(buf, 0, DAC_ch1);
	_mav_put_uint16_t(buf, 2, DAC_ch2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN);
#else
	mavlink_dac_setting_data_t packet;
	packet.DAC_ch1 = DAC_ch1;
	packet.DAC_ch2 = DAC_ch2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DAC_SETTING_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
}

/**
 * @brief Encode a dac_setting_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dac_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dac_setting_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dac_setting_data_t* dac_setting_data)
{
	return mavlink_msg_dac_setting_data_pack(system_id, component_id, msg, dac_setting_data->DAC_ch1, dac_setting_data->DAC_ch2);
}

/**
 * @brief Encode a dac_setting_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dac_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dac_setting_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dac_setting_data_t* dac_setting_data)
{
	return mavlink_msg_dac_setting_data_pack_chan(system_id, component_id, chan, msg, dac_setting_data->DAC_ch1, dac_setting_data->DAC_ch2);
}

/**
 * @brief Send a dac_setting_data message
 * @param chan MAVLink channel to send the message
 *
 * @param DAC_ch1  12bit DAC [mV]
 * @param DAC_ch2  12bit DAC [mV]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dac_setting_data_send(mavlink_channel_t chan, uint16_t DAC_ch1, uint16_t DAC_ch2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN];
	_mav_put_uint16_t(buf, 0, DAC_ch1);
	_mav_put_uint16_t(buf, 2, DAC_ch2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_SETTING_DATA, buf, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
#else
	mavlink_dac_setting_data_t packet;
	packet.DAC_ch1 = DAC_ch1;
	packet.DAC_ch2 = DAC_ch2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_SETTING_DATA, (const char *)&packet, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
#endif
}

/**
 * @brief Send a dac_setting_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dac_setting_data_send_struct(mavlink_channel_t chan, const mavlink_dac_setting_data_t* dac_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dac_setting_data_send(chan, dac_setting_data->DAC_ch1, dac_setting_data->DAC_ch2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_SETTING_DATA, (const char *)dac_setting_data, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dac_setting_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t DAC_ch1, uint16_t DAC_ch2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, DAC_ch1);
	_mav_put_uint16_t(buf, 2, DAC_ch2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_SETTING_DATA, buf, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
#else
	mavlink_dac_setting_data_t *packet = (mavlink_dac_setting_data_t *)msgbuf;
	packet->DAC_ch1 = DAC_ch1;
	packet->DAC_ch2 = DAC_ch2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_SETTING_DATA, (const char *)packet, MAVLINK_MSG_ID_DAC_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN, MAVLINK_MSG_ID_DAC_SETTING_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE DAC_SETTING_DATA UNPACKING


/**
 * @brief Get field DAC_ch1 from dac_setting_data message
 *
 * @return  12bit DAC [mV]
 */
static inline uint16_t mavlink_msg_dac_setting_data_get_DAC_ch1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field DAC_ch2 from dac_setting_data message
 *
 * @return  12bit DAC [mV]
 */
static inline uint16_t mavlink_msg_dac_setting_data_get_DAC_ch2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a dac_setting_data message into a struct
 *
 * @param msg The message to decode
 * @param dac_setting_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_dac_setting_data_decode(const mavlink_message_t* msg, mavlink_dac_setting_data_t* dac_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	dac_setting_data->DAC_ch1 = mavlink_msg_dac_setting_data_get_DAC_ch1(msg);
	dac_setting_data->DAC_ch2 = mavlink_msg_dac_setting_data_get_DAC_ch2(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN? msg->len : MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN;
        memset(dac_setting_data, 0, MAVLINK_MSG_ID_DAC_SETTING_DATA_LEN);
	memcpy(dac_setting_data, _MAV_PAYLOAD(msg), len);
#endif
}
