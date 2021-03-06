/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "battery_service_event_handler.h"
#include "power_common.h"
#include "battery_service.h"

namespace OHOS {
namespace PowerMgr {
BatteryServiceEventHandler::BatteryServiceEventHandler(const std::shared_ptr<AppExecFwk::EventRunner> &runner,
    const wptr<BatteryService> &service)
    : AppExecFwk::EventHandler(runner), service_(service)
{
    POWER_HILOGD(MODULE_BATT_SERVICE, "BatteryServiceEventHandler::BatteryServiceEventHandler instance created.");
}

void BatteryServiceEventHandler::ProcessEvent([[maybe_unused]] const AppExecFwk::InnerEvent::Pointer &event) {}
} // namespace PowerMgr
} // namespace OHOS
