// MESSAGE MEASURING_SETTING PACKING

#define MAVLINK_MSG_ID_MEASURING_SETTING 204

MAVPACKED(
typedef struct __mavlink_measuring_setting_t {
 uint8_t Display_speed[6]; /*<  Display Speed setting*/
 uint8_t Kelvin_mode_set; /*<  4-Wire Kelvin Set mode*/
 uint8_t Kelvin_Range; /*<  4-Wire Kelvin Set Range [High/Low]*/
 uint8_t LC_mode_set; /*<   Calibration or L measuring or C measuring sellction */
 uint8_t L_C_Range; /*<   L  C measuring Range sellction */
}) mavlink_measuring_setting_t;

#define MAVLINK_MSG_ID_MEASURING_SETTING_LEN 10
#define MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN 10
#define MAVLINK_MSG_ID_204_LEN 10
#define MAVLINK_MSG_ID_204_MIN_LEN 10

#define MAVLINK_MSG_ID_MEASURING_SETTING_CRC 18
#define MAVLINK_MSG_ID_204_CRC 18

#define MAVLINK_MSG_MEASURING_SETTING_FIELD_DISPLAY_SPEED_LEN 6

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MEASURING_SETTING { \
	204, \
	"MEASURING_SETTING", \
	5, \
	{  { "Display_speed", NULL, MAVLINK_TYPE_UINT8_T, 6, 0, offsetof(mavlink_measuring_setting_t, Display_speed) }, \
         { "Kelvin_mode_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_measuring_setting_t, Kelvin_mode_set) }, \
         { "Kelvin_Range", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_measuring_setting_t, Kelvin_Range) }, \
         { "LC_mode_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_measuring_setting_t, LC_mode_set) }, \
         { "L_C_Range", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_measuring_setting_t, L_C_Range) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MEASURING_SETTING { \
	"MEASURING_SETTING", \
	5, \
	{  { "Display_speed", NULL, MAVLINK_TYPE_UINT8_T, 6, 0, offsetof(mavlink_measuring_setting_t, Display_speed) }, \
         { "Kelvin_mode_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_measuring_setting_t, Kelvin_mode_set) }, \
         { "Kelvin_Range", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_measuring_setting_t, Kelvin_Range) }, \
         { "LC_mode_set", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_measuring_setting_t, LC_mode_set) }, \
         { "L_C_Range", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_measuring_setting_t, L_C_Range) }, \
         } \
}
#endif

/**
 * @brief Pack a measuring_setting message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Display_speed  Display Speed setting
 * @param Kelvin_mode_set  4-Wire Kelvin Set mode
 * @param Kelvin_Range  4-Wire Kelvin Set Range [High/Low]
 * @param LC_mode_set   Calibration or L measuring or C measuring sellction 
 * @param L_C_Range   L  C measuring Range sellction 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measuring_setting_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const uint8_t *Display_speed, uint8_t Kelvin_mode_set, uint8_t Kelvin_Range, uint8_t LC_mode_set, uint8_t L_C_Range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_SETTING_LEN];
	_mav_put_uint8_t(buf, 6, Kelvin_mode_set);
	_mav_put_uint8_t(buf, 7, Kelvin_Range);
	_mav_put_uint8_t(buf, 8, LC_mode_set);
	_mav_put_uint8_t(buf, 9, L_C_Range);
	_mav_put_uint8_t_array(buf, 0, Display_speed, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASURING_SETTING_LEN);
#else
	mavlink_measuring_setting_t packet;
	packet.Kelvin_mode_set = Kelvin_mode_set;
	packet.Kelvin_Range = Kelvin_Range;
	packet.LC_mode_set = LC_mode_set;
	packet.L_C_Range = L_C_Range;
	mav_array_memcpy(packet.Display_speed, Display_speed, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASURING_SETTING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASURING_SETTING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
}

/**
 * @brief Pack a measuring_setting message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Display_speed  Display Speed setting
 * @param Kelvin_mode_set  4-Wire Kelvin Set mode
 * @param Kelvin_Range  4-Wire Kelvin Set Range [High/Low]
 * @param LC_mode_set   Calibration or L measuring or C measuring sellction 
 * @param L_C_Range   L  C measuring Range sellction 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_measuring_setting_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const uint8_t *Display_speed,uint8_t Kelvin_mode_set,uint8_t Kelvin_Range,uint8_t LC_mode_set,uint8_t L_C_Range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_SETTING_LEN];
	_mav_put_uint8_t(buf, 6, Kelvin_mode_set);
	_mav_put_uint8_t(buf, 7, Kelvin_Range);
	_mav_put_uint8_t(buf, 8, LC_mode_set);
	_mav_put_uint8_t(buf, 9, L_C_Range);
	_mav_put_uint8_t_array(buf, 0, Display_speed, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MEASURING_SETTING_LEN);
#else
	mavlink_measuring_setting_t packet;
	packet.Kelvin_mode_set = Kelvin_mode_set;
	packet.Kelvin_Range = Kelvin_Range;
	packet.LC_mode_set = LC_mode_set;
	packet.L_C_Range = L_C_Range;
	mav_array_memcpy(packet.Display_speed, Display_speed, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MEASURING_SETTING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MEASURING_SETTING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
}

/**
 * @brief Encode a measuring_setting struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param measuring_setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measuring_setting_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_measuring_setting_t* measuring_setting)
{
	return mavlink_msg_measuring_setting_pack(system_id, component_id, msg, measuring_setting->Display_speed, measuring_setting->Kelvin_mode_set, measuring_setting->Kelvin_Range, measuring_setting->LC_mode_set, measuring_setting->L_C_Range);
}

/**
 * @brief Encode a measuring_setting struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param measuring_setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_measuring_setting_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_measuring_setting_t* measuring_setting)
{
	return mavlink_msg_measuring_setting_pack_chan(system_id, component_id, chan, msg, measuring_setting->Display_speed, measuring_setting->Kelvin_mode_set, measuring_setting->Kelvin_Range, measuring_setting->LC_mode_set, measuring_setting->L_C_Range);
}

/**
 * @brief Send a measuring_setting message
 * @param chan MAVLink channel to send the message
 *
 * @param Display_speed  Display Speed setting
 * @param Kelvin_mode_set  4-Wire Kelvin Set mode
 * @param Kelvin_Range  4-Wire Kelvin Set Range [High/Low]
 * @param LC_mode_set   Calibration or L measuring or C measuring sellction 
 * @param L_C_Range   L  C measuring Range sellction 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_measuring_setting_send(mavlink_channel_t chan, const uint8_t *Display_speed, uint8_t Kelvin_mode_set, uint8_t Kelvin_Range, uint8_t LC_mode_set, uint8_t L_C_Range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MEASURING_SETTING_LEN];
	_mav_put_uint8_t(buf, 6, Kelvin_mode_set);
	_mav_put_uint8_t(buf, 7, Kelvin_Range);
	_mav_put_uint8_t(buf, 8, LC_mode_set);
	_mav_put_uint8_t(buf, 9, L_C_Range);
	_mav_put_uint8_t_array(buf, 0, Display_speed, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_SETTING, buf, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
#else
	mavlink_measuring_setting_t packet;
	packet.Kelvin_mode_set = Kelvin_mode_set;
	packet.Kelvin_Range = Kelvin_Range;
	packet.LC_mode_set = LC_mode_set;
	packet.L_C_Range = L_C_Range;
	mav_array_memcpy(packet.Display_speed, Display_speed, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_SETTING, (const char *)&packet, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
#endif
}

/**
 * @brief Send a measuring_setting message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_measuring_setting_send_struct(mavlink_channel_t chan, const mavlink_measuring_setting_t* measuring_setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_measuring_setting_send(chan, measuring_setting->Display_speed, measuring_setting->Kelvin_mode_set, measuring_setting->Kelvin_Range, measuring_setting->LC_mode_set, measuring_setting->L_C_Range);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_SETTING, (const char *)measuring_setting, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
#endif
}

#if MAVLINK_MSG_ID_MEASURING_SETTING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_measuring_setting_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *Display_speed, uint8_t Kelvin_mode_set, uint8_t Kelvin_Range, uint8_t LC_mode_set, uint8_t L_C_Range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 6, Kelvin_mode_set);
	_mav_put_uint8_t(buf, 7, Kelvin_Range);
	_mav_put_uint8_t(buf, 8, LC_mode_set);
	_mav_put_uint8_t(buf, 9, L_C_Range);
	_mav_put_uint8_t_array(buf, 0, Display_speed, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_SETTING, buf, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
#else
	mavlink_measuring_setting_t *packet = (mavlink_measuring_setting_t *)msgbuf;
	packet->Kelvin_mode_set = Kelvin_mode_set;
	packet->Kelvin_Range = Kelvin_Range;
	packet->LC_mode_set = LC_mode_set;
	packet->L_C_Range = L_C_Range;
	mav_array_memcpy(packet->Display_speed, Display_speed, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MEASURING_SETTING, (const char *)packet, MAVLINK_MSG_ID_MEASURING_SETTING_MIN_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_LEN, MAVLINK_MSG_ID_MEASURING_SETTING_CRC);
#endif
}
#endif

#endif

// MESSAGE MEASURING_SETTING UNPACKING


/**
 * @brief Get field Display_speed from measuring_setting message
 *
 * @return  Display Speed setting
 */
static inline uint16_t mavlink_msg_measuring_setting_get_Display_speed(const mavlink_message_t* msg, uint8_t *Display_speed)
{
	return _MAV_RETURN_uint8_t_array(msg, Display_speed, 6,  0);
}

/**
 * @brief Get field Kelvin_mode_set from measuring_setting message
 *
 * @return  4-Wire Kelvin Set mode
 */
static inline uint8_t mavlink_msg_measuring_setting_get_Kelvin_mode_set(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field Kelvin_Range from measuring_setting message
 *
 * @return  4-Wire Kelvin Set Range [High/Low]
 */
static inline uint8_t mavlink_msg_measuring_setting_get_Kelvin_Range(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field LC_mode_set from measuring_setting message
 *
 * @return   Calibration or L measuring or C measuring sellction 
 */
static inline uint8_t mavlink_msg_measuring_setting_get_LC_mode_set(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field L_C_Range from measuring_setting message
 *
 * @return   L  C measuring Range sellction 
 */
static inline uint8_t mavlink_msg_measuring_setting_get_L_C_Range(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a measuring_setting message into a struct
 *
 * @param msg The message to decode
 * @param measuring_setting C-struct to decode the message contents into
 */
static inline void mavlink_msg_measuring_setting_decode(const mavlink_message_t* msg, mavlink_measuring_setting_t* measuring_setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_measuring_setting_get_Display_speed(msg, measuring_setting->Display_speed);
	measuring_setting->Kelvin_mode_set = mavlink_msg_measuring_setting_get_Kelvin_mode_set(msg);
	measuring_setting->Kelvin_Range = mavlink_msg_measuring_setting_get_Kelvin_Range(msg);
	measuring_setting->LC_mode_set = mavlink_msg_measuring_setting_get_LC_mode_set(msg);
	measuring_setting->L_C_Range = mavlink_msg_measuring_setting_get_L_C_Range(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MEASURING_SETTING_LEN? msg->len : MAVLINK_MSG_ID_MEASURING_SETTING_LEN;
        memset(measuring_setting, 0, MAVLINK_MSG_ID_MEASURING_SETTING_LEN);
	memcpy(measuring_setting, _MAV_PAYLOAD(msg), len);
#endif
}
