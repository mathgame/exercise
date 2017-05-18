#ifndef SIGNALS_H
#define SIGNALS_H

//#include <string>
//#include <vector>
//#include <functional>
//#include <unordered_map>
#include <nonstd/binder.hpp>
//class Point;

//using PointFunction = std::function<void(const Point&)>;
//using PointFunctionVec = std::vector<PointFunction>;

//struct Signals
//{
//public:
//	static Signals& Get();

//	void Connect(const std::string& signalName, PointFunction funct);
//	void DispatchSignal(const std::string& signalName, const Point& point);
//	void Disconnect();

//private:
//	Signals() = default;
//	Signals(const Signals&) = default;
//	Signals(Signals&&) = default;


//	std::unordered_map<std::string, PointFunctionVec> m_functions;
//};

struct Signals
{
	static binder_t<>& Get()
	{
		static binder_t<> binder;
		return binder;
	}
};



#endif //SIGNALS_H
