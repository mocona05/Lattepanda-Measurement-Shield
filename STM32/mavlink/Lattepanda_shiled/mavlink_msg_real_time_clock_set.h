// MESSAGE REAL_TIME_CLOCK_SET PACKING

#define MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET 209

MAVPACKED(
typedef struct __mavlink_real_time_clock_set_t {
 uint32_t subsec; /*< Real time clock sec setting*/
 uint16_t year; /*< Real time clock Year setting*/
 uint8_t month; /*< Real time clock month setting*/
 uint8_t mday; /*< Real time clock month setting*/
 uint8_t wday; /*< Real time clock wday setting*/
 uint8_t hour; /*< Real time clock hour setting*/
 uint8_t min; /*< Real time clock min setting*/
 uint8_t sec; /*< Real time clock sec setting*/
 uint8_t timeFormat; /*< Real time clock timeFormat setting*/
 uint8_t DayLightSaving; /*< Real time clock DayLightSaving setting*/
}) mavlink_real_time_clock_set_t;

#define MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN 14
#define MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN 14
#define MAVLINK_MSG_ID_209_LEN 14
#define MAVLINK_MSG_ID_209_MIN_LEN 14

#define MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC 234
#define MAVLINK_MSG_ID_209_CRC 234



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REAL_TIME_CLOCK_SET { \
	209, \
	"REAL_TIME_CLOCK_SET", \
	10, \
	{  { "subsec", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_real_time_clock_set_t, subsec) }, \
         { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_real_time_clock_set_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_real_time_clock_set_t, month) }, \
         { "mday", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_real_time_clock_set_t, mday) }, \
         { "wday", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_real_time_clock_set_t, wday) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_real_time_clock_set_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_real_time_clock_set_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_real_time_clock_set_t, sec) }, \
         { "timeFormat", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_real_time_clock_set_t, timeFormat) }, \
         { "DayLightSaving", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_real_time_clock_set_t, DayLightSaving) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REAL_TIME_CLOCK_SET { \
	"REAL_TIME_CLOCK_SET", \
	10, \
	{  { "subsec", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_real_time_clock_set_t, subsec) }, \
         { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_real_time_clock_set_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_real_time_clock_set_t, month) }, \
         { "mday", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_real_time_clock_set_t, mday) }, \
         { "wday", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_real_time_clock_set_t, wday) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_real_time_clock_set_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_real_time_clock_set_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_real_time_clock_set_t, sec) }, \
         { "timeFormat", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_real_time_clock_set_t, timeFormat) }, \
         { "DayLightSaving", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_real_time_clock_set_t, DayLightSaving) }, \
         } \
}
#endif

/**
 * @brief Pack a real_time_clock_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param subsec Real time clock sec setting
 * @param year Real time clock Year setting
 * @param month Real time clock month setting
 * @param mday Real time clock month setting
 * @param wday Real time clock wday setting
 * @param hour Real time clock hour setting
 * @param min Real time clock min setting
 * @param sec Real time clock sec setting
 * @param timeFormat Real time clock timeFormat setting
 * @param DayLightSaving Real time clock DayLightSaving setting
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_real_time_clock_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t subsec, uint16_t year, uint8_t month, uint8_t mday, uint8_t wday, uint8_t hour, uint8_t min, uint8_t sec, uint8_t timeFormat, uint8_t DayLightSaving)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN];
	_mav_put_uint32_t(buf, 0, subsec);
	_mav_put_uint16_t(buf, 4, year);
	_mav_put_uint8_t(buf, 6, month);
	_mav_put_uint8_t(buf, 7, mday);
	_mav_put_uint8_t(buf, 8, wday);
	_mav_put_uint8_t(buf, 9, hour);
	_mav_put_uint8_t(buf, 10, min);
	_mav_put_uint8_t(buf, 11, sec);
	_mav_put_uint8_t(buf, 12, timeFormat);
	_mav_put_uint8_t(buf, 13, DayLightSaving);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN);
#else
	mavlink_real_time_clock_set_t packet;
	packet.subsec = subsec;
	packet.year = year;
	packet.month = month;
	packet.mday = mday;
	packet.wday = wday;
	packet.hour = hour;
	packet.min = min;
	packet.sec = sec;
	packet.timeFormat = timeFormat;
	packet.DayLightSaving = DayLightSaving;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
}

/**
 * @brief Pack a real_time_clock_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param subsec Real time clock sec setting
 * @param year Real time clock Year setting
 * @param month Real time clock month setting
 * @param mday Real time clock month setting
 * @param wday Real time clock wday setting
 * @param hour Real time clock hour setting
 * @param min Real time clock min setting
 * @param sec Real time clock sec setting
 * @param timeFormat Real time clock timeFormat setting
 * @param DayLightSaving Real time clock DayLightSaving setting
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_real_time_clock_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t subsec,uint16_t year,uint8_t month,uint8_t mday,uint8_t wday,uint8_t hour,uint8_t min,uint8_t sec,uint8_t timeFormat,uint8_t DayLightSaving)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN];
	_mav_put_uint32_t(buf, 0, subsec);
	_mav_put_uint16_t(buf, 4, year);
	_mav_put_uint8_t(buf, 6, month);
	_mav_put_uint8_t(buf, 7, mday);
	_mav_put_uint8_t(buf, 8, wday);
	_mav_put_uint8_t(buf, 9, hour);
	_mav_put_uint8_t(buf, 10, min);
	_mav_put_uint8_t(buf, 11, sec);
	_mav_put_uint8_t(buf, 12, timeFormat);
	_mav_put_uint8_t(buf, 13, DayLightSaving);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN);
#else
	mavlink_real_time_clock_set_t packet;
	packet.subsec = subsec;
	packet.year = year;
	packet.month = month;
	packet.mday = mday;
	packet.wday = wday;
	packet.hour = hour;
	packet.min = min;
	packet.sec = sec;
	packet.timeFormat = timeFormat;
	packet.DayLightSaving = DayLightSaving;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
}

/**
 * @brief Encode a real_time_clock_set struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param real_time_clock_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_real_time_clock_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_real_time_clock_set_t* real_time_clock_set)
{
	return mavlink_msg_real_time_clock_set_pack(system_id, component_id, msg, real_time_clock_set->subsec, real_time_clock_set->year, real_time_clock_set->month, real_time_clock_set->mday, real_time_clock_set->wday, real_time_clock_set->hour, real_time_clock_set->min, real_time_clock_set->sec, real_time_clock_set->timeFormat, real_time_clock_set->DayLightSaving);
}

/**
 * @brief Encode a real_time_clock_set struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param real_time_clock_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_real_time_clock_set_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_real_time_clock_set_t* real_time_clock_set)
{
	return mavlink_msg_real_time_clock_set_pack_chan(system_id, component_id, chan, msg, real_time_clock_set->subsec, real_time_clock_set->year, real_time_clock_set->month, real_time_clock_set->mday, real_time_clock_set->wday, real_time_clock_set->hour, real_time_clock_set->min, real_time_clock_set->sec, real_time_clock_set->timeFormat, real_time_clock_set->DayLightSaving);
}

/**
 * @brief Send a real_time_clock_set message
 * @param chan MAVLink channel to send the message
 *
 * @param subsec Real time clock sec setting
 * @param year Real time clock Year setting
 * @param month Real time clock month setting
 * @param mday Real time clock month setting
 * @param wday Real time clock wday setting
 * @param hour Real time clock hour setting
 * @param min Real time clock min setting
 * @param sec Real time clock sec setting
 * @param timeFormat Real time clock timeFormat setting
 * @param DayLightSaving Real time clock DayLightSaving setting
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_real_time_clock_set_send(mavlink_channel_t chan, uint32_t subsec, uint16_t year, uint8_t month, uint8_t mday, uint8_t wday, uint8_t hour, uint8_t min, uint8_t sec, uint8_t timeFormat, uint8_t DayLightSaving)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN];
	_mav_put_uint32_t(buf, 0, subsec);
	_mav_put_uint16_t(buf, 4, year);
	_mav_put_uint8_t(buf, 6, month);
	_mav_put_uint8_t(buf, 7, mday);
	_mav_put_uint8_t(buf, 8, wday);
	_mav_put_uint8_t(buf, 9, hour);
	_mav_put_uint8_t(buf, 10, min);
	_mav_put_uint8_t(buf, 11, sec);
	_mav_put_uint8_t(buf, 12, timeFormat);
	_mav_put_uint8_t(buf, 13, DayLightSaving);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET, buf, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
#else
	mavlink_real_time_clock_set_t packet;
	packet.subsec = subsec;
	packet.year = year;
	packet.month = month;
	packet.mday = mday;
	packet.wday = wday;
	packet.hour = hour;
	packet.min = min;
	packet.sec = sec;
	packet.timeFormat = timeFormat;
	packet.DayLightSaving = DayLightSaving;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET, (const char *)&packet, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
#endif
}

/**
 * @brief Send a real_time_clock_set message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_real_time_clock_set_send_struct(mavlink_channel_t chan, const mavlink_real_time_clock_set_t* real_time_clock_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_real_time_clock_set_send(chan, real_time_clock_set->subsec, real_time_clock_set->year, real_time_clock_set->month, real_time_clock_set->mday, real_time_clock_set->wday, real_time_clock_set->hour, real_time_clock_set->min, real_time_clock_set->sec, real_time_clock_set->timeFormat, real_time_clock_set->DayLightSaving);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET, (const char *)real_time_clock_set, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
#endif
}

#if MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_real_time_clock_set_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t subsec, uint16_t year, uint8_t month, uint8_t mday, uint8_t wday, uint8_t hour, uint8_t min, uint8_t sec, uint8_t timeFormat, uint8_t DayLightSaving)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, subsec);
	_mav_put_uint16_t(buf, 4, year);
	_mav_put_uint8_t(buf, 6, month);
	_mav_put_uint8_t(buf, 7, mday);
	_mav_put_uint8_t(buf, 8, wday);
	_mav_put_uint8_t(buf, 9, hour);
	_mav_put_uint8_t(buf, 10, min);
	_mav_put_uint8_t(buf, 11, sec);
	_mav_put_uint8_t(buf, 12, timeFormat);
	_mav_put_uint8_t(buf, 13, DayLightSaving);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET, buf, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
#else
	mavlink_real_time_clock_set_t *packet = (mavlink_real_time_clock_set_t *)msgbuf;
	packet->subsec = subsec;
	packet->year = year;
	packet->month = month;
	packet->mday = mday;
	packet->wday = wday;
	packet->hour = hour;
	packet->min = min;
	packet->sec = sec;
	packet->timeFormat = timeFormat;
	packet->DayLightSaving = DayLightSaving;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET, (const char *)packet, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_MIN_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_CRC);
#endif
}
#endif

#endif

// MESSAGE REAL_TIME_CLOCK_SET UNPACKING


/**
 * @brief Get field subsec from real_time_clock_set message
 *
 * @return Real time clock sec setting
 */
static inline uint32_t mavlink_msg_real_time_clock_set_get_subsec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field year from real_time_clock_set message
 *
 * @return Real time clock Year setting
 */
static inline uint16_t mavlink_msg_real_time_clock_set_get_year(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field month from real_time_clock_set message
 *
 * @return Real time clock month setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_month(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field mday from real_time_clock_set message
 *
 * @return Real time clock month setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_mday(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field wday from real_time_clock_set message
 *
 * @return Real time clock wday setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_wday(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field hour from real_time_clock_set message
 *
 * @return Real time clock hour setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_hour(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field min from real_time_clock_set message
 *
 * @return Real time clock min setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_min(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field sec from real_time_clock_set message
 *
 * @return Real time clock sec setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_sec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field timeFormat from real_time_clock_set message
 *
 * @return Real time clock timeFormat setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_timeFormat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field DayLightSaving from real_time_clock_set message
 *
 * @return Real time clock DayLightSaving setting
 */
static inline uint8_t mavlink_msg_real_time_clock_set_get_DayLightSaving(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Decode a real_time_clock_set message into a struct
 *
 * @param msg The message to decode
 * @param real_time_clock_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_real_time_clock_set_decode(const mavlink_message_t* msg, mavlink_real_time_clock_set_t* real_time_clock_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	real_time_clock_set->subsec = mavlink_msg_real_time_clock_set_get_subsec(msg);
	real_time_clock_set->year = mavlink_msg_real_time_clock_set_get_year(msg);
	real_time_clock_set->month = mavlink_msg_real_time_clock_set_get_month(msg);
	real_time_clock_set->mday = mavlink_msg_real_time_clock_set_get_mday(msg);
	real_time_clock_set->wday = mavlink_msg_real_time_clock_set_get_wday(msg);
	real_time_clock_set->hour = mavlink_msg_real_time_clock_set_get_hour(msg);
	real_time_clock_set->min = mavlink_msg_real_time_clock_set_get_min(msg);
	real_time_clock_set->sec = mavlink_msg_real_time_clock_set_get_sec(msg);
	real_time_clock_set->timeFormat = mavlink_msg_real_time_clock_set_get_timeFormat(msg);
	real_time_clock_set->DayLightSaving = mavlink_msg_real_time_clock_set_get_DayLightSaving(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN? msg->len : MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN;
        memset(real_time_clock_set, 0, MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET_LEN);
	memcpy(real_time_clock_set, _MAV_PAYLOAD(msg), len);
#endif
}
