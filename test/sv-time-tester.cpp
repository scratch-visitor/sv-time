#include <iostream>
#include <memory>
#include <thread>
#include <sv/time.hpp>

using namespace std::chrono_literals;

namespace t
{

struct action : public sv::api::basic_task
{
  int execute(std::shared_ptr<sv::api::message> args)
  {
    std::this_thread::sleep_for(2s);
    return 0;
  }
};

struct actor
{
};


} // namespace t

int main()
{
  try
  {

    /* code */
    std::shared_ptr<sv::timer> sample;
    sample = std::make_shared<sv::timer>(std::cout);

    std::shared_ptr<t::action> job = std::make_shared<t::action>();
    job->name = std::string("job #1");

    sample->start(job);

    sample->stop();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return 0;
}