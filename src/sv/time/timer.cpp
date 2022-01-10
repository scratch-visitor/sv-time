#include <sv/time/time.hpp>
#include <chrono>

namespace sv
{

class timer::implement
{
  timer* m_parent;
  std::ostream& m_os;

  std::shared_ptr<api::basic_task> m_task;

  std::chrono::steady_clock::time_point m_start;

public:
  implement(timer* _parent, std::ostream& _os)
    : m_parent(_parent)
    , m_os(_os)
    , m_task(nullptr)
    , m_start(std::chrono::steady_clock::now())
  {
  }
  ~implement()
  {
  }
  void start(std::shared_ptr<api::basic_task> _task)
  {
    if (_task)
    {
      m_task = _task;
    }

    if (!m_task)
    {
      return;
    }

    m_start = std::chrono::steady_clock::now();
    m_os << '[' << m_task->name << "] begin" << std::endl;

    // do something.
    {
      m_task->execute(nullptr);
    }
  }
  void stop()
  {
    auto end = std::chrono::steady_clock::now();

    auto diff = end - m_start;

    if (!m_task)
    {
      return;
    }

    m_os << '[' << m_task->name << "] finished. ";
    m_os << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    m_os << "ms elapsed." << std::endl;
  }
};

timer::timer(std::ostream& _os)
  : impl(new implement(this, _os))
{
}
timer::~timer()
{
  if (impl)
  {
    delete impl;
    impl = nullptr;
  }
}
void timer::start(std::shared_ptr<api::basic_task> _task/*=nullptr*/)
{
  impl->start(_task);
}
void timer::stop()
{
  impl->stop();
}

} // namespace sv