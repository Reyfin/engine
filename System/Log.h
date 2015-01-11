﻿#ifndef LOG_H
#define LOG_H

#include <ostream>
#include <string>


/**
 * @brief The LogLevel enum class is for defining which level should be logged in Log \sa Log
 *
 */

enum class LogLevel
{
	debug	= 5,	/** Debuggingoutput */
	info	= 4,	/** Infooutput like timemeasurements */
	warning	= 3,	/** Warnings, for example functions you shouldnt use or maybe unsafe stuff */
	error	= 2,	/** Stuff that is for sure wrong, bad doesn't lead the programm to a shutdown */
	fatal	= 1,	/** Errors, that cause the programm to terminate/don't work correct */
};

/**
 * @brief operator >
 * @param a
 * @param b
 * @return bool
 */
constexpr bool operator>(LogLevel a, LogLevel b)
{
	return static_cast<int>(a) > static_cast<int>(b);
}

/**
 * @brief operator <
 * @param a
 * @param b
 * @return bool
 */
constexpr bool operator<(LogLevel a, LogLevel b)
{
	return static_cast<int>(a) < static_cast<int>(b);
}

/**
 * @brief operator >=
 * @param a
 * @param b
 * @return bool
 */
constexpr bool operator>=(LogLevel a, LogLevel b)
{
	return static_cast<int>(a) >= static_cast<int>(b);
}

/**
 * @brief operator <=
 * @param a
 * @param b
 * @return bool
 */
constexpr bool operator<=(LogLevel a, LogLevel b)
{
	return static_cast<int>(a) <= static_cast<int>(b);
}

/**
 * @brief The Log class is for logging in every programm.
 *
 * For logging there are different logging-levels \sa LogLevel.
 *
 * Each loglevel has different colors, which are a map from stringliterals to colors.
 * \sa OutputColor
 *
 * The default output is standardout(std::cout), you can choose a stream for logging.
 */
class Log
{
public:
	/**
	 * @brief Log defaultconstructor for logging
	 * @param level determines the loglevel \sa LogLevel
	 *
	 * Constructs a object for logging. The Loglevel ist default error and the output is default
	 * std::cout
	 */
	Log(LogLevel level = LogLevel::error);

	/**
	 * @brief Log constructor with outputstream and loglevel
	 * @param stream outputstream for the log
	 * @param level determines the loglevel \sa LogLevel
	 * Constructs a object for logging. The Loglevel ist default error and the output is default
	 * std::cout
	 */
	Log(std::ostream& stream, LogLevel level = LogLevel::error);

	/**
	 * @brief disallow copyconstructor for this class
	 * @param other
	 */
	Log(const Log& other) = delete;

	/**
	 * @brief disallow copyassignment for this class
	 * @param other
	 */
	Log& operator=(const Log& other) = delete;

	/**
	 * @brief debug output
	 * @param msg the message that should be logged
	 *
	 * Note that this is only printed if the level ist to debug or higher
	 */
	void debug(const std::string& msg);

	/**
	 * @brief info output
	 * @param msg the message that should be logged
	 *
	 * Note that this is only printed if the level ist to info or higher
	 */
	void info(const std::string& msg);

	/**
	 * @brief warning output
	 * @param msg the message that should be logged
	 *
	 * Note that this is only printed if the level ist to warning or higher
	 */
	void warning(const std::string& msg);

	/**
	 * @brief error output
	 * @param msg the message that should be logged
	 *
	 * Note that this is only printed if the level ist to error or higher
	 */
	void error(const std::string& msg);

	/**
	 * @brief fatal output
	 * @param msg the message that should be logged
	 *
	 * Note that this is only printed if the level ist to fatal or higher
	 */
	void fatal(const std::string& msg);


	/**
	 * @brief operator << will log with the semantics of a debug log, everything else should be
	 *	explicit
	 * @param msg
	 * @return reference to logger
	 */
	//Log& operator<<(const std::string& msg);


///
/// INTERFACE END
///
private:
	enum LogLevel		__lvl;		/** loglevel determines which logmessages are printed */
	std::ostream&		__outstream;/** outputstream where the log is written */
};


#endif // LOG_H