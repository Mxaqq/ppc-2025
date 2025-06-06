#pragma once

#include <cstddef>
#include <functional>
#include <utility>
#include <vector>

#include "core/task/include/task.hpp"

namespace chizhov_m_trapezoid_method_stl {
using Function = std::function<double(const std::vector<double>&)>;

double ComputeWeight(const std::vector<double>& point, const std::vector<double>& lower_limits,
                     const std::vector<double>& upper_limits);

double TrapezoidMethod(Function& f, size_t div, size_t dim, std::vector<double>& lower_limits,
                       std::vector<double>& upper_limits);

class TestTaskSTL : public ppc::core::Task {
 public:
  explicit TestTaskSTL(ppc::core::TaskDataPtr task_data) : Task(std::move(task_data)) {}

  bool PreProcessingImpl() override;
  bool ValidationImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;

 private:
  Function f_;
  std::vector<double> lower_limits_;
  std::vector<double> upper_limits_;
  size_t div_;
  size_t dim_;
  double res_;
};
}  // namespace chizhov_m_trapezoid_method_stl