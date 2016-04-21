#include "benchmark.hpp" // Benchmark

#include "results.hpp" // Results
#include "timer.hpp" // Timer

using namespace realm;
using namespace realm::test_util;

std::string Benchmark::lead_text()
{
    std::stringstream stream;
    stream << this->name() << " (MemOnly, EncryptionOff)";
    return stream.str();
}

std::string Benchmark::ident()
{
    std::stringstream stream;
    stream << this->name() << "_MemOnly_EncryptionOff";
    return stream.str();
}

void Benchmark::run(Results& results)
{
    Timer timer(Timer::type_UserTime);

    std::string lead_text = this->lead_text();
    std::string ident = this->ident();

    std::string realm_path = "results.txt";
    std::unique_ptr<SharedGroup> group;
    group.reset(new SharedGroup(realm_path, false,
                                SharedGroup::durability_MemOnly, nullptr));

    this->before_all(*group);


    this->after_all(*group);

    results.finish(ident, lead_text);
}
