// MESSAGE ALARM_SET_A PACKING

#define MAVLINK_MSG_ID_ALARM_SET_A 210

MAVPACKED(
typedef struct __mavlink_alarm_set_a_t {
 uint8_t AL_Mask_week; /*< Alarm Mask setting*/
 uint8_t AL_Mask_hour; /*< Alarm Mask setting*/
 uint8_t AL_Mask_min; /*< Alarm Mask setting*/
 uint8_t AL_Mask_sec; /*< Alarm Mask setting*/
 uint8_t AL_date_week_day_sel; /*< Alarm Mask setting*/
 uint8_t AL_date; /*< Alarm Mask setting*/
 uint8_t AL_hour; /*< Alarm time  hour setting*/
 uint8_t AL_min; /*< Alarm time  min setting*/
 uint8_t AL_sec; /*< Alarm time  sec setting*/
}) mavlink_alarm_set_a_t;

#define MAVLINK_MSG_ID_ALARM_SET_A_LEN 9
#define MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN 9
#define MAVLINK_MSG_ID_210_LEN 9
#define MAVLINK_MSG_ID_210_MIN_LEN 9

#define MAVLINK_MSG_ID_ALARM_SET_A_CRC 37
#define MAVLINK_MSG_ID_210_CRC 37



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ALARM_SET_A { \
	210, \
	"ALARM_SET_A", \
	9, \
	{  { "AL_Mask_week", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_alarm_set_a_t, AL_Mask_week) }, \
         { "AL_Mask_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_alarm_set_a_t, AL_Mask_hour) }, \
         { "AL_Mask_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_alarm_set_a_t, AL_Mask_min) }, \
         { "AL_Mask_sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_alarm_set_a_t, AL_Mask_sec) }, \
         { "AL_date_week_day_sel", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_alarm_set_a_t, AL_date_week_day_sel) }, \
         { "AL_date", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_alarm_set_a_t, AL_date) }, \
         { "AL_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_alarm_set_a_t, AL_hour) }, \
         { "AL_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_alarm_set_a_t, AL_min) }, \
         { "AL_sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_alarm_set_a_t, AL_sec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ALARM_SET_A { \
	"ALARM_SET_A", \
	9, \
	{  { "AL_Mask_week", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_alarm_set_a_t, AL_Mask_week) }, \
         { "AL_Mask_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_alarm_set_a_t, AL_Mask_hour) }, \
         { "AL_Mask_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_alarm_set_a_t, AL_Mask_min) }, \
         { "AL_Mask_sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_alarm_set_a_t, AL_Mask_sec) }, \
         { "AL_date_week_day_sel", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_alarm_set_a_t, AL_date_week_day_sel) }, \
         { "AL_date", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_alarm_set_a_t, AL_date) }, \
         { "AL_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_alarm_set_a_t, AL_hour) }, \
         { "AL_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_alarm_set_a_t, AL_min) }, \
         { "AL_sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_alarm_set_a_t, AL_sec) }, \
         } \
}
#endif

/**
 * @brief Pack a alarm_set_a message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param AL_Mask_week Alarm Mask setting
 * @param AL_Mask_hour Alarm Mask setting
 * @param AL_Mask_min Alarm Mask setting
 * @param AL_Mask_sec Alarm Mask setting
 * @param AL_date_week_day_sel Alarm Mask setting
 * @param AL_date Alarm Mask setting
 * @param AL_hour Alarm time  hour setting
 * @param AL_min Alarm time  min setting
 * @param AL_sec Alarm time  sec setting
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_alarm_set_a_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t AL_Mask_week, uint8_t AL_Mask_hour, uint8_t AL_Mask_min, uint8_t AL_Mask_sec, uint8_t AL_date_week_day_sel, uint8_t AL_date, uint8_t AL_hour, uint8_t AL_min, uint8_t AL_sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ALARM_SET_A_LEN];
	_mav_put_uint8_t(buf, 0, AL_Mask_week);
	_mav_put_uint8_t(buf, 1, AL_Mask_hour);
	_mav_put_uint8_t(buf, 2, AL_Mask_min);
	_mav_put_uint8_t(buf, 3, AL_Mask_sec);
	_mav_put_uint8_t(buf, 4, AL_date_week_day_sel);
	_mav_put_uint8_t(buf, 5, AL_date);
	_mav_put_uint8_t(buf, 6, AL_hour);
	_mav_put_uint8_t(buf, 7, AL_min);
	_mav_put_uint8_t(buf, 8, AL_sec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ALARM_SET_A_LEN);
#else
	mavlink_alarm_set_a_t packet;
	packet.AL_Mask_week = AL_Mask_week;
	packet.AL_Mask_hour = AL_Mask_hour;
	packet.AL_Mask_min = AL_Mask_min;
	packet.AL_Mask_sec = AL_Mask_sec;
	packet.AL_date_week_day_sel = AL_date_week_day_sel;
	packet.AL_date = AL_date;
	packet.AL_hour = AL_hour;
	packet.AL_min = AL_min;
	packet.AL_sec = AL_sec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ALARM_SET_A_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ALARM_SET_A;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
}

/**
 * @brief Pack a alarm_set_a message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param AL_Mask_week Alarm Mask setting
 * @param AL_Mask_hour Alarm Mask setting
 * @param AL_Mask_min Alarm Mask setting
 * @param AL_Mask_sec Alarm Mask setting
 * @param AL_date_week_day_sel Alarm Mask setting
 * @param AL_date Alarm Mask setting
 * @param AL_hour Alarm time  hour setting
 * @param AL_min Alarm time  min setting
 * @param AL_sec Alarm time  sec setting
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_alarm_set_a_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t AL_Mask_week,uint8_t AL_Mask_hour,uint8_t AL_Mask_min,uint8_t AL_Mask_sec,uint8_t AL_date_week_day_sel,uint8_t AL_date,uint8_t AL_hour,uint8_t AL_min,uint8_t AL_sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ALARM_SET_A_LEN];
	_mav_put_uint8_t(buf, 0, AL_Mask_week);
	_mav_put_uint8_t(buf, 1, AL_Mask_hour);
	_mav_put_uint8_t(buf, 2, AL_Mask_min);
	_mav_put_uint8_t(buf, 3, AL_Mask_sec);
	_mav_put_uint8_t(buf, 4, AL_date_week_day_sel);
	_mav_put_uint8_t(buf, 5, AL_date);
	_mav_put_uint8_t(buf, 6, AL_hour);
	_mav_put_uint8_t(buf, 7, AL_min);
	_mav_put_uint8_t(buf, 8, AL_sec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ALARM_SET_A_LEN);
#else
	mavlink_alarm_set_a_t packet;
	packet.AL_Mask_week = AL_Mask_week;
	packet.AL_Mask_hour = AL_Mask_hour;
	packet.AL_Mask_min = AL_Mask_min;
	packet.AL_Mask_sec = AL_Mask_sec;
	packet.AL_date_week_day_sel = AL_date_week_day_sel;
	packet.AL_date = AL_date;
	packet.AL_hour = AL_hour;
	packet.AL_min = AL_min;
	packet.AL_sec = AL_sec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ALARM_SET_A_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ALARM_SET_A;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
}

/**
 * @brief Encode a alarm_set_a struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param alarm_set_a C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_alarm_set_a_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_alarm_set_a_t* alarm_set_a)
{
	return mavlink_msg_alarm_set_a_pack(system_id, component_id, msg, alarm_set_a->AL_Mask_week, alarm_set_a->AL_Mask_hour, alarm_set_a->AL_Mask_min, alarm_set_a->AL_Mask_sec, alarm_set_a->AL_date_week_day_sel, alarm_set_a->AL_date, alarm_set_a->AL_hour, alarm_set_a->AL_min, alarm_set_a->AL_sec);
}

/**
 * @brief Encode a alarm_set_a struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param alarm_set_a C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_alarm_set_a_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_alarm_set_a_t* alarm_set_a)
{
	return mavlink_msg_alarm_set_a_pack_chan(system_id, component_id, chan, msg, alarm_set_a->AL_Mask_week, alarm_set_a->AL_Mask_hour, alarm_set_a->AL_Mask_min, alarm_set_a->AL_Mask_sec, alarm_set_a->AL_date_week_day_sel, alarm_set_a->AL_date, alarm_set_a->AL_hour, alarm_set_a->AL_min, alarm_set_a->AL_sec);
}

/**
 * @brief Send a alarm_set_a message
 * @param chan MAVLink channel to send the message
 *
 * @param AL_Mask_week Alarm Mask setting
 * @param AL_Mask_hour Alarm Mask setting
 * @param AL_Mask_min Alarm Mask setting
 * @param AL_Mask_sec Alarm Mask setting
 * @param AL_date_week_day_sel Alarm Mask setting
 * @param AL_date Alarm Mask setting
 * @param AL_hour Alarm time  hour setting
 * @param AL_min Alarm time  min setting
 * @param AL_sec Alarm time  sec setting
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_alarm_set_a_send(mavlink_channel_t chan, uint8_t AL_Mask_week, uint8_t AL_Mask_hour, uint8_t AL_Mask_min, uint8_t AL_Mask_sec, uint8_t AL_date_week_day_sel, uint8_t AL_date, uint8_t AL_hour, uint8_t AL_min, uint8_t AL_sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ALARM_SET_A_LEN];
	_mav_put_uint8_t(buf, 0, AL_Mask_week);
	_mav_put_uint8_t(buf, 1, AL_Mask_hour);
	_mav_put_uint8_t(buf, 2, AL_Mask_min);
	_mav_put_uint8_t(buf, 3, AL_Mask_sec);
	_mav_put_uint8_t(buf, 4, AL_date_week_day_sel);
	_mav_put_uint8_t(buf, 5, AL_date);
	_mav_put_uint8_t(buf, 6, AL_hour);
	_mav_put_uint8_t(buf, 7, AL_min);
	_mav_put_uint8_t(buf, 8, AL_sec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ALARM_SET_A, buf, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
#else
	mavlink_alarm_set_a_t packet;
	packet.AL_Mask_week = AL_Mask_week;
	packet.AL_Mask_hour = AL_Mask_hour;
	packet.AL_Mask_min = AL_Mask_min;
	packet.AL_Mask_sec = AL_Mask_sec;
	packet.AL_date_week_day_sel = AL_date_week_day_sel;
	packet.AL_date = AL_date;
	packet.AL_hour = AL_hour;
	packet.AL_min = AL_min;
	packet.AL_sec = AL_sec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ALARM_SET_A, (const char *)&packet, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
#endif
}

/**
 * @brief Send a alarm_set_a message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_alarm_set_a_send_struct(mavlink_channel_t chan, const mavlink_alarm_set_a_t* alarm_set_a)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_alarm_set_a_send(chan, alarm_set_a->AL_Mask_week, alarm_set_a->AL_Mask_hour, alarm_set_a->AL_Mask_min, alarm_set_a->AL_Mask_sec, alarm_set_a->AL_date_week_day_sel, alarm_set_a->AL_date, alarm_set_a->AL_hour, alarm_set_a->AL_min, alarm_set_a->AL_sec);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ALARM_SET_A, (const char *)alarm_set_a, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
#endif
}

#if MAVLINK_MSG_ID_ALARM_SET_A_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_alarm_set_a_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t AL_Mask_week, uint8_t AL_Mask_hour, uint8_t AL_Mask_min, uint8_t AL_Mask_sec, uint8_t AL_date_week_day_sel, uint8_t AL_date, uint8_t AL_hour, uint8_t AL_min, uint8_t AL_sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, AL_Mask_week);
	_mav_put_uint8_t(buf, 1, AL_Mask_hour);
	_mav_put_uint8_t(buf, 2, AL_Mask_min);
	_mav_put_uint8_t(buf, 3, AL_Mask_sec);
	_mav_put_uint8_t(buf, 4, AL_date_week_day_sel);
	_mav_put_uint8_t(buf, 5, AL_date);
	_mav_put_uint8_t(buf, 6, AL_hour);
	_mav_put_uint8_t(buf, 7, AL_min);
	_mav_put_uint8_t(buf, 8, AL_sec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ALARM_SET_A, buf, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
#else
	mavlink_alarm_set_a_t *packet = (mavlink_alarm_set_a_t *)msgbuf;
	packet->AL_Mask_week = AL_Mask_week;
	packet->AL_Mask_hour = AL_Mask_hour;
	packet->AL_Mask_min = AL_Mask_min;
	packet->AL_Mask_sec = AL_Mask_sec;
	packet->AL_date_week_day_sel = AL_date_week_day_sel;
	packet->AL_date = AL_date;
	packet->AL_hour = AL_hour;
	packet->AL_min = AL_min;
	packet->AL_sec = AL_sec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ALARM_SET_A, (const char *)packet, MAVLINK_MSG_ID_ALARM_SET_A_MIN_LEN, MAVLINK_MSG_ID_ALARM_SET_A_LEN, MAVLINK_MSG_ID_ALARM_SET_A_CRC);
#endif
}
#endif

#endif

// MESSAGE ALARM_SET_A UNPACKING


/**
 * @brief Get field AL_Mask_week from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_Mask_week(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field AL_Mask_hour from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_Mask_hour(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field AL_Mask_min from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_Mask_min(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field AL_Mask_sec from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_Mask_sec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field AL_date_week_day_sel from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_date_week_day_sel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field AL_date from alarm_set_a message
 *
 * @return Alarm Mask setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_date(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field AL_hour from alarm_set_a message
 *
 * @return Alarm time  hour setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_hour(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field AL_min from alarm_set_a message
 *
 * @return Alarm time  min setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_min(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field AL_sec from alarm_set_a message
 *
 * @return Alarm time  sec setting
 */
static inline uint8_t mavlink_msg_alarm_set_a_get_AL_sec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a alarm_set_a message into a struct
 *
 * @param msg The message to decode
 * @param alarm_set_a C-struct to decode the message contents into
 */
static inline void mavlink_msg_alarm_set_a_decode(const mavlink_message_t* msg, mavlink_alarm_set_a_t* alarm_set_a)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	alarm_set_a->AL_Mask_week = mavlink_msg_alarm_set_a_get_AL_Mask_week(msg);
	alarm_set_a->AL_Mask_hour = mavlink_msg_alarm_set_a_get_AL_Mask_hour(msg);
	alarm_set_a->AL_Mask_min = mavlink_msg_alarm_set_a_get_AL_Mask_min(msg);
	alarm_set_a->AL_Mask_sec = mavlink_msg_alarm_set_a_get_AL_Mask_sec(msg);
	alarm_set_a->AL_date_week_day_sel = mavlink_msg_alarm_set_a_get_AL_date_week_day_sel(msg);
	alarm_set_a->AL_date = mavlink_msg_alarm_set_a_get_AL_date(msg);
	alarm_set_a->AL_hour = mavlink_msg_alarm_set_a_get_AL_hour(msg);
	alarm_set_a->AL_min = mavlink_msg_alarm_set_a_get_AL_min(msg);
	alarm_set_a->AL_sec = mavlink_msg_alarm_set_a_get_AL_sec(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ALARM_SET_A_LEN? msg->len : MAVLINK_MSG_ID_ALARM_SET_A_LEN;
        memset(alarm_set_a, 0, MAVLINK_MSG_ID_ALARM_SET_A_LEN);
	memcpy(alarm_set_a, _MAV_PAYLOAD(msg), len);
#endif
}
