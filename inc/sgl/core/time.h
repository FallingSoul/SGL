#ifndef __SGL_TIME__
#define __SGL_TIME__


namespace sgl
{
	class sglTime
	{
	private:
		using clock = std::chrono::steady_clock;
	public:
		sglTime() = default;
		~sglTime() = default;

		float time()const { return 1.f * this->_time / 1000 / 1000; }
	public:
		static sglTime now() 
		{
			sglTime time;
			time._time = clock::now().time_since_epoch().count();
			return time;
		}
		static sglTime now(sglTime last)
		{
			sglTime time;
			time._time = (clock::now().time_since_epoch().count() - last._time);
			return time;
		}
	private:
		long long _time;
	};

}

#endif //!__SGL_TIME__