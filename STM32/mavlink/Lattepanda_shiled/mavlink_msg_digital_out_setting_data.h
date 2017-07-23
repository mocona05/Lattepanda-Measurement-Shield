// MESSAGE DIGITAL_OUT_SETTING_DATA PACKING

#define MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA 203

MAVPACKED(
typedef struct __mavlink_digital_out_setting_data_t {
 float L_Side_Freq; /*<  Low_Side_out_Freqency setting  [Hz]*/
 float L_Side_Duty; /*<  Low_Side_out_Duty setting  [%] Digit*/
 uint8_t DO; /*<  Digital Output [High/Low]*/
}) mavlink_digital_out_setting_data_t;

#define MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN 9
#define MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN 9
#define MAVLINK_MSG_ID_203_LEN 9
#define MAVLINK_MSG_ID_203_MIN_LEN 9

#define MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC 173
#define MAVLINK_MSG_ID_203_CRC 173



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DIGITAL_OUT_SETTING_DATA { \
	203, \
	"DIGITAL_OUT_SETTING_DATA", \
	3, \
	{  { "L_Side_Freq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_digital_out_setting_data_t, L_Side_Freq) }, \
         { "L_Side_Duty", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_digital_out_setting_data_t, L_Side_Duty) }, \
         { "DO", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_digital_out_setting_data_t, DO) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DIGITAL_OUT_SETTING_DATA { \
	"DIGITAL_OUT_SETTING_DATA", \
	3, \
	{  { "L_Side_Freq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_digital_out_setting_data_t, L_Side_Freq) }, \
         { "L_Side_Duty", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_digital_out_setting_data_t, L_Side_Duty) }, \
         { "DO", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_digital_out_setting_data_t, DO) }, \
         } \
}
#endif

/**
 * @brief Pack a digital_out_setting_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param L_Side_Freq  Low_Side_out_Freqency setting  [Hz]
 * @param L_Side_Duty  Low_Side_out_Duty setting  [%] Digit
 * @param DO  Digital Output [High/Low]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_digital_out_setting_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float L_Side_Freq, float L_Side_Duty, uint8_t DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN];
	_mav_put_float(buf, 0, L_Side_Freq);
	_mav_put_float(buf, 4, L_Side_Duty);
	_mav_put_uint8_t(buf, 8, DO);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN);
#else
	mavlink_digital_out_setting_data_t packet;
	packet.L_Side_Freq = L_Side_Freq;
	packet.L_Side_Duty = L_Side_Duty;
	packet.DO = DO;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
}

/**
 * @brief Pack a digital_out_setting_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param L_Side_Freq  Low_Side_out_Freqency setting  [Hz]
 * @param L_Side_Duty  Low_Side_out_Duty setting  [%] Digit
 * @param DO  Digital Output [High/Low]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_digital_out_setting_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float L_Side_Freq,float L_Side_Duty,uint8_t DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN];
	_mav_put_float(buf, 0, L_Side_Freq);
	_mav_put_float(buf, 4, L_Side_Duty);
	_mav_put_uint8_t(buf, 8, DO);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN);
#else
	mavlink_digital_out_setting_data_t packet;
	packet.L_Side_Freq = L_Side_Freq;
	packet.L_Side_Duty = L_Side_Duty;
	packet.DO = DO;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
}

/**
 * @brief Encode a digital_out_setting_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param digital_out_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_digital_out_setting_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_digital_out_setting_data_t* digital_out_setting_data)
{
	return mavlink_msg_digital_out_setting_data_pack(system_id, component_id, msg, digital_out_setting_data->L_Side_Freq, digital_out_setting_data->L_Side_Duty, digital_out_setting_data->DO);
}

/**
 * @brief Encode a digital_out_setting_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param digital_out_setting_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_digital_out_setting_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_digital_out_setting_data_t* digital_out_setting_data)
{
	return mavlink_msg_digital_out_setting_data_pack_chan(system_id, component_id, chan, msg, digital_out_setting_data->L_Side_Freq, digital_out_setting_data->L_Side_Duty, digital_out_setting_data->DO);
}

/**
 * @brief Send a digital_out_setting_data message
 * @param chan MAVLink channel to send the message
 *
 * @param L_Side_Freq  Low_Side_out_Freqency setting  [Hz]
 * @param L_Side_Duty  Low_Side_out_Duty setting  [%] Digit
 * @param DO  Digital Output [High/Low]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_digital_out_setting_data_send(mavlink_channel_t chan, float L_Side_Freq, float L_Side_Duty, uint8_t DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN];
	_mav_put_float(buf, 0, L_Side_Freq);
	_mav_put_float(buf, 4, L_Side_Duty);
	_mav_put_uint8_t(buf, 8, DO);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA, buf, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
#else
	mavlink_digital_out_setting_data_t packet;
	packet.L_Side_Freq = L_Side_Freq;
	packet.L_Side_Duty = L_Side_Duty;
	packet.DO = DO;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA, (const char *)&packet, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
#endif
}

/**
 * @brief Send a digital_out_setting_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_digital_out_setting_data_send_struct(mavlink_channel_t chan, const mavlink_digital_out_setting_data_t* digital_out_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_digital_out_setting_data_send(chan, digital_out_setting_data->L_Side_Freq, digital_out_setting_data->L_Side_Duty, digital_out_setting_data->DO);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA, (const char *)digital_out_setting_data, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_digital_out_setting_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float L_Side_Freq, float L_Side_Duty, uint8_t DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, L_Side_Freq);
	_mav_put_float(buf, 4, L_Side_Duty);
	_mav_put_uint8_t(buf, 8, DO);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA, buf, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
#else
	mavlink_digital_out_setting_data_t *packet = (mavlink_digital_out_setting_data_t *)msgbuf;
	packet->L_Side_Freq = L_Side_Freq;
	packet->L_Side_Duty = L_Side_Duty;
	packet->DO = DO;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA, (const char *)packet, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_MIN_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE DIGITAL_OUT_SETTING_DATA UNPACKING


/**
 * @brief Get field L_Side_Freq from digital_out_setting_data message
 *
 * @return  Low_Side_out_Freqency setting  [Hz]
 */
static inline float mavlink_msg_digital_out_setting_data_get_L_Side_Freq(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field L_Side_Duty from digital_out_setting_data message
 *
 * @return  Low_Side_out_Duty setting  [%] Digit
 */
static inline float mavlink_msg_digital_out_setting_data_get_L_Side_Duty(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field DO from digital_out_setting_data message
 *
 * @return  Digital Output [High/Low]
 */
static inline uint8_t mavlink_msg_digital_out_setting_data_get_DO(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a digital_out_setting_data message into a struct
 *
 * @param msg The message to decode
 * @param digital_out_setting_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_digital_out_setting_data_decode(const mavlink_message_t* msg, mavlink_digital_out_setting_data_t* digital_out_setting_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	digital_out_setting_data->L_Side_Freq = mavlink_msg_digital_out_setting_data_get_L_Side_Freq(msg);
	digital_out_setting_data->L_Side_Duty = mavlink_msg_digital_out_setting_data_get_L_Side_Duty(msg);
	digital_out_setting_data->DO = mavlink_msg_digital_out_setting_data_get_DO(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN? msg->len : MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN;
        memset(digital_out_setting_data, 0, MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA_LEN);
	memcpy(digital_out_setting_data, _MAV_PAYLOAD(msg), len);
#endif
}
