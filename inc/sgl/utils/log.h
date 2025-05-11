#ifndef __SGL_UITILS_LOG__
#define __SGL_UITILS_LOG__

#include "spdlog/common.h"



namespace sgl
{
	class SGL_API sglLog
	{
	private:
		static inline spdlog::level::level_enum __level__ = spdlog::level::trace;
		static inline std::string __pattern__ = "%^<%L> [%D %T %e ms] [%s:%# %!] %v%$";

	public:
		static sglLog& get_instance()
		{
			static sglLog log;
			return log;
		}

		template<class ... Args>
		void log(const spdlog::source_loc& loc, spdlog::level::level_enum level,spdlog::format_string_t<Args...> fmt, Args&&...args)
		{
			spdlog::memory_buf_t buf;
			fmt::vformat_to(fmt::appender(buf), fmt, fmt::make_format_args(args...));
			this->_log(loc,level,buf);
		}
	private:
		void _log(const spdlog::source_loc& loc, spdlog::level::level_enum level, const spdlog::memory_buf_t& buf);
		sglLog();
		~sglLog() = default;

	};
}
#define SGL_LOG_CALL(logger,level,...) logger.log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, level, __VA_ARGS__)
#define SGL_LOG_T(...) SGL_LOG_CALL(sgl::sglLog::get_instance(),spdlog::level::trace,__VA_ARGS__)
#define SGL_LOG_D(...) SGL_LOG_CALL(sgl::sglLog::get_instance(),spdlog::level::debug,__VA_ARGS__)
#define SGL_LOG_I(...) SGL_LOG_CALL(sgl::sglLog::get_instance(),spdlog::level::info,__VA_ARGS__)
#define SGL_LOG_W(...) SGL_LOG_CALL(sgl::sglLog::get_instance(),spdlog::level::warn,__VA_ARGS__)
#define SGL_LOG_E(...) SGL_LOG_CALL(sgl::sglLog::get_instance(),spdlog::level::err,__VA_ARGS__)



#endif //!__SGL_UITILS_LOG__