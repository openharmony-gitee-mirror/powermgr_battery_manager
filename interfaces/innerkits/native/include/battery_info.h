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

#ifndef BATTERY_SRV_BATERY_INFO_H
#define BATTERY_SRV_BATERY_INFO_H

#include <string>

namespace OHOS {
namespace PowerMgr {
static constexpr int32_t INVALID_BATT_INT_VALUE = -1;
static constexpr int32_t INVALID_BATT_TEMP_VALUE = 100;
static const std::string INVALID_STRING_VALUE = "Invalid";
static constexpr bool INVALID_BATT_BOOL_VALUE = true;

/**
 * Type for acquire BatteryChargeState.
 */
enum class BatteryChargeState : uint32_t {
    /**
     * Battery is discharge.
     */
    CHARGE_STATE_NONE,

    /**
     * Battery is charging.
     */
    CHARGE_STATE_ENABLE,

    /**
     * Battery is not charging.
     */
    CHARGE_STATE_DISABLE,

    /**
     * Battery charge full.
     */
    CHARGE_STATE_FULL,

    /**
    * The bottom of the enum.
    */
    CHARGE_STATE_BUTT
};

/**
 * Type for acquire BatteryHealthState.
 */
enum class BatteryHealthState : uint32_t {
    /**
     * Health Status: unknown.
     */
    HEALTH_STATE_UNKNOWN,

    /**
     * Health Status: good.
     */
    HEALTH_STATE_GOOD,

    /**
     * Health Status: over heat.
     */
    HEALTH_STATE_OVERHEAT,

    /**
     * Health Status: over voltage.
     */
    HEALTH_STATE_OVERVOLTAGE,

    /**
     * Health Status: COLD.
     */
    HEALTH_STATE_COLD,

    /**
     * Health Status: Dead.
     */
    HEALTH_STATE_DEAD,

    /**
    * The bottom of the enum.
    */
    HEALTH_STATE_BUTT
};

/**
 * Type for acquire BatteryPluggedType.
 */
enum class BatteryPluggedType : uint32_t {
    /**
     * Power source is unplugged.
     */
    PLUGGED_TYPE_NONE,

    /**
     * Power source is an AC charger.
     */
    PLUGGED_TYPE_AC,

    /**
     * Power source is a USB DC charger.
     */
    PLUGGED_TYPE_USB,

    /**
     * Power source is wireless charger.
     */
    PLUGGED_TYPE_WIRELESS,

    /**
    * The bottom of the enum.
    */
    PLUGGED_TYPE_BUTT
};

class BatteryInfo {
public:
    enum {
        COMMON_EVENT_CODE_CAPACITY = 0,
        COMMON_EVENT_CODE_VOLTAGE = 1,
        COMMON_EVENT_CODE_TEMPERATURE = 2,
        COMMON_EVENT_CODE_HEALTH_STATE = 3,
        COMMON_EVENT_CODE_PLUGGED_TYPE = 4,
        COMMON_EVENT_CODE_PLUGGED_MAX_CURRENT = 5,
        COMMON_EVENT_CODE_PLUGGED_MAX_VOLTAGE = 6,
        COMMON_EVENT_CODE_CHARGE_STATE = 7,
        COMMON_EVENT_CODE_CHARGE_COUNTER = 8,
        COMMON_EVENT_CODE_PRESENT = 9,
        COMMON_EVENT_CODE_TECHNOLOGY = 10,
    };

    BatteryInfo() = default;
    ~BatteryInfo() = default;
    void SetCapacity(const int32_t capacity)
    {
        capacity_ = capacity;
    }

    void SetVoltage(const int32_t voltage)
    {
        voltage_ = voltage;
    }

    void SetTemperature(const int32_t temperature)
    {
        temperature_ = temperature;
    }

    void SetHealthState(const BatteryHealthState healthState)
    {
        healthState_ = healthState;
    }

    void SetPluggedType(const BatteryPluggedType pluggedType)
    {
        pluggedType_ = pluggedType;
    }

    void SetPluggedMaxCurrent(const int32_t maxCurrent)
    {
        pluggedMaxCurrent_ = maxCurrent;
    }

    void SetPluggedMaxVoltage(const int32_t maxVoltage)
    {
        pluggedMaxVoltage_ = maxVoltage;
    }

    void SetChargeState(const BatteryChargeState chargeState)
    {
        chargeState_ = chargeState;
    }

    void SetChargeCounter(const int32_t chargeCounter)
    {
        chargeCounter_ = chargeCounter;
    }

    void SetPresent(const bool present)
    {
        present_ = present;
    }

    void SetTechnology(const std::string &technology)
    {
        technology_ = technology;
    }

    const int32_t &GetCapacity() const
    {
        return capacity_;
    }

    const int32_t &GetVoltage() const
    {
        return voltage_;
    }

    const int32_t &GetTemperature() const
    {
        return temperature_;
    }

    BatteryHealthState GetHealthState() const
    {
        return healthState_;
    }

    BatteryPluggedType GetPluggedType() const
    {
        return pluggedType_;
    }

    const int32_t &GetPluggedMaxCurrent() const
    {
        return pluggedMaxCurrent_;
    }

    const int32_t &GetPluggedMaxVoltage() const
    {
        return pluggedMaxVoltage_;
    }

    BatteryChargeState GetChargeState() const
    {
        return chargeState_;
    }

    const int32_t &GetChargeCounter() const
    {
        return chargeCounter_;
    }

    bool IsPresent() const
    {
        return present_;
    }

    const std::string &GetTechnology() const
    {
        return technology_;
    }

private:
    int32_t capacity_ = INVALID_BATT_INT_VALUE;
    int32_t voltage_ = INVALID_BATT_INT_VALUE;
    int32_t temperature_ = INVALID_BATT_TEMP_VALUE;
    BatteryHealthState healthState_ = BatteryHealthState::HEALTH_STATE_BUTT;
    BatteryPluggedType pluggedType_ = BatteryPluggedType::PLUGGED_TYPE_BUTT;
    int32_t pluggedMaxCurrent_ = INVALID_BATT_INT_VALUE;
    int32_t pluggedMaxVoltage_ = INVALID_BATT_INT_VALUE;
    BatteryChargeState chargeState_ = BatteryChargeState::CHARGE_STATE_BUTT;
    int32_t chargeCounter_ = INVALID_BATT_INT_VALUE;
    bool present_ = INVALID_BATT_BOOL_VALUE;
    std::string technology_ = INVALID_STRING_VALUE;
};
} // namespace PowerMgr
} // namespace OHOS

#endif // BATTERY_SRV_BATERY_INFO_H
