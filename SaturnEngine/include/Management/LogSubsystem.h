﻿#pragma once

#define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#define SPDLOG_LEVEL_NAMES { "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "CRIT", "OFF" }

#include "spdlog/spdlog.h"
#include "SaturnEngine/Core.h"

namespace SaturnEngine
{
	/**
	 * Logger for Saturn Engine.
	 *
	 * Wrapper around spdlog.
	 */
	class SATURN_API LogSubsystem
	{
	public:
		LogSubsystem();
		LogSubsystem(const LogSubsystem& other) = delete;
		LogSubsystem(LogSubsystem&& other) = delete;
		~LogSubsystem() = default;

		/**
		 * Getter function for the `spdlog::logger`.
		 *
		 * @return reference to `spdlog::logger`
		 */
		std::shared_ptr<spdlog::logger>& Logger();

		//Singleton instance getter function. Present in every subsystem.
		static LogSubsystem* Get();

		LogSubsystem& operator=(const LogSubsystem& other) = delete;
		LogSubsystem& operator=(LogSubsystem&& other) = delete;

	private:
		static LogSubsystem* s_instance;

		std::shared_ptr<spdlog::logger> m_logger;
	};
}

#define ST_LOG(...) SaturnEngine::LogSubsystem::Get()->Logger()->info(__VA_ARGS__)
#ifdef ST_BUILD_DEBUG
// Only logs when compiled in debug mode
#define ST_DEBUG(...) SaturnEngine::LogSubsystem::Get()->Logger()->info(__VA_ARGS__)
#else
// Only logs when compiled in debug mode
#define ST_DEBUG(...)
#endif
#define ST_WARN(...) SaturnEngine::LogSubsystem::Get()->Logger()->warn(__VA_ARGS__)
#define ST_ERROR(...) SaturnEngine::LogSubsystem::Get()->Logger()->error(__VA_ARGS__)
