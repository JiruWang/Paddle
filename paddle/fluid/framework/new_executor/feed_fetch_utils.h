// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <map>
#include <vector>

#include "paddle/fluid/framework/new_executor/interpreter/plan.h"
#include "paddle/fluid/framework/program_desc.h"
#include "paddle/fluid/framework/scope.h"

namespace paddle {
namespace framework {

void SetColAttrForFeedFetchOps(std::shared_ptr<ProgramDesc> program_desc,
                               const int64_t micro_batch_num,
                               const int64_t micro_batch_id);

void SplitFeedTensor(const std::vector<std::string>& feed_names,
                     const int64_t micro_batch_num,
                     Scope* scope,
                     std::vector<std::vector<phi::DenseTensor>>* out);

}  // namespace framework
}  // namespace paddle
