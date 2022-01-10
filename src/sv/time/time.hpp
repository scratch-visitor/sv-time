#ifndef __SV_TIME_HPP__
#define __SV_TIME_HPP__

#include <iostream>
#include <string>
#include <memory>
#include <functional>

namespace sv
{
namespace api
{

struct basic_signal
{
};

struct basic_presenter
{
};

struct basic_input : basic_signal
{
};

struct basic_user_input : basic_input
{
};

struct message
{
  std::string data;
};

struct basic_task
{
  std::string name;
  virtual int execute(std::shared_ptr<message>) = 0;
};

} // namespace api

class timer
{
public:
  timer(std::ostream& _os);
  virtual ~timer();

  void start(std::shared_ptr<api::basic_task> _task = nullptr);
  void stop();

private:
  class implement;
  implement* impl;
};

} // namespace sv

#endif // __SV_TIME_HPP__