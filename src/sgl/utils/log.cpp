#include "sgl/utils/log.h"




#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace sgl
{
	static std::shared_ptr<spdlog::logger> logger;
	sglLog::sglLog()
	{
		logger = spdlog::stdout_color_mt<spdlog::async_factory>("sgl async log");
		logger->set_level(this->__level__);
		logger->set_pattern(this->__pattern__);

	}
	void sglLog::_log(const spdlog::source_loc& loc, spdlog::level::level_enum level, const spdlog::memory_buf_t& buf)
	{
		logger->log(loc, level, std::string_view(buf.data(), buf.size()));
	}

}