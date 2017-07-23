// MESSAGE Kelvin_CALIBRATION_Data PACKING

#define MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data 222

MAVPACKED(
typedef struct __mavlink_kelvin_calibration_data_t {
 float Gain_Kelvin[2]; /*<  Kelvin gain */
 float Offset_Kelvin[2]; /*<  Kelvin offset */
}) mavlink_kelvin_calibration_data_t;

#define MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN 16
#define MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN 16
#define MAVLINK_MSG_ID_222_LEN 16
#define MAVLINK_MSG_ID_222_MIN_LEN 16

#define MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC 111
#define MAVLINK_MSG_ID_222_CRC 111

#define MAVLINK_MSG_Kelvin_CALIBRATION_Data_FIELD_GAIN_KELVIN_LEN 2
#define MAVLINK_MSG_Kelvin_CALIBRATION_Data_FIELD_OFFSET_KELVIN_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Kelvin_CALIBRATION_Data { \
	222, \
	"Kelvin_CALIBRATION_Data", \
	2, \
	{  { "Gain_Kelvin", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_kelvin_calibration_data_t, Gain_Kelvin) }, \
         { "Offset_Kelvin", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_kelvin_calibration_data_t, Offset_Kelvin) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Kelvin_CALIBRATION_Data { \
	"Kelvin_CALIBRATION_Data", \
	2, \
	{  { "Gain_Kelvin", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_kelvin_calibration_data_t, Gain_Kelvin) }, \
         { "Offset_Kelvin", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_kelvin_calibration_data_t, Offset_Kelvin) }, \
         } \
}
#endif

/**
 * @brief Pack a kelvin_calibration_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Gain_Kelvin  Kelvin gain 
 * @param Offset_Kelvin  Kelvin offset 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const float *Gain_Kelvin, const float *Offset_Kelvin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_Kelvin, 2);
	_mav_put_float_array(buf, 8, Offset_Kelvin, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN);
#else
	mavlink_kelvin_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_Kelvin, Gain_Kelvin, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_Kelvin, Offset_Kelvin, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
}

/**
 * @brief Pack a kelvin_calibration_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Gain_Kelvin  Kelvin gain 
 * @param Offset_Kelvin  Kelvin offset 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const float *Gain_Kelvin,const float *Offset_Kelvin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_Kelvin, 2);
	_mav_put_float_array(buf, 8, Offset_Kelvin, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN);
#else
	mavlink_kelvin_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_Kelvin, Gain_Kelvin, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_Kelvin, Offset_Kelvin, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
}

/**
 * @brief Encode a kelvin_calibration_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param kelvin_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_kelvin_calibration_data_t* kelvin_calibration_data)
{
	return mavlink_msg_kelvin_calibration_data_pack(system_id, component_id, msg, kelvin_calibration_data->Gain_Kelvin, kelvin_calibration_data->Offset_Kelvin);
}

/**
 * @brief Encode a kelvin_calibration_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param kelvin_calibration_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_kelvin_calibration_data_t* kelvin_calibration_data)
{
	return mavlink_msg_kelvin_calibration_data_pack_chan(system_id, component_id, chan, msg, kelvin_calibration_data->Gain_Kelvin, kelvin_calibration_data->Offset_Kelvin);
}

/**
 * @brief Send a kelvin_calibration_data message
 * @param chan MAVLink channel to send the message
 *
 * @param Gain_Kelvin  Kelvin gain 
 * @param Offset_Kelvin  Kelvin offset 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_kelvin_calibration_data_send(mavlink_channel_t chan, const float *Gain_Kelvin, const float *Offset_Kelvin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN];

	_mav_put_float_array(buf, 0, Gain_Kelvin, 2);
	_mav_put_float_array(buf, 8, Offset_Kelvin, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data, buf, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
#else
	mavlink_kelvin_calibration_data_t packet;

	mav_array_memcpy(packet.Gain_Kelvin, Gain_Kelvin, sizeof(float)*2);
	mav_array_memcpy(packet.Offset_Kelvin, Offset_Kelvin, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data, (const char *)&packet, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
#endif
}

/**
 * @brief Send a kelvin_calibration_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_kelvin_calibration_data_send_struct(mavlink_channel_t chan, const mavlink_kelvin_calibration_data_t* kelvin_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_kelvin_calibration_data_send(chan, kelvin_calibration_data->Gain_Kelvin, kelvin_calibration_data->Offset_Kelvin);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data, (const char *)kelvin_calibration_data, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
#endif
}

#if MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_kelvin_calibration_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *Gain_Kelvin, const float *Offset_Kelvin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_float_array(buf, 0, Gain_Kelvin, 2);
	_mav_put_float_array(buf, 8, Offset_Kelvin, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data, buf, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
#else
	mavlink_kelvin_calibration_data_t *packet = (mavlink_kelvin_calibration_data_t *)msgbuf;

	mav_array_memcpy(packet->Gain_Kelvin, Gain_Kelvin, sizeof(float)*2);
	mav_array_memcpy(packet->Offset_Kelvin, Offset_Kelvin, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data, (const char *)packet, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_MIN_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_CRC);
#endif
}
#endif

#endif

// MESSAGE Kelvin_CALIBRATION_Data UNPACKING


/**
 * @brief Get field Gain_Kelvin from kelvin_calibration_data message
 *
 * @return  Kelvin gain 
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_get_Gain_Kelvin(const mavlink_message_t* msg, float *Gain_Kelvin)
{
	return _MAV_RETURN_float_array(msg, Gain_Kelvin, 2,  0);
}

/**
 * @brief Get field Offset_Kelvin from kelvin_calibration_data message
 *
 * @return  Kelvin offset 
 */
static inline uint16_t mavlink_msg_kelvin_calibration_data_get_Offset_Kelvin(const mavlink_message_t* msg, float *Offset_Kelvin)
{
	return _MAV_RETURN_float_array(msg, Offset_Kelvin, 2,  8);
}

/**
 * @brief Decode a kelvin_calibration_data message into a struct
 *
 * @param msg The message to decode
 * @param kelvin_calibration_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_kelvin_calibration_data_decode(const mavlink_message_t* msg, mavlink_kelvin_calibration_data_t* kelvin_calibration_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_kelvin_calibration_data_get_Gain_Kelvin(msg, kelvin_calibration_data->Gain_Kelvin);
	mavlink_msg_kelvin_calibration_data_get_Offset_Kelvin(msg, kelvin_calibration_data->Offset_Kelvin);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN? msg->len : MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN;
        memset(kelvin_calibration_data, 0, MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data_LEN);
	memcpy(kelvin_calibration_data, _MAV_PAYLOAD(msg), len);
#endif
}
