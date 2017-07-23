// MESSAGE DAC_CALIBRATION_Data PACKING

#define MAVLINK_MSG_ID_DAC_CALIBRATION_Data 223

MAVPACKED(
typedef struct __mavlink_dac_calibration_data_t {
 float Gain_DAC[2]; /*<  DAC gain*/
 float Offset_DAC[2]; /*<  DAC Offset mV */
}) mavlink_dac_calibration_data_t;

#define MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN 16
#define MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN 16
#define MAVLINK_MSG_ID_223_LEN 16
#define MAVLINK_MSG_ID_223_MIN_LEN 16

#define MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC 205
#define MAVLINK_MSG_ID_223_CRC 205

#define MAVLINK_MSG_DAC_CALIBRATION_Data_FIELD_GAIN_DAC_LEN 2
#define MAVLINK_MSG_DAC_CALIBRATION_Data_FIELD_OFFSET_DAC_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DAC_CALIBRATION_Data { \
	223, \
	"DAC_CALIBRATION_Data", \
	2, \
	{  { "Gain_DAC", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_dac_calibration_data_t, Gain_DAC) }, \
         { "Offset_DAC", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_dac_calibration_data_t, Offset_DAC) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DAC_CALIBRATION_Data { \
	"DAC_CALIBRATION_Data", \
	2, \
	{  { "Gain_DAC", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_dac_calibration_data_t, Gain_DAC) }, \
         { "Offset_DAC", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_dac_calibration_data_t, Offset_DAC) }, \
         } \
}
#endif

/**
 * @brief Pack a dac_calibration_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Gain_DAC  DAC gain
 * @param Offset_DAC  DAC Offset mV 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dac_calibration_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const float *Gain_DAC, const float *Offset_DAC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_DAC, 2);
	_mav_put_float_array(buf, 8, Offset_DAC, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN);
#else
	mavlink_dac_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_DAC, Gain_DAC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_DAC, Offset_DAC, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DAC_CALIBRATION_Data;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
}

/**
 * @brief Pack a dac_calibration_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Gain_DAC  DAC gain
 * @param Offset_DAC  DAC Offset mV 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dac_calibration_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const float *Gain_DAC,const float *Offset_DAC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_DAC, 2);
	_mav_put_float_array(buf, 8, Offset_DAC, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN);
#else
	mavlink_dac_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_DAC, Gain_DAC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_DAC, Offset_DAC, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DAC_CALIBRATION_Data;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
}

/**
 * @brief Encode a dac_calibration_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dac_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dac_calibration_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dac_calibration_data_t* dac_calibration_data)
{
	return mavlink_msg_dac_calibration_data_pack(system_id, component_id, msg, dac_calibration_data->Gain_DAC, dac_calibration_data->Offset_DAC);
}

/**
 * @brief Encode a dac_calibration_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dac_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dac_calibration_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dac_calibration_data_t* dac_calibration_data)
{
	return mavlink_msg_dac_calibration_data_pack_chan(system_id, component_id, chan, msg, dac_calibration_data->Gain_DAC, dac_calibration_data->Offset_DAC);
}

/**
 * @brief Send a dac_calibration_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Gain_DAC  DAC gain
 * @param Offset_DAC  DAC Offset mV 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dac_calibration_data_send(mavlink_channel_t chan, const float *Gain_DAC, const float *Offset_DAC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_DAC, 2);
	_mav_put_float_array(buf, 8, Offset_DAC, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
#else
	mavlink_dac_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_DAC, Gain_DAC, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_DAC, Offset_DAC, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data, (const char *)&packet, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
#endif
}

/**
 * @brief Send a dac_calibration_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dac_calibration_data_send_struct(mavlink_channel_t chan, const mavlink_dac_calibration_data_t* dac_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dac_calibration_data_send(chan, dac_calibration_data->Gain_DAC, dac_calibration_data->Offset_DAC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data, (const char *)dac_calibration_data, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
#endif
}

#if MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dac_calibration_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *Gain_DAC, const float *Offset_DAC)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_float_array(buf, 0, Gain_DAC, 2);
	_mav_put_float_array(buf, 8, Offset_DAC, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data, buf, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
#else
	mavlink_dac_calibration_data_t *packet = (mavlink_dac_calibration_data_t *)msgbuf;

	mav_array_memcpy(packet->Gain_DAC, Gain_DAC, sizeof(float)*2);
	mav_array_memcpy(packet->Offset_DAC, Offset_DAC, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DAC_CALIBRATION_Data, (const char *)packet, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_CRC);
#endif
}
#endif

#endif

// MESSAGE DAC_CALIBRATION_Data UNPACKING


/**
 * @brief Get field Gain_DAC from dac_calibration_data message
 *
 * @return  DAC gain
 */
static inline uint16_t mavlink_msg_dac_calibration_data_get_Gain_DAC(const mavlink_message_t* msg, float *Gain_DAC)
{
	return _MAV_RETURN_float_array(msg, Gain_DAC, 2,  0);
}

/**
 * @brief Get field Offset_DAC from dac_calibration_data message
 *
 * @return  DAC Offset mV 
 */
static inline uint16_t mavlink_msg_dac_calibration_data_get_Offset_DAC(const mavlink_message_t* msg, float *Offset_DAC)
{
	return _MAV_RETURN_float_array(msg, Offset_DAC, 2,  8);
}

/**
 * @brief Decode a dac_calibration_data message into a struct
 *
 * @param msg The message to decode
 * @param dac_calibration_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_dac_calibration_data_decode(const mavlink_message_t* msg, mavlink_dac_calibration_data_t* dac_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_dac_calibration_data_get_Gain_DAC(msg, dac_calibration_data->Gain_DAC);
	mavlink_msg_dac_calibration_data_get_Offset_DAC(msg, dac_calibration_data->Offset_DAC);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN? msg->len : MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN;
        memset(dac_calibration_data, 0, MAVLINK_MSG_ID_DAC_CALIBRATION_Data_LEN);
	memcpy(dac_calibration_data, _MAV_PAYLOAD(msg), len);
#endif
}
